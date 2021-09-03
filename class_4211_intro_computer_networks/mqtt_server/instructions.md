# MQTT Message Broker
Author: Luke Chen  
Email: chen5216@umn.edu

### HOW IT WORKS
The ```server_host.py``` holds the server code and ```client_host.py``` holds the client code. 
The server starts with a main method that creates a server socket on localhost port 8000 (127.0.0.1:8000) 
which accepts all incoming connections. Clients that want to connect will send three connection requests 
which are all accepted by the server. The first two connections are sockets for two way communication with 
the server which allow the client to send requests like CONNECT and PUBLISH while also listening for a 
response. It is possible that you do not need two sockets for this since the server and client take turns 
using this communication. The third socket connection is for server pushes whenever relevant topics are 
published to.  

After accepting the socket connections, the server will create a new thread that runs the server_thread 
code and creates a new profile (_client) for the client to track what they are subscribed to. 
```server_thread()``` then listens for client requests and serves them. Whenever a new PUBLISH request is 
made, the ```notify()``` method is called which iteractes through all clients and the ones that are 
subscribed will receive a notification. Clients create two threads for this process; one for communicating 
with the server and another that accepts incoming pushes.   

Clients make requests in the form of ```type@topic@contents@flag```. 

The data is stored in the database class which holds nested dictionaries of everything published. 

Topic wild cards... wild card matching is done by the client class. Every client is notified of a new 
message and the topic it was published to. It is up to the client object to decide whether or not the 
message should be sent to the client. Note that the client object is part of the server_host program and 
not from the client_host program. The client object is stored in a global list as a way for the server 
to keep tabs on the clients being served. A client's ```notify()``` method is called to check whether 
the message should be sent to the actual client. 

### HOW TO RUN
You will need python3 to run this project. 
In one terminal window, run "python3 server_host.py" and in another 

Connection requests can be entered as ```connect``` or ```CONNECT``` while omitting the topic, content, and 
flag fields. Disconnection requests are similar in that the other fields are not required. Publish requests 
are entered either as ```publish@topic@message``` if omitting the "retain" flag or ```publish@topic@message@retain``` 
to use with the retain flag to save the message. Subscribe requests need only need subscribe type and topic 
like ```subscribe@topic``` without the contents and flag. 

### EXAMPLES
server terminal  
```
>> python3 server_host.py
Connected by ('127.0.0.1', 40226)
alternatively,  ('127.0.0.1', 40228)
Connected by ('127.0.0.1', 40232)
alternatively,  ('127.0.0.1', 40234)
client:  ['CONNECT']
client:  ['PUBLISH', 'weather/temp', '98', 'retain']
current subs: {'weather': [{'temp': [{}, 0]}, 0]}
client:  ['CONNECT']
client:  ['SUBSCRIBE', 'weather/*']
current subs: {'weather': [{'*': [{}, 0]}, 0]}
client:  ['PUBLISH', 'weather/forecast', 'cloudy', 'retain']
current subs: {'weather': [{'temp': [{}, 0], 'forecast': [{}, 0]}, 0]}
client:  ['LIST']
{'weather': [{'temp': [{}, '98'], 'forecast': [{}, 'cloudy']}, ''], 'news': [{}, ''], 'health': [{}, ''], 'security': [{}, '']}
{'weather': [{'temp': [{}, '98'], 'forecast': [{}, 'cloudy']}, ''], 'news': [{}, ''], 'health': [{}, ''], 'security': [{}, '']}
```  
  
client 1 terminal  
```
>> python3 client_host.py
enter with format <type@topic@contents@flag>: connect
client message sent
server: CONNACK
enter with format <type@topic@contents@flag>: publish@weather/temp@98@retain
client message sent
98
server: PUBACK
enter with format <type@topic@contents@flag>: publish@weather/forecast@cloudy@retain
client message sent
cloudy
server: PUBACK
enter with format <type@topic@contents@flag>: list
client message sent
server: LIST
{'weather': [{'temp': [{}, '98'], 'forecast': [{}, 'cloudy']}, ''], 'news': [{}, ''], 'health': [{}, ''], 'security': [{}, '']}
enter with format <type@topic@contents@flag>:
```  
  
client 2 terminal  
```
>> python3 client_host.py
enter with format <type@topic@contents@flag>: connect
client message sent
server: CONNACK
enter with format <type@topic@contents@flag>: subscribe@weather/*
client message sent
98
server: SUBACK
cloudywith format <type@topic@contents@flag>:
```  

*notice how the last line of client 2 terminal has the subscribed message, but it prints over the input line. This is a known bug, but resta assured that the message still gets delivered. 