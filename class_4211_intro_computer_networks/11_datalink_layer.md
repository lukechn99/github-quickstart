# Datalink Layer
This layer is responsible for delivering between adjacent nodes; through local area networks (LANs). MAC addresses are 6 bytes (48 bits)
Data is delivered as "frames" instead of packets.  
The Data link layer has the responsibility of error detection. If a link has too many errors then it will be terminated and the network layer will find a new link. 
NIC cards are used whether the data link is wired or wireless. 

### ARP 
translates IP to MAC address, all a node has to do to fond another's MAC address is look it up in the ARP table with the IP address. The router may know the next hop in terms of IP address, but it happens with the MAC address. Each time you hop you switch your IP address (src) to the current node's 

### Error Detection Code, Cyclic Redundancy Code (CRC)
We attach error detection and correction bits (EDC) onto the data in the datagram. After the data is transfered through a link, the data is checked against the EDC.  
One simple error detection methos is single bit parity or two dimentional parity to check the data. For single bit parity, it would take the bitstring of data and compare it with a parity bit. If the data added up is odd then the parity bit should also be 1 to make it even. And if the data is odd then the parity bit should be 0. For two dimensional bit parity, data is arranged in a matrix with parity bits on the end of the rows and bottom of columns that are responsible for checking that row or column.  
```
Calculation of where the CRC code is:
We want D*2^r XOR R = nG
Given D, we do long division with G (generating function) and find R the remainder so that 
R = remainder((D*2^r)/(G))
```  
[CRC calculator](http://www.ghsi.de/pages/subpages/Online%20CRC%20Calculation/index.php?Polynom=1001&Message=170)

### Multicast
Multiple MAC addresses in a group where one packet sent will reach everyone in the group. 

### Ethernet Frame Structure
```
/---------------,------------------,---------------,-----------,--------------,----------\
| Preamble (8B) | dest. addr. (6B) | src addr (6B) | type (2B) | data (1500B) | CRC (4B) |
\---------------|------------------|---------------|-----------|--------------|----------/
```

### Point to Point Data Link Control
Host connected to switch and only concerns two nodes. 

### PPP Data Frame
```

```

### MAC Protocols
Taking turns: 

### Data Link Layer Functions (Summary)
Error detection, and optional error correction  
Reliable delivery between nodes  

### Random access protocols
Aloha is unslotted and collisions can happen when time frame overlap.  
Slotted aloha is a protocol that either lets data collide 100% or not collide at all, following the slots. Slotted aloha can double the throughput, but can still have wasted slots. Pure aloha has an efficiency of 17% and slotted aloha is double that efficiency.  
CSMA (carrier sense multiple access) is when the node listens before transmitting. It is better than aloha because it will wait until the channel is idle before transmitting. Since there are always more than one person waiting for the channel to become empty before transmitting, there is a fixed transmission probability of 0.8 so that not everyone will transmit at once. CSMA can be persistent or nonpersistent. P-persistent will sense idle first and then apply the probability P to see if it should transmit or not. HOwever, collisions can still occur if the propagation delay is long and nodes are not warned in time while other nodes are transmitting.  
CSMA also has to do collision detection, keep listening while transmitting.  

Ethernet speeds up by powers of 2 until there is a drop. Ethernet has a maximum frame size of 1500 bytes for data. Ethernet carries a preamble of 8 bytes.  

Token ring (hub): different from a bus and can transmit further than a bug. Stations get tokens, and if they have nothing to send, they will pass the tocken onto the next station. Tokens are passed in the form of token bits. When a frame is passed, it has a bit that is set to 0 for token, and 1 if it is carrying data. The token carries 3 bits for priority. For example, 111 is the highest priority and 000 is the lowest. Higher priority data can hijack and take over lower priority data. No collision
Each ring has a monitor station.  

CDMA uses chip sequences and all chip sequences are orthogonal to each other. The chip sequence is an alternative to using one bit for each. You allow collision using your chip sequence. If the incoming transmission to you is -1 that means no one is transmitting to you, and 0 means they are transmitting a 0 to you and 1 if they are transmitting a 1 to you. 

---
Switch vs Hub: a hub only allows one thing passing through at any time. Switches will build their own routing table through learning. 
