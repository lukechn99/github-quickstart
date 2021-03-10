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
