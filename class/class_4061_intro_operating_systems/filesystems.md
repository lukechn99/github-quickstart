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
i-nodes are a representation of the file
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
# Files
Are an abstration provided by the OS  
it is a collection of related information  
```int stat(const char* filename, struct, stat *buf)``` gives you all of the file attributes and stores it in a stat structure *buf*  
```#include<sys/stat.h>```
The files must be in directories you have execute permissions for, otherwise it will do nothing  
some attributes of the stat structure are st_uid, st_size, st_mode, and st_ino (inode)  
The inode is a 16bit 
Hard links create the path to the original file with no new inode creation, it's another name for the same file  
A Symbolic link creates a new inode and file when used. A symbolic link is like a desktop shortcut  
you cannot make hard links to directories or files in other file systems  
a symbolic system can point to another file or directory name
Hard link ```ln foo bar``` links bar onto whatever foo is  
Symbolic link ```ln -s foo bar``` links bar onto foo
[more on symbolic and hard links](https://medium.com/@set808/symbolic-links-vs-hard-links-aka-what-the-heck-is-an-inode-ef16eb5532e2#:~:text=Essentially%20symbolic%20links%20don't,file%20and%20inode%20are%20created)

### Stat
```
struct stat entry_stat; 						// this is a statically declared struct
stat(this_entry, &entry_stat); 						// stats are put into it
printf("file size: %lld\n", (long long)(entry_stat.st_size));
printf("userID: %ld\n", (long)(entry_stat.st_uid));
printf("inode: %ld\n", (long)(entry_stat.st_ino));
```
### ls -l
using ls -l gives ```<file type><permissions> <hard-links> <allocation-size> <date>```
ls is just a program someone wrote that calls stat on the files  

### File access
Reader reads the most recent write  

# Directories
Don't actually exist, it is an abstraction. 
The root of everything is the Unix directory tree  
when navigating directories, we can use full paths and relative paths  
relative path names are convenient to use when in the directory, however, absolute names are better in programs  
C language equivalents to ```cd``` is ```int chdir(const char *path);``` and ```pwd``` is ```char *getcwd (char *name, size_t size);```  
getcwd is useful for getting the absolute working directory in a program  
