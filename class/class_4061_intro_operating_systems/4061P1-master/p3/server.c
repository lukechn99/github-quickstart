#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>
#include "util.h"
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>

#define MAX_THREADS 100
#define MAX_queue_len 100
#define MAX_CE 100
#define INVALID -1
#define BUFF_SIZE 1024
#define MAX_FILENAME 1024
#define MAX_LOGENTRY 1024
/*
  THE CODE STRUCTURE GIVEN BELOW IS JUST A SUGGESTION. FEEL FREE TO MODIFY AS NEEDED
*/



// structs:
typedef struct request_queue {
  int fd;
  char *request;
} request_t;

typedef struct cache_entry {
  int len;
  char *request;
  char *content;
} cache_entry_t;

typedef struct buffer {
  int next_slot_to_retrieve;
  int next_slot_to_store;
  int n_items;
  request_t* items;
} buffer_t;
  
request_t request_queue[MAX_queue_len];
pthread_mutex_t request_queue_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t logger_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t some_content = PTHREAD_COND_INITIALIZER;
pthread_cond_t free_slot = PTHREAD_COND_INITIALIZER;

pthread_t dynamic_worker_thread;

buffer_t b = {.next_slot_to_retrieve = 0, .next_slot_to_store = 0, .n_items = 0, .items = request_queue};
int queue_length_global = MAX_queue_len;
int DONE = 0;
FILE* fp_global;
int workerID[100];

/* ******************** Dynamic Pool Code  [Extra Credit A] **********************/
// Extra Credit: This function implements the policy to change the worker thread pool dynamically
// depending on the number of requests
void * dynamic_pool_size_update(void *arg) {
  while(1) {
    // Run at regular intervals
    // Increase / decrease dynamically based on your policy
  }
}
/**********************************************************************************/

/* ************************ Cache Code [Extra Credit B] **************************/

// Function to check whether the given request is present in cache
int getCacheIndex(char *request){
  /// return the index if the request is present in the cache
  return 0;
}

// Function to add the request and its file content into the cache
void addIntoCache(char *mybuf, char *memory , int memory_size){
  // It should add the request at an index according to the cache replacement policy
  // Make sure to allocate/free memory when adding or replacing cache entries
}

// clear the memory allocated to the cache
void deleteCache(){
  // De-allocate/free the cache memory
}

// Function to initialize the cache
void initCache(){
  // Allocating memory and initializing the cache array
}

/**********************************************************************************/

/* ************************************ Utilities ********************************/
// Function to get the content type from the request
// char* getContentType(char * mybuf) {
// Use a return parameter instead to allow the use of stack allocated arrays in caller
void getContentType(char * mybuf, char* filetype) {
  // Should return the content type based on the file type in the request
  // (See Section 5 in Project description for more details)
  // Determine file type given a pointer to a filename (mybuf) and set the output parameter filetype
  int period_index = 0;
  for (int i = 0; mybuf[i]; i++) {
    if (mybuf[i] == '.') {
      period_index = i;
    }
  }
  if (!strcmp(mybuf + period_index, ".html") || !strcmp(mybuf + period_index, ".htm")) {
    strcpy(filetype, "text/html");
  } else if (!strcmp(mybuf + period_index, ".jpg")) {
    strcpy(filetype, "image/jpeg");
  } else if (!strcmp(mybuf + period_index, ".gif")) {
    strcpy(filetype, "image/gif");
  } else {
    strcpy(filetype, "text/plain");
  }
}

// Function to open and read the file from the disk into the memory
// Add necessary arguments as needed
int readFromDisk(char* path, void* buf, off_t size) {
  // Open and read the contents of file given by path into a buffer buf of size size
  // Return 0 on success and 1 otherwise
  int fd = open(path, O_RDONLY);
  if (fd == -1) {
    perror("file open failed");
    return 1;
  }
  if (read(fd, buf, size) == -1) {
    perror("read failed");
    close(fd);
    return 1;
  }
  close(fd);
  return 0;
}

request_t dequeue (buffer_t *b) {
  // Remove and return element from the buffer pointed to by b
  // If the buffer is empty, then block until signalled by enqueue
  request_t st;
  if (pthread_mutex_lock(&request_queue_mutex)) {
    fprintf(stderr, "pthread function failed\n");
    exit(1);
  }

  // Buffer is empty when idicies are equal (to 0?)
  //  while (b->next_slot_to_retrieve == b->next_slot_to_store) {
  // n_items in [0, queue_length_global]
  while (b->n_items <= 0) {

#ifdef DEBUG
    fprintf(stderr, "Thread %ld waiting: b->next_slot_to_retrieve = %d\n", (long) gettid(), b->next_slot_to_retrieve);
#endif
    if (pthread_cond_wait(&free_slot, &request_queue_mutex)) {
      fprintf(stderr, "pthread function failed\n");
      exit(1);
    }
    // Special case for when queue_length_global == 1
    // Otherwise, b->next_slot_to_retrieve == b->next_slot_to_store at all times and dequeue fails to leave the loop

    /*
      if (queue_length_global <= 1) {
      break;
      }
    */
  }
#ifdef DEBUG
  fprintf(stderr, "Thread %ld getting  b->next_slot_to_retrieve: %d\n", (long) gettid(), b->next_slot_to_retrieve);
#endif
  st = b->items[b->next_slot_to_retrieve];
  b->next_slot_to_retrieve = (b->next_slot_to_retrieve + 1) % queue_length_global;
  b->n_items--;
  if (pthread_cond_signal(&some_content)) {
    fprintf(stderr, "pthread function failed\n");
    exit(1);
  }
  if (pthread_mutex_unlock(&request_queue_mutex)) {
    fprintf(stderr, "pthread function failed\n");
    exit(1);
  }
  return st;
}

void enqueue (buffer_t *b, request_t r) {
  // Insert an element r into the buffer pointed to by b
  // If the buffer is full, then block until signalled by dequeue
  
  if (pthread_mutex_lock(&request_queue_mutex)) {
    fprintf(stderr, "pthread function failed\n");
    exit(1);
  }

  //   while (b->next_slot_to_store == queue_length_global) {
  // Buffer is full and we are not on the first time (otherwise next_slot_to_retrieve == 0)
  //  while (b->next_slot_to_store == 0 && b->next_slot_to_retrieve > 0) {
  while (b->n_items >= queue_length_global) {
#ifdef DEBUG
    fprintf(stderr, "Thread %ld waiting (to enqueue): b->next_slot_to_retrieve = %d\n", (long) gettid(), b->next_slot_to_retrieve);
#endif
    if (pthread_cond_wait(&some_content, &request_queue_mutex)) {
      fprintf(stderr, "pthread function failed\n");
      exit(1);
    }
  }
  // request contains a pointer to memory allocated on the heap
#ifdef DEBUG
  fprintf(stderr, "Thread %ld setting b->items[%d]\n", (long) gettid(), b->next_slot_to_store);
#endif
  b->items[b->next_slot_to_store] = r;
  b->next_slot_to_store = (b->next_slot_to_store + 1) % queue_length_global;
  b->n_items++;
  if (pthread_cond_signal(&free_slot)) {
    fprintf(stderr, "pthread function failed\n");
    exit(1);
  }
  if (pthread_mutex_unlock(&request_queue_mutex)) {
    fprintf(stderr, "pthread function failed\n");
    exit(1);
  }
}

void write_log(void* arg, int rep, request_t req, off_t size) {
  // Write a log message to stdout and fp_global
  // build log message
  char log[MAX_LOGENTRY];
  int* id = arg;
  int connection_fd = req.fd;
  sprintf(log, "[%d][%d][%d][", *id, rep, connection_fd);
  char* connection_request = req.request;
  strcat(log, connection_request);
  strcat(log, "]");
  // find the number of bytes returned or cat "Requested file not found."
  if (size > 0) {
    char bytes[10];
    sprintf(bytes, "[%d]", (int)size);
    strcat(log, bytes);
  } else {
    strcat(log, "[Requested file not found.]");
  }
  strcat(log, "[");
  // "HIT" or "MISS" based on cache results

  strcat(log, "]\n");

  // Log the request into the file and terminal
  if (pthread_mutex_lock(&logger_mutex)) {
    fprintf(stderr, "pthread function failed\n");
    exit(1);
  }
  FILE *fp = fp_global;
  /*if ((fp = fopen("web_serverlog", "a")) == NULL) {
    perror("error in opening file for logging");
    }*/
  fputs(log, fp);
  fprintf(stdout, "%s", log);
  fflush(stdout);
  /*    if (fclose(fp) == -1) {
	perror("error in closing file");
	}*/
  if (pthread_mutex_unlock(&logger_mutex)) {
    fprintf(stderr, "pthread function failed\n");
    exit(1);
  }
}
  
/**********************************************************************************/

// Function to receive the request from the client and add to the queue
void * dispatch(void *arg) {
  // Function run by dispatcher threads that continually accepts connections
  // arg points to an integer id
  while (1) {

    // Accept client connection
    // Ignore negative return value
    int fd;
    if ((fd = accept_connection()) < 0) {
#ifdef DEBUG
      fprintf(stderr, "Dispatcher thread %ld received error %d\n", (long) gettid(), fd);
#endif
      continue;
    } else {
#ifdef DEBUG
      fprintf(stderr, "Dispatcher thread %ld received connection %d\n", (long) gettid(), fd);
#endif
    }
    
    // Get request from the client
    char *filename = calloc(sizeof(char), MAX_FILENAME);
    if (filename == NULL) {
      perror("calloc failed");
      continue;
    }
    memset(filename, 0, MAX_FILENAME);
    if (get_request(fd, filename)) {
      free(filename);
      continue;
    } else {
#ifdef DEBUG
      fprintf(stderr, "Dispatcher thread %ld received filename: %s\n", (long) gettid(), filename);
#endif
    }
    // Add the request into the queue
    request_t r = {.fd = fd, .request = filename};
#ifdef DEBUG
    fprintf(stderr, "Dispatcher thread %ld enqueueing request with .fd: %d and .request: %s\n", (long) gettid(), r.fd, r.request);
#endif
    enqueue(&b, r);
#ifdef DEBUG
    fprintf(stderr, "Dispatcher thread %ld finished enqueueing request with .fd: %d and .request: %s\n", (long) gettid(), r.fd, r.request);
#endif
  }
  return NULL;
}

/**********************************************************************************/

// Function to retrieve the request from the queue, process it and then return a result to the client
void * worker(void *arg) {
  // Function that continuously removes items from the queue and returns the corresponding files or an error to the requester
  // arg is not used in this function
  int rep = 0;
  while (1) {
    // Get the request from the queue
    request_t req;
    rep += 1;

#ifdef DEBUG
    fprintf(stderr, "Worker thread %ld calling dequeue\n", (long) gettid());
#endif
    req = dequeue(&b);
#ifdef DEBUG
    fprintf(stderr, "Worker thread %ld got request with .fd: %d and .request: %s\n", (long) gettid(), req.fd, req.request);
#endif
    // Get the data from the disk or the cache (extra credit B)
    char errmsg[256];
    // req.request includes a leading forward slash, so we remove it
    char *path = req.request + sizeof(char);
    struct stat s;
    // Need to stat file to determine the size of the buffer we need to allocate
    // If stat fails, this should indicate that there is an issue with the requested file
    if (stat(path, &s) == -1) {
      perror("stat failed");
      memset(errmsg, 0, 256);
      sprintf(errmsg, "%s not found", req.request);
      write_log(arg, rep, req, -1);
      return_error(req.fd, errmsg);
      free(req.request);
      continue;
    }
    
    off_t size = s.st_size;
    // Handle malloc error
    void* buf = malloc(size);
    if (buf == NULL) {
      free(req.request);
      perror("malloc failed");
      continue;
    }
    if (readFromDisk(path, buf, size)) {
      // If readFromDisk returns a truthy value, then open or read failed
      memset(errmsg, 0, 256);
      sprintf(errmsg, "%s not found", req.request);
      write_log(arg, rep, req, -1);
      return_error(req.fd, errmsg);
      free(req.request);
      continue;
    }

    /*
    // build log message
    char log[MAX_LOGENTRY];
    int* id = arg;
    int connection_fd = req.fd;
    sprintf(log, "[%d][%d][%d][", *id, rep, connection_fd);
    char* connection_request = req.request;
    strcat(log, connection_request);
    strcat(log, "]");
    // find the number of bytes returned or cat "Requested file not found."
    if (size > 0) {
    char bytes[10];
    sprintf(bytes, "[%d]", (int)size);
    strcat(log, bytes);
    } else {
    strcat(log, "Requested file not found.");
    }
    strcat(log, "[");
    // "HIT" or "MISS" based on cache results

    strcat(log, "]\n");

    // Log the request into the file and terminal
    if (pthread_mutex_lock(&logger_mutex)) {
    fprintf(stderr, "pthread function failed\n");
    exit(1);
    }

    FILE *fp = fp_global;
    if ((fp = fopen("web_serverlog", "a")) == NULL) {
    perror("error in opening file for logging");
    }*/
    /*    fputs(log, fp);
	  fprintf(stdout, "%s", log);
	  fflush(stdout);
	  if (fclose(fp) == -1) {
	  perror("error in closing file");
	  }*/
    //    if (pthread_mutex_unlock(&logger_mutex)) {
    //    fprintf(stderr, "pthread function failed\n");
    //    exit(1);
    //  }
    // return the result


    char filetype[16];
    memset(filetype, 0, 16);
    getContentType(path, filetype);
	    
#ifdef DEBUG
    fprintf(stderr, "Worker thread %ld returning request .request: %s of type: %s to: %d\n", (long) gettid(), req.request, filetype, req.fd);
#endif
    return_result(req.fd, filetype, buf, s.st_size);
    write_log(arg, rep, req, size);
    free(buf);
    free(req.request);
  }
  return NULL;
}

/**********************************************************************************/
// TEST
// ./web_server 9000 . 10 10 0 10 0

void shutdown(int signal) {
  // Handler for SIGINT, which sets DONE to 1 so that the while loop in main exits and prints number of pending requests
  // shutdown handles all termination to prevent interruption from additional signals
  // The argument signal is not used
  DONE = 1;
  // Since shutdown will end the process, there is no need to unlock any mutex after locking
  if (pthread_mutex_lock(&request_queue_mutex)) {
    fprintf(stderr, "pthread function failed\n");
    exit(1);
  }
  printf("The number of pending requests in the request queue: %d\n", b.n_items);
  /*  if (pthread_mutex_unlock(&request_queue_mutex)) {
    fprintf(stderr, "pthread function failed\n");
    exit(1);
  }*/
  if (pthread_mutex_lock(&logger_mutex)) {
    fprintf(stderr, "pthread function failed\n");
    exit(1);
  }
  // Close log file
  if (fclose(fp_global) == -1) {
    perror("error in closing file");
    exit(1);
  }

  exit(0);
}

// TEST
// ./web_server 9000 . 10 10 0 10 0


int main(int argc, char **argv) {
  // Parse arguments and create worker and dispatcher threads, then sleep until SIGINT received
  // Handle graceful termination after SIGINT
  // Error check on number of arguments
  if(argc != 8){
    printf("usage: %s port path num_dispatcher num_workers dynamic_flag queue_length cache_size\n", argv[0]);
    return -1;
  }

  // Get the input args
  int port = atoi(argv[1]);
  int num_dispatcher = atoi(argv[3]);
  int num_workers = atoi(argv[4]);
  // int dynamic_flag = atoi(argv[5]);
  int queue_length = atoi(argv[6]);
  int cache_size = atoi(argv[7]);
  char* path = argv[2];

  

  // Perform error checks on the input arguments

  if (port < 1025 || port > 65535) {
    printf("usage: %s port path num_dispatcher num_workers dynamic_flag queue_length cache_size, where port in [1025, 65535]\n", argv[0]);
    return -1;
  }
  if (num_dispatcher > 100 || num_workers > 100 || queue_length > 100 || cache_size > 100 ||
      num_dispatcher < 1 || num_workers < 1 || queue_length < 1 || cache_size < 0) {
    printf("usage: %s port path num_dispatcher num_workers dynamic_flag queue_length cache_size, where num_dispatcher, num_workers, queue_length in [1, 100] and cache_size in [0, 100]\n", argv[0]);
    return -1;
  }

  // Change SIGINT action for grace termination
  sigset_t signal_mask;
  int status = sigfillset(&signal_mask);
  if (status == -1) {
    perror("sigfillset failed");
    exit(-1);
  }

  struct sigaction s;
  memset(&s, 0, sizeof(struct sigaction));
  s.sa_handler = shutdown;
  s.sa_mask = signal_mask;
  status = sigaction(SIGINT, &s, NULL);
  if (status == -1) {
    perror("sigaction failed");
    exit(-1);
  }
  // Open log file
  FILE *fp;
  if ((fp = fopen("web_serverlog", "w")) == NULL) {
    perror("error in opening file for logging");
  }
  // Set global variable so that other functions can access file
  fp_global = fp;

  // Change the current working directory to server root directory
  if (chdir(path) == -1) {
    perror("chdir failed");
    exit(1);
  }

  // Initialize cache (extra credit B)
  queue_length_global = queue_length;
  memset(request_queue, 0, sizeof(request_t) * queue_length_global);
  // Start the server
  init(port);

  // Create dispatcher and worker threads (all threads should be detachable)
  pthread_t workers[100], dispatchers[100];
  pthread_attr_t detach;
  if (pthread_attr_init(&detach)) {
    fprintf(stderr, "pthread function failed\n");
    exit(1);
  }

  if (pthread_attr_setdetachstate(&detach, PTHREAD_CREATE_DETACHED)) {
    fprintf(stderr, "pthread function failed\n");
    exit(1);
  }
  for (int d = 0; d < num_dispatcher; d++) {
    // if (pthread_create(&dispatchers[d], NULL, dispatch, NULL)) {
    //    fprintf(stderr, "pthread function failed\n");
    //    exit(1);
    //  }
    if (pthread_create(&dispatchers[d], &detach, dispatch, NULL)) {
      fprintf(stderr, "pthread function failed\n");
      exit(1);
    }
  }

  for (int w = 0; w < num_workers; w++) {
    workerID[w] = w;
    if (pthread_create(&workers[w], NULL, worker, (void *) &(workerID[w]))) {
      fprintf(stderr, "pthread function failed\n");
      exit(1);
    }
  }


  // Create dynamic pool manager thread (extra credit A)
  if (pthread_create(&dynamic_worker_thread, NULL, &dynamic_pool_size_update,
      num_workers) < 0) {
    perror("error creating dynamic worker pool creator");
  }

  // Terminate server gracefully

  
  while (!DONE) {
    // Sleep until we catch a signal
    pause();
  }

  // Print the number of pending requests in the request queue
  // close log file
  /*  if (pthread_mutex_lock(&logger_mutex)) {
    fprintf(stderr, "pthread function failed\n");
    exit(1);
  }
  if (fclose(fp) == -1) {
    perror("error in closing file");
    }*/
  // Remove cache (extra credit B)

  return 0;
}
