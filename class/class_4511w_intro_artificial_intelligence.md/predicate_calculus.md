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
```There is a student who is tall and friendly```  
```Nobody likes broccoli```

### Order of quantifiers
```
∀x∃y Loves(x,y)
∃x∀y Loves(x,y)
∀x∀y Loves(x,y) everyone loves everyone
∃x∃y Loves(x,y) there are two people who love each other
```