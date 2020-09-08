### Class Basics
Weekly labs
first one on Github, second on Docker
use Zybooks, section 10, due 9/17, ch. 2-5
office hours on Discord
look at course summary for a rundown of what needs to be done
webinars on tuesdays and thursdays

### C Basics
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
	
};
```
Structs are basically classes where every member is public. Structs are used to hold information that *everything* needs access to.  
Normally, you would put all of your structs in a file and then include that file in other code so everyone has access to it.  
We usually think of classes as objects and structs as data.  

### Chat
```
12:59:27	 From  Donald Huynh : Was poppin.
12:59:35	 From  Timothy D Wrenn : Can everyone hear me?
12:59:37	 From  Yunuo Zhang : hello
12:59:39	 From  Alex Seefeldt : yes
12:59:39	 From  Yunuo Zhang : yes
12:59:39	 From  Andrew Gazelka : yes
12:59:40	 From  Tyler Kawka : yes
12:59:40	 From  Chris : yeaj
12:59:40	 From  Matthew Meidt : We can
12:59:41	 From  Benjamin DeNio : yes
12:59:41	 From  Gavin Gray : yes
12:59:41	 From  Maximilian Risdall : yes
12:59:44	 From  Yunuo Zhang : yes
12:59:44	 From  Benjamin DeNio : yes
12:59:46	 From  Alex Seefeldt : yes
12:59:47	 From  Gavin Gray : yes
12:59:47	 From  Caleb Twiggs : Yep
12:59:47	 From  sam peterson : yeah
12:59:56	 From  Sam : yes
12:59:56	 From  Alex Seefeldt : it looks like a browser
12:59:57	 From  Matthew Meidt : Launch zoom
13:00:05	 From  Jess Moore : we see your chrome browser
13:00:36	 From  Tyler Kawka : yes
13:00:45	 From  Chris : heard it was great
13:00:48	 From  Donald Huynh : Pog
13:00:57	 From  Jess Moore : thank you :)
13:01:00	 From  Matthew Meidt : Appreciated 
13:01:05	 From  Samuel Williams : Awesome
13:01:27	 From  Caleb Twiggs : Much appreciated. Especially with all the craziness already happening in the world :)
13:03:42	 From  Yunuo Zhang : Can we use vole to finish lab?
13:03:47	 From  Yunuo Zhang : Or assignment?
13:04:06	 From  Maximilian Risdall : we also got an email with it I believe
13:05:46	 From  Alex Cheng : Docker on Windows is doable; I've done it before
13:05:52	 From  Cole Johnson : doesn't docker work well with WSL 2?
13:05:59	 From  Matthew Meidt : Good to know
13:06:03	 From  Alex Cheng : IIRC it does? Haven't tested it on WSL2 myself
13:06:08	 From  Alex Cheng : I know it fell on its face in WSL1
13:06:15	 From  Sam : Did he say it’d be better to run a linux vm on a windows machine and use docker there?
13:06:16	 From  Yunuo Zhang : There is an email to teach us download it?
13:06:31	 From  Matthew Meidt : Yep!
13:06:32	 From  Chris : yeah
13:06:32	 From  Tyler Kawka : no
13:06:32	 From  sam peterson : no it still shows the powerpoint
13:06:33	 From  Alex Seefeldt : we see the powerpoint
13:06:33	 From  Cole Johnson : No
13:06:34	 From  Gavin Gray : no
13:06:51	 From  Alex Seefeldt : yes
13:08:33	 From  sam peterson : will the webinars be at the same time as this is
13:10:34	 From  Frank Bender : will we be able to use ruby at all?
13:10:59	 From  Matthew Meidt : Yeah
13:11:01	 From  Frank Bender : rails is a framework
13:11:07	 From  Frank Bender : ruby Is a language like python
13:11:14	 From  Frank Bender : oh ok
13:11:17	 From  Frank Bender : sorry just joined
13:16:21	 From  Carter C Mintey : anyone else not able to see the pictures on the syllabus?
13:16:32	 From  Alex Cheng : Yes; the images themselves have incorrect permissions
13:16:32	 From  Tyler Kawka : yeah I cant see them
13:16:34	 From  Sam : I was having the same issues
13:16:44	 From  Yuji Itakura : Same here
13:22:50	 From  Michael Ung : Hi everyone
13:23:07	 From  Collin Bockman : Can the quizzes be taken outside of the webinar hours if we cannot watch a particular webinar live?
13:30:01	 From  Frank Bender : assignment
13:30:03	 From  Matthew Meidt : You delcare the variable as an int
13:30:07	 From  Matthew Meidt : And then assign the value 5 to the int
13:30:09	 From  Kevin Moonen : Declaring a variable named `x` and defining it to be 5
13:31:52	 From  Frank Bender : is there a constant declaration in C?
13:32:30	 From  Timothy D Wrenn : Yes there is a constant in C++. const int FUN = 5;
13:35:42	 From  Luke : is "x" still a constant even though it's not caps?
13:35:49	 From  Frank Bender : is there a difference between namespaces and objects?
13:35:59	 From  Timothy D Wrenn : Yes and yes
13:36:01	 From  Joe Cassidy : Can you declare multiple "using namespace X"?
13:36:03	 From  Dac Tran : is there a type associated with each namespace?
13:36:16	 From  Matthew Meidt  to  Luke(Privately) : Yes it is, the caps is a style guide
13:36:34	 From  Matthew Meidt  to  Luke(Privately) : const int X = 100; would be more stylistically correct
13:36:41	 From  Brandon Schenck  to  Luke(Privately) : yes it is. All caps is just a naming convention for constants
13:36:46	 From  Donald Huynh : You mean variable type?
13:36:52	 From  Dac Tran : yeah
13:37:08	 From  Timothy D Wrenn : std namespace
13:37:21	 From  Timothy D Wrenn : Objects cout, cin, endl, etc.
13:37:27	 From  Timothy D Wrenn : using namespace std;
13:37:32	 From  Timothy D Wrenn : std::cout
13:37:35	 From  Timothy D Wrenn : std::cin
13:37:42	 From  Timothy D Wrenn : std::endl
13:37:51	 From  Timothy D Wrenn : endl is the same as '\n'
13:38:30	 From  Frank Bender : so cout, cin and endl are objects and not methods?
13:38:44	 From  Benjamin DeNio : they are methods 
13:39:08	 From  Luke  to  Matthew Meidt(Privately) : is there an equivalent of a namespace in Java?
13:39:10	 From  Benjamin DeNio : youre just importing the methods from the std (standard) functions library
13:39:45	 From  Matthew Meidt  to  Luke(Privately) : I think classes correspond most closely to the concept in Java
13:39:48	 From  Michael Ung : I believe they are objects, std::cout is an ostream object.
13:39:55	 From  Oliver Cuzzourt : Aren't they objects and "<<" or ">>" are the methods / operations?
13:40:03	 From  Michael Ung : They are from the standard library tho so you are correct on that part
13:40:18	 From  Matthew Meidt  to  Luke(Privately) : But they would be public static classes
13:41:26	 From  Timothy D Wrenn : The insertion operator << and the extraction >> are methods which are part of the iostream library. In fact istream contains all the input operations. ostream contains all of the output operations. You can overload these operators for your user defined data types.
13:41:44	 From  Matthew Meidt  to  Luke(Privately) : So something like 
public NS1{
 public static double value(){ return 5;}
}
13:43:41	 From  Joe Cassidy : Can class methods belong to namespaces other than that of the class they operate on?
13:44:50	 From  Matthew Meidt  to  Luke(Privately) : public NS1{
  public static double value(){return 5;}}
public NS2{
  public final double X = 100;
  double value() {return 2*X;}}
}

public static void main(String args[]){
  System.out.println(NS1.value());
  System.out.println(NS2.value());
  System.out.println(NS2.X);
}
13:44:55	 From  Matthew Meidt  to  Luke(Privately) : Would be how you might do it in Java
13:48:09	 From  Matthew Meidt  to  Luke(Privately) : Oooo packages are the most direct equivalent

```
