# Requirements Engineering
Notations are important. English language itself is not structured and discrete enough to express design. 

### IEEE Software Requirements
The I triple E is a set of standards for Software Requirements Specifications  
We consider **Functional** constraints as the abilities that the service needs such as a login, a search bar, or other specific use case. 
It is usually pertaining more towards the user than the system. We need *form based specifications* to specify functional requirements. 
Some of these include a description of the function or entity being specified, a description of inputs and their origin, outputs and their destination, 
a description of the action to be taken, for functions use a precondition to guarantee a postcondition, preparation for the side-effects
and  **Non-functional** constrainsts that apply to the *whole* system. Some metrics for non-functional requirements are speed, size, ease of use, 
reliability, robustness, and portability. 
**User requirements** and **System requirements** 

### Case Study: Insulin Pump Control System 1.3.1
Clearly, this is a safety-critical system. If the pump fails to operate or does not
operate correctly, then the user’s health may be damaged or they may fall into a
coma because their blood sugar levels are too high or too low. This system must
therefore meet two essential high-level requirements:  
1. The system shall be available to deliver insulin when required.  
2. The system shall perform reliably and deliver the correct amount of insulin to
counteract the current level of blood sugar.  
The system must therefore be designed and implemented to ensure that it always
meets these requirements. More detailed requirements and discussions of how to
ensure that the system is safe are discussed in later chapters.


![hardware arch](https://github.com/lukechn99/github-quickstart/blob/master/5801/res/1.3.1.1.PNG)
*Hardware architecture*  


![activity model](https://github.com/lukechn99/github-quickstart/blob/master/5801/res/1.3.1.2.PNG)
*Activity model*  


### Case Study: Mentcare System 1.3.2
A patient information system that maintains health care records pertaining to mental health


### Use Cases
Graphical model and structured test describing interactions between users and a system.
