# Computer Networks and the Internet
### What is the internet
### The network edge
### The network core
### Delay, loss, and throughput in packet-switched networks
---
EXAMPLE  
Compute the time required for circuit switching and packet switching with the following conditions:  
•The destination is 3 hops away from the source (2 intermediate routers between the source and the destination, with 3 links).  
•The distance between any two adjacent nodes is 5 Km.  
•The signal propagation speed is 5*10^5m per second.  
•The message size is 10Megabits (1 Mega = 10^6).  
•The maximum packet size is 100k bits (1k = 10^3,You can ignore the size of the header).  
•The transmission speed of each link is 100Megabits per second.  
•The circuit setup time is 10^-1second for the case of circuit switching.  
•The processing time for routing decision at each node is negligible.  
  
*circuit switching DOES NOT calculate packets*
Circuit switching:Required time = setup time + transmission time + propagationtime  
```𝑇𝑜𝑡𝑎𝑙 = 10^−1 + (10 ∗ 10^6) / (100 ∗ 10^6) + (15∗1000) / (5 ∗ 10^5) = 0.1 + 0.1 + 0.03 = 0.23```

Packet Switching:  
Required time = transmission time from source for all the packets + propagation time  
```𝑁(p𝑎𝑐𝑘𝑒𝑡𝑠) = (10 ∗ 10^6) / (100 ∗ 10^3) = 100  
𝑇(𝑡𝑟𝑎𝑛𝑠𝑚𝑖𝑠𝑠𝑖𝑜𝑛) = 100 ∗ ((100 ∗ 10^3) / (100 ∗ 10^6)) + ((100 ∗ 10^3) / (100 ∗ 10^6)) + ((100 ∗ 10^3) / (100 ∗ 10^6)) = 0.102  
𝑇(𝑝𝑟𝑜𝑝𝑎𝑔𝑎𝑡𝑖𝑜𝑛) = (15 ∗ 1000) / (5 ∗ 10^5) = 0.03
𝑇𝑜𝑡𝑎𝑙 = 0.132  
```
---
### Protocol layers and their service models
### Networks under attack
### History

# The Application Layer
### Principles of network applications
Network applications are written for edge devices, not for the network core. Applications need an application layer protocol which acts as the part of the brain that lets you speak to others. Applications on different machines communicate through the different network layers;  
IP is used to locate the device (the DNS assists in this), the once the message reaches the right machine, it needs to find the right process.  
Each IP address (machine) supports many processes and applications running at once, so the next step is locating the correct port for the process. If the IP address were a house, then the port would be a person in the house.  
You can choose to use TCP or UDP for this communication.  
Applications communicates down to the transport layer through an API which defines the interface between application and transport layers. The socket is the Internet API

### The web and HTTP
HTTP is the web's application layer protocol and operates on a client server model. The client sends a http request and the server gives an http response.  
HTTP uses TCP to sustain a connection from server to client while exchanging messages. After closing the TCP connection, however, all memory of the client is lost, thus HTTP is known as stateless. Nowadays, cookies are given to clients to give some semblance of recognition and statefulness.  
In *persistent* http, the connection stays open for multiple objects to be sent, in *non-persistent* http, the connection is only for one object and then the server closes the connection. In non-persistent HTTP, the response time is ```2RTT + file transmission time```. One RTT (time for a packet to travel from client to server and back) is used to initiate the TCP connection and then another is used for the file request and transfer.  
Persistent HTTP can do as little as one RTT for all referenced objects.  
  
---
EXAMPLE (HTTP request message)  
```
GET /index.html HTTP/1.1\r\n
Host: www-net.cs.umass.edu\r\n
User-Agent: Firefox/3.6.10\r\n
Accept: text/html,application/xhtml+xml\r\n
Accept-Language: en-us,en;q=0.5\r\n
Accept-Encoding: gzip,deflate\r\n
Accept-Charset: ISO-8859-1,utf-8;q=0.7\r\n
Keep-Alive: 115\r\n
Connection: keep-alive\r\n
\r\n
```
The first line is a requesst (GET, POST, HEAD, etc.)  
The next lines are the header lines which all end in a carriage return and line feed  
Then finally, the message ends with a carriage and line feed  
  
EXAMPLE (HTTP response message)
```
HTTP/1.1 200 OK\r\n
Date: Sun, 26 Sep 2010 20:09:20 GMT\r\n
Server: Apache/2.0.52 (CentOS)\r\n
Last-Modified: Tue, 30 Oct 2007 17:00:02 GMT\r\n
ETag: "17dc6-a5c-bf716880"\r\n
Accept-Ranges: bytes\r\n
Content-Length: 2652\r\n
Keep-Alive: timeout=10, max=100\r\n
Connection: Keep-Alive\r\n
Content-Type: text/html; charset=ISO-8859-1\r\n
\r\n
data data data data data ...
```
---
HTTP/2 improves on HTTP/1 and HTTP/1.1 by compressing headers, pipelining HTTP requests, using server push, backward compatibility, and overall speediness of service. 

### Electronic mail in the internet
TCP port 25  
Whereas HTTP waits for a pull to give data, email works as a push, pushing emails to servers without them asking.  
Email uses SMTP when a server is receiving a message, but uses POP3 or IMAP when a client is receiving the message.  
In POP3, there is a phase for the user to authorize using their password (think logging into Gmail), and then there is a transaction phase that is interactive, the user can list emails, retrieve them, delete, or quit, much like an email application. POP3 allows for this between the client and mail server. 

### DNS
DNS is not centralized because we don't want a single point of failure, instead, DNS is split up between local name servers, that each ISP owns, and authoritative name servers. Your requests will first go to the local name server, if it cannot be found there, then it elevates up to the authoritative name server, where the authoritative name server will get the mapping to the destination and give it back to the local name server. There are a dozen root name servers worldwide.  
DNS queries can be iterative or recursive. Recursive burdens the previous DNS server even after it hands off to the next because it will eventually be responsible for returning the request to the requestor.  

### P2P applications
Client server means always on host and permanent IP address. Clients can be off or on, have dynamic IP addresses, and don't have to communicate with other clients.  
In P2P, there is no always on server and connections are intermittent. P2P needs a central directory server still to find peers.  
In P2P, there will often be distributed hash tables. See 

### Video streaming and content distribution networks
### Socket programming
TCP and UDP examples
