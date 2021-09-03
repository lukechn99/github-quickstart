# Project 3: Threaded Webserver
test machine: csel-kh1250-11

group: 44

date: November 25, 2020

name: Joseph Annareddy, William Chan

x500: annar004, chan1766

## Compiling
```make``` or ```make web_server```  
Unzip the testing.zip file to access test files.

## Running
```./web_server port path num_dispatcher num_workers dynamic_flag queue_length cache_size```
with arguments as given in the following table:


| Argument                                                    | Valid values                                                                                      |
|-------------------------------------------------------------|---------------------------------------------------------------------------------------------------|
| ```port```                                                  | Integers in [1025, 65535]                                                                         |
| ```num_dispatcher```, ```num_workers```, ```queue_length``` | Integers in [1, 100]                                                                              |
| ```cache_size```                                            | Integers in [0, 100]                                                                              |
| ```dynamic_flag```                                          | Any 32-bit integral value, where 0 disables dynamic thread pools and any other value enables them |
| ```path```                                                  | A valid path to a directory that serves as the webroot                                            |
For example, ```./web_server 8000 . 1 1 1 2 1``` and then use ```wget http://127.0.0.1:8000/testing/text/big.txt``` in another terinal window or ```http://127.0.0.1:8000/testing/text/big.txt``` in browser.

## How our program works
main() takes in arguments specifying the port number, number of dispatchers, workers, queue length, and cache size.  
Worker and dispatcher threads are created in main() using ```pthread_create``` and a sigaction is defined for graceful termination  
in place of normal termination when ^C is used.  
Dispatcher thread will continually accept connections of files to look for and pushes them onto a request queue for workers to serve  
Worker threads pop requests off of the queue and attempt to serve the requests and then log the result. 

## Extra Credit
We implement Extra Credit policies A and B
### Dynamic thread pools (Extra Credit A)
This was not attempted

### Caching (Extra Credit B)
The LFU caching mechanism should be a bounded queue of frequently used requests. When the worker serves a request, it will first check to see if the requested file is cached.  
If it is cached, the file will be moved up one space, being swapped with the one before it to make it easier to access in the future. If the file is not in the cache, it will be added to the end of the cache. If the cache is full when adding a file, the least frequently used file (at the end of the cache) will be popped off and its space will be used for the new file. 

## Contributions
### Joseph Annareddy

### William Chan
dispatch, worker, readFromDisk, getContentType, dequeue, enqueue, main, graceful termination (shutdown)
