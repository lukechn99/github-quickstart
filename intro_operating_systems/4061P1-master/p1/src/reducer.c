#include <stdio.h>
#include <string.h>

#include "reducer.h"

// global variables
// declare the final data structure
finalKeyValueDS *final;

// create a key value node
finalKeyValueDS *createFinalKeyValueNode(char *word, int count){
	finalKeyValueDS *newNode = (finalKeyValueDS *)malloc (sizeof(finalKeyValueDS));
	strcpy(newNode -> key, word);
	newNode -> value = count;
	newNode -> next = NULL;
	return newNode;
}

// insert or update an key value
finalKeyValueDS *insertNewKeyValue(finalKeyValueDS *root, char *word, int count){
	finalKeyValueDS *tempNode = root;
	if(root == NULL)
		return createFinalKeyValueNode(word, count);
	while(tempNode -> next != NULL){
		if(strcmp(tempNode -> key, word) == 0){
			tempNode -> value += count;
			return root;
		}
		tempNode = tempNode -> next;
	}
	if(strcmp(tempNode -> key, word) == 0){
		tempNode -> value += count;
	} else{
		tempNode -> next = createFinalKeyValueNode(word, count);
	}
	return root;
}

// free the DS after usage. Call this once you are done with the writing of DS into file
void freeFinalDS(finalKeyValueDS *root) {
	if(root == NULL) return;

	finalKeyValueDS *tempNode = NULL;
	while (root != NULL){
		tempNode = root;
		root = root->next;
		free(tempNode);
	}
}


// reduce function
// takes in a file path as "key"
// reduces the file into key, which is the word, and value, which is the aggregate of the count
void reduce(char *key) {
	// get info from file
	char buffer[100];			// buffer for fscanf to read the key
	int count = 0;				// count for value to be inserted with key

	FILE *fp = fopen(key, "r");		// opens the key file path for reading 
	fscanf(fp, "%s", buffer);		// reads up to 100 characters for a word into buffer
	char c;
	while ((c = getc(fp)) != EOF) {	// we continue getting characters until end of file
		if (c == 49) {			// we ignore spaces
			count++;		// increment count
		}
	}					// use the provided insertNewKeyValue function to insert into the finalDS
	final = insertNewKeyValue(final, buffer, count);
}

// write the contents of the final intermediate structure
// to output/ReduceOut/Reduce_reducerID.txt
void writeFinalDS(int reducerID){
	// create reduce output path
	// "output/ReduceOut/Reduce_reducerID.txt"
	char path[100];
	snprintf(path, 100, "output/ReduceOut/Reduce_%d.txt", reducerID);

	FILE *fp;
	fp = fopen(path,"w");							// opens the reducer specific txt file for writing
	finalKeyValueDS *ds = final;
	while (ds != NULL) {
		if (fprintf(fp, "%s %d\n", ds->key, ds->value) < 0) {	// uses fprintf to add the key and value from finalDS into the file
			printf("Error: %d\n", errno);
		}
		ds = ds->next;							// moves onto next node in finalDS
	}
	fclose(fp);								// closes file after finishing
}

int main(int argc, char *argv[]) {
	if(argc < 2){
		printf("Less number of arguments.\n");
		printf("./reducer reducerID");
		exit(0);
	}

	// ###### DO NOT REMOVE ######
	// initialize 
	int reducerID = strtol(argv[1], NULL, 10);

	// initialize the final data structure
	// insertNewKeyValue() will initialize this in reduce
	final = NULL;
	
	// ###### DO NOT REMOVE ######
	// master will continuously send the word.txt files
	// alloted to the reducer
	char key[MAXKEYSZ];
	while(getInterData(key, reducerID))
		reduce(key);

	// You may write this logic. You can somehow store the
	// <key, value> count and write to Reduce_reducerID.txt file
	// So you may delete this function and add your logic
	writeFinalDS(reducerID);
	freeFinalDS(final);

	return 0;
}
