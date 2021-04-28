# Network Layer Data Plane
The network layer takes segments from the transport layer and encapsulates them into datagrams and then unwraps it on the other side. The router in every host will use the IP datagram's header to tell where it's coming from and where it's going. 

### Overview of the Network Layer
Routing builds a map of the network and uses that to update the forwarding table. And fowarding is what actually happens inside of the router when you connect input port to output port. Routers traditionally have hard-coded routing algorithms but can also use software defined networking.  
  
Network service models can be a promise of delivery within a time-frame.  

### What's Inside a Router?
Input port processing and destination-based forwarding happens before the datagram heads into the switching fabric. We decapsulate from the physical layer and then do a forwarding table lookup to see which output port it is going to. Finally, it is queued if the fabric is full.   
  
Switching uses a switching fabric like memory, bus, or crossbar. Depending on the fabric, the switch has a certain switching rate. Memory and bus are limited by bandwidth.  
  
Output port processing is what happens after the datagram leaves the switch fabric. Datagrams are then buffered if they are arriving faster than the output port and transmit out. From there they can be queued or scheduled for transmission based on priority. Without a buffer, congestion could cause lose of datagram packets.  
  
Queueing happens whever the switching fabric is not fast enough to handle all of the input ports. When one input port flows to an output port, it temporarily blocks other datagrams from moving to that output port.  
Packet scheduling

### IP, IPv4, IPv6
IP is split into classes (A, B, C, D) where A has the most number of hosts that it can contain. Less of the front bits are used for th actual network, since there are so few, and more bits are committed to differentiating hosts.  
```
Class A : [oooo.xxxx.xxxx.xxxx]
Class C : [oooo.oooo.oooo.xxxx]
```

IP addresses are either statically assigned (hard coded into a host) or dynamically assigned using the DHCP server. A new client asks the DCHP server and DHCP offers an IP address.  
  

IPv4 datagram format, fragmentation, addressing  
```
/---------|---------|------------------|------------------------------------\
| version | header  | type of service  | length                             |
|         | length  |                  |                                    |
|---------|---------|------------------|---------|--------------------------|
| 16-bit identifier                    | flags   | fragmentation offset     |
|-------------------|------------------|---------|--------------------------|
| time to live      | upper layer      | internet checksum                  |
|                   | protocol         |                                    |
|-------------------|------------------|------------------------------------|
| 32 bit source IP address                                                  |
|---------------------------------------------------------------------------|
| 32 bit destination IP address                                             |
|---------------------------------------------------------------------------|
| options (timestamp, record route taken, routers to visit, etc.)           |
|---------------------------------------------------------------------------|
| data (either TCP or UDP)                                                  |
\---------------------------------------------------------------------------/
```
  
We are starting to move away from IPv4 and towards IPv6 because the 32-bit address space is running out. While IPv4 is made up of four 8-bit chunks, IPv6 uses a 128-bit address space and introduces alphabetical characters in addition to the numbers used in IPv4. Sections are separated by a “.” in IPv4 and a “:” in IPv6.  
The IPv4 datagram header format is also different from the IPv6 datagram header format. In IPv4, the datagram has a 4 bit IP protocol version number, a 4 bit header length, an 8 bit type of service, a 16 bit representation for the length of the whole datagram. For fragmentation and reassembly, it has a 16 bit identifier, 4 bit flags, and 12 bit fragmentation offset. Next it has a 8 bit time to live which decrements on hops, 8 bits for the upper layer protocol to deliver the payload to, and a 16 bit checksum. Finally, there are 16 bits for the source IP address and 16 bits for the destination IP address.  
The IPv6 datagram header has some of the same fields, except it has 128 bit address spaces, no checksum or fragmentation. It has a 4 bit version, 8 bit traffic class, 20 bit flow label, 16 bit payload length, 8 bits for the next header, and 8 bits for the hop limit. The IPv6 header is smaller and faster to process.  
  
IP fragmentation happens when a datagram goes through a part of the network where the maximum transfer size (MTU) is smaller than the size of the datagram. Datagrams are fragmented to size and given an offset number which tells how to reassemble at the destination host.  
  
Network address translation (NAT) is used to conserve IP addresses. Hosts within the same network may have different IP addresses, but once they head out of the network into the greater internet, instead of keeping their IP, they use the IP of the network NAT IP address and use a different port number to show which host they are inside of the local network.   
  
IPv6 is a new standard that hasn't been fully adopted. When in use, it will tunnel through the internet, avoiding the IPv4 networks and only going to IPv6 networks.  
```
/---------|---------|-------------------------------------------------------\
| version | header  | flow label                                            |
|         | length  |                                                       |
|---------|---------|------------------|------------------|-----------------|
| payload length                       | next header      | hop limit       |
|-------------------|------------------|------------------|-----------------|
| 128 bit source IP address                                                 |
|---------------------------------------------------------------------------|
| 128 bit destination IP address                                            |
|---------------------------------------------------------------------------|
| data (either TCP or UDP)                                                  |
\---------------------------------------------------------------------------/
```  

### Generalized forwarding and SDN
Match, action  
no need to know SDN

# Network Layer Control Plane
Routing protocols such as RIP, OSPF, and BGP create the routing table.  
These protocols determine the best route based on criteria such as cost, speed, least congestion, etc.  
Classical routing paradigms include hop-by-hop where each packet knows where it is going and the router just chooses the next hop for the packet. Another is "source routing" where the sender determines the path the packet should take. 

### Routing algorithms (distributed)
Some routing algorithms are centralized which means that a centralized route server does all the managing and route making. The alternative is distributed which includes link state and distance vector.  
  
Link state tells every other node its distance to neighbors.  
Each router keeps link state packets that store the router ID, neighbor's ID, and cost to get to that neighbor. It distributes this packet to all routers with controlled flooding. Computes the routing table with Dijkstra's.  

Distance vector tells neighbors its distance to every other vector. It tells its neighbors the distance between them. **Communication between neighbors only**. After sharing information with neighbors, the Bellman-Form algorithm is used to see which route has the smallest cost. 

### Intra-AS (autonomous system) routing: RIP, OSPF, IS-IS, EIGRP
Intra-AS routing focuses on performance and uses interior gateway protocols (IGP)
RIP (routing information protocol) uses the distance vector algorithm and measures distance by number of hops. RIP depends on hearing an advertisement from neighbors every 3 minutes, otherwise it treats the neighbor as dead.  
  
OSPF (open shortest path first) uses link state algorithm where a router will flood link state advertisements to the entire AS. Hierarchical OSPF splits the AS into areas that are connected by area border routers

### Inter-AS routing among ISPs: BGP
The internet is made up of ASes each of which have border gateway routers that interconnect. 
BGP allows a subnet to advertise its existence to the rest of the internet. BGP messages include OPEN, KEEPALIVE, UPDATE, and NOTIFICATION exchanged over TCP. A semi-permanent TCP connection is kept between BGPs. It advertises all of the hosts that you can reach through the AS so that other ASes know to use this AS. It can also withdraw advertisements. Once the advertisement is received as an eBGP, the BGP propagates the advertisement to everything inside of its own AS with iBGP. 
advertising BGP route information  
Determining best route  
IP-anycast  
Routing policy can be used to determine who routes through you and who doesn't. If you don't want to take traffic, you can simply not advertise or withdraw your advertisement. ASes want to use hot potato routing and hand off to the closest router minimizing intra-domain cost even if it increases inter-domain cost. 
Routing policy for inter-AS is typically that the admin wants control over how traffic is routed and who routes through its net focusing on policy over performance. The policy for intra-AS routing is single domain so no policy decisions are needed but typically focuses on performance. 

### SDN control plane

### Internet control message protocol (ICMP)
Used by hosts, routers, and gateways 

### Network management and SNMP
Network management framework  
SNMP
