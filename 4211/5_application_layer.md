# Application Layer
While processes (running programs) on the same machine communicate with IPC, processes on different end systems connecting  over the internet must communicate through the application-layer protocol.  
  
Steps to send application layer communication:  
1. Address the machines and find the destination host. IP corresponds to the NI card, so a computer with more than one NI card can have more than one IP address. The MAC address comes with the device unlike the IP address. Delivering to the end host needs IP address and port number 
2. We find a process to send through (TCP or UDP). Routing then depends on IP addresses. The Internet consists of many routers and uses only the bottom 3 layers of the networks. Each router has a table. We need to identify the IP address we are going to, and then the port number. For example, HTTP servers use port 80 and email uses port 25. So for email, we will be delivering to some IP x.x.x.x port 25. This is necessary because there are always many processes besides the target process on any given end system. 
3. What kind of service you need. 

### App Needs
An app needs the transport service to provide:
1. Data loss, is the app flexible or not, some apps may require 100% reliable data
2. Timing, low delay, long delay
3. Throughput
4. Security, how sensitive is the data?

| Application | Data Loss | Bandwidth | Time Sensitive |
| --- | --- | --- | --- |
| Email | cannot tolerate | elastic | no |
|audio/video | loss-tolerant, can drop some frames | audio (5Kb), video (10Kb) minimum | yes, 100ms |
| IM | yes

### World Wide Web
When creating a network app, you have to choose which transport layer to use when communicating from one end system to another end system. 

# Popular Application Level Protocols
Protocols need to define type of message exchanged, message syntax, message semantics, rules for how and when to respond. They can follow a public-domain protocol or proprietary. Public protocol requires feedback (RFC) and allows for interoperability. 

### Electronic Mail


### Domain Name Sharing
Domains can be identified by name instead of IP through the DNS system  

### P2P File Sharing
