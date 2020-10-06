# Factory Class
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
