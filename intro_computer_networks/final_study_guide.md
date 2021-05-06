# Final Exam Study Guide

### Chapter 3: Transport Layer
***UDP Checksum*** is used to detect errors in segments. The sender splits the entire segment into 16 bit chunks and then adds them all together and takes the 1's complement. This is the checksum which is then checked by the receiver against the received segment. In calculation, overflows will circle back to the right-most bit.  
```
For segment 1100110011001100 1011101110111011 1001100110011001, we split into 16 bit chunks

1100110011001100, 1011101110111011, and 1001100110011001 and then add the first two together bitwise

    1100110011001100
  + 1011101110111011
---------------------
   11000100010000111

The 1 wraps around again
    1000100010000111
  + 0000000000000001
---------------------
    1000100010001000

Then we add the third 16-bit sequence

    1000100010001000
  + 1001100110011001
---------------------
    0010001000100010 when we account for overflow
    
Then we find the one's complement

    0010001000100010
 => 1101110111011101
```

  
***GBN, SR, and Sliding Window Scheme*** Go-back-to-N and selective repeat are two methods of transporting segments in the Transport layer.  

***TCP 3-way Hand Shaking*** is done when a new connection is opened.  

***TCP Closing Sequence*** is used to confirm the closing of both the client and server's connection to the client  

***Round Trip Time Estimation and Timeout*** RTT is used to measure the expected amount of time needed from one host to another. The first time that two hosts communicate, they will not know the RTT, but over time, they will use estimates and standard deviations to figure out a reasonable RTT.  

***TCP Congestion Control*** is a protocol used to prevent congestion in the transport layer  


### Chapter 4: The Network Layer - Data Plane
Forwarding vs. Routing

Packet Fragmentation

IPv4 and IPv6

NAT


### Chapter 5: The Network Layer - Control Plane
Link State Routing Algorithm

Distance Vector Routing Algorithm

Path Vector Routing Algorithm

BGP (Boarder Gateway Protocol)

 

### Chapter 6: The Link Layer and LANs

Framing: Byte Stuffing or Bit Stuffing

Error Detection: Parity Checking and Cyclic Redundancy Code (CRC)

MAC Protocols: CSMA, CSMA/CD, Token Passing, Token Ring, and Ethernet
