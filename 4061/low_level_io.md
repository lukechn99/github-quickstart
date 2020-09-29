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

### file descriptor magic
dup2 is IO redirection, it allows you to use things like "cat" and "man" for different purposes without modifying them.

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
