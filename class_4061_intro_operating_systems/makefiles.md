## Recitation Mini-lecture
### Makefiles
Runs many commands all at once. 
A makefile consists of a target


```
all: mymake run
mymake: myfile.c
	gcc -c myfile.c
	gcc -o test.out myfile.o
clean:
	rm *.o test.out
run:
	./test/out
```
can use with commands...
```
make
make mymake
make clean
make run
make all
```
the difference between .o and .out which is that .o is an object file, one or more object files can be linked with one or more libraries to create the executable .out file.   
there is a one-to-one relationship between .c and .o files  
but all needed .o files must be included in the .out for the .out to run correctly

### Exercise/demo
