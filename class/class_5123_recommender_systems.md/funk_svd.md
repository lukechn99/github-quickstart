https://sifter.org/~simon/journal/20061211.html

# Netflix Prize 
Netflix provided 100M ratings (from 1 to 5) of 17K movies by 500K users. These essentially arrive in the form of a triplet of numbers: (User,Movie,Rating). E.g., one such entry might be (105932,14002,3). Times 100 million. Now go make sense of it. In particular, for (User,Movie,?) not in the database, tell me what the Rating would be--that is, predict how the given User would rate the given Movie.  
Netflix has then posed a "quiz" which consists of a bunch of question marks plopped into previously blank slots, and your job is to fill in best-guess ratings in their place. They have chosen mean squared error as the measure of accuracy, which means if you guess 1.5 and the actual rating was 2, you get docked for (2-1.5)^2 points, or 0.25. (In fact they specify root mean squared error, affectionately referred to as rmse, but since they're monotonically related it's all the same and thus it will simply hurt your head less if you ignore the square root at the end.)

### Approach
100 million ratings in a sparse matrix means the matrix has around 8.5 billion entries, most of which are empty.  
A fun property of machine learning is that this reasoning works in reverse too: If meaningful generalities can help you represent your data with fewer numbers, finding a way to represent your data in fewer numbers can often help you find meaningful generalities. Compression is akin to understanding and all that.  

# Funk SVD
It is less expensive and doesn't require filler data.  
Qualms: If you follow where the data goes, there's no guarantee that you'll reach the same place as SVD. As a shortcut, it doesn't preserve all the original properties. Alongside this issue, there is no normalizing, users and items with more ratings had more impact over the resulting vectors. 
Lack of orthogonality... why is that a problem?  
Optimized versions of SVD and other recommenders are harder to explain. 