### Defining the Problem
Example: map coloring problem - How many colors do you need for a map based on coloring constraint that no adjacent regions have the same color?  
1). Define variables (regions)  
2). Define values (colors, discrete or continuous)  
3). Define contraints (unary, binary, n-ary, global)  
a. unary 
b. binary
c. n-ary means variables
d. global means all values are different
e. linear and non-linear constraints  

### Algorithms
Algorithms take into account soft and hard constraints which can either be preferences or requirements respectively.  
Some **properties** that are relevant include **completeness** (if there is a solution, the algorithm will find it; in terms of constraint satisfaction, it means that every variable gets a value that satisfies constraints), **cost optimality**, **consistency** (all constraints are satisfied), **complexity** of algorithm.  
Most constraint satisfaction problems can be represented as search algorithms. One way to represent the map coloring problem as a search is to have alternating layers of variables and possible values. This can be solved with a DFS. For this DFS, all solutions are the same cost because it is bounded by the number of variables and values.  

### Heuristics
While A* uses domain dependent heuristics (context is needed to make predictions), constraint satisfaction should use domain independent heuristics to *speed up the search*.  
One such heuristic could be to *select the **variables** with the smallest number of possible values to explore* first because with less values to explore, the possibility of failing faster and moving on it higher as opposed to testing many values early on.  
Another heuristic is to *start with the **variables** with most constraints*. This also encourages failing faster.  
Another heuristic is to *select the **value** with least constraint because this is the one that is most likely to succeed*.  

### Crypto Arithmetic
```
    TWO
  + TWO
--------
   FOUR
```
Assign a digit to each letter to satisfy the arithmetic, first digit can't be 0, must satisfy arithmetic, and are all different.  
```
Set-up
T != 0
F != 0
O + O = R + C1 * 10
W + W + C1 = U + C2 * 10
T + T + C2 = O + C3 * 10
F = C3

Solve (for fun)
T + T + C2 = O + F * 10
>> C2 = O + F * 10 - T - T

W + W + C1 = U + C2 * 10
>> W + W + C1 = U + (O + F * 10 - T - T) * 10
>> C1 = U + (O + F * 10 - T - T) * 10 - W - W

O + O = R + C1 * 10
>> O + O = R + (U + (O + F * 10 - T - T) * 10 - W - W) * 10
>> O + O = R + (U + (O + 10F - 2T) * 10 - W - W) * 10
>> O + O = R + (U + 10O + 100F - 20T - 2W) * 10
>> O + O = R + 10U + 100O + 1000F - 200T - 20W
```
We would choose to start with variable T or F because it has the most constraints (can't be 0)

### Questions
So a constraint satisfaction search really just is a permuations expansion with hueristics/constraints?  
