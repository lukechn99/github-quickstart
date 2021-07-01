# Linux/Unix OS
Note whenever ```<keyword>``` is used, it is meant to be a placeholder and should be replaced with your specific keyword when being used. 

### Commonly Used Commands
Sudo is 
```>> sudo```  


```>> ls```  


```>> pwd```


```>> cd <directory>```  
changes directory. For a list of relative path options, use ```>> ls -a```. For use with an absolute path, make sure to use a ```/``` before the path name. 

```>> cp <file/directory> <file/directory>```  
cp copies a file or directory from one location to another. You can use relative or absolute paths when doing this. In addition to moving a file, you can also use ```cp``` to rename a file with ```>> cp <file> <valid new name>```. 

```>> tar <option> <files...>```  
```tar``` compresses files into a .tar folder/file. Common options are -cf and -xf which are used for create .tar and extract .tar respectively. 


```>> chmod```  
chmod is used for changing the permissions field of a file or directory. This field looks like xxx_xxx_xxx where the first group represents the owner, group, and all users respectively. Each permission (owner, group, all users) has three bits that represent read, write, execute. So xxx_xxx_xxx looks like rwx_rwx_rwx when all permissions are allowed.  
For example, ```chmod 700 file.txt``` means you are changing permissions to ```rwx_---_---``` where the owner can read, write and execute, but other users have no permissions. The 7 in ```chmod 700``` is 111 in bits and the 00 are 000_000.  
Another common use is ```chmod 777 file.txt``` which gives all permissions for all users.  

```>> rm <file>```  
Removes a file or directory. You can also remove a whole directory through ```>> rm -r <directory>```

```>> ln <target> <link name>```  
creates links to a target

```
>> view <file>
>> cat <file>
>> less <file>
>> more <file>
>> tail <file>
>> head <file>
```
Are all for viewing files

---
OTHER COMMANDS
---
### Get Information About Your Computer
```>> ps```  


```>> ifconfig```  


### Helpful Tools
```Tab```  


```Ctrl + r```  


```Ctrl + c```  


```Ctrl + a```  
Moves the cursor to the beginning of the line. It can be very helpful for adding ```sudo``` to a long command because you won't have to keep pressing the arrow key. 


```>> grep <pattern> <file>```  
grep is used to look for patterns in the specified file. A common option to use is ```>> grep -i <pattern> <file>``` which will ignore case sensitivity when searching. To look for a file *name* that fits the pattern in the current directory, use ```>> find . | grep <pattern>```. 

```piping```  
Piping, represented by ```|``` is used to transfer the output of one command into another command just as a pipe connects multiple things. For example, we know that the command ```>> ls -l``` returns a LONG list of all files and directories in your current directory, but what if we don't want to see such a long list? Then we can pipe the output of ```>> ls -l``` into ```more``` which will restrict how many lines we see at a time. The full command would be ```>> ls -l | more```. 

```>> join <file> <file>```
Joining two files will combine corresponding lines of the two files. The best way to do this is to redirect the output to another file so that it can be saved; ```>> join file1.txt file2.txt > new_file.txt```.  
```
EXAMPLE (with the above command)

file1.txt           file2.txt           new_file.txt
apples              2                   apples 2
bananas             5                   bananas 5
oranges        +    1              =    oranges 1
avocados            0                   avocados 0
watermelons         1                   watermelons 1
tomatos
```
notice how tomatos were not copied over because there was no corresponding line in file2.txt


```>> vi <file>```  
Opens the Vim editor for files. Will edit a file if it exists and create the file if it does not exist. 

```>> find```  

```>> touch <file>```  
Whenever you edit a file or open it, a timestamp will be recorded. If you want to update the timestamp to the current time without opening or modifying it, you can use ```touch``` which will do the updating for you. A reminder, you can always use ```>> ls -l``` to check that the time has been successfully updated. 

```>> echo <string>```  
It is used to return as output whatever you used as input. Executing ```>> echo hello``` will return ```hello```. One cool thing you can do with ```echo``` is to assign a variable and then ```echo``` is back to you. For example, set variable x to 9 with ```>> x=9``` and then print back the value of x with ```>> echo $x```. Finally, you can also use ```echo``` in the same was as ```ls```, albeit in much less pretty format, by executing ```echo *```. 

export

ns

netstat



### Package managers
When you first install WSL, it is a clean slate and free of useful programs you may want to use. For example, Python does not exist yet and you cannot use it. However, you can use package managers to add then to your WSL. It's good to know that different Linux distributions use different package managers; Ubuntu uses apt, 
