#include "mapper.h"

// global variables
// declare our intermediate data structure
intermediateDS *inter;

// combined value list corresponding to a word <1,1,1,1....>
valueList *createNewValueListNode(char *value){
	valueList *newNode = (valueList *)malloc (sizeof(valueList));
	strcpy(newNode -> value, value);
	newNode -> next = NULL;
	return newNode;
}

// insert new count to value list
valueList *insertNewValueToList(valueList *root, char *count){
	valueList *tempNode = root;
	if(root == NULL)
		return createNewValueListNode(count);
	while(tempNode -> next != NULL)
		tempNode = tempNode -> next;
	tempNode -> next = createNewValueListNode(count);
	return root;
}

// free value list
void freeValueList(valueList *root) {
	if(root == NULL) return;

	valueList *tempNode = NULL;
	while (root != NULL){
		tempNode = root;
		root = root -> next;
		free(tempNode);
	}
}

// create <word, value list>
intermediateDS *createNewInterDSNode(char *word, char *count){
	intermediateDS *newNode = (intermediateDS *)malloc (sizeof(intermediateDS));
	strcpy(newNode -> key, word);
	newNode -> value = NULL;
	newNode -> value = insertNewValueToList(newNode -> value, count);
	newNode -> next = NULL;
	return newNode;
}

// insert or update a <word, value> to intermediate DS
intermediateDS *insertPairToInterDS(intermediateDS *root, char *word, char *count){
	intermediateDS *tempNode = root;
	if(root == NULL)
		return createNewInterDSNode(word, count);
	while(tempNode -> next != NULL) {
		if(strcmp(tempNode -> key, word) == 0){
			tempNode -> value = insertNewValueToList(tempNode -> value, count);
			return root;
		}
		tempNode = tempNode -> next;

	}
	if(strcmp(tempNode -> key, word) == 0){
		tempNode -> value = insertNewValueToList(tempNode -> value, count);
	} else {
		tempNode -> next = createNewInterDSNode(word, count);
	}
	return root;
}

// free the DS after usage. Call this once you are done with the writing of DS into file
void freeInterDS(intermediateDS *root) {
	if(root == NULL) return;

	intermediateDS *tempNode = NULL;
	while (root != NULL){
		tempNode = root;
		root = root -> next;
		freeValueList(tempNode -> value);
		free(tempNode);
	}
}

// emit the <key, value> into intermediate DS
void emit(char *key, char *value) {
	inter = insertPairToInterDS(inter, key, value);
}

// map function
void map(char *chunkData){
	// you can use getWord to retrieve words from the
	// chunkData one by one. Example usage in utils.h
	// Create variables as exampled in utils.h
	int i = 0;
	char *word;

	// Get all the words in a chunk
	while ((word = getWord(chunkData, &i)) != NULL) {
		// Add a '1' in our chained linked list for the word
		// This will create the structure or bucket for the
		// word if it doesn't exist
		emit(word, "1");
	}
}

// write intermediate data to separate word.txt files
// Each file will have only one line : word 1 1 1 1 1 ...
void writeIntermediateDS() {
	// Get a pointer to the root
	intermediateDS *node = inter;

	// Loop over the linked lists
	while (node != NULL) {
		// NULL check, just in case
		if (node->key == NULL) {
			// If it's NULL, move on
			node = node->next;
			goto next_label;
		}
		// Create buffer for storing file name. Length is:
		// strlen(mapOutDir) + 1 (/) + strlen(word) + 4 (.txt) + 1 (\0)
		size_t len = strlen(mapOutDir) + 1 + strlen(node->key) + 4 + 1;
		char *filename = calloc(1, len);
		snprintf(filename, len, "%s/%s.txt", mapOutDir, node->key);
		// Create file to write to
		FILE *fp = fopen(filename, "w");
		if (fp == NULL) {
			// Continue if we get an error
			printf("Unable to open %s for writing! errno=%d\n",
				filename, errno);
			goto next_label;
		}

		// Write word to file
		if (fprintf(fp, "%s", node->key) < 0) {
			// Continue if we get an error
			printf("Unable to write to %s! errno=%d\n", filename,
					errno);
			goto cont_label;
		}

		// Get pointer to head of value list
		valueList *vnode = node->value;
		// Loop over value list
		while (vnode != NULL) {
			// Write a '1' for each entry in the value list
			if (fprintf(fp, " 1") < 0) {
				// Continue if we get an error
				printf("Unable to write to %s! errno=%d\n",
						filename, errno);
				goto cont_label;
			}

			// Advance to the next one
			vnode = vnode->next;
		}

		// Write newline to file
		if (fprintf(fp, "\n") < 0) {
			// Exit if we get an error, modelling example soln
			printf("Unable to write to %s! errno=%d\n", filename,
					errno);
			goto cont_label;
		}

cont_label:
		// Close file
		fclose(fp);
next_label:
		// Advance to the next node
		node = node->next;
	}
}

int main(int argc, char *argv[]) {

	if (argc < 2) {
		printf("Less number of arguments.\n");
		printf("./mapper mapperID\n");
		exit(0);
	}
	// ###### DO NOT REMOVE ######
	mapperID = strtol(argv[1], NULL, 10);

	// ###### DO NOT REMOVE ######
	// create folder specifically for this mapper in output/MapOut
	// mapOutDir has the path to the folder where the outputs of 
	// this mapper should be stored
	mapOutDir = createMapDir(mapperID);

	// Initialize intermediate data structure to NULL
	// insertPairToInterDS in emit() will initialize it
	inter = NULL;

	// ###### DO NOT REMOVE ######
	while(1) {
		// create an array of chunkSize=1024B and intialize all 
		// elements with '\0'
		char chunkData[chunkSize + 1]; // +1 for '\0'
		memset(chunkData, '\0', chunkSize + 1);

		char *retChunk = getChunkData(mapperID);
		if(retChunk == NULL) {
			break;
		}

		strcpy(chunkData, retChunk);
		free(retChunk);

		map(chunkData);
	}

	// ###### DO NOT REMOVE ######
	writeIntermediateDS();

	// Free intermediate data structure - we're done with it
	freeInterDS(inter);

	return 0;
}
