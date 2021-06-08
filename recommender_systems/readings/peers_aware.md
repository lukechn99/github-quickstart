# PARS: Peers-aware Recommender System [source](https://dl-acm-org.ezp3.lib.umn.edu/doi/10.1145/3366423.3380013)
*Huiqiang Mao, Yanzhi Li, Chenliang Li, Di Chen, Xiaoqing Wang, Yuming Deng*

This paper suggests that items are not to be looked at in isolation but rather with regards to its peers. For example Coke will be considered with close substitute Pepsi. 

Given historic recommendation lists, new permutations of their items are generated. The permutation is just a set of the items from the historic lists arranged in different ways. Each item in the permutation is rated on the scale of 0-1. A bunch of contraints are applied to determine the best choice. The permutations form an augmented matrix.  
The problem is mainly defined with 3 variables: lambda (0<l<1), y(ki) is a binary variable, x is something else.  
The algorithm uses a preference estimation subproblem, recommendation optimization subproblem, decomposition algorithm
