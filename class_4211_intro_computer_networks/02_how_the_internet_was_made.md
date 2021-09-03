# How the Internet Was Made
We consider organization of the internet as a series of steps, kind of like the procedure used in airplanes.  
This is designed with multiple layers, and layers must follow standards. This allows for identification and ease of connection between products. This is unlike proprietary solutions that cannot interface with standards.  

### Layering
IP stack has five layers (application, transport, network, link, physical). We worry about/address different things at different layers. At the link layer, we address transmission errors like bits getting switched, but once we get to the network layer, we no longer have to worry about that. In this way, layering distributes tasks and simplifies the overall architecture of the internet. Layers use subsequently lower layers to communicate, each layer changes the data, eventually reaching the physical network.  
*For example* the application (layer 5) will create data to send, using layer 4 (TCP or UDP) which in turn uses 3, then 2, then 1. The layer 1 physical data will reach the router at layer 1 and have a specific protocol for that layer. The router will guide the data all the way up to the IP network layer where it will interpret the IP address destination before sending it down to layer 1 and then off to the destination host. The data will reach at layer 1 and then travel to layer 5.  

![enveloping](https://github.com/lukechn99/github-quickstart/blob/master/4211/res/layers.PNG)

*A switch uses layers 1 and 2, a router uses 1 to 3*  

### ISO/OSI Stack
Alternatively to the IP stack, there is also the OSI stack which has the presentation and session layers below the application layer for a total of 7 layers. The presentation layer is for conversion of data formats (e.g. endian). The session layer does authentication and recovery from failure.  

### Drawbacks
Possible duplication of functionality between layers.  
