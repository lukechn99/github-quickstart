# Architectural Design
Going beyond the requirements gathering, going beyond the individual classes, going into the design and how system components work.  
Architectural design is less common in agile because things are interleaved which means more refactoring if your system is robustly designed beforehand.  
Refactoring code and classes is relatively painless, however, refactoring system components is much harder. This is analogous to changing furniture in a house versus changing a wall or other structural element. Advantages of being explicit include better stakeholder communication, deeper system analysis (eliminate contradicting requirements like ease of use vs security), and large scale reusability.  

### Architecture in the Large and Small
Coding is architecture in the small. Architecture in the large refers to whether . Non-functional requirements have the heaviest impact on the system's architecture because they often refer to system requirements rather than user requirements. 

### Overarching Goal
Everyone can understand what's going on, and conform to and provide the services needed, both functional and non-functional. 

### Epic
The government wanted a unified system for health care information to be shared between different providers. But now that Epic can provide that, they have a monopoly and have no reason to improve. However, in the process, they had to communicate a lot with the government. 

### Some decisions to make...
is there something to use as a template and can be reused?  
how to make your system secure, where to put the security measures?  
how do we minimize communication to increase performance?  
how do we provide high availability?  
each architectural model only shows one view/perspective of the system, how do you want to portray it?  

### MVC Model View Controller Pattern
The model handles the data and associated methods, it should track application state and passes state changes to the view.   
The view defines how the data is presented to the user and renders the model.  
The controller manages user interaction and communicates the interactions (button click, key press, etc.) to the model or view to map user actions to model updates and selects view.   
For a web application, the three components are used under a browser. The browser gives input to the controller and receives output from the view.  
Pros: 
Cons: 

### Layered Architecture Pattern
Layered architecture is used to model the interfacing of sub-systems.  
This means entire layers can be replaced as long as the interface is followed.  
Layers consist of functionality that are interrelated.  
One good use is when you are building new services on top of what you already have. For example, you can have the UI layer, UI management authemtication and authorization, core business logic, and then syste, support (OS, databases). Certain things like login and role checking can be grouped together in one layer, similarly, data import/export and report generation can be on one layer. 

### Repository Architecture
The system is split into subsystems. Subsystems have their own databases. componenets only interact through the repository. Used when a system has large volumns of information that need to be stored for a long time or a highly data-driven system. Components are independent which is good for adding or removing components. However, the repository becomes a single point of failure. For an IDE, the components are different code editors that all function off of a project repository.  

### Client-Server Architecture
A distributed system model which shows how data and processing is distributed across a range of components. Clients call for services through a network. Some of the first examples of this were when independent computers wanted to make a print and accessed the printer through the network. Prints would queue. The main point of a server is that the server's service does not have to be implemented on every machine, instead it only has to be in one place(the printer) and individual computers without that ability can just use the printer. 

### Pipe and Filter Architecture
Not good for interactive systems because it is very sequential manner. As such, it is designed for processing data. For this architecture, the data format must be agreed upon

### Application Architectures
These are designed to meet an organizational need. Applications can often share the same architecutre and just configure it to meet specific requirements. Mostly it is a design checklist. Different types of applications will have diffferent architectures. Some examples include data processing applications, transaction processing applications, event processing systesms, and language processing systems. 

### Information Systems Architecure
Transaction based system with interactions that typically involve the database. It is also often layered. 
