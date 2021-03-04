#include "mapreduce.h"

int main(int argc, char *argv[]) {

  // Check that there are exactly four arguments
	if(argc < 4) {
		printf("Less number of arguments.\n");
		printf("./mapreduce #mappers #reducers inputFile\n");
		exit(0);
	}

	if (argc > 4) {
		printf("Too many arguments.\n");
		printf("Usage: ./mapreduce #mappers #reducers inputFile\n");
		exit(0);
	}

	// ###### DO NOT REMOVE ######
	int nMappers 	= strtol(argv[1], NULL, 10);
	int nReducers 	= strtol(argv[2], NULL, 10);
	char *inputFile = argv[3];

	

	// Check that nMappers >= nReducers
	if (nMappers < nReducers) {
	  fprintf(stderr, "Usage: ./mapreduce #mappers #reducers inputFile, where #mappers greater than or equal to #reducers\n");
	  exit(0);
	}
	// Check that nMappers and nReducers have valid values
	// Note that if argv[1] or argv[2] cannot be converted to integers by strtol, strtol returns 0, getting caught by this case
	if ((nMappers <= 0) || (nReducers <= 0)) {
	  fprintf(stderr, "Usage: ./mapreduce #mappers #reducers inputFile, where #reducers > 0 and #mappers > 0\n");
	  exit(0);
	}

	// Check that the file exists and we have the proper permissions by opening and closing it
	int if_fildes = open(inputFile, O_RDONLY);
	if (if_fildes == -1) { // Open failed
	  perror("Opening inputFile failed");
	  exit(1);
	} else {
	  close(if_fildes);
	}
	

	// ###### DO NOT REMOVE ######
	bookeepingCode();

	// ###### DO NOT REMOVE ######
	pid_t pid = fork();
	if(pid == 0){
		//send chunks of data to the mappers in RR fashion
		sendChunkData(inputFile, nMappers);
		exit(0);
	}
	sleep(1);
	// Check whether fork failed
	if (pid < 0) {
	  perror("sendChunkData fork failed");
	  exit(1);
	}

	// To do
	// spawn mappers processes and run 'mapper' executable using exec
	for (int mapperID = 1; mapperID <= nMappers; mapperID++) {
	  pid_t mapperpid = fork();
	  // A 32-bit integer has fewer than 20 digits in decimal representation,
	  // so the decimal representation of nMappers as a character array will always fit in id
	  char id[21];
	  sprintf(id, "%d", mapperID);
	  // Child process runs mapper with string id
	  if (mapperpid == 0) {
	    #ifdef DEBUG
	    fprintf(stderr, "MapperID: %s; PID: %ld\n", id, (long) getpid());
	    #endif
	    int execStatus = execl("./mapper", "./mapper", id, NULL);
	    // If this point is reached, execl has failed
	    perror("Mapper exec failed");
	    exit(1);
	  }
	  // Exit if fork fails
	  else if (mapperpid < 0) {
	    perror("Mapper fork failed");
	    exit(1);
	  }
	}
	// To do
	// wait for all children to complete execution
	// Wait for all child processes running mapper (nMappers) and sendChunkData (1) to exit (nMappers + 1 in total)
	for (int i = 1; i <= nMappers + 1; i++) {
	  int childStatus;
	  pid_t finishedMapper = wait(&childStatus);
	  #ifdef DEBUG
	  fprintf(stderr, "PID: %ld finished with status code %d\n", (long) finishedMapper, childStatus);
	  #endif
	  if (finishedMapper < 0) {
	    perror("Mapper wait failed");
	  }
	}
    

	// ###### DO NOT REMOVE ######
    // shuffle sends the word.txt files generated by mapper 
    // to reducer based on a hash function
	pid = fork();
	if(pid == 0){
		shuffle(nMappers, nReducers);
		exit(0);
	}
	sleep(1);
	if (pid < 0) {
	  perror("shuffle fork failed");
	  exit(1);
	}

	// To do
	// spawn reducer processes and run 'reducer' executable using exec
	for (int reducerID = 1; reducerID <= nReducers; reducerID++) {
	  pid_t reducerpid = fork();
	  // A 32-bit integer has fewer than 20 digits in decimal representation,
	  // so the decimal representation of nReducers as a character array will always fit in id
	  char id[21];
	  sprintf(id, "%d", reducerID);
	  // Child process runs reducer executable with string id
	  if (reducerpid == 0) {
	    #ifdef DEBUG
	    fprintf(stderr, "reducerID: %s; PID: %ld\n", id, (long) getpid());
	    #endif
	    int execStatus = execl("./reducer", "./reducer", id, NULL);
	    // If this point is reached, execl has failed
	    perror("Reducer exec failed");
	    exit(1);
	  }
	  // Exit if fork fails
	  else if (reducerpid < 0) {
	    perror("Reducer fork failed");
	    exit(1);
	  }
	}

	// To do
	// wait for all children to complete execution

	// Wait for a total of (nReducers + 1) children (all processes running and shuffle) to exit
	for (int i = 1; i <= nReducers + 1; i++) {
	  int childStatus;
	  pid_t finishedReducer = wait(&childStatus);
	  #ifdef DEBUG
	  fprintf(stderr, "PID: %ld finished with status code %d\n", (long) finishedReducer, childStatus);
	  #endif
	  if (finishedReducer < 0) {
	    perror("Reducer wait failed");
	  } 
	    
	}
	return 0;
}
