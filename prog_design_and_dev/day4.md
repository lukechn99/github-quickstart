# pointers and stuff
```
using std::endl;

int main() {
	int numbers[10] = {1, 6, 3, 4, 5, 6, 7} ;

	int x = 3;

	int * p;

	p = &x;

	cout << *p << endl;			// returns 3
	cout << *numbers << endl;	// returns 1

	p = numbers;
	cout << *p << endl;			// returns 1

	cout << (*p + 1) << endl;	// returns 6
	
	for (int i = 0; i < 10; i++)
		cout << *p++ << endl;	// p is a pointer on the array
	
	return 0;
}
```
### public access specifier vs private?
https://www.learncpp.com/cpp-tutorial/83-public-vs-private-access-specifiers/
In classes, members are private by default, but we can label them as private or public using access specifiers.  
In total, there are 3 access specifiers  

### protected vs private?
https://www.learncpp.com/cpp-tutorial/115-inheritance-and-access-specifiers/
The protected access specifier is only used in an inheritance context.
Protected allows all class members and derived classes to access it, but they are not accessible from outside the class.  
Private access specifier does not allow derived classes to use the private member.

### does a struct enforce encapsulation?
https://www.justsoftwaresolutions.co.uk/cplusplus/struct_and_class.html
Encapsulation is achieved by making all data members private and giving them access methods like getters and setters.  
A struct does not automatically enforce encapsulation, but data members can be made private so that the struct is encapsulated.  

### compare and contrast the 'has a' and 'is a' relationship between classes  
The is-a relationship refers to inheritance where you can check if a class is derived from another class.
This derivation would be called specialization.  
Has-a relationship is not about inheritance, rather it's about composition. If class A has-a class B, then one of A's  
members is an instance of class B.
