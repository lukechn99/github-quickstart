# Application Layer
Steps to send application layer communication:  
1. Address the machines and find the destination host. IP corresponds to the NI card, so a computer with more than one NI card can have more than one IP address. The MAC address comes with the device unlike the IP address. Delivering to the end host needs IP address and port number 
2. We find a process to send through (TCP or UDP). Routing then depends on IP addresses. The Internet consists of many routers and uses only the bottom 3 layers of the networks. Each router has a table. We need to identify the IP address we are going to, and then the port number. For example, HTTP servers use port 80 and email uses port 25. So for email, we will be delivering to some IP x.x.x.25. This is necessary because there are always many processes besides the target process on any given end system. 

### World Wide Web
When creating a network app, you have to choose which transport layer to use when communicating from one end system to another end system. 

# Popular Application Level Protocols
### Electronic Mail


### Domain Name Sharing
Domains can be identified by name instead of IP through the DNS system  

### P2P File Sharing
