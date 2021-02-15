# TCP
TCP uses in-order transmission all following the same path. It is reliable because it will keep account of packets sent and received.  
TCP enables special handling of flow control and can slow down traffic if need be. 
1. Connection oriented (need setup and teardown)
2. Reliable transport
3. Flow control (feedback to sender to slow down if congestion occurs)
4. Congestion control

# UDP
User Datagram Protocol is connectionless, no flow control, no congestion control, and unreliable data transfer. They take different paths

### Uses of each
TCP is good for HTTP, telnet, flash videos.  
UPD is used for streaming media (potentially doubles the number of packets you can send), teleconferencing, DNS, internet telephony. 
