# Systems
Use UML to plan the system. We have to consider many things outside of the code:  
External perspective - where you model the context or environment  

*models should be **complete** and **correct***

### UML Diagram Types
Activity diagrams show the activities going on, especially for data and what's happening to it and where it's going  
Use case diagrams show the interactions ebtween a system and its environment  
Sequence diagrams show interactions between the system, system components, and actors  
Class diagrams show the classes and objects  
State diagrams  

*most companies do not follow hardcore agile rules; instead, they will tailor it to their company... or laziness*

### Context Models
We need to know the context that our code is being put into. In the case of the MentCare system, it will interact with a scheduling system, a drug prescribing system, admissions system, greater hospital patient records that lie outside of mental care, and other systems.  

### Process Models
We use a UML activity diagram to do this: diamonds are decision points, bold bars show a kind of sub-graph that you can do in any order. Each "node" is an individual activity and are not documented in depth on that diagram. This is drawn like a flow diagram. 

![process model](https://github.com/lukechn99/github-quickstart/blob/master/5801/res/processmodel.PNG)

### Interaction Models
