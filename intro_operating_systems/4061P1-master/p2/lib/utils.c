#include "utils.h"

// Reserve msgtyp = 1 for mapper ACK
long getMsgTypeFromMID(int mapperID) {
  return ((long) mapperID) + 1;
}
long getMIDFromMsgType(int msgType) {
  return ((long) msgType) - 1;
}

int isEND(struct msgBuffer msg) {
  // Should only run 1 iteration if the message is not END
  for (int i = 0; i < MSGSIZE; i++) {
    if (msg.msgText[i] != ENDMSG) {
      return 0;
    }
  }
  return 1;
}

char *getChunkData(int mapperID) {
  // use getMsgTypeFromMID(mapperID) to get the type of messages intended for mapper with mapperID
  // use isEND(msg) to check if msg is an END message
  // send your ACK with msgType = 1, for example:
  // struct msgBuffer a = {.msgType = 1, .msgText = "ACK"}; // The content of .msgText doesn't really matter
  
  // establish the message queue
  key_t k = ftok(".", MSQID);
  if (k == -1) {
    perror("ftok failed");
    return NULL;
  }
  struct msgBuffer msg;
  int msgid;
  if ((msgid = msgget(k, IPC_CREAT | 0666)) < 0) {
    return NULL;
  }

  // receive message
  if ((msgrcv(msgid, &msg, sizeof(msg.msgText), getMsgTypeFromMID(mapperID), 0)) < 0) {
    return NULL;
  }
  if (isEND(msg)) {
    long t = 1;
    if (msgsnd(msgid, &t, 0, 0) < 0) {
      perror("msgsnd failed");
    } 
    return NULL;
  }

  // allocates memory for the message to be used
  char* message = malloc(sizeof(msg.msgText));
  strncpy(message, msg.msgText, MSGSIZE);
  
  return message;
}

// sends chunks of size 1024 to the mappers in RR fashion
void sendChunkData(char *inputFile, int nMappers) {
  // FILE EXTRACTION
  // Get file size
  struct stat s;
  int status = stat(inputFile, &s);
  if (status < 0) {
    perror("stat failed");
    exit(-1);
  }
  off_t size = s.st_size, amount_read = 0;
#ifdef DEBUG
  fprintf(stderr, "%s contains %ld bytes\n", inputFile, (long) size);
#endif

  size_t file_size = size;
  
  // Open file
  FILE* in_file = fopen(inputFile, "r");
  if (in_file == NULL) {
    perror("sendChunkData fopen failed");
    exit(-1);
  }
  int msgqueue_id;  
  // Special case for file of size 0
  if (size == 0) {
    // Open message queue
    // We assume that getChunkData and sendChunkData are run in the same directory
    key_t k = ftok(".", MSQID);
    if (k == -1) {
      perror("ftok failed");
      exit(-1);
    }
    msgqueue_id = msgget(k, 0666 | IPC_CREAT);
    if (msgqueue_id < 0) {
      perror("msgget failed");
      exit(-1);
    }
    // The mappers still expect END messages, so we jump to the cleanup phase
    goto CLEANUP;    
  }

  
  int fd = fileno(in_file);
  if (fd < 0) {
    perror("fileno failed");
    exit(-1);
  }


  // map the file contents to memory for easier access
  void* mmaped_input = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (mmaped_input == (void*) -1) {
    perror("mmap failed");
    if (fclose(in_file) == EOF) {
      perror("fclose failed");
      exit(-1);
    } 
    exit(-1);
  }

  // Close the input file
  // The mapping remains valid and we avoid needing to close the file in the following error handling code
  if (fclose(in_file) == EOF) {
    perror("fclose failed");
    // Unmap the mapped file before exiting
    if (munmap(mmaped_input, file_size)) {
      perror("munmap failed");
      exit(-1);
    }    
    exit(-1);
  }

  // MESSAGE QUEUE

  // Open message queue
  // We assume that getChunkData and sendChunkData are run in the same directory
  key_t k = ftok(".", MSQID);
  if (k == -1) {
    perror("ftok failed");
    // Unmap the mapped file before exiting
    if (munmap(mmaped_input, file_size)) {
      perror("munmap failed");
    }    
    exit(-1);
  }
  
  msgqueue_id = msgget(k, 0666 | IPC_CREAT);

  if (msgqueue_id < 0) {
    perror("msgget failed");
    // Unmap the mapped file before exiting
    if (munmap(mmaped_input, file_size)) {
      perror("munmap failed");
    }    
    exit(-1);
  }

  // Construct chunks of at most chunkSize bytes and send each chunk to a mapper
  char* input = (char*) mmaped_input;
  int bytes_sent, mapperId = 1;
  while (amount_read < size) {
    off_t amount_remaining = size - amount_read;
#ifdef DEBUG
    fprintf(stderr, "Amount remaining to read: %ld\n", (long) amount_remaining);
#endif
    struct msgBuffer msg;
    // Initialize all of msg to 0
    memset(&msg, 0, sizeof(struct msgBuffer));
    // Specify the mapper intended to receive the message
    msg.msgType = getMsgTypeFromMID(mapperId);
    if (amount_remaining < chunkSize) { // only one chunk remaining
      // Send all remaining data, which fits in a single chunkSize byte message
      memcpy(msg.msgText, input, amount_remaining);
      // Send msg to queue
#ifdef DEBUG
      fprintf(stderr, "Sending last message with %ld bytes\n", (long) amount_remaining);
#endif
      bytes_sent = msgsnd(msgqueue_id, (void*) &msg, MSGSIZE, 0);
      if (bytes_sent < 0) {
	perror("msgsnd failed");
	// Unmap the mapped file before exiting
	if (munmap(mmaped_input, file_size)) {
	  perror("munmap failed");
	  exit(-1);
	}
	exit(-1);
      }
      amount_read += amount_remaining;
      break;
    } else {
      // Set input_end to point at maximum value for the end of the chunk,
      // where input_end points at the first character after input excluded from the chunk (first character of the next chunk)
      char* input_end = input + chunkSize * sizeof(char);
#ifdef DEBUG
      fprintf(stderr, "input: %lx\n", (long) input);
#endif
#ifdef DEBUG
      fprintf(stderr, "input_end: %lx\n", (long) input_end);
#endif
      size_t amount_to_send = chunkSize;

      // If input_end points at a non-word character, we can send input to input_end (excluding input_end)
      if (validChar(*input_end)) {
	// Otherwise, check input[input + amount_to_send - 1]
	// If input_end - 1 points at a non-word character, then send the amount_to_send bytes starting at input and ending at input_end (excluding input_end)
	while (amount_to_send > 0 && (validChar(*(input_end - 1)))){
	  amount_to_send--;
	  input_end--;
	}
      }

      if (amount_to_send <= 0) {
#ifdef DEBUG
	fprintf(stderr, "Word length exceeded chunkSize of %ld\n", (long) chunkSize);
#endif
	// Unmap the mapped file before exiting
	if (munmap(mmaped_input, file_size)) {
	  perror("munmap failed");
	  exit(-1);
	}
	exit(-1);
      } else {
	// Send msg to queue
	memcpy(msg.msgText, input, amount_to_send);
	bytes_sent = msgsnd(msgqueue_id, (void*) &msg, MSGSIZE, 0);
	if (bytes_sent < 0) {
	  perror("msgsnd failed");
	  // Unmap the mapped file before exiting
	  if (munmap(mmaped_input, file_size)) {
	    perror("munmap failed");
	    exit(-1);
	  }
	  exit(-1);
	}
	amount_read += amount_to_send;
      }
      // Set input and mapperId for next iteration
      input = input_end;
      mapperId++;
      if (mapperId > nMappers) {
	mapperId = 1;
      }
    }
  }

  // Unmap the input file, and catch munmap if it returns -1 on failure
  if (munmap(mmaped_input, file_size)) {
    perror("munmap failed");
    exit(-1);
  }
  
  // We jump to cleanup if the file is empty
 CLEANUP:
  // Send END mesage to mappers
  for (int i = 1; i <= nMappers; i++) {
    struct msgBuffer msg;
    memset(&msg, 0, sizeof(struct msgBuffer));
    // Set the END message to contain a values not found in ASCII
    memset(msg.msgText, ENDMSG, MSGSIZE);
    msg.msgType = getMsgTypeFromMID(i);
    bytes_sent = msgsnd(msgqueue_id, (void*) &msg, MSGSIZE, 0);
    if (bytes_sent < 0) {
      perror("msgsnd failed");
      exit(-1);
    }
  }
  
  // Wait for ACK's from children, which have msgType = 1
  for (int j = 1; j <= nMappers; j++) {
    struct msgBuffer m2;
    // Only read messages with msgType = 1
    long type = 1;//0;//-1;
    ssize_t bytes_received = msgrcv(msgqueue_id, (void*) &m2, MSGSIZE, type, 0);
    if (bytes_received < 0) {
      perror("sendChunkData msgrcv failed");
      exit(-1);
    }
  }

  // Delete the message queue associated with msgqueue_id
  status = msgctl(msgqueue_id, IPC_RMID, 0);
  if (status == -1){
    char errmsg[2048];
    memset(errmsg, 0, 2048);
    sprintf(errmsg, "sendChunkData msgctl failed to remove queue %d", MSQID);
    perror(errmsg);
    exit(-1);
  }
  

}

// hash function to divide the list of word.txt files across reducers
//http://www.cse.yorku.ca/~oz/hash.html
int hashFunction(char* key, int reducers){
  unsigned long hash = 0;
  int c;

  while ((c = *key++)!='\0')
    hash = c + (hash << 6) + (hash << 16) - hash;

  return (hash % reducers);
}

int getInterData(char *key, int reducerID) {
  /*
  * wordFileName is the word file path
  * open messageQueue
  * messageReceive(messageQueue, reducerID);
  * if chunkData == END
  *   messageSend(messageQueue, ACK, master);
  */

  // open messageQueue
  key_t k = ftok(".", 5340701);
  if (k == -1) {
    perror("ftok failed\n");
    exit(-1);
  }
  struct msgBuffer msg;
  int msgid;
  if ((msgid = msgget(k, IPC_CREAT | 0666)) < 0) {
    perror("unable to get msg queue");
    exit(-1);
  }


  // clear message buffer
  memset(&msg, 0, sizeof(struct msgBuffer));

  // receive message
  if (msgrcv(msgid, &msg, sizeof(msg.msgText), getMsgTypeFromMID(reducerID), 0) < 0) {
    perror("unable to receive message");
    exit(-1);
  }


  // ACK if we got an end message
  if (isEND(msg)) {
    // strcpy(msg.msgText, "ACK");
    //    msg.msgType = 1;
#ifdef DEBUG
  fprintf(stderr, "Reducer %d received END, sending ACK\n", reducerID);
#endif  
  long a = 1;
    if (msgsnd(msgid, &a, 0, 0) < 0) {
      perror("unable to send ACK");
      exit(-1);
    }
  } else {
    // Not an END message, we can't do anything
#ifdef DEBUG
    fprintf(stderr, "Reducer %d received %s\n", reducerID, msg.msgText);
#endif
    // Set output parameter
    // We assume that the path is at most 50 bytes long
    strncpy(key, msg.msgText, 50);
    return 1;
  }



  // we're done
  return 0;
}

void shuffle(int nMappers, int nReducers) {
  /*
  * input: (number of mappers, number of reducers):
  * open messageQueue
  * for each mapper:
  *   for each wordFileName in mapOutDir
  *     reducerID = hashfunction(wordFileName, nReducers)
  *     messageSend(messageQueue, wordFilePath, reducerID)
  * for each reducerID
  *   messageSend(messageQueue, END, reducerID)
  * for each reducer
  *   wait(for ACK from messageQueue)
  * close(messageQueue);
  */

  // open messageQueue
  key_t k = ftok(".", 5340701);
  if (k == -1) {
    perror("ftok failed\n");
    exit(-1);
  }
  struct msgBuffer msg;
  int msgid;
  if ((msgid = msgget(k, IPC_CREAT | 0666)) < 0) {
    exit(-1);
  }

  // for each mapper, send paths to reducers
  for (int i = 1; i <= nMappers; i++) {
    // create file directory path for mapper
    char path[PATHSIZE];
    memset(path, 0, PATHSIZE);
    // adds the mapper directory to path char string
    sprintf(path, "output/MapOut/Map_%d/", i);
    // opens dir for directory info
    DIR* dir = opendir(path);
    if (dir == NULL) {
      perror("The path is invalid\n");
      exit(-1);
    }
    struct dirent* entry;
    // reads entry types and continues distribution of file paths
    // to reducers using hashFunction
    while ((entry = readdir(dir)) != NULL) {
      // ignore the hidden directories "." and ".."
      if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
    		continue;
    	}
      // message buffer has text field cleared and set to
      // file path + file name
      struct msgBuffer pathmsg;
      memset(&pathmsg, 0, sizeof(struct msgBuffer)); 
      strncpy(pathmsg.msgText, path, PATHSIZE); 
      strcat(pathmsg.msgText, entry->d_name);
      pathmsg.msgType = getMsgTypeFromMID(hashFunction(entry->d_name, nReducers) + 1);
      if (entry->d_type == DT_REG) {
	#ifdef DEBUG
	fprintf(stderr, "Sending %s with type %d\n", pathmsg.msgText, pathmsg.msgType);
	#endif
        if (msgsnd(msgid, &pathmsg, sizeof(pathmsg.msgText), 0) < 0) {
          perror("path send to reducer failed\n");
          exit(-1);
        }
      } else {
        // we need to throw an error because there
        // should not be any non-files here
        perror("entry was a not a regular file\n");
      }
    }
    int status = closedir(dir);
    if (status == -1) {
      perror("closedir failed");
      exit(-1);
    }
  }
  
  // send END to each reducer
  for (int i = 1; i <= nReducers; i++) {
    struct msgBuffer msg;
    memset(&msg, 0, sizeof(struct msgBuffer));
    // Set the END message to contain a values not found in ASCII
    memset(msg.msgText, ENDMSG, MSGSIZE);
    msg.msgType = getMsgTypeFromMID(i);
    if (msgsnd(msgid, (void*) &msg, MSGSIZE, 0) < 0) {
      perror("msgsnd failed");
      exit(-1);
    }
  }

  // wait for ACK
  for (int i = 1; i <= nReducers; i++) {
    struct msgBuffer ackmsg;
    if(msgrcv(msgid, &ackmsg, sizeof(ackmsg.msgText), 1, 0) < 0) {
      perror("ACK not received");
    }
  }

  // close message queue
  int status = msgctl(msgid, IPC_RMID, NULL);
  if (status == -1){
    char errmsg[2048];
    memset(errmsg, 0, 2048);
    sprintf(errmsg, "shuffle msgctl failed to remove queue %d", MSQID);
    perror(errmsg);
    exit(-1);
  }
}

// check if the character is valid for a word
int validChar(char c){
	return (tolower(c) >= 'a' && tolower(c) <='z') ||
					(c >= '0' && c <= '9');
}

char *getWord(char *chunk, int *i){
  char *buffer = (char *)malloc(sizeof(char) * chunkSize);
  memset(buffer, '\0', chunkSize);
  int j = 0;
  while((*i) < strlen(chunk)) {
    // read a single word at a time from chunk
    // printf("%d\n", i);
    if (chunk[(*i)] == '\n' || chunk[(*i)] == ' ' || !validChar(chunk[(*i)]) || chunk[(*i)] == 0x0) {
      buffer[j] = '\0';
      if(strlen(buffer) > 0){
	(*i)++;
	return buffer;
      }
      j = 0;
      (*i)++;
      continue;
    }
    buffer[j] = chunk[(*i)];
    j++;
    (*i)++;
  }
  if(strlen(buffer) > 0)
    return buffer;
  return NULL;
}

void createOutputDir(){
  mkdir("output", ACCESSPERMS);
  mkdir("output/MapOut", ACCESSPERMS);
  mkdir("output/ReduceOut", ACCESSPERMS);
}

char *createMapDir(int mapperID){
  char *dirName = (char *) malloc(sizeof(char) * 100);
  memset(dirName, '\0', 100);
  sprintf(dirName, "output/MapOut/Map_%d", mapperID);
  mkdir(dirName, ACCESSPERMS);
  return dirName;
}

void removeOutputDir(){
  pid_t pid = fork();
  if(pid == 0){
    char *argv[] = {"rm", "-rf", "output", NULL};
    if (execvp(*argv, argv) < 0) {
      printf("ERROR: exec failed\n");
      exit(1);
    }
    exit(0);
  } else{
    wait(NULL);
  }
}

void bookeepingCode(){
  removeOutputDir();
  sleep(1);
  createOutputDir();
}
