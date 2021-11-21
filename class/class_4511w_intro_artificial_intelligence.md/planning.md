# planning

Search and logic representation  
can we use logic to represent states?

logic is static, the validity of a statement does not change

```
                        [A]
[A]                     [B]
[B]   [C]       ->      [C]
--------------      --------------
initial state       goal state
```

How can we represent this as logic? One way is to include the state number in the predicate:  

Block(A)  
Block(B)  
Block(C)  
On(B, Table, S<sub>0</sub>)  
On(A, B, S<sub>0</sub>)  
On(C, Table, S<sub>0</sub>)  

### Describing actions
Another way is to describe actions. We have a precondition and an effects section. We add and delete expressions from the sentence in the effects section.   
Grasp(x, r, )  
Precondition: Clear(x) ^ Handfree(r) ^ On(x, y)  
We see that there are only conjunctions, no negations,  
You delete negative expressions and add 

### Search
We have an initial state, and then do backward search from the goal state. This makes