# Network Layer
The network layer delivers *datagram* from host to host. It is separated into the data plane and the control plane. Data plane is how the data gets moved and the control plane determines how we do the routing. Routing algorithms are used. The network is very dynamic. Typically, the data plane is associated more with forwarding, it is lower level, while the control plane is more about routing; it handles the higher level operations. 
Out of band control is when the control is done through the control plane, we also have in-band control where control is done with the data plane.  

### The data plane
Uses the forwarding table to forward the datagram moves from hop to hop. 
Network service models here are virtual circuit (TCP) or datagram (UDP). The router and switches are treated the same. In the data plane, we talk more about the forwarding table which is the data ...  
DHCP: ISP will reassign your IP to be used when you are offline. 
You could track a cell phone is you know the MAC address, which is permanent on the NIC Card, and then track the IP address it is coming from and then the location of the IP address.  
Look at destination IP address, compare with routing table and see what output port it should direct you to. 
Key functions of the networking layer include forwarding and routing. 

### The control Plane
Network-wide logic, determine what needs to be in the routing table. Looks at how to colllect data for the routing table.   
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

| IP Destination | Link Interface |
| --- | --- |
| 11001000 00010111 00010*** ********* | 0 |
| 11001000 00010111 00011000 ********* | 1 |
| 11001000 00010111 00011*** ********* | 2 |
For example, 11001000 00010111 00010110 10100001 goes to interface 0  
and 11001000 00010111 00011000 10101010 goes to interface 1  
  
Anything that matches the longest prefix will go to that interface link.  
This table will be continually updated.  
https://condor.depaul.edu/sjost/361/materials/SubnetMask.html

### IP Datagram Forwarding Model
The next hop is the least specific one. 
The datagram format has a 32 bit format. They have an IP protocol version, a header of length 32 bits, the type of service (delay, throughput, reliability bits), total length (max of 65535 bytes), identification, flags, fragment offset, time to live (to prevent the packet from just bouncing around the internet if it doesn't find its destination), protocol type.  
IP fragmentation is what happens when the data hits an ethernet switch going into a smaller network. They are reassembled at the destination.  
For example, you start with a datagram of size 4000 bytes and a fragflag = 0 because no fragmentation has happened yet. If it goes through the ethernet, which only allows sizes of 1500 bytes, but it must be in multiples of 8 bytes, so it will be split into 3 chunks of 1480 (185 * 8), 1480, and 1040. With offsets of 0, 185, and 370 and fragflags of 1, 1, and 0 respectively. 

### NAT (Network Address Translation) 
All hosts under a local network can just use the same IP address but can be identified with a port number instead. For example we have 1.0.0.1, 1.0.0.2, and 1.0.0.3 connected to 1.0.0.4 which is the router. The router can then use a NAT translation table to just use 138.76.29.7 and have a unique port number. For example, 1.0.0.1 can send traffic out as 138.76.29.7, 5001  
Of course, usually the port number tells you which process on the host to go to, but since the port number is to indicate device from server, the NAT router needs to change the dest addr datagram to the actual IP addr. When you come down to the transport layer, you only have a port number, when you come down from transport to network layer, you get th eIP Address. 
The mapping is maintained for the port number of the host so that there is a unique port for 

| What outsiders see | What host it actually connects to | What process/port it actually connects to |
| --- | --- | --- |
| 138.76.29.7 / 10 | 1.0.0.1 | 80 |
| 138.76.29.7 / 20 | 1.0.0.1 | 25 |
| ... | ... | ... |
| 138.76.29.7 / 90 | 1.0.0.2 | 80 |
| 138.76.29.7 / 110 | 1.0.0.2 | 995 |
| ... | ... | ... |
| 138.76.29.7 / 130 | 1.0.0.3 | 25 |  
We can see from the example above that all outgoing traffic comes from IP address 138.76.29.7 and all incoming traffic comes to 138.76.29.7 but each port of 138.76.29.7 is mapped to another host inside of that network and a specific port on that host.  

### IPv6
No checksum, because every time the hop limit gets decreased they have to recalculate. No fragmentation, instead you will . This means that IPv6 is faster.  
However, most nodes will handle both IPv4 and IPv6. IPv6 users will tunnel through the network, skipping by all of the IPv4 parts of the network. 

### Routing Algorithms
Intra-domain routing is simple: Like UMN to UMN. But outside of a domain is trickier. Interdomain routing has to avoid things like foreign countries for safety reasons.  
Instead of routers talking to neighboring routers to exchange info, they talk to a single remote controller so that there is a central point of communication.  
In considering a routing algorithm, we look at cost graphs as an abstraction of the network. In these graphs, paths are represented as bi-directional, but in reality the paths are directional with their own cost even if they are going between A to B and B to A.  
The cost of a path is the sum of the cost of the edges it passes through.  
Routes can be decided on heuristics like not corssing into .gov or simply looking for shortest path.  
When a node disappears or goes down, the network needs to self-heal without human intervention.  
Types of routing includes hop-by-hop where the packet is given its next hop by every router it passes through. The alternative is source routing where the sender includes, in the header of the packet, the exact path that the packet will take. In source routing the header size is larger. Currently, we do hop-by-hop, but we would like to move into source routing because it enables us to avoid nodes that we don't want to go into. Source routing means less work for routers but more work for the sender.  

Distributed routing algorithm can sense the delay of previous packets. It can operate through link state routing or distance vector routing. Link state routing happens when a router measure the cost of each of its links and then shares this information with all of its neighbors. Distance vector assumes that the neighbor will tell you the cost of getting to the destination. With destination X, A will know the distance from A to B and then B will tell A how much more there is to X from B.  

**Link state** vs **distance vector**. Link state tells every other node its distance to its neighbors and distance vector tells its neighbors its distance to every other node.  
Link state means everyone will have the information, essentially the whole topology is known by everyone. . Distance vectors only share information with neighbors. The weakness of distance vectors is that information may be outdated by the time it is received.  
One weakness of link state means that multiple nodes will interpret one path as the best path and everyone will try to take that path thus causing congestion. 
Link state will send out small link state packets to other nodes that describe its links to neighbors using controlled flooding. In controlled flooding, packets flood the entire network, as soon as you receive a packet you send to all your neighbors. However, it is controlled so that only new information will flood and old info will not be propagated.  
***INTERESTING*** would be interesting to see what percentage of packets received by a node are flooded and what percent is thrown away. How would this change over the course of the network's life? Size?  
Although Dijkstra's algorithm could be used on a routing table, nowadays the best path is not necessarily the shortest path when considering security and other limitations.  
```
Dijkstra's

initialize neighbor priority queue
start at src node:
    if src == dest:
        return cost
    for each neighbor to src that has not been visited:
        add neighbor to queue
    visit closest neighbor
    save the src + neighbor + cost
    src = visited neighbor
```

### Comparing LS to DV
Split horizon is where after passing traffic to an intermediate node, you don't tell the intermediate node the cost of you going to the neighbor. Split horizon with poisoned reverse is when you pass traffic and then tell the intermediate node that the cost of you going to the destination is infinity so that it will not be passed back.  
```
     [B]         
     /\
    /   \
   /      \
  /         \
[A]----9----[C]
```

Distance vector uses **RIP** or routing information protocol (Cisco's proprietary alg), uses bellman-ford algorithm, may have routing loops. RIP information is exchanged between neighbors every 30 seconds. If no advertisement is heard within 180 seconds, you are declared/assumed dead

Link state uses **OSPF** which is open shortest path first, uses dijkstra's and controlled flooding, may have oscillations.   

The actual internet is not flat with identical routers like we assume. It is hierarchical because there are hundreds of millions of destinations. Due to the wild nature of the internet, it was not designed with security in mind. The global internet is formed from *autonomous systems* interconnected with each other. ASes are used in attempt to compartmentalize and organize the internet. With ASes, you have intra-AS routing where you are moving within a system, and then inter-AS when you move out of the system. **Hierarchical routing** uses areas which connect to other aread through area border routers. The area border routers connect to backbone routers which connect the areas together. 

**Software-Defined Network** (SDN) is slowly being implemented to our switches and routers. Software defined means that the function of the router or switch is not attached to the hardware; it is not fixed. It can be changed and updated as needed. This also means that we can do programmable switches and routers. Routing information can still be per-router or logically centralized remote controller.  
Programmable networks mean that we have in-network computing. Switches will have an OS that you can use to specify the rules.  
P4 language for switches allows you to parse packets and use a match-action pipeline to interpret what action to take based on header value matches.  
The programmer decides what action is taken for each header key.  
SDNs are no longer just based on an IP address. Instead it can be 

### Border Gateway Protocol and Routers (BGP)
Routing inside of an AS is simple with LS or DV. However, inter-AS routing is more difficult and uses the BGP. BGP uses the path vector protocol which lists out the path which is a series of ASes thaat you will pass through in order to get to your destination. First tier service providers don't actually tell anyone how their BGP is implemented. BGP messages are exchanged with TCP
