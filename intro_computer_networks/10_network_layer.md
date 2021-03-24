# Network Layer
It is separated into the data plane and the control plane.  
Data plane is how the data gets moved and the control plane determines how we do the routing. Routing algorithms are used. The network is very dynamic. 
Out of band control is when the control is done through the control plane, we also have in-band control where control is done with the data plane.  

### The data plane
Network service models here are virtual circuit (TCP) or datagram (UDP). The router and switches are treated the same. In the data plane, we talk more about the forwarding table which is the data ...  
DHCP: ISP will reassign your IP to be used when you are offline. 
You could track a cell phone is you know the MAC address, which is permanent on the NIC Card, and then track the IP address it is coming from and then the location of the IP address.  
Look at destination IP address, compare with routing table and see what output port it should direct you to. 
Key functions of the networking layer include forwarding and routing. 

### The control Plane
Network-wide logic, determine what needs to be in the routing table.  
Traditional routing algorithms vs software-defined networking. Shortest path to intelligent path. We are no longer routing data just based on IP address instead it will base it on other parts of the data.  
In traditional routing algorithms, routers use forwarding tables to decide what port to direct you towards next using header values. The worwarding table is based on the routing algorithm and the routing algorithm is based on the routing table.  
In Logically centralized control (not actually centralized), there is a remote controller that interacts with local agents. One flaw is that any changes that happen take a long time to become known over the population of routers. It travels by propagation and is limited by transmission speeds and distance. The logically centered controller has a global view that can see everything, which gives consistency to the network.  

### Organization
In the control plane is a routing agent (daemon) that gets the routing information from the network and updates the routing table. The routing table then heads into the data plane to update the forwarding table. Input links to the switch look up forwarding ports based on the forwarding table. The switching fabric in the switch will direct input links to the correct output interface (port).

### Router Architecture
Input ports are buffered and sometimes output ports are also buffered. Output ports queue when transmission speeds or quantities don't match and it has to hold data back. Data comes in with several standard components; these are the lookup, forwarding and queueing. 
Styles of routers include memory switch fabric, bus switch fabric, and crossbar switch fabric. Memory is used for the really old ones, bussing is used when the bus is big enough to handle all connections at once for time division multiplexing. The bus should handle 20mbps if it handles 10 links of 2 mbps. Crossbar fabric is a lattice form that has a connection from each input to each output.  
Most architectures are bus based. In a bus, the data propagates to every connection but only the one who wants it will copy it down.  
High frequency equals shorter distance. The smaller the bus, the higher tranmission speeds it can give.  
Crossbar is non-blocking as long as inputs are going to different outputs but requires N squared number of small 2x2 switches because it requires a unique path for each pair of input output.  
Buffering comes in when the switch fabric cannot handle all of the traffic so some of it needs to wait before being directed. 

### Classful IP Addressing
IP Addresses have a network part and a host part  
Class A can have 2^26 - 1 hosts under the IP address. As we go from class A to B, C, D there is less room for hosts. A new company will usually apply for a class B network which can hold 2^16 IP addresses. Class C can have 2^8 and class D does not have any. A company will most likely not be able to get a class A because those are owned by the government. If you don't want to have a full class, you can go for a CIDR which stands for classless interdomain routing. Classes A, B, C, and D have a fixed number of hosts

### Special IP Addresses
Network address is all 0000 for the host.  
Loopback address is 127.0.0.1 which comes back to you. 

### DHCP (Dynamic Host Configuration Protocol)
In most cases, you do not have a permanent IP address. Every time you turn on your computer and connect to the internet, you need to first get an IP address. To do this you need to go to the DHCP which will assign you a temporary IP address because there are not enough IP addresses. While you don't have an IP, the traffic is being transmitted through the physical layer. This kind of traffic needs to travel by MAC address. It is typically located on your home router.   
A DHCP server sits somewhere on your network and arriving clients will give a transaction ID number, the DHCP will pick up your "DHCP discover" and respond with a "DHCP offer" that proposes an IP address to you. When you broadcast out, you use something like 0.0.0.0.x and the DHCP will send the proposal back to you under 255.255.255.255.x
Aside from just giving an IP address, the DHCP also gives you the address to the DNS server, a network mask, and address of first hop for client.  
Not having enough IP Addresses is only a problem for IPv4, once IPv6 is implemented fully we will not need DHCP.  

### Datagram vs. Virtual Circuit
Datagram only determines next hop while virtual circuit determines the entire path. 

### Forwarding table
Directs to the port based on the prefix of the destination address. 

| IP | Link Interface |
| --- | --- |
| 11001000 00010111 00010*** ********* | 0 |
| 11001000 00010111 00011000 ********* | 1 |
| 11001000 00010111 00011*** ********* | 2 |

anything that matches the longest prefix will go to that interface link. 
