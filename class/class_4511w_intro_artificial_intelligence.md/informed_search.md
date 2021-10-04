### Frontier
We explore along a frontier starting with the nodes closest to the start node and then expand the frontier along the cheapest routes. To do this, we sort the frontier costs and explore/expand the lowest cost node. If the closest frontier node happens to be a goal node, then you're done.  

### Uniform Cost
We use g(n) which is the cost so far from start to node n. 

### (Greedy) Best-First
Use an estimate heuristic h(n) which is the estimated cost from a node n to goal.  
We sort the frontier by estimated cost instead of realized cost. There's no guarantee on solution quality because h is an estimate.  

### Uniform Cost using h(n)
We use h(n) ~= A*, one of the first AI algorithms  
Uniform cost keeps track of the cost along the path. This cost so far along the path from *start* to node n can be represented as g(n)  
So we have true cost g(n) and estimated cost h(n)  
f(n) = h(n) + g(n) is the total solution cost  
Now we sort the frontier by f(n) costs. Some observations that can be made are that the g(n) cost will increase as you travel along, the h(n) cost will decrease, and the f(n) cost should remain fairly constant. When h(n) is 0 then A* is basically just uniform cost, and if h(n) is very large then we have an overestimate h(n) > h*(n). And is 0 <= h(n) <= h*(n) then A* is admissible and is guaranteed to find the optimal solution. It allows you to be faster in searching for your solution because it makes some assumptions and improves over uniform cost, g(n), which only operates on known knowledge. This is only true if h(n) is a good function that never overestimates and is fairly accurate. So we can see that for a good h(n), f(n) as a solution cost is better than g(n).  
h(n) must be an underestimate and must be positive.  

### A*
Optimality is the property of computation  
Admissiblilty guarantees optimal solution  
If h(n) is admissible, then the solution found by A* is cost optimal. ***h(n) is consistent if h(n) is always <= h(n') + c(n, n')***. This is just saying that h(n) is shorter than any other path thatgoes through other nodes n' to reach the goal.  
If h(n) is admissible, A* will find the cost optimal solution. For this to happen, h(n) <= h*(n).   
If h(n) is consistent, then the solution will be found as soon as A* begins expanding the first node (it is hard to find a function that is not consistent).  
Consistency is a subset of admissibility.  
  
A* is complete, meaning that existing solutions will be found, cost optimal (quality of solution, the set of best solutions), and optimally efficient (time optimal).  

### Weighted A*
f(n) = g(n) + w * h(n)

### AI Local Search
Gradient descent, **hill climbing**, not everything is visible. Local decisions are very cheap to make because you need very little information and effort to make them. There are local maxima, ridges, plateau, and stochastic choices.   
**Beam search** is another local search algorithm that aims to reduce the size of the search. In normal BFS, the frontier grows very fast. To limit this, you set a beam width that limits how many nodes are used from using every node in a layer to only using the best K nodes. Stochastic methods to choose. Beam search is not complete because it could possibly elimintate the solution at some level. You sacrifice accuracy for speed. One idea is that you could have iterative beam search where you start with choosing the k best, but if that doesn't work then you choose the (n - k) / 2 best nodes, and keep increasing up to n for the level so that the algorithm becomes complete. 

### Simulated Annealing
Comes from metallurgy where metals are harder to reshape when they cool down. This method changes the algorithm as time goes by. It follows a "cooling schedule." In the beginning, you move more randomly and quickyl and later on you move more slowly. Once you find the right direction, you are less likely to diverge off of the path. 

### Iterative deepening of A*
Can be used to save memory in A* because A* is fairly memory intensive. 

### Evolutionary Algorithms
**Genetic Algorithms** take the idea of randomness, inheriting DNA from parents, and fitness. 

### Questions
So if something changes and you have to re-estimate h(n), would you also have to re-sort the priority queue? How expensive is the calculation of h(n) compared to just using g(n)? One case in which something would change is if you realize the cost, g(n), along some route and now other nodes whose h(n) is dependent on that cost have to be re-estimated.  
How much knowledge of  
Stochastic? Random choice  
How could we best apply a strategy pattern towards solving different AI challenges?