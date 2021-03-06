# The Internet
Mobile network, global ISP, home network, regional ISP, institutional network. The internet is a network of *different* networks  

### A service view of the internet
Infrastructure that provides services to applications include Web, email, games, e-commerce, VoIP, and social nets

### Building blocks of the internet
Nodes: nodes include hosts (servers, PCs, laptops, phones, smart devices, etc.) and switches (routers, switches)  
Links: coax cable, optical fiber, wireless. These include point to point where the link is between two parties, or it can be multiple access 
and accessible by many different parties. Multiple access risks collisions so there has to be protocols to avoid
Everything has an address.  
The internet is made up of a simple (dumb) network and smart endpoints. The network itself is dumb and does not remember anything about you.  
IP is the network layer, then is UDP and TCP, then is SMTP (email), HTTP (web), and RTP (phone) protocols.  
Each successive layer is built on the previous.
Layers include the Application, Transport, Network, Datalink, and Physical.  
The IP address is a virtual address, but we dliver things based on physical address

### Physical media
Twisted Pair (TP): two copper wires twisted together and can go from 10 Mbps (category 3 phone wire) to 100Mbps (category 5 ethernet). It has to be connected to your home and run 
there directly to serve your home. 
Fiber Glass: also has to be connected to your home, not as popular  
Radio Links: These include microwave (needing a relay station and is directional), LAN, wide-area (cellular), and satellite. Satellite has a long end-to-end delay

### Issues in Networks
Efficient switching to share resources among multiple users (sharing and multiplexing)
Routing and forwarding: determines how to guide a packet from one place to another, decide which switches to use and where to switch
Packet switching: we deliver in a packet stream (like a movie being streamed instead of all in one chunk)  

We do store and then forward for packet switching  
It used to be that you have to buy routers and switches from Cisco, today both switches and routers are white boxes with software put together by yourself. 
Cisco used to bundle the software and hardware for a markup, now, Cisco and IBM are in trouble because we can buy the hardware and bundle our own software. 
  
Multiplexing: multiple packets and tasks can be going on at the same time through a single link  
  
Naming and Addreses: IPv4 has basically already run out of addresses, we have moved onto IPv6. Networks have a physical address

### Packet Switching vs Circuit Switching
Older telephone networks used circuit switching. A path would be set up and this path was dedicated to the communication link. This is because link bandwidth used to be very small and could only handle. All bits of conversation were carried on one circuit.  
For computer networks, we use packet switching because computer communication is more "burst-like" and is well suited towards packets. This enables statistical multiplexing because you can collect packets from different people and send them in the same link to optimize use of the link at all times. Information is divided into packets, for example, a 5mb file might be divided into 1kb packets and merged after receiving.  
Packet switching takes L/R seconds to transmit a packet. And this cot repeats for each router that the packet needs to be re-routed. So the total will be nL/R where n is the numebr of router transfers, L is the size of the packet, and R is the speed of each step. R is not going to be the same between each step and can be variable.  
Typically a swtich will have incoming connections and outgoing connections. Some of these connections will go to clients and other will go to other switches.  
In packet switching, the entire packet has to arrive at a node before passing forward.  

### Calculations on Circuit Switching and Packet Switching
*Example*:  
*How long does it take to send a file of 640,000 bits from host A to host B over a circuit-switched network? All links are 1.536 Mbps, each link uses TDM with 24 slots/sec, and it takes 500 msec to establish end-to-end circuit.*  
The 500 msec is a constant cost, so that's automatically 0.5 seconds. 
The connection speed of the link is 1.536 megabits per second which is 1,610,612.736 bits per second  
But since it is divided into 24 slots/sec thn the connection speed is 67,108.864 bits per slot/sec  
At this speed, it will take 9.54 seconds to send the file of 640,000 bits. With the 0.5 seconds taken to establish a connection, the total is 10.04 seconds.  
  
One important idea is **Propagation Delay** which is the time it takes for a file of size L to be transmitted to a router at a speed of R. The total propagation delay will be the summation of L/R(1) + L/R(2) + ... L/R(n) where R(n) is the transmission speed.  
  
*Example*:
*Packet switching uses a probability of how much traffic you can expect to come through this link. For example, you could have a 1Mb/s link, that serves 35 people, but only 10 are expected to be active at a time, so it only has to handle that many. The probability of more than 10 people active is 0.0004.  
  
The first time you send data through a circuit, it takes time alpha between each router/switch. After the first pass to and back, which is the *circuit setup time*, subsequent transmissions are much faster.  
For packet switching, packets have propagation delay, however, because multiple packets are sending simultaneously they can overlap. Once they reach the next switch/router, they will wait for all packets to catch up (buffer) and then begin sending to the next router. Each send also has a packet delay of alpha which is the *distance / propagation speed* 

**End-to-end delay for circuit switching:  
delay = n * (dproc + d/s) + l/r**  

**End-to-end delay for packet switching:  
delay = n * (dproc + dqueue + (l/r) + (d/s))**  

where **n** is the number of routers  
**dproc** is the processing delay  
**dqueue** is the queuing delay  
**l** is the packet length  
**r** is the link bandwidth  
**d** is length of physical link  
**s** is the propagation speed  

### Frequency and Time Division Multiplexing
Divide a single channel into pieces.  
**FDM**: requency division multiplexing lets all four channels send simultaneously. FDM transcievers that are using that 100mbps link split into 4 channels only needs to transmit at 25mbps because that's their channel size.  
**TDM**: time division, we split up the time share of who is sending, but each sender can use the full link for their time frame  
For example, for a 100mbps link, a TDM transciever would need to operate at 100mbps in order to full take advantage of the link.   
**CDM**: Code division multiplexing  

![multiplexing](https://github.com/lukechn99/github-quickstart/blob/master/4211/res/multiplex.PNG)

### Client Server Model
This is a form of using the network edge. Client host will request service and receive service from an always on server. Email is a good example; instead of directly sending an email from peer to peer, it is sent to a server. This will prevent email loss if the reciver is not powered on.  
In the peer-to-peer model, there is minimal use of a dedicated server. Instead, clients serve as both client and server. 

### Other things
Video streaming is actually done through packet switching rather than circuit switching. In circuit switching, there would have to be a dedicated link for each viewer. Packet switching allows for Multicasting and better utilization of resources.  
Network edges are computers, applications, and hosts. Network cores include routers and networks of networks. Access networks are small networks in one area, like a campus network. Communication links can be fiber, copper, radio, and satellite.   
