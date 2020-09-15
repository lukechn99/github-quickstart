# Programs in C and Unix
### use command line arguments
this is how you get inputs into your program  
we will write scripts that will call programs many times with different arguments  

### program scoping
```
int my_func (...) {
	int a;				// stack variable, allocated on the stack at each call
	static int b = 0;	// static variables are allocated before the program executes
	
	b++;
	...
}
```
static vs local vs global variables?  
static variables are deallocated at program end  
local variables are deallocated at function end  

### pointers are a memory address
```
int x;
int *y;

*y = 10; 	// this does not work because *y is referring to an address
			// when you assign an int, it is actually taking you to 
			// address 10
```
two ways you could fix this are
```
int x;
int *y;

y = &x;
y = (int *) malloc sizeof(int);

*y = 10;
```

### buffer overflow and stack smashing attack
common in "native code"  
```
void func (char *buffer, ...) {
	char local[5];
	...
	strcpy(local, buffer);
	...
	
}
```
possible solutions are to...  
1. use strcpy(a, b, N) which limits how many are copied  
2. use Java  
3. check string length before copying  

### Unix tools
```
gcc -g -o crash crash.c
```
GDB can help you figure out what's causing your segmentation faults  
Valgrind  
Lint  

top tells you what's running. You can identify memory leaks. Normal programs should maintain a steady memory use.
```
top -u <uid>
```
