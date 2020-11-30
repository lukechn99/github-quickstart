# Threads
Abstraction for executing instruction stream  
They exist within a process and share its resources, but have their own stack and program counter  
A process automatically has one thread  
They are all independent, no one thread controls another. 

### Switching between threads in a process
The CPU will swtich between threads when running a process  
With concurrency, blocking causes thread switches  
Assume that threads can switch at any time when writing threaded programs

### Benefits of Threads
Concurrency: blocking points are good times to switch. One thread blocks and we switch to another  
Modularity: threads can be assigned to different threads. We can decompose the problem into parts.  
Parallelism: leverage multi-core processors to actually run threads in parallel (as opposed to concurrency where you switch)  
Scale: threads are more lightweight than processes  
Overhead: cheaper than processes  

### Example: an Editor
threads = activities  
In an editor program, we have different activities going on:  
keyboard input  
autosave  
display to monitor  
manage buffer  
When one activity blocks, like the user stops typing, the processor could move onto save the doc  
Each *activity* should have a different *thread*

### Example: A Web Server
assuming they use dispatcher() and worker() which are both different activities that need to be done. Dispatcher finds web pages to send and the worker returns a page, then they also need to communicate in between them.  
Threads share buffer, cache, globals, heaps, but not stack
With a single thread, we finish the request in 30 seconds  
```
[read] -> [serve] -> [write]  
  10         10         10    
```
With multiple threads, we can start a new read when the previous serve is still going on, and the average time per request goes down with mulitple requests  
```
[read] -> [serve] -> [write]  
          [read] ->  [serve] -> [write]  
                     [read] -> [serve] -> [write]  
```
### Drawbacks
No isolation of failures, threads can be switched without warning based on a system timer, this could interrupt things.  
Due to race conditions, we need to implement thread safety with locks. However, locks reduce concurrency because it is a blocking operation. 

# Multithreading
Lightweight method of parallelism and concurrency without need for IPD because of their shared resources  

### Thread creation
``` pthread_create(pthread_t* thread, pthread_attr_t* attr, void* func, void* arg) ```
Usually creates a thread with a function (3rd param) and arguments to execute on (4th param)  
Returns 0 on success and error number on failure

### Joinable and Detached Threads
Joinable threads don't release resources until ```pthread_join(pthread_t thread, void* retval)``` is called by another thread. Processes pause at pthread_join until the thread is finished.  
Detaches threads automatically release resources on exit

### Mutex locks
We set a lock before using a shared resource and we release the lock after using the shared resource.  
```
 THREAD A          THREAD B
[section 1]       [section 2]
     |                 | <-------- Lock pthread_mutex_lock(mutex)
[shared var]      [shared var]
     |                 | <-------- Unlock pthread_mutex_unlock(mutex)
[section 2]       [section 2]
```
Compile with ```gcc -pthread -o out main.c``` to use threads. 
Sample code with **Mutex and Joinable Threads**:
```
#define NTHREADS 10
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// shared variable
int counter;

pthread_t tid[NTHREADS]

void* addCount (void *arg) {
  int value = *(int*)arg;
  pthread_mutex_lock(&lock);
  counter += value;
  pthread_mutex_unlock(&lock);
  return NULL;
}

int main(int argc, char* argv[]) {
  // create 10 joinable threads
  int i;
  int arg_arr[NTHREADS];
  
  for (i = 0; i < NTHREADS; i++) {
    arg_arr[i] = i;
  }
  for (i = 0; i < NTHREADS; i++) {
    // create joinable threads
    if (pthread_create(&(tid[i]), NULL, addCount, (void*) &arg_arr[i]) != 0) {
      perror("failed to create");
    }
  }
  
  // since we use joinable threads, we must call pthread_join to finish
  for (i = 0; i < NTHREADS; i++) {
    pthread_join(tid[i], NULL);
  }
  
  return 0;
// joinable threads

```
Important functions are...
```
pthread_t
pthread_create
pthread_join

pthread_mutex_t
pthread_mutex_lock
pthread_mutex_unlock
```

### Conditions
Conditions are used to determine whether to lock or not. They are created as ```pthread_cond_t cond```  
initialized as ```pthread_cond_init```  
The condition is typically created outside of a the functions, and then initialized in main()  
```pthread_cond_wait``` is very important as it waits on a condition variable before continuing.  
```pthread_cond_signal``` and ```pthread_cond_broadcast``` let other threads know when they can start after the condition is met. ```pthread_cond_signal``` notifies one and ```pthread_cond_broadcast``` notifies all.
```
/*
Breakout Number: 11

Members:
* Evgeni Radichev (radic024)
* Hamse Abdi (abdix234)
* Luke Chen (chen5216)
* Haneesha Kella (kella458)
* Hassan Osman (osman256)
* Bat-Ider Ganbold (ganbo011)

*/

#define NUM_ARGS 0

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/time.h>

long condTotal = 0;

struct buffer {

	int vals[100];
	int index; //indicates the next available spot
};

struct condBuffer {

	struct buffer* q;
	pthread_cond_t* cond;
	pthread_mutex_t* mutex;
};


void insert(struct buffer* q, int val) {

	q->vals[q->index] = val;
	++q->index;
}

int delete(struct buffer* q) {

	--q->index;
	int val = q->vals[q->index];
	return val;
}

// TODO: Insert code to use a condition variable.
void* condProducer(void* arg) {

	// Random delay. DO NOT REMOVE!
	usleep(rand() % 1000);

	struct condBuffer* cq = (struct condBuffer*) arg;

	pthread_mutex_lock(cq->mutex);
	// Counter.
	static int in = 0;
	++in;

	// Add an element to the buffer.
	insert(cq->q, in);
	pthread_cond_signal(cq->cond);
	pthread_mutex_unlock(cq->mutex);
}

// TODO: Insert code to use a condition variable.
void* condConsumer(void* arg) {

	// Random delay. DO NOT REMOVE!
	usleep(rand() % 1000);

	struct condBuffer* cq = (struct condBuffer*) arg;

	pthread_mutex_lock(cq->mutex);
	while(cq->q->index == 0){
		pthread_cond_wait(cq->cond, cq->mutex);
	}
	// Remove an element from the buffer.
	condTotal += delete(cq->q);
	pthread_mutex_unlock(cq->mutex);
}

int main(int argc, char** argv) {

	if (argc != NUM_ARGS + 1) {

		printf("Wrong number of args, expected %d, given %d\n", NUM_ARGS, argc - 1);
		exit(1);
	}

	// Seed the random generator.
	srand(time(NULL));

	// Create threads.
	pthread_t condPool[100];

	struct timeval start;
	gettimeofday(&start, NULL);

	// Create the cond variable controlled task buffer.
	struct condBuffer* cq = (struct condBuffer*) malloc(sizeof(struct condBuffer));
	cq->q = (struct buffer*) malloc(sizeof(struct buffer));
	cq->q->index=0;
	cq->cond = (pthread_cond_t*) malloc(sizeof(pthread_cond_t));
	cq->mutex = (pthread_mutex_t*) malloc(sizeof(pthread_mutex_t));
	pthread_cond_init(cq->cond, NULL);
	pthread_mutex_init(cq->mutex, NULL);

	// Creating producers and consumers
	for (int i=0; i < 50; ++i) {

		pthread_create(&condPool[i], NULL, condProducer, (void*) cq); //start 50 producer threads
		pthread_create(&condPool[50 + i], NULL, condConsumer, (void*) cq); //start 50 consumer threads
	}

	for (int i=0; i < 100; ++i) pthread_join(condPool[i], NULL); //wait for all the threads to be finished

	struct timeval end;
	gettimeofday(&end, NULL);

	// Validating the results
	printf("Cond Test: \nTotal of buffer = %ld\n", condTotal);
	printf("Time (in us) to run = %ld\n\n", ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec));

	}
```


```
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_cond_t cond;

pthread_mutex_t lock;

int done = 1;

void* demo (void *arg) {
	int id = (int) *(int*)arg;
	
	pthread_mutex_lock(&lock);
	while(done == 1) {
		done = 2;
		pthread_cond_wait(&cond, &lock
```

### Semaphores
Locks with an internal counters. While mutex locks use values of either 1 or 0, semaphores can have a counter variable for access.  
Create a semaphore with ```sem_t semaphore``` and ```sem_init(sem_t* sem, int pshared, int value);``` pshared is 0 for threads and a positive int for processes. The value specifies what the counter should be.  
```sem_wait(sem_t* sem);``` is a decrement or wait
```sem_post(sem_t* sem)``` is an increment  
Use mutex locks in conjunction with semaphores and place a lock after wait. 
```
/*
Breakout Number:

Members:
* Evgeni Radichev (radic024)
* Hamse Abdi (abdix234)
* Luke Chen (chen5216)
* Haneesha Kella (kella458)
* Hassan Osman (osman256)
* Bat-Ider Ganbold (ganbo011)

*/

#define NUM_ARGS 0

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include<sys/time.h>

long semTotal = 0;

struct buffer {

	int vals[100];
	int index;
};

struct semBuffer {

	struct buffer* q;
	sem_t* psem;
	sem_t* csem;
	pthread_mutex_t* mutex;
};

void insert(struct buffer* q, int val) {

	q->vals[q->index] = val;
	++q->index;
}

int delete(struct buffer* q) {

	--q->index;
	int val = q->vals[q->index];
	return val;
}

// TODO: Insert code to use a semaphore.
void* semProducer(void* arg) {

	// Random delay. DO NOT REMOVE!
	usleep(rand() % 1000);

	struct semBuffer* sq = (struct semBuffer*) arg;

	sem_wait(sq->psem);
	pthread_mutex_lock(sq->mutex);
	static int in = 0;
	++in;

	// Add an element to the queue.
	insert(sq->q, in);
	pthread_mutex_unlock(sq->mutex);
	sem_post(sq->csem);
}

// TODO: Insert code to use a semaphore.
void* semConsumer(void* arg) {

	// Random delay. DO NOT REMOVE!
	usleep(rand() % 1000);

	struct semBuffer* sq = (struct semBuffer*) arg;

	while(sq->q->index == 0){
		sem_wait(sq->csem);
	}
	pthread_mutex_lock(sq->mutex);
	// Reove an element from the queue.
	semTotal += delete(sq->q);
	pthread_mutex_unlock(sq->mutex);
	sem_post(sq->psem);

}

int main(int argc, char** argv) {

	if (argc != NUM_ARGS + 1) {

		printf("Wrong number of args, expected %d, given %d\n", NUM_ARGS, argc - 1);
		exit(1);
	}

	// Seed the random generator.
	srand(time(NULL));

	// Create threads.
	pthread_t semPool[100];

	struct timeval start;
	gettimeofday(&start, NULL);

	// Create semaphore controlled task queue.
	struct semBuffer* sq = (struct semBuffer*) malloc(sizeof(struct semBuffer));

	sq->q = (struct buffer*) malloc(sizeof(struct buffer));
	sq->q->index=0;
	sq->psem = (sem_t*) malloc(sizeof(sem_t));
	sq->csem = (sem_t*) malloc(sizeof(sem_t));
	sq->mutex = (pthread_mutex_t*) malloc(sizeof(pthread_mutex_t));

	// TODO: Initialize semaphores
	sem_init(sq->psem,0,50);
	sem_init(sq->csem,0,0);

	pthread_mutex_init(sq->mutex, NULL);

	// Creating producers and consumers
	for (int i=0; i < 50; ++i) {

		pthread_create(&semPool[i], NULL, semProducer, (void*) sq);
		pthread_create(&semPool[50 + i], NULL, semConsumer, (void*) sq);
	}

	for (int i=0; i < 100; ++i) pthread_join(semPool[i], NULL); //wait for all the threads to be finished

	struct timeval end;
	gettimeofday(&end, NULL);

	// Validating the results
	printf("Sem Test: \nTotal of buffer  = %ld\n", semTotal);
	printf("Time (in us) to complete = %ld\n", ((end.tv_sec - start.tv_sec) * 1000000) + (end.tv_usec - start.tv_usec));
}
```

### Deadlocks
For example, if thread 1 is accessing resource A and wants to access resource B while thread 2 is using resource B and wants to access resource A, then there could be a lock.  

One solution is to throw an exception instead of waiting. 
