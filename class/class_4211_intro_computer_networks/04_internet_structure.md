# Internet Structure
National and Tier 1 ISP, Regional ISP, and Local ISP are some of the commercial levels. Tier 1 ISPs interconnect privately.  
Point-of-presences (POP) use peering to look at what tier two service providers are connected. Peering lets traffic be more optimized so that data can go through from one service provider to another service provider. If you are a tier 1 service provider and I am one as well, and we both have customers who want to talk to each other then we want to transfer the data from my network to your network through a peering point as fast as possible. This is done by the border gateway router. Peering points are coming off of IXPs which are Internet Exchange Points

### What can go wrong with this structure?
Electrical interference can cause bit-level errors  
Media access delay or frame collision can cause frame-level errors  
Packet delay, loss, or disordering due to network congestion can cause packet-level errors  
At a very high level, if a cable is cut or a system crashes, there can be link and node errors  

### Packet Delay
Nodal processing (packet-ize the data) -> kernel space (headers) -> Network Interface Card (NI Card) -> queueing (waiting to transmit)  
Transmission delay (L/R = bits/bps) -> propagation delay (d/s = length of physical link / propagation speed in medium)  
Nodal delay = processing delay + queueing delay + transmission delay + propagation delay  
  
We measure the speed as **throughput** which is the rate in bits/time unit that is transferred between sender and receiver. This can be measured instantaneously at a point in time or on average over a period of time. Throughput is limited by the smaller link called the bottleneck link.  
Good throughput does not guarantee low latency. Congestion means throughput will lower because of the mess caused by collisions, there will also be higher latency. 

---
- ISP: Internet service providers like AT&T, Verizon, etc. 
- IXP: Internet exchange points allow tier 1 ISPs to exchange data
- Peering Point: a point where network traffic is transfered from one network to another
- Frame: packets are split into frames when they are too big
- Propagation speed: typically ~2 * 10^8 m/sec for optical signals, electrical is ~5 * 10^6 m/sec
---
