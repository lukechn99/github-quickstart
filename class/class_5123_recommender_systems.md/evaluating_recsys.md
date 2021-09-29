### Evaluation Goals
Aside from just a number metric for accuracy, we have to evaluate a recommender system by looking at novelty, trust, coverage, and serendipity among other things. It's a very multi-facet ordeal that's hard to capture in a single number.  

### Experimental Design Issues
The experiment should be designed in a way that 

### Accuracy Metrics
Can be measured based on a single item and how much that prediction matched up with actual results or for a whole recommended list of items. 

# Evaluation Paradigms

### User Studies
Users are recruited to evaluate the recommendations after interacting with them. This can be a really good way to gather evaluation after changing the UI or recommender algorithm. However, you must be aware of possible bias from users who know you are gathering information. 

### Online Evaluation
Data from candid online users are gathered while they naturally use the recommender system. This gets rid of the bias that comes with recruiting users with the sole intention of gathering metrics from them.  
We can actively test different recommendation algorithms with the use of A/B testing where we use algorithm A on one group and algorithm B on another group. Or we can use A and B interchangeable and at random among everyone. Additionally, it can also be a set of different algorithms (A, B, C, D...) that we test randomly following a multi-armed bandit approach where we use reinforcement learning to use the best algorithm 90% of the time and try the other algorithms the other 10% of the time and reprioritize as necessary.  

### Offline Evaluation
Offline methods are the most statistcally robust because they use existing data sets. Many standardized frameworks exist for this purpose. The drawback of offline evaluation is that they don't look at the user's likelihood of doing something in the future

### Questions
Why are offline evaluations not able to look at future interactions? They can still predict right? I suppose they would have to predict something and then wait for a new offline phase to see if their prediction was correct. 

# General Goals of Evaluation Design

### Accuracy
Accuracy is quantified in terms of the difference between actual and estimated ratings for an item.  
```
error = estimated rating - actual rating
```
The MSE method of measuring accuracy takes the sum of each ```error``` squared and divides by the number of items predicted |E|.  
The RMSE method just uses sqrt(MSE).  

### Coverage
Coverage looks at how many of the items and users are included in the recommendations. The more sparse a rating matrix is, the more items and users it won't be able to recommend to.  
*User-space coverage* looks at the fraction of users that we can recommend at least *k* items to and the *item-space coverage* looks at the fraction of items for which *k* users can be recommended. Sometimes it is hard to compute enough neighbors for a user and so they don't get as many recommendations. One way to make up for users for which the algorithm cannot give *k* predictions is to make random predictions to satisfy *k*. *User-space coverage* is evaluated in terms of accuracy versus coverage because at one extreme you could use *k* random predictions giving 100% coverage and negligible accuracy. At another extreme you could have zero predictions for a very sparse user and have 0% coverage and... 100% accuracy? IDK.  

### Confidence and Trust
We look for the algorithms that give the smallest confidence intervals because they foster the most trust in users. 

### Novelty
The best way of measuring is to ask users if they were "previously aware of this item."  
Using offline evaluation methods we can gauge novelty by using the assumption that something is novel if it is more likely to be clicked on in the future than in the moment it was recommended. These systems are penalized for recommending items that were already recommended and rewarded for recommending new items. 

### Serendipity
All serendipitious recommendations are novel, but not all novel are serendipitious. Where novel is the new, serendipitious is unexpected. 

### Diversity
Diversity is important so that at least one recommendation (of a list) could be useful. This is just like having diversity of traits in a population. Diversity promotes novelty and serendipity.  

### Robustness and Stability
A system must withstand some fake ratings or quickly changing trends.  

### Questions
What is overfitting and underfitting?  
How does overestimating and underestimating accuracy work?  
It's interesting how some ratings might be completely subjective while other objective. For books people are rating physical quality but are also rating a story/content. For food items you might be rating taste or quality of construction for a pot. 