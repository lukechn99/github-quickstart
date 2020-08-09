# 9/10/18 Strings, loops, and Turtle  

A loop is an action that is repeated until a condition is met. A few different loops are the "for" loop and "while" loop. These two can often be configured to
replace and be substitutes for each other. 



## What are arguments or functions?
Is turtle a large program that was previously written? Where is it called/imported from? The internet? The initial download file?
Compute pi using programs

To take apart a number like 314 you can use modulus arithmetic
314 % 10 will give 4
31 % 10 will give 1

How do you make sure your reader knows what you’re doing?
Use comments #
For a function usually write “def function(argument)”

## Loops

Draw a square

# first import and then create the turtle. Here you can name, give speed, give color to the turtle
# drawSquare is the function name so that you can call it up again later
# myturtle is not the name, it is the name of a parameter

import turtle
bill = turtle.turtle()
# turtle.turtle() is moduleName.function() this calls the function “turtle” from the module “turtle”
# the import can also be imported as “from turtle import *”
def drawSquare(myturtle, l):
# the instructions needed are left 90 degree turn and forward for a distance
	for i in range(4)
# the range can have up to 3 values, a beginning, a step and an end, or just beginning and end
		myturtle.forward( l )
		myturtle.right( 90 )
# range( 4 ) means range ( 0, 4 ), range can also be written range( 0, 10, 2 ) where it will start at 0 and end at 10 and move 2 at a time. It will finish as soon as it reaches 10 (or any end)
# make sure to write zeroes with a slash

This should create a square


Strings

“Abc7d!” is a string
Single quotes can also be used, but it must be consistent
Double quote cannot have a double quote as a part of the string inside, but you can use a single quote inside
Ex. “abc”def” python will not know where the string begins or ends, instead use ‘abc”def’

>>> input(‘type a number…’)
type a number… 534

Then 534 is stored as a string, integer computations cannot be done on the string, to do integer operations you have to convert it into an integer

a = ‘534’

You can call pieces of the string by using brackets

a[0] = 5
a[-1] = 4

Using 1 in the brackets calls up 3, 2 calls up 4, -2 would call up 3, and -3 would call up 5
