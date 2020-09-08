### Basics
Check out "this week" every week for content
Q&A discussion board on canvas
Zoom office hours
Watched pre-taped lectures, ask questions on the canvas thread, and then they will be answered in the next live session
For project questions, ask TAs  
  
2 midterms, drop 1  
5 projects, drop 1  
25% participation... you cannot mess this up  
  
projects must run on CSE labs machines  
  
you can go to any lecture or recitation. They are the same (1pm vs 4pm)

***Outcomes***  
Write code that exploits OS features  
Write code that is efficient, reliable, and possibly secure  
Linux/UNIX interface  
General systems programming concepts beyond OS (databases, networking, efficient response of programs)  
We use C because other languages are too far from the machine; applications that use low-level OS 
facilities include JVM, web browser, DB engine, camera controls, microphones, network  
Java is 10x to 20x slower than C  
  
You need to be willing to look at "man pages", documentation, look stuff up yourself, learn by doing  
  
Programs we write have to respond to asynchrony, like exception catching  
  
### OS
Operating systems provide two interfaces
USER APPLICATIONS
	||
OPERATING SYSTEM
	||
ARCHITECTURE  
between the architecture and between applications

### Roles of the OS
REFEREE  
it addresses resource allocation among users and applications  
isolate users and applications, communicate between them  
  
ILLUSIONIST  
seems like each application has the entire machine to itself  
makes it seem like there's an infinite amount of memory, storage  
  
HANDY PERSON  
library, drivers  
