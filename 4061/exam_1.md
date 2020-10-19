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
C programs (pointers, flags, ...)  
How C programs are transformed into processes  
Getters and setters, get-modify-set  
PIDs, Child PIDs, identities  
Crashes  
Zombies, orphans  

### I/O
Low-level, high-level, redirection  
Semantics, what happens if you read from a file you just wrote to?  
Binary  
Random  
Buffering  
Errors  
Control (behavior of I/O devices, terminal control)  
Formatting, stdio library allows for formatted I/O

### File Systems
Files and directories  
Links  
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
	
}
```
- create a program that creates N children, the parent then inserts tasks into a pipe consistng of a single integer i. A child computes i! and prints it to stdout
  
There WILL be a question on I/O and Fork/Exec
