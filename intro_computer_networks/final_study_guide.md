# Final Exam Study Guide

### Basics
The different layers correspond to different data encapsulations. The terminology is super confusing, so we have it laid out here:
```
      Layers          Data type                      Addressing type          Explanation
.----[Application]                                                            Application layer is what the whole network is working to support.
|
| socket
|
'--> [Transport]      --> Segment                    Port number (socket)     Transport layer is the logical communication support for app processes, 
                                                                              enhancing the capabilities of the network, facilitating messages. It 
                                                                              breaks application messages up into segments and reassembles messages
                                                                              for applications on the receiving end using either UDP or TCP. It is 
                                                                              logical in the sense that it thinks its sending directly to the other 
                                                                              host's transport layer.
     [Network]        --> Packet(Segment)            IP address               Network layer is the logical communication between hosts. Logically, it
                                                                              thinks it is sending directly to the other host's network IP. When used
                                                                              in UDP, packets are referred to as datagrams (?)
     [Data Link]      --> Frame(Packet(Segment))     MAC address              
     [Physical ]      --> bit                                                 All data eventually gets sent over a physical medium like pairs of 
                                                                              copper twisted together — called TP, fiber optics, etc. 
```  
Computer networks are made up of 5 layers (some sources say 7 layers). End hosts like computers, cell phones, and IoT devices typically use all 5 layers while devices like routers and switches only use the bottom 3 layers. The top 2 layers are the application layer, which is creating the data to send, and the transport layer which is a way to interface the application layer with the rest of the stack. Routers and switches don't need to have these 2 layers because they do not need run any applications (as far as I know) when routing data. The use flow might look like...  
```
 My computer                                                                                                                         Your computer
[application | Facebook sends "hi" to you where your FB is browser port is 443, IP is..., etc.   ]                                  [application]
[transport   | segment(port=443 | "hi")                                                          ]     Router         Router        [transport  ]
[network     | packet(IP=67.228.23.200 | segment(port=443 | "hi"))                               ] -> [network  ] -> [network  ] -> [network    ]
[data link   | frame(MAC=00:1A:C2:7B:00:47 | packet(IP=67.228.23.200 | segment(port=443 | "hi")))]    [data link]    [data link]    [data link  ]
[physical    | beep beep boop 10101100 11101010...                                               ]    [physical ]    [physical ]    [physical   ]

```

Each layer's encapsulation adds on a new header describing information needed to interpret what's in that encapsulation.  
The transport layer uses segments that can be tranported with UDP or TCP. The transport layer gets its data from the application layer through the use of sockets. The application layer communicates down with sockets and doesn't care what happens afterwards because those lower level operation are abstracted. The receiving host application also does not need to worry about the lower level abstractions and can just worry about which socket it is receiving from.  
```
TCP Segment Header - 20 bytes
Source Port
Destination Port
Flags
Checksum
Sequence Numbers (which helps in identifying different segments at the receiver end)
Options (Some other important settings, which convey different meanings)
```

When being sent down from the transport layer into the network layer, the segment is given a packet header  
```
Packet Header - 
Source IP Address
Destination IP Address
TTL (time to live)
Identification
```

When two computers are sending information back and forth, MAC addresses are used. To find the MAC address for for the frame header, the device uses its ARP (address resolution protocol) which translates IP to MAC.  
The data link layer is only used to communicate on the subnet or local area network (?)  
Every device has an ARP table/cache, but sometimes, it won't find the IP address is wants to translate. To see if the destination address is even in the same network, it will mask its own address and compare with the destination IP. For example, 127.0.0.1 wants to send to 127.0.0.2 and the network mask is anything inside of 127.0.0.x, then 127.0.0.x is the masked IP and we see that the destination does indeed match with it. If that is the case, then it will sends out an ARP request to the broadcast MAC address ff:ff:ff:ff:ff:ff or 00:00:00:00:00 should be the same thing. The request is basically a "MAC Wanted" poster; any device reading with that IP address will send back its MAC address and the original device can add it to its ARP table.  
If the destination IP does not match with the devices own masked IP, then it is out of network and the the ARP request will be skipped and a layer 3 packet will be encapsulated in an Ethernet frame which will be forwarded to the host’s default gateway.  
As a side note, you can use ```arp -n -e``` to view your computer's ARP table or add one with ```arp  -s  10.12.67.43  12:48:08:bb:a5:bb```.  
The data link layer adds adds error checking bits, rdt, flow control

```
Frame Header
Source Mac Address
Destination Mac Address
Data (Payload - its nothing but the network packet given by the network layer)
Length (total length of the data - Typically its 1500 bytes.)
Checksum/Error Detection and Correction Bits (CRC)
```
The data link may transfer over Ethernet, frame relay, 802.11, and many others! Link header and encapsulation is different for each protocol.  

### Chapter 3: Transport Layer
The transport layer is all about TCP and UDP.  

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
GBN has a maximum window size of one less than the possible sequence number while SR has a maximum window size of half the possible sequence number. 

***TCP 3-way Hand Shaking*** is needed before data transfer for a TCP connection, UDP does not use this at all since it is connectionless. TCP connections are intentional one-on-one connections between two hosts. They must send some preliminary segments to each other to establish the parameters of the ensuing data transfer. This is the time for hosts to set up their TCP state variables. Only the two end-hosts are aware of the TCP protocols. All intermediate switches send the datagrams without regard for what it is.  
Step 1: Machine 1 wants to initiate a connection with machine 2, So machine 1 sends a segment with SYN (Synchronize Sequence Number). This segment will inform the machine 2 that Machine 1 would like to start a communication with Machine 2 and informs machine 2 what sequence number it will start its segments with. The sequence number is selected randomly and used to keep data in order.  
Step 2: Machine 2 will respond to Machine 1 with "Acknowledgment" (ACK) and SYN bits set. Now machine 2's ACK segment will acknowledge machine 1's SYN segment and inform Machine 1 what sequence number it will start its data with.  
Step 3: Now finally machine 1 Acknowledges Machine 2's initial sequence Number and its ACK signal. And then Machine 1 will start the actual data transffer.  

***TCP Closing Sequence*** is used to confirm the closing of both the client and server's connection to the client  

***Round Trip Time Estimation and Timeout*** RTT is used to measure the expected amount of time needed from one host to another. The first time that two hosts communicate, they will not know the RTT, but over time, they will use estimates and standard deviations to figure out a reasonable RTT.  

We have to periodically measure RTT because too long of a timeout will slow down your program and too short will make you miss things due to a premature timeout.  
```EstimatedRTT' = (1 - alpha) * EstimatedRTT + alpha * sampleRTT``` typically alpha is 0.125  
In other words, the updated RTT is 7/8 of the previous RTT and 1/8 of a sample RTT  
```DevRTT' = (1 - beta) * DevRTT  + beta * abs(SampleRTT - EstimatedRTT)``` where beta typically equals 0.25  
```TimeoutInterval = EstimatedRTT' + 4*DevRTT'```

***TCP Congestion Control*** is a protocol used to prevent congestion in the transport layer. It, along with flow control, is exclusive to TCP; UDP does not have these capabilities. Both flow and congestion control slow down the sender's data outflow. Whereas flow control is used to make sure the receiver isn't overwhelmed by the sender, congestion control is to make sure the network isn't overwhelmed by a sender. 

---
extras!  
  
multiplexing and demultiplexing: messages from multiple applications can be combined into one segment (multiplexing) and then taken apart at the receiving end and given to respective applications (demultiplexing)  
  
user datagram protocol: it's like a free for all, not connection setup needed, no congestion control, everyone gets to fire off at will  
  
transmission control protocol (tcp): uses handshake and closing sequence because it is connection based, uses send and receive buffers, pipelined in-order bytestream  
  
stop and wait protocol: 

---


### Chapter 4: The Network Layer - Data Plane
When we talk about the network layer data plane, we're talking about packets/datagrams, IP (IPv4 and IPv6) and fragmentation.  

***Forwarding vs. Routing*** Routing happens in the control plane while forwarding happens in the data plane. 

***Packet Fragmentation*** happens when a datagram goes through a part of the network where the maximum transfer size (MTU) is smaller than the size of the datagram. Datagrams are fragmented to size and given an offset number which tells how to reassemble at the destination host.  


***IPv4 and IPv6*** changes IP addresses from 32 bits to 128 bits by removing several header fields. It also changes several other things...  
No checksum: IPv6 removes the checksum from the header to speed up packet forwarding.  
  
No fragmentation: In IPv6, end hosts must perform path MTU discovery to decide the length of the packet. No fragmentation reduces the overhead of fragmenting 
packets of the routers.  
    
Expanded addressing capabilities: 128 bit addresses means we will not run out. In addition to unicast and multicast addresses, IPv6 has introduced a new type of address, called an anycast address, that allows a datagram to be delivered to any one of a group of hosts.  
  
Flow labeling: IPv6 allows differentiation of importance among data. Audio and video might be categorized as flows as opposed to email or file transfer. Or data from a more important device will be categorized as a flow and prioritized over other data. 

***NAT*** 

---


MTU: network links have a maximum transfer size/unit and if the datagram passing through is bigger, then it will be split into smaller datagrams that fit the network links

---

### Chapter 5: The Network Layer - Control Plane
***Link State Routing Algorithm*** uses Dijkstra's algorithm. This class is super sensitive about how you fill out your routing tables.  


***Distance Vector Routing Algorithm*** Routes are advertised by

Distance - How far the destination network is based upon a metric such as hop count.
Vector - The direction (next-hop router or egress interface) required to get to the destination.
This routing information is exchanged between directly connected neighbours.[2] Therefore when a node receives a routing update, it has no knowledge of where the neighbour learned it from. In other words, the node has no visibility of the network past its own neighbour. This part of distance vector is also known as "routing by rumour".

Furthermore, routing updates are sent in full (rather than delta-based updates) and at regular intervals, resulting in extremely slow convergence times - one of the key downfalls to distance vector protocols. In addition due to the slow convergence times and "routing by rumour", distance vector protocols are prone to routing loops.

However, on the flipside, the resource consumption is low compared to link-state, due to not having to hold the full state of the entire topolog

***Path Vector Routing Algorithm*** is like distance vector but on the inter-AS level and is a part of the border gateway protocol. 

***BGP (Border Gateway Protocol)*** The BGP will filter route advertisements from neighbors based on its own policies, be in charge of the route selection to other ASes, and filter the sending of information/advertisements to others. Basically, it selectively hears and is very cunning about what it tells, always prioritizing its own policy.  
The border gateways are also where peering happens and different providers can exchange traffic. Of course they are trying to optimize their own costs even at cost to others. However, due to the trading nature of the relationship, no money is exchanged, just favors. 
 

### Chapter 6: The Link Layer and LANs
At this level, we are concerned with the actual links between nodes. These links can be wired, wireless, or LAN. The link layer lives on the NIC card that every device has. *Each protocol uses a different frame header, trailer, etc.*  
The data link layer's main functions include framing (putting the datagram in a frame and adding header and trailer, assessing whether it's okay or not to send over a link, error detection (through CRC).  
They can be sent through different link types; point to point is with one sender and one receiver (no need for MAC addressing), protocols that are point to point include PPP and HDLC.  
Broadcast LAN has multiple people broadcasting into the channel at once and can result in collisions. To solve this, we can partition the channel by time (TDMA), frequency (FDMA), or code (CDMA). We can also use polling or take turns to coordinate access. We can also use random access which allows collisions but rectifies them. 
![MAC Protocols](https://user-images.githubusercontent.com/47294899/117450180-81f65080-af06-11eb-8aa2-2086c956fac8.png)


***Framing: Byte Stuffing or Bit Stuffing*** 
Since PPP puts everything in one long bit-string, there needs to be differentiation between data and flags. If the bit string 01111110 is used as a piece of data, it is followed by another 01111110 so that the receiver knows it was intended to be data. Otherwise it is not followed and the receiver knows it was a flag. 


***Error Detection: Parity Checking and Cyclic Redundancy Code (CRC)*** 
Along with the datagram from the link layer, EDC bits are attached at the end in a frame. We take the Data bits and choose ```r + 1``` pattern G and choose r CRC bits R so that <D, R> is exactly divisible by G. If the remainder is not 0 then there is an error.  
```
example:
Given a word (D) 1101101
and a divisor (G) 10101

division is done with XOR, remember that 1 1 = 0, 1 0 = 1, 0 0 = 0

1) append 0's onto the end of the word equal to the number of bits in the divisor - 1: word = 11011010000, divisor = 10101
2) use XOR to divide: 
        1110111
      _________________
10101 | 11011010000
        10101
        011100
         10101
         010011
          10101
          001100
           00000
           011000
            10101
            011010
             10101
             011110
              10101
              01011
3) evaluate whether it is 0 or not: remainder is 1011 so there is an error
4) if there is an error, then add the remainder onto the appended word: 11011011011. If not then you are good to go!
5) If there was an error then try again with the added value. 
```
As an aside, reliable delivery can be used on less dependable mediums (like wireless). These are the same protocols as the network layer: GBN and SR. More reliable forms oflinks like twisted pair or fiber don't need this. 

***MAC Protocols: CSMA, CSMA/CD, Token Passing, Token Ring, and Ethernet*** 
MAC protocols can be grouped into either *random access* or *ontrolled access*  
Controlled access are token passing, token ring, and ethernet.  
Token rings release their token after reception of a frame while another protocol called FDDI releases the token after it has transmitted its own frame. 

  
Random access are ALOHA, slotted ALOHA, CSMA, CSMA/CD, and CSMA/CA. They need to know how to detect or avoid collisions and recover.  


---

MAC (media access control): physical device address
  
PPP link: before communication, two hosts need to establish the link, authenticate and configure the network layer, open  
  
Polling: a centralized master invites slaves to transmit in turn which is good for avoiding collisions but bad because of overhead  
  
Token passing: a token for transmitting is passed from node to node typically in a ring of nodes (physically a ring or logical a ring and physically a bus)  

Ethernet: The adapter waits until the channel is idle and then starts to transmit a frame. If the whole frame is transmitted without interruption, an "OK" is transmitted, otherwise the adapter aborts transmission and sends a jam signal. It will then choose a random exponential time of the power of 2 multiplied by 512 and then tries a resend. After 16 aborts, it lets the network layer know that the datagram was not delivered.  

---
