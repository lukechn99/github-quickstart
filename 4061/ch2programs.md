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
