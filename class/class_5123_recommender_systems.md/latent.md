# Latent Factor Models
The latent factors are abstract dimensions computed to be orthogonal and to minimize the error in reconstructing the ratings matrix. These factors are the same for users (preferences) and items (characteristics).  

### Progression
Nearest neighbor -> matrix factorization -> latent factors  
Nearest neighbor is **very good** in terms of results, but it has lots of sparse areas and could be better in terms of efficiency.  
If we compress these sparse matrices through factorization with latent semantic indexing (which uses SVD).  
```
                 dim.               I
|       |     |       ||       ||       |
|   M   | =  U|   S   ||   V   ||   D   |dim.
|       |     |       ||       ||       |
```
The dimensions are orthogonal, we can truncate as well if there are 0 columns or rows. However, factoring such a big matrix is hard. It is hard to tells what the dimensions stand for. The diagonal matrix, *V* represents how much each thing matters.  
Typically, 13-19 dimensions are able to represent someone's movie tastes.  
Even better than factorization is to go directly to the user-dimension and item-dimension representations.  

**Funk SVD**  
```
               dim.
              |   |
|       |     |   |     I
|   M   | =  U| S ||    D    |dim.
|       |     |   |
              |   |
```
Use middling values for *S* and *D*, then multiply to get M(predicted), then compare M and M(predicted) to look at the *episilon * |error|* of known values to adjust the initial middling values of *S* and *D* into more significant values.  
Eventually, each user has a vector represented by the rows of *S* and each item has a vector represented by the columns of *D*.  
**Even this is not very useful**, within this factorization, there is a latent interpretation, but we still haven't found it. 

### Questions
*The basic idea of dimensionality reduction methods is to rotate the axis system, so that pairwise correlations between dimensions are removed. The key idea in dimensionality reduction methods is that the reduced, rotated, and completely specified representation can be robustly estimated from an incomplete data matrix.*  
What does that mean?  
