# 4061P1
test machine: csel-kh1250-15

name: Joseph Annareddy, William Chan, Luke Chen

x500: annar004, chan1766, chen5216



## Purpose
Count words in plaintext files using the MapReduce algorithm implemented on a single machine.

## What exactly our program does
Use message queues for interprocess communication to implement functions
*sendChunkData*, *getChunkData*, *shuffle*, and *getInterData*.

- mapreduce.c uses ```sendChunkData()``` after splitting to send 1024 byte chunks to mapper.c   - mapper.c uses ```getChunkData()``` to receive data and does mapping  
- mapreduce.c uses ```shuffle()```  
- reducer.c receives shuffled data through using ```getInterData()```  
<!-- Functions to edit are in project_2/lib/utils.c -->

## Compiling
```make``` or ```make mapreduce```
## Assumptions
We assume that the two functions ```char *getChunkData(int mapperID);``` and ```void sendChunkData(char *inputFile, int nMappers);``` as well as the two functions ```int getInterData(char *key, int reducerID);``` and ```void shuffle(int nMappers, int nReducers);``` are called in the same directory, such that if ```key_t k = ftok(".", MSQID);``` where ```MSQID``` is some integer, then ```k``` has the same value in both functions.

We assume that there are no existing message queues with the message queue identifier given by ```key_t k = ftok(".", MSQID);``` or ```key_t k = ftok(".", 5340701);``` before running the program.

## Contributions
### Joseph Annareddy
project_2: ```getInterData```

### William Chan
project_2: ```sendChunkData```

### Luke Chen
project_2: ```getChunkData``` and ```shuffle```
