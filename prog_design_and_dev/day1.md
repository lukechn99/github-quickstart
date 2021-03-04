### Class Basics
Weekly labs
first one on Github, second on Docker
use Zybooks, section 10, due 9/17, ch. 2-5
office hours on Discord
look at course summary for a rundown of what needs to be done
webinars on tuesdays and thursdays

### C++ Basics
C++ has mutable strings
C++ v11 has auto-keyword which does runtime binding of variables, like Python
C++ does not have a garbage collector, you must release memory to avoid a memory leak
```
// create a pointer to memory
new *p = new int;
// this allocates 4 bytes

// delete after use to free space
delete p;

new *p = new int[25];
// allocates 25 ints for an array, or 100 bytes

delete [] p;
```
C++ has pass by value *and* pass by reference, pass by reference allows you to change the original variable
C vs. C++ strings, C++ strings are objects and can use overloaded operators (+, -, <, etc.)
importing your own library uses ""

### Namespaces in C++
```
// C++ has constant operators
const int FUN = 5
```  
  
scope is where the var is known
scope resolution operator ::
a namespace is a collection of information/coherent entities
the std namespace includes cout, cin, endl, etc.
without "using namespace std" then you would have to use std::cout
endl is the same as '\n'
```
#include <iostream>
using namespace std;
namespace ns1{
	int value() { return 5; }
namespace ns2{
	int const x = 100;
	int value() { return x*5; }
int main() {
	cout << ns1::value() << '\n';
	cout << ns2::value() << '\n';
	cout << ns2::x;
```
Tim Wrenn: The insertion operator << and the extraction >> are methods which are part of the iostream library. In fact istream contains all the input operations. ostream contains all of the output operations. You can overload these operators for your user defined data types.

### Aggregate Data Types
Structs and Classes
```
struct {
	members;
}
```
struct placement matters, place before functions that use it, if placed inside, only that function can use it
you can create very advanced structs:
```
typedef char String20[21];
enum HealthType {Poor, Fair, Good, Excellent};
struct {

}
```
structs can be nested within each other, like folders

Classes
```
class ClassName {
	private:

        public:

};
```
Structs are basically classes where every member is public. Structs are used to hold information that *everything* needs access to.  
Normally, you would put all of your structs in a file and then include that file in other code so everyone has access to it.  
We usually think of classes as objects and structs as data.  

