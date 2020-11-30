# Strategy Pattern
A set of algorithms that can be used interchangeably. In sorting, for example, the strategy is based on how many items and how much is already sorted.  
Bubble sort is good for when data is already presorted, or partially presorted.  
Shell is for datasets with a certain gap size.  
Heapsort, quicksort, and mergesort are O(logn)  

---
For example, men have a goal of courting women. However, the method they use will be different depending on who they are, who the lady is, and the context. So we might have an abstract interface with the method court(), but the implementation and how it's carried out will be different based on each situation. The method court() for one might mean giving roses while court() for another might manifest as presenting a ring.  
---

Example of using the strategy pattern with a calculator
```
#include <iostream>
using namespace std;

class opInterface {
public:
	virtual void perfop (int left, int right) = 0;
};

class add : public opInterface {
public:
	void perfop (int left, int right) {
		cout << (left + right) << endl;
	}
};
		
class sub : public opInterface {
public:
	void perfop (int left, int right) {
		cout << (left - right) << endl;
	}
};
		
int main() {
	char op;
	int left, right;
	bool done = false;
	opInterface *operations[2];
	
	operations[0] = new add;
	operations[1] = new sub;
	
	while (not done) {
	
		cout << "Enter operation: ";
		cin >> op;
		cout << "Enter operand1: ";
		cin >> left;
		cout << "Enter operand1: ";
		cin >> right;
		cout << "Result: ";
		
		switch (op) {
			case '+':
				operations[0]->perfop(left, right);
				break;
			case '-':
				operations[1]->perfop(left, right);
				break;
			default : cout << op << " is unknown\n";
		}
	
		cout << "Enter y to continue: ";
		cin >> op;
		if (op != 'y')
			done = true;
	}
	
	return 0;
} // end main
```
 
Using the strategy pattern sometimes means that we are replacing places where we would normally use inheritance with composition of the object and the behavior that it uses. 
