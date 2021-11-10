# Machine Learning
Always about minimizing error or loss. It is optimization.  
What is the error, loss, and technique?  

Is SVD machine learning? Is it optimization? Does there need to be learning from examples?  

Machine learning: **The system tweaks the model due to some stimuli so that the model is trained**  

Learning to rank, in ranking, since everything is relative, the loss function is no longer just the predictions but the error in the ordering. You want to optimize for top-k precision. You can do this by looking at the top-k pairwise.  
```
expected        actual
a               a
b               c
c               b
d               d
e               g
f               e
g               f
h               j
i               h
j               i

out of the 45 possible pairings, the actual output gets 40/45 correct
```
Nowadays, nDCG or MAP is a better measure of how good the top-k are. We can use nDCG in machine learning and optimization by optimizing for nDCG for a top-k list. Or rather, a normalized discounted cumulative loss function is more accurate since we're trying to minimize nDCG. 

Learning to predict

### Multi-armed Bandit Approach to Machine Learning
Assumes the best solution may be a statistical mix of solutions. You can either keep score of each algorithm or the combination that brought about the hit.  
There are a family of multi-armed bandit algorithms that describe how you explore the space with a balance between **explore and exploit**. More exploration helps establish the space faster. But some services don't want to waste time by exploring and wants to exploit right away. The multi-armed bandit used in conjunction with looking at what you've done apart from the system can help hone in on your interests. 

### Reinforcement Learning
Which things I did contribute to the goal? Goal can be to keep people on the site, better conversion rates, short term volume, etc. You could even optimize something like raising peoples' incomes as a social media platform so that they have more to spend on you. 