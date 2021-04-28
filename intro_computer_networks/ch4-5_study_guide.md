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

Network address translation (NAT)  
IPv6  

### Generalized forwarding and SDN
Match, action  
no need to know SDN

# Network Layer Control Plane
### Routing algorithms
Link state  
Distance vector  

### Intra-AS routing: OSPF
RIP

### Inter-AS routing among ISPs: BGP
Role of BGP, advertising BGP route information  
Determining best route  
IP-anycast  
Routing policy  

### SDN control plane

### Internet control message protocol (ICMP)

### Network management and SNMP
Network management framework  
SNMP
