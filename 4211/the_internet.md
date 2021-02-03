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

### Calculations on Circuit SWitching and Packet Switching
ask in office hours

### Frequency division multiplexing
Divide a single channel into pieces.  
**FDM**: requency division multiplexing lets all four channels send simultaneously  
**TDM**: time division, we split up the time share of who is sending, but each sender can use the full link for their time frame  
For example, for a 100mbps link, a TDM transciever would need to operate at 100mbps in order to full take advantage of the link. FDM transcievers that are using that 100mbps link split into 4 channels only needs to transmit at 25mbps because that's their channel size.  
**CDM**: Code division multiplexing

### Other things
Video streaming is actually done through packet switching rather than circuit switching. In circuit switching, there would have to be a dedicated link for each viewer. Packet switching allows for Multicasting and better utilization of resources.  
