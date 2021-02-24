# Peer to Peer
File sharing, not physical but built on the IP network, peers must know each others' IP addresses. They form a virtual network. This brings up topology questions about how you will find your peers.  
Direction node lets you in to the P2P network. One node could give you 5 more IP addresses in the P2P network. Now with these links you could work on getting more. However, because you do not really know if these 5 are close or far from your destination, it makes the topology complicated.  
Peers can shut down and when they do they disconnect from the network. The next time they come on they could have a different IP address. This means dynamic change, but also means high scalability.  
One example if Napster which was a P2P song sharing network. People joined the network by joining the directory server which held all of the information for who has which song. The server itself does not hold any songs. The server here is called the direction node.  
Fun fact: Napster will slow your downloads because they know once you're done you will log off. The longer you're online, the more other people can download off of you too. Some P2P systems work off of a credit system where you help others and you can get credentials to be helped more.  
Some concerns with this are that when you, as a node, are available for use, there is a chance that you will be used maliciously. 

### Query Flooding: Gnutella
Fully distributed with no central server. Creating an overlay network. Peers are limited in how many they can connect with, instead, the topology is a network graph. Queries will be forwarded if the neighbor you reach out to already has their full 10 connections. Once the peer is found, a query hit is sent over the reverse path. To join, you just have to talk to one node.  
Peer leaving: problem 16 in textbook

### Skype
Skype uses hierarchical overlay of SNs (super nodes) which are servers running 24/7. The super nodes make the topology more reliable.  
NATs are for multiple nodes using the same IP address.  

### KaZaA
Uses group leaders that take the place of super nodes. When one of these go down, we have to have a secondary backup node. 

### DHT Distributed Hash Table
We hash a resource name and store it in a table. We then designate one node as the holder of the resource. 
First, we assign an integer identifier to every peer in range. 
The hash table is distributed among you and your 10 neighbors. No single one person needs to hold the whole hash table. We hash the query so that we know which neighbor to go to? Like a two tier hash table? Hash table of hash tables?  
I don't understand the hypercube example. 3 bit representation, only one bit changes at a time??? 001 -> 011 -> 010?
![hypercube](https://github.com/lukechn99/github-quickstart/blob/master/4211/res/hypercube.png)
For example, if 10111 wants to connect with 01010, then the path would look like 10111 -> 00111 -> 00110 -> 01110 -> 01010 with only one bit changing each time. This represents travelling between neighbors closer to the destination.  
In each DHT, a peer can keep track of successor, predecessor, a short cut, or all of them. 
