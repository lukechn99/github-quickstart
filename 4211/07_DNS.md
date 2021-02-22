# DNS
Every host name on the internet has to be translated into an IP address. It is the DNS that does that transformation. 
MAC Addresses are flat and permanent, but IP is two layered. For example, 128.101.35.34 describes a host at the U of M. The first two parts, 128.101 is the first layer and represents the U of M, the second part shows which host (host ID). Host names (URLs) are hierarchical which means that they have a deeper directory. 

### Internet Domain Names
They are organized in a hierarchy and can go infinitly deep. Domain names are explored down a root like a tree. For example it might start from .com .edu .org, then look at things like umn.edu, google.com, trees.org.  Commonly organized as 
lupus.fokus.gmd.de where de is the domain, gmd is the sub-domain, fokus is the 
There exist 13 root servers in total. When searching for a DNS, the local name servers will be searched first, then the root server, and then down to other local DNS servers (authoritative server) until the name is either found or it returns DNE. DNS is decentralized. After a DNS search, a mapping is created for quicker lookup next tie. Each DNS server has a database that can look up host names.  

DNS queriers can work recursively or iteratively. Recursive puts the burden of name resolution on the contacted name server. If a local name server does not know, then the responsibility for finding it will be recursively passed onto the root, then intermediate server, authoritatve server, etc. It can be burdensome
Iterative will simply redirect instead of replicating the query and check. It will say "I don't know, but you should try this server"  

DNS records are kept as resource records which describe the <name, value, type, ttl> where type tells what the name is.  
If type is "A" then the name is the host name and value is IP address.  
If type is "NS" then the name is the domain and the value is the IP address of the authoritiative name server of the domain.  
If type "CNAME" then is it the canonical name and the value is the canonical name

TTL represents how long the record is kept for. We want to limit this because the longer we keep a record, the more likely something has changed and the record is no longer accurate. 

DNS protocol messages are formatted as ...

DNS uses UDP protocol 

---
IP address: unique to a NI card, has 32 bits split into 4 parts, composed of network ID and host ID  
MAC Address: mapped to IP through IP ARP, unique to the the device  When moving from one switch to another switch, you use MAC address
