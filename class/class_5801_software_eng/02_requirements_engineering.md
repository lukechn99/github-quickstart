# Requirements Engineering
Why do it? Fixing a problem after the fact can cost 100x more than just putting it in earlier.  
During this process, we check that the system is **valid** and provides the functions which support the customer's need. The three main steps are elicitation, specification, and validation.  
Notations are important. English language itself is not structured and discrete enough to express design.  
Some techniques we can use are to review the requirements with the client and analysts, produce a prototype

### IEEE Software Requirements
The I triple E is a set of standards for Software Requirements Specifications  

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
The key features of the system are:  
1. Individual care management Clinicians can create records for patients, edit the
information in the system, view patient history, and so on. The system supports
data summaries so that doctors who have not previously met a patient can
quickly learn about the key problems and treatments that have been prescribed.
2. Patient monitoring The system regularly monitors the records of patients that
are involved in treatment and issues warnings if possible problems are detected.
Therefore, if a patient has not seen a doctor for some time, a warning may be
issued. One of the most important elements of the monitoring system is to keep
track of patients who have been sectioned and to ensure that the legally required
checks are carried out at the right time.
3. Administrative reporting The system generates monthly management reports
showing the number of patients treated at each clinic, the number of patients
who have entered and left the care system, the number of patients sectioned, the
drugs prescribed and their costs, etc.

The overall design of the system has to take into account privacy and safety
requirements. The system must be available when needed; otherwise safety may be
compromised, and it may be impossible to prescribe the correct medication to patients.
There is a potential conflict here. Privacy is easiest to maintain when there is only a
single copy of the system data. However, to ensure availability in the event of server
failure or when disconnected from a network, multiple copies of the data should be
maintained. I discuss the trade-offs between these requirements in later chapters.  

### Use Cases
Graphical model and structured test describing interactions between users and a system.  

| Content | Description |
| --- | --- |
| Name | clear and concise description of the use case |
| ID number | Must be unique |
| Brief description | describe the scope of the case |
| Actors | who can engage in the activity |
| Preconditions | Basic qualifications of what the program can start with |
| Basic flow (main course) | the steps the actor goes through to get to their goal |
| Alternate flow (alternate course) | less common user-system interactions |
| Exception Flows | things that happen that prevent the user from achieving the goal (e.g. incorrect username/password combo) |
| Postconditions | the range of results promised based on a correct precondition |


### User and System Requirements
User requirements: what services the system is expected to provide to system users and the constraints they operate under.  
ex. The Mentcare system shall generate *monthly* (constraint) management reports *showing the cost of drugs* (service) prescribed by each clinic during that month.  
  
System requirements: a description of the system's functions, services, and operational constraints.  
ex. Access to drug cost reports shall be restricted to authorized users as listed on a management access control list.

### Functional and Non-functional Requirements
We consider **Functional** requirements as the abilities that the service needs or statements of service such as a login, a search bar, or other specific use case. 
It is usually pertaining more towards the user than the system. We need *form based specifications* to specify functional requirements. 
Some of these include a description of the function or entity being specified, a description of inputs and their origin, outputs and their destination, 
a description of the action to be taken, for functions use a precondition to guarantee a postcondition, preparation for the side-effects.  

**Non-functional** constraints that apply to the *whole* system. Some metrics for non-functional requirements are speed, size, ease of use, 
reliability, robustness, and portability. Nonfunctional requirements arise through user needs because of budget constraints, organizational policies, the need for interoperability with other software or hardware systems, or external factors such as safety regulations or privacy legislation.  
![table of nonfunctional requirements](https://github.com/lukechn99/github-quickstart/blob/master/5801/res/4.1.1.PNG)  
*Table of non-functional requirements*  

### Requirements Engineering Process: Elicitation, Analysis, and Validation
![RE Process](https://github.com/lukechn99/github-quickstart/blob/master/5801/res/4.2.1.PNG)
Throughout this process, we gather the users of the system and what they need to do. These become your use cases

### Requirements Elicitation
Some key elements that elicitations should capture include:  
1. come to a middle ground with stakeholders on demands and requirements
2. agree on terms and implicit knowledge specific to the client's domain needed to operate on this project
3. discover different sources of requirements (e.g. not all will come from the accounting department, some requirements may come from HR)
4. negotiation on what's needed
5. document findings
Elicitation can be done through interviews (both closed question and open) and ethnographies (where the developer/analyst observes clients). Ethnographies can be useful because people rarely ever actually follow controlled procedures.  

### Requirements Specification
**After** finding requirements, the engineer can start documenting the requirements through Requirements Specification. These can be expressed in natural language where each sentence expresses an idea or requirement, in a structured language like SRS or use cases, graphical notations (like UML), or even mathematical specifications.  
In natural language, some basics you need are structure and some sort of standardization, avoidance of jargon, differentiation between mandatory (shall) and desireable features (should).  

### Requirements Validation
You want to check that the requirements you gathered actually reflect the needs of the client. The documentation of the requirements should be error and conflict free. They should be realistic, and verifiable. To this end, the requirements should be reviewed, prototyped and used, and requirements should be tested using test-driven development. With test driven development, the tests that adhere to requirements are written first so that the code can immediately be tested. 

### Requirements Change
They change because many problems cannot be fully defined, and so as more is discovered, requirements will change. Other reasons for change can inclde mistakes that were in the original code, the advancement of the business environment and technology, and new user imposed requirements.  
When considering new requirements, we will want to keep track of them by tracking the change management process, traceability policies, 
