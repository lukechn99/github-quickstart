# Linux/Unix OS
Note whenever ```<keyword>``` is used, it is meant to be a placeholder and should be replaced with your specific keyword when being used. 

### Commonly Used Commands
Sudo is 
```>> sudo``` 

ls

pwd

```>> cd```

```>> cp <file/directory> <file/directory>```  
cp copies a file or directory from one location to another. You can use relative or absolute paths when doing this. In addition to moving a file, you can also use ```cp``` to rename a file with ```>> cp <file> <valid new name>```. 

```>> tar```



```>> chmod```  
chmod is used for changing the permissions field of a file or directory. This field looks like xxx_xxx_xxx where the first group represents the owner, group, and all users respectively. Each permission (owner, group, all users) has three bits that represent read, write, execute. So xxx_xxx_xxx looks like rwx_rwx_rwx when all permissions are allowed.  
For example, ```chmod 700 file.txt``` means you are changing permissions to ```rwx_---_---``` where the owner can read, write and execute, but other users have no permissions. The 7 in ```chmod 700``` is 111 in bits and the 00 are 000_000.  
Another common use is ```chmod 777 file.txt``` which gives all permissions for all users.  

```>> rm```  
Removes a file or directory. You can also remove a whole directory through ```>> rm -r <directory>```

```>> ln <target> <link name>```  
creates links to a target

```
>> view
>> cat
>> less
>> more
>> tail
>> head
```
Are all for viewing files

---
OTHER COMMANDS
---
### Get Information About Your Computer
```>> ps```  


### Helpful Tools
Tab

control + r

grep

piping 

joining

vi

find

touch

echo

export

ns

netstat



### Package managers
When you first install WSL, it is a clean slate and free of useful programs you may want to use. For example, Python does not exist yet and you cannot use it. However, you can use package managers to add then to your WSL. It's good to know that different Linux distributions use different package managers; Ubuntu uses apt, 
