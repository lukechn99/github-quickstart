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

### Questions
So if something changes and you have to re-estimate h(n), would you also have to re-sort the priority queue? How expensive is the calculation of h(n) compared to just using g(n)? One case in which something would change is if you realize the cost, g(n), along some route and now other nodes whose h(n) is dependent on that cost have to be re-estimated. 