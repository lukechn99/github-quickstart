# DNS
We use host names to navigate the Internet. However, every host name on the internet has to be translated into an IP address and it is the DNS that does that translation. 
MAC Addresses are flat and permanent, but IP is two layered. For example, 128.101.35.34 describes a host at the U of M. The first two parts, 128.101 is the first layer and represents the U of M, the second part shows which host (host ID). Host names (URLs) are hierarchical which means that they have a deeper directory. 

### Internet Domain Names
They are organized in a hierarchy and can go infinitly deep. Domain names are explored down a root like a tree. For example it might start from .com .edu .org, then look at things like umn.edu, google.com, trees.org. **Fully qualified domain names** are commonly organized as  
<host name>.<sub-domain, local domain name>.<second level domain>.<top-level domain, root domain> 
For example afer.cs.umn.edu  
[Hierarchy descriptions](https://www.inetdaemon.com/tutorials/internet/dns/operation/hierarchy.shtml) should be taken with a grain of salt because it seems like different sources have different names for the hierarchy.  
There exist 13 root servers in total. When searching for a DNS, host DNS queries will first search the local name servers, then the root server, and then down to other local DNS servers (authoritative server) until the name is either found or it returns DNE. DNS is decentralized. After a DNS search, a mapping is created for quicker lookup next tie. Each DNS server has a database that can look up host names.  

DNS queriers can work recursively or iteratively. Recursive puts the burden of name resolution on the contacted name server. If a local name server does not know, then the responsibility for finding it will be recursively passed onto the root, then intermediate server, authoritatve server, etc. It can be burdensome
Iterative will simply redirect instead of replicating the query and check. It will say "I don't know, but you should try this server"  

DNS records are kept as resource records (RR) which describe the <name, value, type, ttl> where type tells what the *name* and *value* are:  
If type is "A" then the name is the host name and value is IP address.  
If type is "NS" then the name is the domain and the value is the IP address of the authoritiative name server of the domain.  
If type "CNAME" then is it the canonical name and the value is the canonical name.  
If type "MX" then value is the hostname of the mailserver associated with name.  

TTL represents how long the record is kept for. We want to limit this because the longer we keep a record, the more likely something has changed and the record is no longer accurate. 

DNS protocol messages are formatted as...  
| identification (a 16-bit number for the query) | flags |
| --- | --- |
| number of questions | number of answer RRs |
| --- | --- |
| number of authority RRs | number of additional RRs |
| --- | --- |
| questions |
| --- |
| answers | 
| --- |
| authority |
| --- |
| additional information |


DNS uses UDP protocol 

---
IP address: unique to a NI card, has 32 bits split into 4 parts, composed of network ID and host ID  
MAC Address: mapped to IP through IP ARP, unique to the the device  When moving from one switch to another switch, you use MAC address
Resource Records (RRs): store records of the DNS
