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
- wait() is used for process synchronization, what does it return? wait() is essential to the OS scheduler so that it knows when to run things. The main difference between sleep() and wait() is that sleep() pauses the entire execution, wait() is for interprocess communication. If we don't use wait() or waitpid() then processes will execute in a strange fashion; some children may have not finished when the parent has already exited, thus making the child an *orphan*. Read more about this [section](###-programs-and-processes)
  
C programs (pointers, flags, ...)  
How C programs are transformed into processes  
Getters and setters, get-modify-set  
PIDs, Child PIDs, identities  
Crashes  
Zombies happen when a child finishes long before the parent calls wait(). At this point, it cannot be eliminated from the system yet and wastes resources and memory. The resources are reclaimed once the parent calls wait()  
Orphans happen when a child process has ```getppid()``` of 1. This means that their parent exited before the child finished, thus abandoning the child. Orphans are always adopted by the root process  

### I/O
Low-level
- file descriptor like STDIN_FILENO (0), STDOUT_FILENO (1), STDERR_FILENO (2)
- creat()
- open() uses flags O_WRONLY, O_RDONLY, O_RDWR, O_TRUNC, ex. ```open(out_file_name, O_WRONLY | O_CREAT)``` Truncate, if writing, will shorten the file to length 0
- close(), read(), write(), lseek()  
  
High-level
- fopen(), fclose()
- getc(), putc(), gets(), puts()
- fseek() random access  
  
```
// demo of how to use low-level IO 
int main (int argc, char* argv[]) {
	char* source = argv[1];
	char* dest = argv[2];
	int s_fd = open(source, O_RDONLY);
	int d_fd = open(dest, O_WRONLY);
	
	// error checking
	if (s_fd == -1 || d_fd == -1) {
		perror("couldn't open file, no such file or firectory");
		return(-1);
	}

	char buf[128];
	in nread, cur_pos = 0;
	while(1) {
		nread = read(s_fd, buf, 127);
		if (nread == 0) {
			break;
		}
		write(d_fd, buf + cur_pos, nread);
		cur_pos += nread;
	}
	close(s_fd);
	close(d_fd);
	return 0;
}
```
**Redirection** is used to 
Semantics, what happens if you read from a file you just wrote to?  
Binary  
Random  
**Buffering** output produced by fprintf() will not immediately be moved to file.txt and is instead placed in a main memory array until the array fills. The low-level read() does not draw from this buffer and finds the file empty. Calling fflush() forces the buffer into the file leading to read() actually seeing the data.  
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
	int fds[2];
	int N = atoi(argv[1]);

	// children will inherit the same fds
	pipe(fds);
	// children will only execute code below this line

	// creates a one way pipe
	int i;
	for (int i = 0; i < N; i++) {
		pid_t pid = fork();
		if (pid == 0) {
			// close write
			close(fds[1]);
			read(fds[0], &i, 1);
			printf("%l\n", factorial(i);
		}
		else if (pid > 0) {
			// close read
			close(fds[0]);
			write(fds[1], i, 1);
		}
	}
}

long factorial(int i) {
	if (i == 1) return 1;
	else return i * factorial(i - 1);
}
```
  
There WILL be a question on I/O and Fork/Exec
