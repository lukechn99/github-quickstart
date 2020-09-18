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

## Structure of a C program
A C program has many components including functions, structs (like records), arrays, and typedefs (user defined types)  
One function is called main() and this is where the first *thread* starts  
Generally, main is written like...
```
int main (int argc, char *argv[])
	// where argc is the number of command line args
	// argv is the array of command line args represented as strings
int main (int argc, char **argv[]) 
	// uses a pointer to pointers
```
There are ***no strings*** in C  
Instead, we can use definitions like  
```
char *s
typedef char *string;
typedef char [] string = "something";
typedef char [maxLength] string;
```
strings are terminated with a \0

*argc counts everything including the executable*

```
>> func -c 10 2.0
```
will have an argc of 4 with argv[0] being 'f', 'u', 'n', 'c', '\0'  
for arguments like the '10', we need *atoi* to convert it back into an int

### header files and c files
in c programs you can include code from header files and other c files  
header files will typically contain constants and types  

## Program Structure
A C program has multiple modules which are different files of code/functions grouped by relevance and separately compiled. 
Typically you will use one header file that has all the types, datastructures, and function prototypes. This will be shared among the other C files
  
foo.h
```
#define MaxTokens 10		// this is defined everywhere foo.h is included
int sortit (char a[100]);	// this is a function prototype
```
foo.c
```
#include <foo.h>			// like a macro
int sortit (char a[100]) {	// implementation
	...
}
```
main.c
```
#include <foo.h>
int main {
	sortit...
}
```

## Program scoping
```
static int foo;		// can only be accessed globally in this file
int foo;		// can be accessed globally by any linked file
extern int baz;		// using extern is a promise that baz is allocated elsewhere... what?
			// when baz IS defined, it must be defined without static so
			// that it can be accessed in the first function
```
Most functions we use are in the standard library, which we include.  
Other libraries like those for using threads are not automatically linked, so we need to  
manually link with commands like -lpthread when we use gcc
When compliling with the -o option you are creating an executable. Only 1 main allowed
Compiling with -c makes a .o file

## Error Handling
When an error is hit, extern int *errno* is set to -1  
there are many possible errno values
check for errors in system calls
```
int close (int fildes);

if (close (fildes) == -1)	// error happened
	perror ("close failed ...");
```

### pointers are memory addresses
```
int x;		// int
int *y;		// pointer to int

y = &x;		// y = address of x
*y = 10;	// dereference of y: what is the address of y? Store 10 in that address, x = 10
```

## Memory Allocation
Dynamic memory allocation: malloc allocates bytes and returns a ptr to the space allocated or NULL if nothing is left  
```
void *ptr1;
my_t *ptr2;
ptr1 = malloc(5);
ptr2 = (my_t *) malloc (sizeof (my_t));		// automatically allocated bytes to fit the size of my_t

void free(void *ptr_var);
```
Memory leaks happen when you don't free all the memory you allocated. Make sure to keep track of all the pointers you malloc and run free on them. 

## Void
void can be cast to any ptr type  
void can be used as a return type or an argument  
