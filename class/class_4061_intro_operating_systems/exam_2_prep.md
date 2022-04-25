# Study Plan
This test has every after pipes

# Contents
### IPC
Shared memory, message-passing, issues, programming interfaces  
Pipes are...  
- Tools for write and read between processes
- They use the 
Message queues are...
- 
Programming Example:  


### Signals
How are they used, how to deal with them, issues like reentrancy and races, programming models  
Signals are... 
- Asynchronous IPC (does not have to be anticipated)  
- Need a pid to use (the receiver is always a process)  
- Use kill() to send a signal
- Handled in one of four ways: default action, ignore, block or unblock signals (The process receives the signal only after it is unblocked–sigprocmask()), handle with a specific action (Associate an action on delivery of signal–sigaction())
SIGABRT:Process abort  
SIGINT:Ctrl-C–SIGSTOP:Execution stopped  
SIGKILL/ SIGTERM:Terminated  
SIGCHLD:Child exited
Programming Example:  
```
// initialize new sigset - sigset_t, sigemptyset to handle a ctrl + c
// creates the sigset_t
// initializes it as an empty set
// sigaddset adds SIGINT (ctrl + c) to the sigset_t
sigset_t st;
if ((sigemptyset(&st) == -1) || (sigaddset(&st, SIGINT) == -1)) {
  perror("failed");
  return 1;
}
// block SIGINT - sigprocmask
if (sigprocmask(SIG_BLOCK, &st, NULL)) {
  perror("block error");
  return -1;
}
```

### Threads
Benefits:

* Concurrency:multiple pieces of code can be executed simultaneously  
* Modularity:decompose functionality
* Parallelism:threads running in parallel (multi-core)
* Scale:more threads available than processors
* Overhead:multiple threads cheaper than multiple processes
Drawbacks:

* Sharing and thread safety:requires synchronization
* Global variables: per thread global variables may be required

### Synchronization
Locks

### Networking
Basics of addressing, basic

### Terms
Processes vs threads: A process is a an instance of a computer program being executed. 

### Sample Questions
What is a race condition? -  
What are two main differences between Unix pipes and Unix message queues? -  
Write a multithreaded program to do ... -  
Use signals to do ... -  

# Exam Structure
