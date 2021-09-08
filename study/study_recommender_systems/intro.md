# Recommender Systems
Recommender systems are an automation of the agents and personal assistants that were previously used (personal shoppers, travel agents). It started as research for video recommenders in the 1990s. Recommender systems were integrated into industry with Amazon and others. It was also a part of the tech bubble and the tech burst. There are potential applications of recommendation systems in CV, AI, ML, but especially in CV and maybe VR/AR. Matrix factorization, Top-N algorithms are used. Magic barrier: you can't recommend better than a person could rate in the first place, the value of a recommendation where we consider if the recommendation even contributes anything useful. Temporal questions matter a lot, seasonal recommendations, sequential recommendations, educational module sequences, etc. It is also hard to recommend highly personal things like which surgeon to use. To address these, we almost always need higher knowledge.  
It is a combination of ML, data mining, business, HCI  
Amazon bought the original collaborative filtering algorithm from the U of M and then realized that they have way more users than items. So doing user-user recommendations didn't work very well. Instead they wanted to do item-item correlations. Find the things that a person likes and recommend the items that are similar. This resulted in recommendations that are really tame.  
The real recommendations sometimes came from the psychology of buying
Item-item was also too slow and lost information. This was when we started computing recommendations more smartly. We start using SVD to provide each user with a vector that represents them. This was still too slow and didn't operate well on sparse matrices.  
Taking advantage of the sparsity of the matrix, people stopped trying to factor and just tried to optimize for the products of the vectors to minimize the distance from the existing scores and filling in the missing ones. SVD, stochastic descent, least squares were all methods people used to do this.  
The final wave, and current trends, in recsys involves machine learning.  
How discounts are run, brand loyalty, price sensitivity, and consumer knowledge are a huge part of what goes into sales and coupons at checkout. The money given to the consumer through coupons, loyalty programs, and other promotions are offset by either attracting a new customer or bringing customers into the marketplace more often.  

### General Model
Users will contribute *user experience*, which is added to the big data pool that's being gathered, and a recommendation, based on the many others who have their data in the pool will be considered and a recommendation is given back to the user. 

### Approaches
Recommendations can be personal or generatized to a population.  
Product association is where products are linked by users who rate them.  
Content-based figures out a profile for what you like.  
Collaborative uses opinions of the community to figure out what else you might like.  

### Ideas
How to recommend items that fall through the cracks  
Time-weighted recommendations  
Being "too good" at recommendations turns out to be bad  
You could take the average ratings for a person and divide all other ratings by that one to normalize things  


---
Rating : is an expression of preference that can be given explicitly (rating an item) or implicitly (through behavior cues)  
Prediction : estimation of preference  
Recommendation : selected items for the user  
Content : attributes or description of the item (text, title, reviews, tags, etc.)  
Collaborative : who likes this item and what else do those people like? Expanding the recommender system to beyond just one user. It uses other people's opinions to determine what you might like  
