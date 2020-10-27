# Factory Class
The factory handles the creation logic instead of the program
```
enum PetType {
	PT_dog, PT_cat
}

class pet {
	...
};

class Dog : public Pet {
	...
};

class Cat : public Pet {
	...
}

class PetFactory {
	switch(type) {
		
}

int main () {
	PetFactory pfact;
	Pet *vpetptr[5];
	int petcnt = 0;
	
	vpetptr[0] = pfact.CreatePet(PT_dog, "name", "breed", "color");
	
	return 0;
}
```
The purpose of having a factory is that it can generate objects of different things.  
Use the factory pattern when you have a variety of objects to generate.  
For our project, the factory will generate packages, persons, and drones.  

### Don't use a factory
if creation logic is simple

### Use concrete factory
When there could be an if statement for creation

### Use a factory method 
if creation logic is tied to specific classes

### Template Class
Templates cannot be compiled, they have to be written in the header files, do not write code in the header files. 
```
template <typename T>
class EntityFactory {
	public:
		Entity* CreateEntity(const picojson::
		
};
int main() {
	EntityFactory<Drone> = DroneFactory
```

example of template code use:
```
// .h

