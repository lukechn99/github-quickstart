# Backtracking Algorithms
A combination of previous notes, new studying, and directed study towards the solving of the Stone Game
Backtracking algorithms are generally very slow

### Stone Game
*copied from leetcode*
Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile  
has a positive integer number of stones piles[i]. The objective of the game is to end with the most stones.  The  
total number of stones is odd, so there are no ties. Alex and Lee take turns, with Alex starting first.  Each turn,  
a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until  
there are no more piles left, at which point the person with the most stones wins. Assuming Alex and Lee play  
optimally, return True if and only if Alex wins the game.

```
Example 1:
Input: piles = [5,3,4,5]
Output: true
Explanation: 
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
```

This seems like an application of a greedy algorithm right away from the description before looking at the example because each player wants to follow a heuristic

### Permutations
```
swap(array, i, j)
	temp = array(i)
	array(i) = array(j)
	array(j) = temp

permute (array, i):
	if i < array.length - 1
		for j = i to array.length - 1
			swap(array, i, j)
			permute(array, i + 1)
			swap(array, i, j)
	else
		print(array)
		
