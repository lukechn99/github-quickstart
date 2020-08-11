# 9/12/18 Functions

What should we be doing for homework?
Can you harm your computer by accident through writing something in Python?

Function
```
def foo(a, b):
	return(a + b)
```
function foo with arguments a and b, a and b have no value yet  
now you can use this as a function and call it later:
```
myvalue = foo(10, 1000)
```
now a and b are defined within the function and have a value. myvalue = foo(10, 1000) will yield 1010 as per instructions of the function
if you call a or b outside of the function it will show an error, this is because functions are input output. 
numbers can be input and then they will give an output, but they cannot be taken out. This is called __scoping__
another function also using a and b can also be written and a and b will not intersect
you can also make a function inside of a function, but you can’t call the inside function

Recursive (chapter 4)
```
def fact(n):
	if n == 1:
		return (n)
	else:
		return (n * (n - 1))
```
when you can simplify the problem then factorial is helpful, like factorials above
the function name fact is made up and could be anything else
```
x = fact(10)
print(x)
```
when you get to very large numbers, this way is not as efficient

Lab
Make a square with sides 2, and the circle inside the square has radius 1
Ratio of the area of the circle to the area of the square
Monte Carlo gives random numbers, if you ask for enough random points then it can model the ratio between the square and the circle

To call a random number:

```
import random
	random.random()
```
this calls the package random, and the function from the package random
random.random() automatically assumes [0, 1), you can also change the range

# or 

	random.uniform(a, b)
# where a is a minimum and b is a maximum

# or

	random.randint(a, b)
# gives an integer

Counter, for a < 1000
a = a + 1

You do not need to make a physical circle. Instead you  can generate random numbers between 0 and 1 for x and y and then use pythagorean theorem to determine if the triangle they form has a hypotenuse greater than the radius of the circle. Using two counter you can count how many times the random point lands within the circle versus when it is within the 1 by 1 square. 

Machine epsilon extra credit
1.0 = 1.0 + E
What’s the largest E so that the computer will still think it is 1.0
	Start with E = float 1.0, for 1.0 + E > 1.0 
	E = 0.5 * E
