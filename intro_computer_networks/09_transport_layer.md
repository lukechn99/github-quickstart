# Transport Layer (TCP and UDP)
Before going to the transport layer, you just specify TCP or UDP and then everything below that is abstracted. 
UPD sends out packet by packet with eah packet not following necessarily the same path.  
TCP first sets up a path before sending data out. Important functions include error handling, sequence, flow control (for a particular session) and congestion control. Flow control means the sender won't overwhelm the receiver   

Hosts have 5 layers, but the nodes and the network runs on 3 layers for routing. This means that applications (application layer) runs on hosts and not the network. 
The data link layer is used between any two switches or routers to make sure the data is safely transmitted.  

Need to set up a path. 
Multiplexing can be where data from multiple applications are bundled into one package to be sent. 

The application layer chooses whether to use UDP or TCP which is then carried out in the transport layer. Application layer will use port numbers because each application has a different port number
The terms Frame, datagram, segment and message coordinate respectively with the Link, network, transport and application layers

### UDP
One UDP segment is formatted as a source port #, destination port #, a 16 bit length, and 16 bit checksum. IP address is put in at the network layer. Checksum is all about error checking. You create a checksum to send with the packet, and then upon the receiver receiving, the receiver will compute the checksum and verify that the data was not changed in transit. Checksums are generated with binary addition with overflows wrapped around back. Then take the 1's complement which is where 0s become 1 and 1s become 0 then. The checksum adds up every single 16 bit piece of data from the segment. This means adding the 16 bit source port + 16 bit destination port + 16 bit length + the entire message in 16 bit pieces. 

| source port # | dest port # |
| --- | --- |
| length | checksum |
| message |

### TCP
One to one sender to receiver. Full duplex bi-directional, connection-oriented handshaking.  
TCP segment is wayyy more complicated.  
acknowledgement number is the sequence number in reverse  + some other data... whattt?  
also uses a checksum, control info, 
Host A, sending a message of 1 byte to host B with sequence number 40 means that host B will send acknowledgement 40+1=41 back to show that it received the full message of length 1 byte. Acknowledgement comes in the form of the SEQ number + how many bytes were received.  
In the case of an errors, packets are resent.  
However, if Host B actually receives Host A's message, but the acknowledgement is lost, then there would be a duplicate packet sent. Another case that could cause duplication is if the connection takes too long and Host A times out, then Host A will resend before Host B even responds.  

### TCP Stop and Wait Protocol


