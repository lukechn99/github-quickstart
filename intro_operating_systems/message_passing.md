# Message Passing
Unix uses a message queue  
Message queues, unlike pipes, can exist outside of your program because it is managed by the OS  
```
#include <sys/msg.h>
int msgget(key_t key, int permflags);
// we use any random key and hope there's no mailbox already using it
// returns the queue ID, which is used for sending and receiving later

int msgsnd (int qid, const void *message, size_t msgsize, int flags), flags can be , returns 0 on success and -1 for failure
int msgrcv (int qid, void *message, size_t msgsize, long msg_type, int flags), msg_type is the identifier
msgctl(int msgid, int cmd, struct msqid_ds *buf) performs controls on the queue; buf points to the msg queue, msgid is the queue identifier
cmd can bs IPC_STAT, IPC_SET, IPC_RMID, IPC_INFO, MSG_INFO, remove a message is msgctl(msgid, IPC_RMID, NULL)
msgget(ket_t key, int msgflg), flags can be 
```
**A message has a long mtype and a char mtext**

### Message data type  
Uses tags to ensure that the right person receives the message
```
struct mymsg_t {

```

```
// sender.c
mymsg_t m1 = {15, "hello"};
mymsg_t m2 = {20, "goodbye"};
int mid;
key_t key = 100;
mid = msgget (key, 0666 | IPC_CREAT);	// e,g,o can read and write into queue
msgsnd(mid, (void*)&m1, sizeof(m1.mtext), 0);
msgsnd(mid, (void*)&m2, sizeof(m2.mtext), 0);
```
They stay there until they are retrieved. This could mean that multiple processes can access a mailbox and only take the ones that are tagged for them

```
// receiver.c
mymsg_t msg;
int mid;
key_t key = 100;
mid = msgget (key, 0666 | IPC_CREAT);
msgrcv (mid, , sizeof(), 15, 0);
```
Message type 0 just reads the first message  
mtype can also be a specific code
### project tips
sendChunkData() (heavy code needed)  
Break them into 1024 byte chunks, tag them with a mapper id, and place them into the queue, after each parse, use memset to zero-out the buffer  
Be aware of end-words. Generate an END message for each mapper  

getChunkData()  
dynamically allocate the chunk you are returning  
  
shuffle()  
for each intermediate output file, skipping . and .., send the file name and path to reducers. Use the provided hash function.  
Generate an END message for each reducer  
  
getInterData() (fairly easy)  
returns a key (filename and path), grabs the data for the reducer through the queue
