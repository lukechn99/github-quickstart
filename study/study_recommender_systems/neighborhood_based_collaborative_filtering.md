### Key Properties of Ratings Matrices
Ratings used in the ratings Matrix *R* can be continuous scale ratings, interval based, ordinal, binary, or just unary.  
A flaw of how ratings for items are gathered is that most items have very little rating and a few "popular" items have the vast majority of ratings. This causes the recommendation of generally popular items over more obscure ones that might be a better fit and less diversity of recommendation.  
Often-times it's the low-frequency items that make the most money, so companies like Amazon have incentive to recommend the right low-requency items.  

### Predicting Ratings with Neighborhood-Based Methods
User-User: if A and B are similar, then A's observed rating of item *i* can be used to predict B's unobserved rating of item *i*  
Item-Item: user A's ratings of action movies *i* and *j* can be used to determine if they would like *k*  
Classification only looks at row similarity (between users) while keeping the item constant. Collaborative filtering looks at row and column because the missing values are spread out among rows and columns.  
In user-based neighborhood models, each user is compared against every other user to determine similarity. Some flaws of this are that different users may be biased towards different ratings on the same scale. To do user-based collaborative filtering, you compute the Pearson correlation between user *i* and every other user one by one. The ones with highest Pearson correlation to the user become the peer group. To account for rating bias across users, we subtract a user's mean from each of their ratings. The correlation number is mostly used to **rate** the neighbors and **weight** the neighbors to see who has the biggest impact on your recommendations.  
Neighborhood based methods are always split into offline and online phases where the offline phase takes care of pairwise computations and the online phase takes care of the predictions and rankings. The offline phase needs to be run periodically and the online phase needs to be quite fast.  
Item based methods are sometimes more accurate because they use the user's own ratings of movies. User based methods will introduce more new material and induce more diversity and serendipity. User based methods are less stable because of the possible change that new user ratings could bring. There are more users than items typically.  
  
Vector cosine is good for unary data.  

### Clustering and Neighborhood-Based Methods


### Questions
the neighborhood based method can be shouwn to be a heuristic approximation of a least squares regression model... what?  
clustering methods?  
What's a neighborhood? The use of similar users (user-user) or similar items (item-item) to make recommendations.  
collaborative filter:generalization of regression modelling::neighborhood based:generalizations of nearest neighbor classifiers???  
"If none of John's nearest neighbors have rated *Terminator* then it might be evidence that this movie is not a good recommendation for John." Doesn't this mean that eventually when enough people have not rated a movie in a while then it will fall into obscurity and be recommended less as well?  
What is vector cosine? It uses a vector dot product  
