# Networks vs Internet
Different networks use different protocols, so typically, networks cannot communicate with each other. 
Aside from protocols, different networks also use different transceivers that recognize 0s and 1s. 
Protocols typically use headers to store essential information. 

### Motivating Questions
What is internet?  
What is a protocol?  
How are networks built?  
How is complexity dealt with?  

### Internet
The internet is a network of physical networks. Instead of needing many switches, the internet just uses addresses. 

### Ethernet switches
Switches connect multiple devices, physically connecting n devices to n outputs. Different networks have different switches. 
Networks can be physically ocnnected or not physically connected (like satellite). Similar to a router (internet) which directs 
internet traffic.  
Older telephone systems used **circuit switching**. The path from one telephone to another is reserved just for that connection. 
Today most telephones go through the internet, they use **packet switching**. In packet switching, the switch buffers the data 
until the whole packet arrives. In packet switching, the connection is not reserved.  
Switches allow you to build big networks. 

### Protocols
Everything has to be somewhat standardized as opposed to proprietary in order to allow for communication. 

### Layers
We cannot write out the entire network in a single program. We need layers in the network just as a program needs subroutines. The internet has 5 layers
