### Representing a problem
Representing a problem as a graph of states, we can find the solution by soving the graph. Some questions to answer then are: 1). how do we keep track of the parent in order to recreate the solution path and 2). where do we store the graph.  
Uinformed search algorithms don't care about the specifics of the problem as opposed to using problem specific details to guide the search.  

### The different algorithms
In DFS we store everything in a stack and only store as we go, in BFS we store everything in a queue and only store as we go, in Uniform Cost (Dijkstra's) we put everything into a sorted queue (this gives optimal cost solution), in bi-directional search you know the goal node and work in both directions from start towards end and end towards start.  

### Properties of the search algorithms
No matter the algorithm, some properties that hold are: 1). it is complete, a.k.a. it will *find* a solution if it exists 2). cost optimality (optimal is a set of best solutions, optimum is the single best), time, and space  

### Which one to use?
DFS is best for memory, BFS and UC are best for performance (finding optimal solutions) but are terrible for time-space complexity. DFS can be made slightly better by having more awareness of the problem and setting a depth limit or multiple depth limits that could iteratively increase. The depths are used to start backtracking when hit. Bi-directional search works well when there's a funnelling point in the middle so that the two search paths can converge.  

### Search space
Graphs can be expanded into a tree