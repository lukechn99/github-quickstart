# Transport Layer
### Transport-Layer Services

### Multiplexing and Demultiplexing
### Connectionless Transport: UDP
UDP Segment Structure  
UDP Checksum  
### Principles of Reliable Data Transfer
How it's built:  
The protocol will only pass up to the application layer the data that it can guarantee is correct. Two protocols that are used to verify packet validity are Go-Back-To-N and Selective Repeat.  
  
Go-Back-To-N:  
The sender can send packets without acknowledgement from the receiver within a window size of N. Everything before that window has been acknowledged and everything that comes after is yet unknown. It is a **sliding window protocol**. GBN will acknowledge and send up to the application layer everything that comes in the correct sequence once the window is completed. However, as soon as it gets a packet that is out of order (packet N) all packets that come after are deleted and 
  
Selective Repeat:  

### Connection-Oriented Transport: TCP
### Principles of Congestion Control
### TCP Congestion Control
