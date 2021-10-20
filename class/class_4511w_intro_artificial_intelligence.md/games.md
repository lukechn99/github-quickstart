### Properties of Games
1 or more opponents  
Observable (chess) and unobservable (poker)  
Zero sum games (1 winner 1 loser)  
Perfect information  

### Modelling the Search Process
Initial state  
Actions  
Terminal test: can be easy to find for some games and harder for others like Go  
Utility function: returns the value of a state  
Evaluation function: given a state, figures out the value of the state. It can sometimes be the same as the utility function  

### Game Tree
One player wants to maximize a value and another wants to minimize that value. So we build a game tree with each layer (ply) alternating between maximizing or minimizing the state.  
For tic-tac-toe for example, 
```
[ ][ ][ ]               [ ][ ][ ]               [O][ ][ ]
[ ][ ][ ] --maximize--> [ ][X][ ] --minimize--> [ ][X][ ]
[ ][ ][ ]               [ ][ ][ ]               [ ][ ][ ]
```

The **minimax algorithm** (a type of DFS) assumes both players make the best move possible. You evaluate from the very bottom and then make choices as you go up. MAX nodes will choose the MAX choice, MIN nodes will choose the MIN node.  
Could we make this better by pruning some branches? A method that does this is called **alpha beta pruning**. Alpha is the best value for MAX and beta is the best value for MIN. Alpha starts at -infinity and goes up while beta starts at +infinity and goes down. For example, with a MIN node it doesn't need to calculate the children it has that are for sure going to be higher than its minimum.  
```
MIN         4
          /   \
MAX     4       15
      /   \   /   \
    2      4  ?     15
```
For MIN node on top, it sees one child that can achieve 4 and another child that can achieve a 15, then the ? branch never needs to be computed because we know the MIN node will reject the 15 child.  
Minimax with **more than 2 players** just alternated layers/plies with all of its players. Then instead of tracking MIN and MAX, you will have a value representing each player and each player selects the value that's best for them.  
At the root, the beta is 4, so anything >= 4 will be pruned as the root is trying to minimize.  
So, for MAX nodes, we prune values >= beta and for MIN nodes, we prune value <= alpha.  
* alpha is the best value so far for MAX.  alpha starts at - ∞ and can increase as the search progresses
* beta is the best value so far for MIN.  beta starts at + ∞ and can decrease as the search progresses.
* At a MAX node, if the value v of a child is $ v >=beta, then prune the search and return the value v, else alpha = max(alpha, v)
* At a MIN node if the value v of a child is v <= alpha, then prune the search and return the value v, else beta = min(beta, v)
* In alpha beta pruning, you only prune the nodes you haven't looked at, that's the whole point of pruning


### Stochastic Games
Coin flipping, dice throwing, etc.  
In these games, we add a layer of chance (stochastic) nodes that account for the probability of taking one of those paths. You have no control of the chance nodes. Instead, we use expectiminimax which takes the below values at a weight so that the probability is represented.  

### Monte Carlo Tree Search (MCTS)
Use a default policy of random sampling after a certain point and look at the win rate from that node. It uses randomness to help solve deterministic games that are very difficult to solve by strategy alone. 
Selection: select a path  
Expansion: add one node onto the end  
Simulation: from that new node, use the default policy to look at the win-rate from that node  
Backpropagation: update the path back to root with the success rate of the new node