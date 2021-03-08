# Computer Networks and the Internet
### What is the internet
### The network edge
### The network core
### Delay, loss, and throughput in packet-switched networks
---
EXAMPLE  
Compute the time required for circuit switching and packet switching with the following conditions:  
•The destination is 3 hops away from the source (2 intermediate routers between the source and the destination, with 3 links).  
•The distance between any two adjacent nodes is 5 Km.  
•The signal propagation speed is 5*105m per second.  
•The message size is 10Megabits (1 Mega = 106).  
•The maximum packet size is 100k bits (1k = 103,You can ignore the size of the header).  
•The transmission speed of each link is 100Megabits per second.  
•The circuit setup time is 10-1second for the case of circuit switching.  
•The processing time for routing decision at each node is negligible.  

Circuit switching:Required time = setup time + transmission time + propagationtime
```𝑇𝑜𝑡𝑎𝑙 = 10^−1 + (10 ∗ 10^6) / (100 ∗ 10^6) + (15∗1000) / (5 ∗ 10^5) = 0.1 + 0.1 + 0.03 = 0.23```

Packet Switching:  
Required time = transmission time from source for all the packets + propagation time  
```𝑁(p𝑎𝑐𝑘𝑒𝑡𝑠) = (10 ∗ 10^6) / (100 ∗ 10^3) = 100  
𝑇(𝑡𝑟𝑎𝑛𝑠𝑚𝑖𝑠𝑠𝑖𝑜𝑛) = 100 ∗ ((100 ∗ 10^3) / (100 ∗ 10^6)) + ((100 ∗ 10^3) / (100 ∗ 10^6)) + ((100 ∗ 10^3) / (100 ∗ 10^6)) = 0.102  
𝑇(𝑝𝑟𝑜𝑝𝑎𝑔𝑎𝑡𝑖𝑜𝑛) = (15 ∗ 1000) / (5 ∗ 10^5) = 0.03
𝑇𝑜𝑡𝑎𝑙 = 0.132  
```
---
### Protocol layers and their service models
### Networks under attack
### History

# The Application Layer
### Principles of network applications
### The web and HTTP
### Electronic mail in the internet
### DNS
### P2P applications
### Video streaming and content distribution networks
### Socket programming
TCP and UDP examples
