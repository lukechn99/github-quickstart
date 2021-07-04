# github-quickstart  

what the command does and the typical situations in which it is used  
make sure to commit before doing anything...  (don't try resolving merge conflicts without committing........)

### config
The very first setup steps you should perform after the install are setting username and email.
```$ git config --global user.name "Luke Chen"```  
```$ git config --global user.email "lukechn99@gmail.com```  
Git config is used to configure Git settings. It is used to setup email, username, and editor in Github the first time you use it.  
```$ git config --global core.editor emacs```  
It is also used to set aliases, which are shortcuts for other commands.  
```$ git config --global alias.ci commit```  
In this way the user can type "ci" as a shortcut every time they need to use commit.  
```$ git config --global alias.unstage 'reset HEAD --'```  
Git config can be used to store your Github username and password so that it does not need to be entered every time you push and pull. After using the command, you will need to enter your username and password one last time.  
```git config --global credential.helper store```  
If you are paranoid about someone accessing your computer and finding your Github credentials by using ```git config --list``` (which will show your username and password among other things), then use the following and set a timeout:  
```
git config --global credential.helper cache
git config --global credential.helper 'cache --timeout=3600'
# times out after one hour, timeout is specified in seconds
```
  
### clone
Git clone reproduces a Github repository on your local directory. Navigate into the directory that you want to to clone the repository into and then use  
```$ git clone <tags> <repository>```  
The clone command also does branch tracking.  
Using Git clone will implicitly add the ```origin``` remote for you. Other remotes can be manually added.  

### init
Git init is the alternative to cloning; instead of cloning a repository that exists on Github, it initializes a new repository In your current directory. 
```$ git init```
  
### remote
```$ git remote``` shows you the server you've cloned from.  
```$ git remote -v``` will also show the URL that the remote server is located at.  
You can also add remotes that allow you to access  
```$ git remote add <shortname> <url>```  
In this way, we can use the shortname instead of the whole URL if we want to perform a command onto a repository other than the origin.  
  
### status
```$ git status``` allows you to check the status of a directory. This command will tell you if the local directory is up to date with the main branch.  
You can also use it when navigating between branches.  

### log
```$ git log``` shows the commit log.  

### commit
```$ git commit``` commits all of the files of the current index.  
It is typically used with a ``` -m "<message>"``` that is a short explanation of what was committed in this update.  

### push
```$ git push``` can be used to add all of the local refs to the remote ref. 
It can be used to with tags to specify which branches should be committed. 
The most common is ```--all``` which pushes all of them. 
### pull
```$ git pull``` updates the local directory with the remote repository. It is helpful to use pull before working on code to make sure that the code you're working on is the most up to date. Local changes must be committed or stashed before a pull can be done.   

### add
```$ git add``` is used to stage changes to the index before committing. It must be used to add all new files to the local repository before commit is used.  
It can be used as ```$ git add --all``` to stage all files, or you can replace ```--all``` with an actual file name to only stage that file.  

### reset
Reset unstages the changes but doens't change anything about the file on your local computer. It is the opposite of ```add```.  

### rm
removes a specified file  
Typically used as ```$ git rm text.txt```  

### stash
saves your local changes, and takes them off the stage for committing and pushing  

### checkout
shows which branch you're on. If you use command ```$ git checkout <name>``` then it either switches you over to that branch if it exists or creates it as a new branch and switches you over. **BRANCH CREATION** uses ```$ git checkout -b <branch name>```  
  
### diff
compares the differences between your local file(s) and the one(s) on Github.

# Typical Workflow  
On creation
```
$ git clone <repo> 		// or "git init" if you haven't made the repo yet
$ git checkout release	// typically you want to work with a relrease branch that holds the code you've tested and finished, and a development branch for code you are working on
$ git checkout development
$ nano .gitignore		// a .gitignore details which files should not be tracked by the version control, executables, object files, etc. do not need to be shared because each machine could compile them differently. Nano is an in-terminal text editor that can quickly create and edit .gitignore and other files
$ git status			// should show that your local branch is ahead of the development branch
$ git add .gitignore
$ git commit -m "added .gitignore"
$ git push
```
While working
```
$ git pull				// updates your local repo
$ ...					// work on code
$ git checkout release	// change to release once you've finalized code and merge from development branch
$ git merge development
$ git add --all
$ git commit -m "feature finished"
$ git push
```

# Common Errors & How to Fix Them
We will use the example file ```text.txt``` as a placeholder.  
### error: you need to resolve your current index first
When we try to ```git checkout```, 

### fatal: unable to access could not resolve host:
When this comes up, common solutions online ask you to reset proxies and set URL origins, but there are steps to take before making changes you don't know how to reverse:  
1. Make sure the directory that you are trying to perform the ```git``` action in is the right one  
2. Make sure the URL is correct, make sure the ```git``` command you are using is correct  
3. Check your credentials: has the repo you're trying to ```git clone``` include you as a collaborator? Are the credentials stored on your credential store correct? You can check these things with ```git config --list```  
4. Try those weird online solutions  

### You made changes in the wrong branch... uh-oh
```$ git stash``` then move to the correct branch and ```$ git stash pop``` then do adds and commits as normal.  

### Git branches are not showing after 'clone'
Check all branches including hidden ones with ```git branch -a```  
```
$ git branch -a
* master
  remotes/origin/HEAD
  remotes/origin/master
  remotes/origin/devel
  remotes/origin/release
```
Checkout the branch you are looking for using the "full" name  
```
$ git checkout origin/devel
```
Once switched to that branch, do another checkout and the "short" name will be remembered  
```
$ git checkout devel
```

### error: The following untracked working tree files would be overwritten by checkout:
```
git add *
git stash
```
