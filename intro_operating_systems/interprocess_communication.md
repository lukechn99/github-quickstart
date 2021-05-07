# Pipes
Pipes can read and write, they have finite space, write will be blocked if there is not enough space  
the OS stores pipe contents, pipes store less than files  

### Process communication through pipes
Communication means that two processes will both read and write to each other through a pipe, coordinating this could be difficult  
The solution would be to use two pipes for two distinct communication streams
```
#define MSGSIZE 16;

void main ()  {
	char inbuf [MSGSIZE];
	...
	
pid = fork();
if (pid == 0) { // child reads from pipe
	
```
Set the pipe in the fd (file descriptor) so that it can input from and output to pipes  
A Server with multiple clients can listen to the 
```
while (1) {
	for (i = 0; i < MaxChildren; i++) {
		if ((read(ch[i][0], ...) == -1 && (errno == EAGAIN)) {
			// then there is nothing to read
		} else {
			// do something with the pipe contents
		}
	}
}
```
