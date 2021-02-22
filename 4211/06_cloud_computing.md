# Cloud Computing
Cloud shifts the burden from small companies to cloud providers

### Pure P2P
There is no always-on server. It is highly scalable, but difficult to manage.  
We can use a directory server that can lead from one peer to another, or broadcast outwards to find the peer.  
Skype is an example of something that uses P2P and client-server

### HTTP
As long as you use HTTP protocol, you can communicate through the web and build your own browser. Regardless of machine, they can communicate to web servers using HTTP.  
HTTP uses TCP: client initiates RCP connection to server, server accepts TCP connection from client, HTTP messages are exchanged, then the connection is closed.  
HTTP is stateless and retains no information about prior client requests. Stateful protocols are complex because they have to remember your history. However, websites that do want to remember you use cookies.  
HTTP 1.0 is non-persistant which means you are able to access at most one object before the connection closes. You need one RTT for the connection setup  
Later versions of HTTP allow multiple objects to be accessed over one single connection. This is due to increased server capabilities.  

HTTP Format:  
Request line
[method] [URL] [version]cr,lf
Header lines
[header field name]
Entity body

URL is almost like a tree structure; access the root to get to the 

HTTP response status codes, after a request, the server to client response will have a code in the first line (200 okay, 301 moved permanently, 400 bad request, 404 not found, 505 http version not supported, etc.)

Authentication:
HTTP itself is stateless, so we need to implement this as an extra thing. Servers that are protected will respond with a 401 auth. req.  
Cookies can also identify you. The server will send a cookie the first time you connect, and in subsequent connections, the client will present the cookie when sending later requests.  
Security versus safety

### Containers


### HTTP/2
The main goals is to decrease latency to improve page load speed
It addresses problems in HTTP version 1 like negotiation mechanisms between clients and 
Pipelining of HTTP requests
WE allow multiple queues to fixe the head of line problem  
It uses HTTP push instead of pull. This says that if the server understands who you are, and what you are interested in, then we don't want to wait for you to ask foan object. Instead, they will be pushed to you for fast access in case you need them. 

### Email
Mail needs a mail server. Most mail actually goes between mail servers.  
The major components are user agents, mail servers, and SMTP (RFC 821). While mail servers communicate by SMTP, the user agent does not have to. User agents connect through a different protocol (usually POP3 or IMAP) when receiving messages from mail servers. When sending, however, they still use SMTP.   
Email uses TCP over port 25.  
Phases of transfer include handshaking, transfer of message, and closure. 
Over SMTP, messages had to be sent in 7-bit ASCII.  
| Header |
---
| Blank line |
---
| Body | 
With Multimedia (MIME), we define even more things in the header so that the recipient can properly play out the contents. 

### POP3
Post Office Protocol uses a authorization phase and a transaction phase.  
In authorization, declare a user and password. The server will either respond +OK or -ERR  
In the transaction phase, the client can list out new mail, retrieve a message, or delete messages and then close the connection. 

### Email vs. HTTP
HTTP: pull, it is waiting for your request
email: push
Both use ASCII command and responde  
HTTP: each object is iencapsulated in its own response message
SMTP: multiple object messages sent in a multipart message.  
These protocols only consider text, not images or videos. They are changed later to accommodate other media.  
