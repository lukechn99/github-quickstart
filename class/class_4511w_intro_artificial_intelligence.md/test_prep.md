### Chapter 7 (Propositional Calculus): only 7.3, 7.4, 7.5 up to 7.5.2 (included)
Resolution: How to do it?
1. Eliminate <=>
2. Eliminate =>
3. Move negations in front of literals
4. rewrite as conjunctions of disjunctions A v (B ^ C) -> (A v B) ^ (A v C)

### Chapter 8 (First-order Logic): only 8.1 and 8.2

### Chapter 9 (Inference in 1st Order Logic): only 9.1, 9.2, 9.5 up to 9.5.3 (included)
We are sometimes faced with first-order inference problems, we can solve them by converting to propositional inference.  
This is where we do unifications {x/A}, Skolemizations, and other things. Take a look at [predicate calculus](/predicate_calculus.md) which has more details. 

### Chapter 10 (Knowledge Representation): only 10.1 and 10.5.1 (this is Chapter 12 in the 3rd edition)
**10.1 Ontological Engineering**
Representing abstract concepts with Events, Time, Physical Objects, and Beliefs. 

**10.5.1 Semantic Networks**  
Relationships include member of, is a, subset of, etc.
![semantic network](https://github.com/lukechn99/github-quickstart/blob/master/class/class_4511w_intro_artificial_intelligence.md/semantic_network.png)

### Chapter 11 (Planning): only 11.1, 11.2.1, 11.2.2 (this is Chapter 10 in the 3d edition)
Air cargo problem:  
```
Figure 11.1 shows an air cargo transport problem involving loading and unloading cargo and flying it from place to place. The problem can be defined with three actions: Load, Unload, and Fly. The actions affect two predicates: In(c, p) means that cargo c is inside plane p,
and At(x,a) means that object x (either plane or cargo) is at airport a. Note that some care must be taken to make sure the At predicates are maintained properly. When a plane flies from one airport to another, all the cargo inside the plane goes with it. In first-order logic it
would be easy to quantify over all objects that are inside the plane. But PDDL does not have a universal quantifier, so we need a different solution. The approach we use is to say that a piece of cargo ceases to be At anywhere when it is In a plane; the cargo only becomes At the
new airport when it is unloaded. So At really means “available for use at a given location.” The following plan is a solution to the problem:
[Load(C1,P1,SFO),Fly(P1,SFO,JFK),Unload(C1,P1,JFK),
Load(C2,P2,JFK),Fly(P2,JFK,SFO),Unload(C2,P2,SFO)]
```
![aircargo](https://github.com/lukechn99/github-quickstart/blob/master/class/class_4511w_intro_artificial_intelligence.md/aircargo.png)

**Forward state planning**  
We solve planning by applying heuristic search algorithms. We take the initial state and transform it by unifying it with actions to search forward for goal states, or we can use  
**Backward search** (regression search)  
Starts at the goal state and moves backwards. 


### Tidbits
look at aircargo problem in textbook

Search: state space representation for representation and search algorithms for reasoning

Logic: logic for representation and resolution for reasoning

Planning: action schema for representation and forward/backward search for reasoning

Resolution (will be predicate calculus), planning (representation, how do you write schemas), semantics (knowledge graphs, ontologies)
How did we do forward search or chaining and backward search? Study this because I have no idea. 

Study plan: look through slides
then textbook

Every variable must be quantified, the safest place to put it is at the beginning
