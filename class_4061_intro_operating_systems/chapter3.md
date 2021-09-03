### Fork and Exec
A control program that can run ANY program
ex. browser that is one process, but is a control program that can run many other programs

Example of a shell
```
int main() {
	pid_t pid = 0;
	char cmd [100];							// buffering
	while(1) {
		fpintf(stdout, "enter cmd");
		scanf ("%s", cmd);
		
		// we fork because we want the child to run the exec, and still have the parent around
		// without a fork, the parent would die after an exec
		pid = fork;
		
		// only executes if it is a child
		if (pid == 0) {
			execl(cmd, cmd, (char*) 0);
			perror("failed");
			
```
the parent and child have the same values to start, but after forking, they have no effect on each other.  

### Buffers
when you write or read, it's usually to a buffer
we use buffers to use less system calls. We can gather data and then do many things in one system call

### Random I/O
we usually assume I/O to be sequential, but we might need random I/O for file append, skipping to a place in a song, database query for hotels  
sequential I/O can be slow when going down an array
```
#include <stdio>
fseek(File, (i-1)*MAX_LINE, SEEK_SET);	// this jumps right to the spot
fgets(F, ...);							// reads the info
```
the limitation of random I/O is that you have to *know* where to seek to  

### Binary I/O
writing a file in binary as opposed to ascii means that the file would be unreadable by humans, readable by machine/programs, and much smaller than ascii
