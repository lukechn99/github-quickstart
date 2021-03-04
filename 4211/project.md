Don't zip
### IoT
How do we connect them all together? The most naive idea is to connect them all using HTTP protocol. However, this is very heavy nd not efficient for so many devices and so much information being transmitted. 
### Project Intro
Implement an efficient and lightweight publish subscribe protocol. There will be publishers (client), subscribers (client), and brokers (server).  

### Project requirements
Part 1  
The server needs to handle multiple clients and does not need to remember client information after disconnect. Messages will not be stored in the server, as soon as it gets a message, it will publish  
Clients just needs a basic user interface, and have the ability to be both publisher and/or subscriber. However, while you are subscribed, the server needs to remember what they are subscribed to. Need to handle weather, news, health, and security. Clients need sto be able to connect, disconnect, publish, and subscribe. Each of those will need a message exchange. We also need to account for normal and abnormal disconnect messages. 
Part 2
Heirarchical topic structure, we will have a topic level separator and multi-level wild cards which can indicate that you subscribe to whatever topics on that level. 
Topic level is talking about things like test/alpha/sensor, messages can be published to any level, but if you are subscribed to test/alpha/sensor, then you will only receive the messages on sensor.  
If you are subscribed to test/#, then you will receive messages for everything withing test
Need to implement unsubscribe while still being connected.  
Implement a list function which will return the last message from every topic. 
Is there ownership of a topic?
Does list automatically get called for every new subscriber? No, it is user invoked. 
### Grading and deadline
Get it done
### UNIX socket programming in C/C++
Sockets are IPC end points.  
You need IP address and port
Client: get IP address and port # of the server, create a TCP socket, send/receive, close  
Server: Create TCP socket and bind it to an IP address and port number, listen to the port and accept new connections, send/receive, close connection.  
The server will need to fork() new children to handle the clients  
```m = ntohl(m)``` is the byte conversion API for network to host bye conversion
Big endian is used in the network layer, and little endian is used by host
UDP uses datagram (```SOCK_DGRAM```) and TCP uses socket stream (```SOCK_STREAM```). The difference being that TCP writes many messages to a buffer and it gets read in one read, UDP will send each write separately. 
