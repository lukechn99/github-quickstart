# Threads
Abstraction for executing instruction stream  
They exist within a process and share its resources, but have their own stack and program counter  
A process automatically has one thread  
They are all independent, no one thread controls another. 

### Switching between threads in a process
The CPU will swtich between threads when running a process  
With concurrency, blocking causes thread switches  
Assume that threads can switch at any time when writing threaded programs

### Benefits of Threads
Concurrency: blocking points are good times to switch. One thread blocks and we switch to another  
Modularity: threads can be assigned to different threads. We can decompose the problem into parts.  
Parallelism: leverage multi-core processors to actually run threads in parallel (as opposed to concurrency where you switch)  
Scale: threads are more lightweight than processes  
Overhead: cheaper than processes  

### Example: an Editor
threads = activities  
In an editor program, we have different activities going on:  
keyboard input  
autosave  
display to monitor  
manage buffer  
When one activity blocks, like the user stops typing, the processor could move onto save the doc  
Each *activity* should have a different *thread*

### Example: A Web Server
assuming they use dispatcher() and worker() which are both different activities that need to be done. Dispatcher finds web pages to send and the worker returns a page, then they also need to communicate in between them.  
Threads share buffer, cache, globals, heaps, but not stack
With a single thread, we finish the request in 30 seconds  
```
[read] -> [serve] -> [write]  
  10         10         10    
```
With multiple threads, we can start a new read when the previous serve is still going on, and the average time per request goes down with mulitple requests  
```
[read] -> [serve] -> [write]  
          [read] ->  [serve] -> [write]  
                     [read] -> [serve] -> [write]  
```
### Drawbacks
No isolation of failures, threads can be switched without warning based on a system timer, this could interrupt things.  
Due to race conditions, we need to implement thread safety with locks. However, locks reduce concurrency because it is a blocking operation. 

# Multithreading
Lightweight method of parallelism and concurrency without need for IPD because of their shared resources  

### Thread creation
``` pthread_create(pthread_t* thread, pthread_attr_t* attr, void* func, void* arg) ```
Usually creates a thread with a function (3rd param) and arguments to execute on (4th param)  
Returns 0 on success and error number on failure

### Joinable and Detached Threads
Joinable threads don't release resources until ```pthread_join(pthread_t thread, void* retval)``` is called by another thread. Processes pause at pthread_join until the thread is finished.  
Detaches threads automatically release resources on exit

### Mutex locks
We set a lock before using a shared resource and we release the lock after using the shared resource.  
```
 THREAD A          THREAD B
[section 1]       [section 2]
     |                 | <-------- Lock pthread_mutex_lock(mutex)
[shared var]      [shared var]
     |                 | <-------- Unlock pthread_mutex_unlock(mutex)
[section 2]       [section 2]
```
Compile with ```gcc -pthread -o out main.c``` to use threads. 
