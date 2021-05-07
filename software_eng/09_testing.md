# Testing
Goals: specification testing, defect testing, validation testing (are we building the right product?), verification (are we building the product right?)  
```A failing test is a successful one```  

Important parts include software inspections and software testing. Inspection checks if the best possible methods are being used. And then software testing is for 
Inspections are for testing against the SRS, software architecture, UML design models, database schemas, and program.  
Software testing on the other hand, means testing cases, data, and results throughout the implmentation.  

### Stages of Testing
Development Testing: "write and test" things like unit tests  
Release Testing: A testing team tests the complete system  

### Black Box White Box
With a black box, we don't need to know the implmentation, only what the input and output are supposed to be. Typically this means user acceptance testing and system testing.  
White box testing is more like unit testing and integration testing, knowledge of the code is needed. 

### How to do unit testing
Do the basic flow first and then move onto edge cases
Test each statement at least once, this means every loop and every call. We want to have a test for every possible return value.  
```
Statement1;
Statement2;
if (x < 10) {
  Statement3;
}
Statement4
```  
The code above needs at least two test cases. The first path that a test case would go through is ```Statement1 -> Statement2 -> x < 10 == False -> Statement4``` and the second path is ```Statement1 -> Statement2 -> x < 10 == True -> Statement3 -> Statement4```. Structured basis testing only needs to touch every line of code, But for defined use combination, we need to add more tests. For example:  
```
if (condition1) {
  x += 1
} else {
  y += 1
}
if (condition2) {
  y += 1
} else {
  x += 1
}
```  
With Structured base testing, we only need two tests; one for true true and one for false false. For defined use, we need to test 4 cases which are  true true, true false, false true, and false false. 

### Equivalence Partitioning
A good test case covers a large part of the possible input data, if two cases have the same error then you probably only need one of them. These two ideas together means that we try to cover as much as possible with the fewest number of cases. We map possible inputs to possible outputs using partitions. Group sections of input data so that they are in related partitions. Then group the output data into related partitions as well.  
```
Statement1;
Statement2;
if (x < 10) {
  Statement3;
}
Statement4
```  
In the code above, you would proabably partition input into input that's less than 10 and input that's greater than or equal to 10. 

### Testing with Data States
You don't want data defined more than once, defined and then exit out, or defined and then killed. Logic errors like killing a variable and then trying to use it or using it before it's defined. 

### Error Guessing
Try to guess where errors might be with intuition to target areas that are susceptible to error. 

### Boundary Analysis
Think about one-off errors. Test below the boundary, at the boundary, and above the boundary.  
<------0-----------n------> test -1, 0, n/2, n, n+1  
Pay attention to compound boundaries. Sometimes your individual values will be okay, but when you add two values together you get something longer than an int, or more than a byte, or some other kind of overflow that might mess up the data or index out of bounds because of two or more pieces of data together. 

### Classes of Good Data
You should aim to test the nominal case, maximum configuration, minimum, and old data. 
