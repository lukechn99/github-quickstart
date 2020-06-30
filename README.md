# github-quickstart  

what the command does and the typical situations in which it is used  
* __config__  
Git config is used to configure Git settings. It is used to setup email, username, and editor in Github the first time you use it.  
```git config --global core.editor emacs```  
It is also used to set aliases, which are shortcuts for other commands.  
```$ git config --global alias.ci commit```  
In this way the user can type "ci" as a shortcut every time they need to use commit.  
```$ git config --global alias.unstage 'reset HEAD --'```  
  
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
