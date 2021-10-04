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

The **minimax algorithm** assumes both players make the best move possible. You evaluate from the very bottom and then make choices as you go up. MAX nodes will choose the MAX choice, MIN nodes will choose the MIN node.  
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