# File Systems

### Metadata
keeps track of size
a program that monitors a file
```
#include <sys/stat.h>
void monitor (char *fname) {
	struct stat sb;
	off_t psize = -99;
	while (1) {
		stat (fname, &sb);	// check if it worked
		if  (sb.st_size != psize) {
			printf("file size is now %d bytes\n", sb.st_size);
			psize = sb.st_size;
		}
		sleep(60);
	}
}
```
The operating system needs to know who can do what with permissions on a computer.  
Permissions are comprised of "read", "write", "execute"  
User permissions are easy to tell based on who's logged into the computer  
However, how do we know what permissions a process/program has?  
ex. if Luke executes a program made by Jon, the process is run with the permissions of Luke, not Jon  
stat calls file metadata, it returns a structure with the metadata  

### Masks
Opposite of flags  
FLAG_1 | FLAG_2 | FLAG_3
mask is used to turn things off, negation, logical &
```
creat ("name", PERM & (~mask));
// note that perm is defined with #define or some other declaration, an octal constant
// PERM => octal constant 0<u><g><o>, e.g. 0777 is user, group, and other can r, w, x (3 binary digits)
```
one mask is 022  
mask 300 configures so that everyone can r/w/x, user can only read
0 and 0 determine "other" and "group"
3 means 011 which says the user can only read, 0/1/1 corresponds to r/w/x
3/0/0/ corresponds to user/group/other  

### Hard links
### Unix file attributes, inodes, file types, semantics, permissions
i-nods are a representation of the file
### Memory-mapped files (if time)
```
void *mmap (void *start, size_t length, int prot, int flags, int fd, off_t offset)
```
Maps the file to memory and returns a pointer to the location in memory where the file is now stored.  
Since memory is random access, we can now access any part of the file without being sequential.  
This means we can use memory manipulation instead of file i/o functions to access contents of the file. 
```
fildes = open(...)
address = mmap (0, len, PROT_READ, MAP_PRIVATE, fildes, off)
c = (char*) *address;	// this is the equivalent of read(fildes, &c, 1);
```
