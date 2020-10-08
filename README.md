# github-quickstart  

what the command does and the typical situations in which it is used  
* __config__  
Git config is used to configure Git settings. It is used to setup email, username, and editor in Github the first time you use it.  
```$ git config --global core.editor emacs```  
It is also used to set aliases, which are shortcuts for other commands.  
```$ git config --global alias.ci commit```  
In this way the user can type "ci" as a shortcut every time they need to use commit.  
```$ git config --global alias.unstage 'reset HEAD --'```  
Git config can be used to store your Github username and password so that it does not need to be entered every time you push and pull. After using the command, you will need to enter your username and password one last time.  
```git config --global credential.helper store```
  
* __clone__  
Git clone reproduces a Github repository on your local directory. Navigate into the directory that you want to to clone the repository into and then use  
```$ git clone <tags> <repository>```  
The clone command also does branch tracking.  
Using Git clone will implicitly add the ```origin``` remote for you. Other remotes can be manually added.  
  
* __remote__  
```$ git remote``` shows you the server you've cloned from.  
```$ git remote -v``` will also show the URL that the remote server is located at.  
You can also add remotes that allow you to access  
```$ git remote add <shortname> <url>```  
In this way, we can use the shortname instead of the whole URL if we want to perform a command onto a repository other than the origin.  
* __status__  
```$ git status``` allows you to check the status of a directory. This command will tell you if the local directory is up to date with the main branch.  
You can also use it when navigating between branches.  
* __commit__  
```$ git commit``` commits all of the files of the current index.  
It is typically used with a ``` -m "<message>"``` that is a short explanation of what was committed in this update.  
* __push__  
```$ git push``` can be used to add all of the local refs to the remote ref. 
It can be used to with tags to specify which branches should be committed. 
The most common is ```--all``` which pushes all of them. 
* __pull__  
```$ git pull``` updates the local directory with the remote repository. It is helpful to use pull before working on code to make sure that the code you're working on is the most up to date.  
* __add__  
```$ git add``` is used to incrementally add changes to the index before committing. It must be used to add all new files to the local repository before commit is used.  
* __rm__  
removes a specified file  
* __stash__  
saves your local changes, and takes them off the stage for committing and pushing  
* __checkout__  
shows which branch you're on. If you use command ```$ git checkout <name>``` then it either switches you over to that branch if it exists or creates it as a new branch and switches you over.
* __diff__  
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
