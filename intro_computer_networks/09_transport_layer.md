# Transport Layer (TCP and UDP)
Before going to the transport layer from the application layer, you must specify TCP or UDP. What happens below that and how the data is actually transferred around is abstracted as far as the application layer is concerned.  
UPD sends out packet by packet with each packet not following necessarily the same path.  
TCP first sets up a path before sending data out. Important functions include error handling, sequence, flow control (for a particular session) and congestion control.   

Hosts have 5 layers, but the nodes (switches and routers) and the network runs on 3 layers for routing. This means that applications (application layer) runs on hosts and not the network. 
The data link layer is used between any two switches or routers to make sure the data is safely transmitted.  
```
 HOST A             Node                        Node               Host B
[Application]                                                     [Application]
[Transport  ]                                                     [Transport  ]
[Network    ] ---> [Network    ] ---> ... ---> [Network    ] ---> [Network    ]
[Data Link  ]      [Data Link  ]      ...      [Data Link  ]      [Data Link  ]
[Physical   ]      [Physical   ]      ...      [Physical   ]      [Physical   ]
```

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
Connection setup works with a three way handshake. The client sends SYN, seq=x to the server, the server responds with SYN+ACK, seq=y, ack=x back to the client. At this point the connection is established. At this point, the client sends another message back to say that  
Client opens and closes connection. The FIN bit, which is usually set to 0, will be set to 1 by the client which signifies to the server that the connection should close. Once received, the server will half close, and once the client receives the ACK it will also half close. The server will send a final FIN and fully close. The half closing is so that both server and client are finished before closing. This is because the first FIN that's sent is not guaranteed to arrive, so it requires an acknowledgement. 

### TCP Stop and Wait Protocol
TCP is much more complicated than UDP because responses are required. The sender algorithm includes a send phase where we send the data with a sequence number, buffer data segment, and a timer. During the wait phase, the receiver will wait for acknowledgement x + n - 1 where n is the number of bytes. If the number received does not equal x + n, then something went wrong so we might resend a message. We expect x + n - 1 because x + n is one more byte than received.  
Stop and wait has round trip propagation delay to just and the timeout duration is calculated based on that. The round trip time is the end of the time at which the first packet is transmitted until the ACK comes back is called the **RTT** which is the response "round trip time". We make sure that the timeout is longer than the expected RTT. 

### SRDTP
Finite state machines have a number of states that a 

### Pipelined Protocols
Allows multiple data segments to be in transit at once, the receiver needs a buffer to receive

### Flow control and Congestion control
**Go-back-to-N** makes sure that if one packet is wrong, all subsequent packets have to be repeated. Every packet after the Nth packet is discarded and re-sent. The sender sets up a timer for re-sending. The sender continuously sends packets without waiting for ACK. It uses a sliding window of size N which is the maximum amount of packets that can be sent without acknowledgement. Once the window has been finished, the sender has to wait for receiver acknowledgement. The receiver also has a window size that limits how many packets the receiver can accept. 

**Selective Repeat** if the Nth one is missing, the subsequent ones will just be stored in a buffer and wait for the Nth one to resend. The receiver acknowledges packets before the lost packet, but will not acknowledge the ones that come after because they are out of order. Instead, those will be stored in a buffer to wait for the sender to re-send the missing packet. Only the missing one is re-sent.  


For example, we could have a window of size N = 5 covering packets 0, 1, 2, 3, 4. Once packet 0 has been acknowledged, then the window moves onto 1, 2, 3, 4, 5.  
The sender has a window and the receiver has a window. The sender window moves when it has received acknowledgement. Its window size depends on what the receiver says it can handle and some other factors. The sender will send data in bursts of the window size. If the sender sends more than the receiver can buffer, it is dropped by the receiver. If the receiver gets packets 2, 3 then it will save them in the buffer until 1 arrives. The receiver will not acknowledge anything because the sender assumes cumulative acknowledgement. In essence this means that ack of 3 implies ack 2, 1, and 0.  

```
Flow Control Example:
Notice that both sender and receiver have a window. 

Sender: how much can you handle?
Receiver: I can buffer 3
Sender: send [0, 1, 2], 3, 4, 5, 6, 7, 8, 9
Receiver: [0, 1, 2] ack 2
Sender: send 0, 1, 2, [3, 4, 5], 6, 7, 8, 9
-3 lost-
Receiver: [ , 4, 5] no ack
Sender: resend 0, 1, 2, [3, 4, 5], 6, 7, 8, 9
Receiver: [3, 4, 5] ack 5
Sender: send 0, 1, 2, 3, 4, 5, [6, 7, 8], 9
```

**Rate control**  
```Rate = CongWin/RTT * byes/sec```  

**Congestion Control** is an issue guided by morals because we can't really restrict greedy senders from sending too much and hogging the whole network.  
Approaches include end-to-end control and network-assisted congestion control. TCP does not use these; each source determines network capacity for itself, uses implicit feedback, and uses ACKs to pace transmission. Since this works largely on feedback, it's hard to gauge a starting value for congestion windows to use. The TCP congestion algorithm uses *slow start* and then *congestion avoidance*. This algorithm transmits as fast as possible until data gets lost. At that point the congestion window (congwin) will decrease in size, and then slowly build up again. Before you reach a predefined threshold, the window size increases by a factor of 2, and after reaching the threshold it increases by 1. Slow start begins with a congWin = 1 and doubles on every successful acknowledgement.    
TCP AIMD: additive increase, multiplicative decrease  
The maximum window size is decided on by looking at the congestion window and the receiving window size and becomes the lesser of the two because it will be the limiting factor.  
In TCP Reno, when a loss happens, the new threshold becomes the number of segments being sent at its height divided by 2 and then increases by 1 again. Reno with fast recovery drops bak down to the threshold instead of 1.  
One way to do congestion control is to assign credits based on what the path can handle.  

The three mechanisms can be summed as AIMD, slow start, and conservative after timeout evens.  

### Timeout
We have to periodically measure RTT because too long of a timeout will slow down your program and too short will make you miss things due to a premature timeout.  
```EstimatedRTT' = (1 - alpha) * EstimatedRTT + alpha * sampleRTT``` typically alpha is 0.125  
In other words, the updated RTT is 7/8 of the previous RTT and 1/8 of a sample RTT  
```DevRTT' = (1 - beta) * DevRTT  + beta * abs(SampleRTT - EstimatedRTT)``` where beta typically equals 0.25  
```TimeoutInterval = EstimatedRTT' + 4*DevRTT'```

---
Data loss: happens when data is dropped
Flow control: measures to make sure the sender won't overwhelm the receiver
