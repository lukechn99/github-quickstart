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

### Rules
1. consistency
2. if its in predicate and not changed, should not be in effect. If changed, it should be in effect
3. toggle predicates that are opposite: holding() vs emptyhand()
4. when a robot grabs an object, does the object have its own coordinates?

### Semantic Network (knowledge graph)
This is represented like OOP  
Clyde is a bird, a bird has wings, so we don't need to say "Clyde has wings"  
What if Clyde only has one wing? Then we have to describe it separately and say that Clyde has one wing.  
A bird is an animal. However Clyde:Bird::Bird:Animal is not true because Clyde is an instance while Bird is a subclass of Animal.  
When we recognize a class, we can do so in two ways: one is intensional which relies on one prototype, another is extensional which is the whole set of instances.  
At what point does Clyde not become a bird anymore?  

Suppose Oscar is an ostrich, ostriches are endangered, and ostriches are studied by enthomologists.  
Then does that mean Oscar, as an individual, is endangered and studied by enthomologists? No. A property of the class does not necessarily apply to each instance of the class.  

We have representations as "object attribute value"  
Is the semantic network a tree or a graph?

Some **properties** include exceptions (Clyde might not have two wings like other birds), there is inheritance (so you don't need to redundantly describe)  

In general we use trees for these networks because typically, classes, subclasses, instances, and properties typically operate in a tree-like structure, especially when you think about subclasses and instances using their parent properties. However, it can get complicated when an instance belongs to two classes because then you have two choices when inheriting properties. One way we can get around this in knowledge graphs is to do a DFS or BFS and see which class comes first, in other words, take the closest available property.  

Ontologies: structure in knowledge information, how do structure the knowledge we have. 

```
Example: 

Table: 
    Properties: legs, top, etc.
```

### CYC
Common sense knowledge
- Theory
- write a lot of rules/examples
GPT-3 for learning

### Questions
Symbolic representation vs neural networks