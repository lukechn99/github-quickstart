### Some simple associated math
P(A && B) / P(A) will tell you what proportion of those who bought A also bought B with A. This can work in some cases, but would not work if B was simply a very popular item that is always being purchased anyways.  
We want to look at the probability of buying A and buying B as independent purchases and then the probability of buying A and buying B together:  
P(A && B) / (P(A) * P(B)) this is called "lift"  

### Business rules
We should also program in common sense to recommender systems: don't recommend things they're already buying, don't suggest inappropriate things, things that are out of stock, things that lose money, think about who the customer is, recommend from a pool of items that need to go, recommend items that lead to future purchases, etc.  

### How to suggest "product B"
B could be a product that extends product A, typically bought after buying product A  