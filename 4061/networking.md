# Networks
Application layer : programmer area  
Transport layer : TCP (guarantees receiving in the order of sending, you have to establish a connection, like a phone call), UDP (is connectionless, like sending mail, but unreliable)  
Network layer : protocols include VoIP, video conference, P2P file share, IM, web, email, MMOs, 
Link layer
Physical layer

Thera re so many IP's so we use a DNS to assign a name for easier use.  

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
