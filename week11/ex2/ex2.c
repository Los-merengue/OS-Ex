#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 16
#define MAX_FILE_SIZE 8 // for the blocks
#define BLOCK_SIZE 1024 // for  1 KiB of size
#define DISK_SIZE 128 // for the blocks
#define MAX_FILENAME 8

typedef struct {
	char name[MAX_FILENAME];
	int size; // in blocks
	int blocks[MAX_FILE_SIZE];
} File;

typedef struct {
	File files[MAX_FILES];
	char disk[DISK_SIZE]{BLOCK_SIZE];
	int freeBlocks[DISK_SIZE];
} FileSystem;

void createFile(FileSystem *fs, char *name, int size) {
	// Implement file creation logic 
}

void deleteFile(FileSystem *fs, char *name){
	//Implement file deletion logic
}

void writeFile(Filesystem *fs, char *name, char *data, int size){
	// Implement write to file logic
}

void readFile(FileSystem *fs, char *name){
	// Implement read from file logic
}

int main() {
	FileSystem fs;

	// Initialize the file system, set all blocks to free, etc.

	// User interaction loop for file operations

	return 0;
}
