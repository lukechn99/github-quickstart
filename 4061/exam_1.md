# Study Plan
Read the book  
Look at notes  
Study lecture content  
Write small programs (pipes, redirection)
For a study group  

# Content
Everything through Tuesday, October 13

### Programs and Processes
Fork, exec, exit, wait  
- fork() creates a process, child only shares the code AFTER the fork, so the child will not encounter fork again
- exec() changes a process image
- wait() is used for process synchronization, what does it return?  
C programs (pointers, flags, ...)  
How C programs are transformed into processes  
Getters and setters, get-modify-set  
PIDs, Child PIDs, identities  
Crashes  
Zombies, orphans  

### I/O
Low-level
- file descriptor like STDIN_FILENO (0), STDOUT_FILENO (1), STDERR_FILENO (2)
- creat(), open(), close(), read(), write(), lseek()
High-level
- fopen(), fclose()
- getc(), putc(), gets(), puts()
- fseek() random access  
Redirection  
Semantics, what happens if you read from a file you just wrote to?  
Binary  
Random  
Buffering  
Errors  
Control (behavior of I/O devices, terminal control)  
Formatting, stdio library allows for formatted I/O

### File Systems
Files and directories  
- User/Group/Other
- A User would be yourself
- You can log into a system as a "Group" and have group permissions
- Other is anyone else
- opendir(), closedir()
Links  
- ```link()``` creates a hard link
- ```symlink()``` creates a symbolic link
- ```unlink()``` destroys a link
i-nodes (what is in the metadata, hard links and symbolic links)
Masks, permissions

### Inter-process Communication (IPC)
What are issues  
How do use pipes?  

# Exam Structure
Focus on system and library calls  
About 35% short answer  
- why does Unix treat all devices as part of the system?
- what is random I/O and why is it useful?
- why would a given code snippet break?
- how can a fork fail?
Pros and cons of certain things  
Expect about 10 short answer
  
About 65% code oriented
- what does this code fragment do?
- how to write a function to do ___?
- how would you modify this
- implement ```char *fgets(char *s, int n, FILE *stream)``` using low level I/O
```
// s is the buffer to store
// n is the max number of characters to read
// stream is a pointer to the file object to read from
// we can use open(), close(), read(), and write()
char *myfgets(char *s, int n, FILE *stream){
	char buff[n];
	read(stream, buff, n);
	return buff
}
```
- create a program that creates N children, the parent then inserts tasks into a pipe consisting of a single integer i. A child computes i! and prints it to stdout  
```
int main() {

}
void 
	int fds[2];

	// children will inherit the same fds
	pip(fds);
	pid_t pid = fork();
	// children will only execute code below this line

	// creates a one way pipe
	if (pid > 0) {
		close(fds[1]);
		write(fds[0], ...);
	else if (pid == 0) {
		close(fds[0]);
		write(fds[1], ...);
}
```
  
There WILL be a question on I/O and Fork/Exec
