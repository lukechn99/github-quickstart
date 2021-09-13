ethics  
should robots have autonomy to kill?  

### History
First coining of the term "AI" was in 1955. It proposed that every aspect of intelligence can be precisely represented by machine.

### Basics
An agent has perceptions and actions and can be judged based on performance metrics.  
most problems can be simplified into a graph with many states as nodes. With this simplification, solving a problem becomes traversing a graph and now we just need graph algorithms, information like directed vs undirected, cyclical vs acyclic, disjoint vs connected, etc.  
Problem graphs with a cycle are bad for solving, graphs with joined paths are still complex while graphs that can be represented as a tree are easiest to deal with.  
Specific problems will be represented in graph form with an initial state and terminal state(s). However, since there may be many terminal/goal states, it can bebetter to describe a "goal condition" and then there will be states that fit that condition.  

### Representation of Graphs
Commonly, a graph is represented as an adjacency table or nodes, however, in AI, the graph is commonly constructed during the search. The graph is not computed upfront.  
With no loops, DFS with backtracking will find solutions. DFS complexity depends on the length of the search path and is generall less expensive than BFS. BFS needs to keep track of the children and needs a lot of space to keep track of the width. When doing BFS, you're guaranteed to find the shortest solution because you are going from the center out. DFS might find a solution after going down one path but that path may not be the optimal one.  
State space should be connected for all states to be reachable.  

'''
[1][4][3]        [1][2][3]
[8][2][ ] --x--> [4][5][6]
[7][6][5]        [7][8][ ]
'''
These two states of the popular slider puzzle are actually disjoint. We can save a lot of time if we can find out whether or not the initial and final states for our problems are disjoint. 