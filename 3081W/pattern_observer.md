# Observer Pattern
An example problem we could have is that a company wants to send new subscribers a welcome email. However, what if you wanted to scale up the number actions to take or scale to different companies? That would require a different customer object for each and significant code modification.  
An observer can observe different types of objects, so we do not need to create new code for new functionality. They can do this because they use the same abstract interface (using methods like OnEvent()) that their subjects will use.  
Observers will notify based on an OnEvent()

### How to set up an observer pattern
Identify Observers and Subjects.  
Observers are the objects that will be notified of change. Observers use an abstract uninstantiable class and concrete observer classes. For example, we might have an observer interface with an OnEvent() method, but this one is abstract, so we must make button observers and right-click observers that monitor a specific OnEvent()  
Subjects are objects that do not have to handle specifics of what's handed to the observer because they can simply use the abstracted interface.  
Observers are responsible for knowing what to watch for, the subjects don't have to mind that. Subjects do not know, nor do they need to know, which observers depend on them.  
A subject needs a dynamic data structure to keep track of which observers to notify, and **needs an attach() and detach() method** to add and remove observers. This is like registering a listener. 
Observers should have methods that allow them to extract information from the subject if the OnEvent() call does not give enough info. 

### Head-first design
