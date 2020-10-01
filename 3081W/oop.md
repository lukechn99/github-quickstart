# Cohesion
when looking at software design, we want HIGH cohesion, everything should work towards one goal
functional cohesion is where each function does a single task, but together coordinate to do more, classes should also have functional cohesion  
sequential cohesion outputs information that is then input into another  
communcational cohesion is where two elements operate on the same input data and contribute towards output  
procedural cohesion is ensuring the order of execution  
temporal cohesion is where all elements are related temporally  
logical cohesion is where the code is related logically but not functionally, code can look very different for one function that read from the cloud versus one that reads from disk  
coincidental cohesion, elements are not related, no conceptual relations

# Coupling
should be LOOSELY coupled

# Major constructs of OOP
### Abstraction
only present what's necessary, we don't need to know implementation details of sort() or pow()  
when implementing a class, abstract things, so that a developer using your class does not have to worry  

### Polymorphism
a variable can be anything, and is bound at runtime
an instance of Person can be a Friend, Family, Significat Other, or something else, the behaviors are determined at runtime, this is called inheritance  
very closely related to inheritance
C++, has the advantage of letting you overload many operators
**protected access** specifier allows children/derived classes to access some data

### Encapsulation
making things private

### Single responsibility principle

### Open closed principle
Don't go back to edit your class, otherwise you will have to do regression testing  
but the class should be open to 

### Virtual Functions
When we have a derived class with the same method name as the superclass and we want the derived class to use its own, we define the superclass method as virtual
```
class restaurant {
	virtual void pay() const {
		...
	}
}	
class foodTruck : public restaurant {
	void pay() const override {
		...
	}
}
```
