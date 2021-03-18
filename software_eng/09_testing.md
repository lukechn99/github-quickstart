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

### Testing with Data States
You don't want data defined more than once, defined and then exit out, or defined and then killed. Logic errors like killing a variable and then trying to use it or using it before it's defined. 
