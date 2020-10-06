### Constructors
There are three different constructors in C++  
The default constructor is used to set instances to default values  
```
Circle(double rad): radius(rad) {}
```
```
// called as
Circle c;

// not
Circle c();
```
The parametrized constructor sets to parameterized values  
```
Circle() {radius = 1;}
```
The copy constructor is used for dynamic 

```
#include <iostream>
#include <string>
using namespace std;

class Restaurant {                          // Info about a restaurant
   public:
      void SetName(string restaurantName);  // Sets the restaurant's name
      void SetRating(int userRating);       // Sets the rating (1-5, with 5 best)
      void Print();                         // Prints name and rating on one line
   
   private:
      string name;
      int rating;
};

// Sets the restaurant's name
void Restaurant::SetName(string restaurantName) {
   name = restaurantName;
}

// Sets the rating (1-5, with 5 best)
void Restaurant::SetRating(int userRating) {
   rating = userRating;
}

// Prints name and rating on one line
void Restaurant::Print() {
   cout << name << " -- " << rating << endl;
}

int main() {
   Restaurant favLunchPlace;
   Restaurant favDinnerPlace;
   
   favLunchPlace.SetName("Central Deli");
   favLunchPlace.SetRating(4);
   
   favDinnerPlace.SetName("Friends Cafe");
   favDinnerPlace.SetRating(5);
   
   cout << "My favorite restaurants: " << endl;
   favLunchPlace.Print();
   favDinnerPlace.Print();
   
   return 0;
}
```

This could be split into 3 files (?)
  
restaurant.h
```
#define restaurant.h

class Restaurant {                          // Info about a restaurant
   public:
      void SetName(string restaurantName);  // Sets the restaurant's name
      void SetRating(int userRating);       // Sets the rating (1-5, with 5 best)
      void Print();                         // Prints name and rating on one line
   
   private:
      string name;
      int rating;
};
```
  
restaurant.cc
```
#include "restaurant.h"

// Sets the restaurant's name
void Restaurant::SetName(string restaurantName) {
   name = restaurantName;
}

// Sets the rating (1-5, with 5 best)
void Restaurant::SetRating(int userRating) {
   rating = userRating;
}

// Prints name and rating on one line
void Restaurant::Print() {
   cout << name << " -- " << rating << endl;
}
```
  
main.cc
```
#include <iostream>
#include <string>
using namespace std;

int main() {
   Restaurant favLunchPlace;
   Restaurant favDinnerPlace;
   
   favLunchPlace.SetName("Central Deli");
   favLunchPlace.SetRating(4);
   
   favDinnerPlace.SetName("Friends Cafe");
   favDinnerPlace.SetRating(5);
   
   cout << "My favorite restaurants: " << endl;
   favLunchPlace.Print();
   favDinnerPlace.Print();
   
   return 0;
}
```

### Compile time binding, run time binding, access specifiers
Protected, public, private, virtual  
whenever there is a "is-a" relationship, we use the public classifier to define the derived class

```
class shape {
	public:
		void disp_area();				// if this methos is used
      	virtual void disp_area();		// allows for polymorphism, can create a pure abstract class
		virtual void disp_area() = 0; 	// 

class triangle:public shape {
   public:
      void disp_area();
```

### Virtual Functions and Abstract Classes
A class is virtual if it contains at least one virtual function  
A base class can benefit from being virtual if there is a method all of its children should implement  
A ***pure virtual function*** is a virtual function that is not implemented in the base class, thus all derived classes must override the function. A pure virtual function is declared with the "virtual" keyword and is assigned with 0. Ex: virtual double ComputeArea() const = 0; declares a pure virtual function ComputeArea(). A virtual method does not have the =0 that the pure virtual one does.  
An ***abstract class*** is a class that cannot be instantiated as an object, but is the superclass for a subclass and specifies how the subclass must be implemented. Any class with one or more pure virtual functions is abstract.
