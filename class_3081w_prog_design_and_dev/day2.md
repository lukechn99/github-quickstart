### exercise:
```
#define FUN = 35 // compiler instruction does not need ;
int main() {
	std::cout << FUN << std::endl;
	return 0;
}
```
This causes a syntax error because FUN is actually "= 35" not "35", and when it executes it will not understand why there is a "="  

---
### Classes exercise
are a type of struct, a data type
write a class called Circle that has methods to calculate the area, diameter, and circumference, provide getters and setters
```
// this is my first attempt without C syntax
class Circle {
	private double radius; // the programmer does not need to directly access radius
	public void setRadius() {}
	public double getRadius() {}
	public double getDiameter(double radius) {} // this is public, we need public so the programmer can access info
	public double getArea(double radius) {}
	public double getCircum(double radius) {}
}
```
```
#define _USE_MATH_DEFINES

class Circle {
	public:
		circleClass();
		void setRadtius();
		double getRadius();
		double getDiameter();
		double getArea();
		double getCircumference();
	private:
		double radius;
		
}
```
Observer pattern
Factory pattern
Singleton pattern
etc.

### Things you need
Preprocessor directive
```
#include < > // header file
#include " " // programmer defined header file
#define // define constants at compilation
#define PI 3.141592 // this is right
#define PI = 3.141592; // is wrong
```
could we give shortcuts with a #define?

only one driver routine

---
