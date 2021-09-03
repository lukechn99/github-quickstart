# TCP and UDP
### TCP
TCP uses in-order transmission all following the same path. It is reliable because it will keep account of packets sent and received.  
TCP enables special handling of flow control and can slow down traffic if need be. 
1. Connection oriented (need setup and teardown)
2. Reliable transport
3. Flow control (feedback to sender to slow down if congestion occurs)
4. Congestion control

### UDP
User Datagram Protocol is connectionless, no flow control, no congestion control, and unreliable data transfer. They take different paths

### Uses of each
TCP is good for HTTP, telnet, flash videos.  
UPD is used for streaming media (potentially doubles the number of packets you can send), teleconferencing, DNS, internet telephony. 

There are a number of services that are provided by a Transport layer Protocol. Some of the services that are applicable to both TCP and UDP protocols are as follows:

1. Reliability:
In TCP: TCP is a connection-oriented protocol.
• When a data file or message is sent from source to destination, there is a guarantee that a packet will be delivered until the connection does not fail.
• The data transfer between client and server in the form of reliable byte stream. Therefore, TCP is reliable.  
In UDP: UDP is a connectionless protocol.
• When the data file or message is sent from source to destination there is no chance for guaranteed delivery to destination.
• The data transfer is not possible in the form of byte stream in the case of UDP. Therefore, UDP is unreliable.

2. Ordering of data:
In TCP:  
• TCP protocol delivers the packets in an order. The source transmits the second packet only after the first packet is received at the destination. Therefore, TCP follows ordering of packets.  
In UDP:  
• UDP protocol does not deliver the packets in an order. The transmission of packets from the source to destination follows no order. Therefore, UDP follows no ordering.  

3. Constant Throughput:
In TCP:
• The throughput for TCP protocol is much more than throughput for UDP protocol because TCP is reliable.  
• There is guarantee for constant throughput in TCP protocol. Therefore, TCP also have certain throughput value.  
In UDP:
• The throughput for UDP protocol is less than throughput for TCP protocol because UDP is unreliable.  
• There is guarantee for constant throughput in UDP protocol. Therefore, UDP also have certain throughput value.  

4. Timing:
In TCP:
• The fixed amount of delays occurs in receiving an acknowledgement from the receiver to the client because it is connection orientated. That means no jitter occurs in TCP.  
• If packets is sent by client but not received any acknowledgement, then client wait for timeout expiration and retransmit the same packet to receiver. Therefore, the TCP protocol satisfies the timing services.  
In UDP:  
• As UDP is connectionless and does not send any acknowledgements upon receiving the packets.  
• Therefore, no time delay in receiving acknowledgements. But the client doesn’t know, whether the packet was dropped or delayed. Therefore, UDP protocol satisfies the timing property but it doesn’t give the guarantee that packet delayed or not.  

5. Security:
In TCP:
• TCP is a reliable and connection oriented protocol, since it is very difficult to perform attack on TCP packets.  
• Security is provided in the form of encryption. Therefore, the TCP provides more secure communication between client and receiver.  
In UDP:
• As UDP is connection-less, it is easy performing the attacks like spoofing, DOS etc. Security is provided in the form of encryption. Therefore, UPD doesn’t provide guarantees for secure communication.  
