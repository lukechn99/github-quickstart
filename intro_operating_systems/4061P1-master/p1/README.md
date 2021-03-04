# 4061P1
test machine: csel-kh1250-15

date: October 7, 2020

name: Joseph Annareddy, William Chan, Luke Chen

x500: annar004, chan1766, chen5216

## Purpose
Count words in plaintext files using the MapReduce algorithm implemented on a single machine.

## Compiling
```make``` or ```make mapreduce```

## What exactly our program does
Our program implements the mapreduce algorithm as specified in the project description.
To run the program (after compiling as shown above), ```./mapreduce #mappers #reducers inputFile```,
where ```#mappers``` and ```#reducers``` are natural numbers such that ```#mappers``` is greater than or equal to ```#reducers```,
and ```inputFile``` is a valid path to a plaintext file.  
From the root directory, a sample run can be invoked with ```./mapreduce 5 2 test/T1/T1.txt```  or ```make t1``` to run  

## Assumptions
No assumptions outside the project specifications were made.

## Contributions
### Joseph Annareddy
mapper.c

### William Chan
mapreduce.c

### Luke Chen
reducer.c
