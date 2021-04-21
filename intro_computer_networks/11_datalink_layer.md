# Datalink Layer
This layer is responsible for delivering between adjacent nodes. 
Data is delivered as "frames" instead of packets.  
The Data link layer has the responsibility of error detection. If a link has too many errors then it will be terminated and the network layer will find a new link. 
NIC cards are used whether the data link is wired or wireless. 

### ARP 
translates IP to MAC address

### Error Detection Code, Cyclic Redundancy Code (CRC)
We attach error detection and correction bits (EDC) onto the data in the datagram. After the data is transfered through a link, the data is checked against the EDC.  
One simple error detection methos is single bit parity or two dimentional parity to check the data. For single bit parity, it would take the bitstring of data and compare it with a parity bit. If the data added up is odd then the parity bit should also be 1 to make it even. And if the data is odd then the parity bit should be 0. For two dimensional bit parity, data is arranged in a matrix with parity bits on the end of the rows and bottom of columns that are responsible for checking that row or column. 
