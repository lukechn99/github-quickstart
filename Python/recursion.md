# 9/14/18 Recursion

Recursive:
Add numbers in a range, this requires a certain design pattern
Add all the numbers from 1 to 200

def addnumb(low, high):
	a = 0
# a is the initial value outside of the loop
for i in range(low, high):
# for i in range means that while i is in the range. Range is a function that counts in increments of 1 by default from the low to high. You can also tell it to count from some number to another number by a step
		a = a + i
	return(a)

Multiply all the numbers from 1 to 200

Def multnumb(low, high):
	a = 1
for i in range(low, high):
		a = a * i
	return(a)

Def countprimes(low, high):
	count = 0
	For i in range(low, high):
		if isprime(i):
			Count += 1

