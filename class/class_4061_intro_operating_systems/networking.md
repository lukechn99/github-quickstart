# Networks
Application layer : programmer area  
Transport layer : TCP (guarantees receiving in the order of sending, you have to establish a connection, like a phone call), UDP (is connectionless, like sending mail, but unreliable)  
Network layer : protocols include VoIP, video conference, P2P file share, IM, web, email, MMOs, 
Link layer
Physical layer

There are too many IP addresses to remember so we use a DNS to assign a name for easier use.  

### Creating a network app
applications that run on different end systems and communicate over a network

### Application architectures
Client-server: always on host and permanent IP servers. Clients can come and go, change IP, be intermittent, do not communicate with each other, etc.
Peer-to-peer: no always-on server, end systems directly communicate, anyone can change, very fluid, highly scalable, but not easy to manage

### Sockets
Machines can create sockets for communication, sockets are like end points  
Once created, they must be joined before communication  
To receive messages, the process must have an identifier because the machine has many IPs and processes  
Because of this, we use a port number, which is just for that machine. The port number along with an IP address  
forms the identifier

### TCP service
connection oriented
Adjusts sending based on congestion rate, does not necessarily send right away

### UDP service
message oriented  
packets are sent as soon as the host sends it  
Low latency, timing critical, and tolerates loss

# Network Programming
Sockets are a ket abstraction for end points of server programming. A socket can be created as ``` int socket(int domain, int type, int protocol)``` which gives us a file descriptor to use. The domain will usually be IPv4 or IPv6 which would be PF_INET, type would be either TCP or UDP using SOCK_STREAM or SOCK_DGRAM respectively. A common socket creation may look like ```fd = socket(PF_INET, SOCK_STREAM)```

### Server
The **socket** for the server needs to be known by everyone. It needs an open socket that is **binded** to a network address. Then, it needs to set up a queue for incoming connection requests with **listen**. Finally, we need to **accept** connections from the queue.  
When a server accepts a connection, it creates a new socket to communicate with, after communication with writes and reads, it will close that one-time socket if the connection-accept succeeds (client connects and server accepts).  
We bind the socket to a port so that clients know where to find it. Clients send connection requests, and once they are accepted, the server creates a private socket just for that client. 
*This is like when students queue for office hours, the queue is public, but once a student's connection is accepted, the TA creates a private room to communicate with the student in*  
**Bind** takes a socket andbinds it to a domain. ```int bind(int sockfd, struct sockaddr *my_addr, socklen_t addrlen);```
An example could be
```
int port = 6666;
struct sockaddr_in addr;
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = htonl(INADDR_ANY); // default IP address that the OS picks
addr.sin_port = htons(port);              // server will choose the port
bind(fd, (struct sockaddr*) &addr, sizeof(addr));
```
Bind errors can be remedied by specifying that the port can be reused because port collisions are prone to happen. If you want to choose a port that is guaranteed to be open, use ```netstat``` in the terminal to see which ports are available.  
**Listen** just sets up a queue for incoming connection requests. Use ```int listen (int fd, int backlog);```  
For example, we can do ```listen (fd, 5);``` which uses fd as the public socket and 5 as the max number of requests to queue.  
**Accept** returns the fd for a new socket. 

### Client
A client has to know the port number and IP of the server. It can use DNS to get the IP address based on the symbolic name. 
```
#include <netdb.h>

struct hostent* gethostbyname(const char *name);  // name is the URL
```
Client creates just one socket. No bind is needed because the OS will use the client's IP and finds a free port. After setting up the socket, the client can connect to the server and communicate with reads and writes.  
See an example of a [server](https://github.com/lukechn99/github-quickstart/blob/master/intro_operating_systems/tcp_server.c) and a [client](https://github.com/lukechn99/github-quickstart/blob/master/intro_operating_systems/tcp_client.c). The server and client should be run over two different machines (hint: CSE labs is good for this)
