# Predicate Calculus and 1st Order Logic
Predicate calculus has more notations and allows for more complex and expressive sentences. However, predicate calculus has higher computational complexity. You can convert from prepositional to predicate calculus and back. 

### Predicates
```Dog(Fido) -> Fido is a dog``` Fido is a constant and dog is a predicate.  
You can have a unary predicate like Dog(x) where constant x is a Dog. Unary just means is or is not. You can also have binary or even n-ary. 

### Notation
Existential quantifier, universal quantifier, connectors (v, ^, ~, ->), constants, variables, predicates, and functions (which are seen as arguments for predicates)

### English to Predicate
```No one would harm a dog``` Here, "one" is the person, "harm" is the predicate, "a" represents any, "and" dog is a predicate
```~(∃x Harm(x, dog))```  
Maria Gini would say 
```
~[∃xPerson(x) ^ ∃yDog(y) ^ Harm(x,y)]
> ∀x~Person(x) v ∀y~Dog(y) v ~Harm(x,y)
Use a trick like ~A v ~B v C -> (A ^ B) -> C
> ∀x∀y[(Person(x) ^ Dog(y)) -> ~Harm(x, y)]
```  
We use the fact that ```~∃ = ∀```.  

Another sentence, ```There exists only one person that hates dogs```  
We can see that there exists at least one person, but only one that hates dogs.  

```All pets are cats or dogs```  
∀xPet(x) -> Cat(x) v Dog(x)  
∀x ~Pet(x) v Cat(x) v Dog(x)

```There is a student who is tall and friendly```  
```Nobody likes broccoli```  

### Order of quantifiers
```
∀x∃y Loves(x,y) everyone has someone who loves them
∃x∀y Loves(x,y) there is someone who loves everyone
∀x∀y Loves(x,y) everyone loves everyone
∃x∃y Loves(x,y) there are two people who love each other
```

### Unification
Unification only works when the predicates are the same

```
1). All men are mortal
2). Socrates is a man
Is Socrates mortal?
```
Generalized modus ponus (if A->B and A, then B)
```
∀x man(x) -> mortal(x)
man(Socrates)
prove mortal(Socrates)
```
With modus ponus, we can say that if man(x) then mortal(x), but we cannot directly say man(Socrates) then mortal(Socrates) without *unification*. Unification takes a variable and a constant and unifies them together. It is not an assignment process, but rather you are saying they can be the same. 
```
{x/Socrates} so we can safely say man(Socrates) -> mortal(Socrates)
```
Given man(Socrates) and man(Plato), you cannot unify them.  
You can also unify two variables.  
You cannot unify a variable to a constant twice. 
```
man(x) and man(f(x)) can be unified, variable and function
{x/f(w)}
man(x) and man(f(Socrates)) can be unified, variable and function of constant

Function and constant always fails

man(f(Socrates)) and man(f(x)) can be unified
{f(Socrates)/f(x)}
Two functions of constants always fails
```

### Resolution with Predicate Calculus
```
1). 
A(x) v B(y), ~A(P)
------------------
{x|P}, B(y)

After unifying x and P then we can cancel out the first part and are left with B(y)

2).
A(x) v B(x,y), ~A(P)
------------------
{x|P}, B(P,y)

3).
A(x) v B(x), ~A(z)
------------------
{x|z}, B(z) or B(z)
```

### CNF
Steps
1. eliminate ->
2. move negation in front of predicates
3. standardize variables apart (variables from combined expressions might have the same name you must change their name to differentiate)
4. replace ∃ variables with skolem constants or skolem functions (∃xA(x) becomes A(S<sub>0</sub>)). And if there are multiple expressions that need a skolem constant, you can use S<sub>1</sub>, S<sub>2</sub>, etc.
5. drop ∀
6. distribute v over ^ to end with conjunction of disjunctions (vvv) ^ (vvv)
7. divide expression, dropping ^
```
example
∀x∃y[A(x,y) v C(y)] this means y can be different depending on x
We skolem-ize it, but y depends on x, so y is a function of x and we use skolem function S(x) 

∀x[A(x,S(x)) v C(S(x))]
```
```
example

KB:
if a course is easy, some students are happy
if a course has a final, no students are happy

show:
if a course has a final, the course is not easy

write expressions:
∀x easy(x) -> ∃y happy(y,x)
∀x∀y final(x) -> ~happy(y,x)
∀x final(x) -> ~easy(x)

simplify:
1).
∀x∃y easy(x) -> happy(y,x)
∀x easy(x) -> happy(S(x),x)
```
