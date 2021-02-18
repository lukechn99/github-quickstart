# UML, OOP, and Class Diagrams
### Classes
We are determining what an object will look like when we create a class.  
Classes must have a name, attributes (+, -, #, ~), and operations.  
The class name should be short and descriptive.  
Attributes include members and state. These control visibility. Public methods and members . State variables should generally never be public. 
Static asks the question: does it belong to the class or the object?

Classes are supposed to be blueprints (abstraction) which are then instantiated (brought into existance). Abstraction (not the class) is the complement of instantiation.  
Therefore the 

### Relationships
Inheritance (specialization of an object), is-a, empty arrow  
Aggregation (grouping of individual objects), has-a, empty diamond
Composition (inclusion of other objects), contains-a, full diamond


The differnce between aggregation and composition is what happens when an object is destroyed. In aggregation , each object is standalone and won't be affected. For a composition, if the composition is destroyed, then the objects are destroyed too. 

Classes can be combined and related

Polymorphism: A squirrel is a rat which is an object. Therefore, if any method of space asks for an object, a squirrel will do. 

Overload is redefining a same-named function, different input parameters and different use  
Overriding is 
