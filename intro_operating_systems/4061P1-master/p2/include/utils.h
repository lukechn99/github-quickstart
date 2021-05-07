#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <ctype.h>
#include <sys/mman.h>

#define chunkSize 1024
#define MSGSIZE 1100
#define MSQID 420
#define PATHSIZE 100
#define ENDMSG -128

struct msgBuffer {
    long msgType;
    char msgText[MSGSIZE];
};

// helpers
long getMsgTypeFromMID(int mapperID);
long getMIDFromMsgType(int msgType);
int isEND(struct msgBuffer msg);

  
// mapper side
int validChar(char c);
char *getWord(char *chunk, int *i);
char *getChunkData(int mapperID);
void sendChunkData(char *inputFile, int nMappers);


// reducer side
int hashFunction(char* key, int reducers);
int getInterData(char *key, int reducerID);
void shuffle(int nMappers, int nReducers);

// directory
void createOutputDir();
char *createMapDir(int mapperID);
void removeOutputDir();
void bookeepingCode();

#endif
