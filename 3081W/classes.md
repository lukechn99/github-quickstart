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

### Compilt time binding, run time binding, access specifiers
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
