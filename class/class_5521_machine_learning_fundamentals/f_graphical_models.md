# Graphical Models

The goal of this is to infer hidden variables with visible ones: Movie preferences inferred using ratings, diseases using symptoms, an original image using noisy ones.

We represent the world as a collection of random variables $X_1, X_2, ...$ and the joint distribution $P(X_1, X_2, ...)$

There are directed graphical models (like Bayesian networks) which emphasize relationships between random variables as *causal*, and undirected graphical models (like Markov random fields) which can express soft constraints between variables (like pixels in an image)

## Directed Graphical Models

Random variables have causal relationships. We create a node for each random variable and edges show the dependency between variables. Since they are directional links, the origin of a link is the parent and the destination of the link is the child.

## Decomposition

$P(X, Y, Z) = P(Z|X, Y)P(X, Y)=P(Z|X, Y)P(Y|X)P(X)$

Then based on this decomposition, we have the following links:

X -> Z

Y -> Z

X -> Y

Nodes which don't have a parent are decomposed as $P(N)$ by itself. Nodes that have parents are written as $P(N|P_1, P_2, ...)$

An example of this could be using variables:

$\{fever, cough, fast \ breathing, shaking, nausea, vomiting, pneumonia, flu, cold\}$

We can determine the $P(flu = 1 | cough = 1, vomiting = 1, shaking = 0)$ assuming binary variables. As the number of variables grow, this can become unfeasible to calculate. In order to make this more feasible, we can decompose into simpler terms. In best case scenario, all variables are independent and we can decompose the joint probability into a product of independent probabilities.

## Conditional Independence

X and Y are independent if $P(X,Y)=P(X)P(Y)$

X and Y are conditionally independent given Z if $P(X|Y,Z)=P(X|Z)$

Relationships are either causal or diagnostic. The probability of having wet grace *because* it's raining is causal, but the probability of raining given that there is wet grass is diagnostic.

The different structures that we can see in graphs are 1). head to tail, 2). tail to tail, and 3). head to head.

In head to tail, we have a linear causal chain that might look like cloudy -> rain -> grass wet. Then we take a look at $P(cloudy)$, $P(rain|cloudy)$, and $P(wet|rainy)$. For this problem, given that it is raining, it does not matter whether it's cloudy or not when we are concerned about whether the grass is wet. Then wet grass is conditionally independent of cloudy weather. This is conditional independence.
The steps used to resolve a head-to-tail are factorization, conditional independence, propagation of information, causal inference, and diagnostic inference through Bayes' rule.

In tail-to-tail, we have one parent node and two children