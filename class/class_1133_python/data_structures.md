# 9/17/18 Data Structures

Review
Maximum recursion depth exceeded error:
# bug for infinite loop
# too many levels of recursion
# look up common python problems and solutions

When there is a recursive there must be an exit condition
gcd (a, b) = gcd (b, a%b)
Exit condition is 
	if b == 0 
	gcd (a, b) = a

Using print intermittently will help in troubleshooting, especially in recursive

Iterative
def gcd (a, b):
	while b != 0

Unfortunately the Euler method calls for re-assigning variables, use a temporary variable
# could you use randint() to generate random integers less than the greater of a and b and return true when it divides both a and b, find the greatest one?

Data Structures
We have used strings, numbers, and range()
Others are tuples and lists
These are all sequences

Immutable vs mutable:
Immutable means that once created it can’t be changed, only copied when you want to make a change

For a mutable, a change can affect other things
Ex. a = 1, c = a, then c = 1, but if a = 2 then c will also be changed

Lists are mutable, all other data structures are immutable

For string a = ‘hello world’

a[1] is e

a[0] is not w that is why it is immutable?

List [element, element, element]
a = [1, 2, 3]
b = a * 3
What will b be?

b = [1, 2, 3, 1, 2, 3, 1, 2, 3]

If c = [a] * 3
c = [[1, 2, 3], [1, 2, 3], [1, 2, 3]]
