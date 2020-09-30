```
char buf[12];
int fd, n1;
fd = open("foo", O_RDONLY);
n1 = read(fd, buf1, 11);
```
if you want buf to be a string, then you need to...
```
// error check open and close
buf[11] = '\0'
```

memory vs performance
```
int BUFSIZE = 512;


while (num_read = read(fd, buffer, BUFSIZE) > 0) {
	total += num_read;
}
```
### file descriptor magic
every process has a file descriptor table that maps things like 0 to STDIN, 1 to STDOUT, and 2 to STDERR  
dup2 is IO redirection, it allows you to use things like "cat" and "man" for different purposes without modifying them  
redirects don't really matter within a single file, e.g. instead of redirecting STDOUT to a file, you could simply write to the file  
it is useful when we are given a program that uses STDIN and STDOUT that you cannot change  
if we want the file descriptor change to stay (STDOUT always going to output.txt) then we need to preserve them through forks and execs  
```
int fd, fd1, fd2, pid;
fd = open("my_file.txt", O_RDONLY, 0);
pid = fork();				// when we fork, the child also gets a copy of the file descriptor table
if (pid != 0) {				// parent
	read(fd, ...);			// show fd table
	fd1 = open("foo", ...);
}
else {					// child process is basically "cat" but with a different fd table. Cat does not have to change, and does not know
	// read(fd, ...);
	fd2 = open("bar", ...);
	dup2(fd2, 1);
	execl("cat...");		// the fd table is still preserved even if the child changes into a different program
}
// child could open one file and parent could open another, and there would be no cross effect
```
All linux command programs use stdin and stdout, so with redirection, we can customize the use of these command programs without changing what they are  
redirection can also be used for communication between processes  

### IO interrupts
system calls can be interrupted when more important events come up. It will hand the interrupted program back to the user, and it can be re-executed later  
if your program is interrupted, it will return 
```
retval = -1 && errno = EINTR
```
produced from code
```
while (ret = read(fd, buffer, MAX_SIZE), retval = -1 && errno = EINTR);	// this while loop is evaluated based on its last argument, it will execut the other expressions
```
### setnonblock
non-blocking IO, what is it?
```
int setnonblock(int fd) {
	int fdflags;
	if (fdflags = fcntl(fd, F_GETFL, 0) == -1)	// gets all flags for fd
		return -1;
	
```
