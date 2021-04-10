# Recommender Systems
Analysis, algorithms

### Analysis of Recommender Systems
What's being recommended? Product? Bundle? People? Playlists?  
What's the purpose of the recommendation?  
Recommendation context, who is the person or group?  
Whose opinions? Recommendations are often not based on just your opinions  
Personalization level? Usually we start with non-personalized or attached to a demographic. We can map to long term interests or ephemeral recommender.  

Interface is the presentation  

### Recommender Algorithms
All systems use users, items, and ratings as the three basic building blocks.  
Each user has a user attribute (that describes their characteristics) and a user model that we build based on their preferences. Items also have attributes. Ratings connect the users and items.  
Recommendation algorithms include non-personalized, content-based, collaborative, and others.  

### Non-Personalized Algorithms
Use community trends (either data or ratings). 

### Content-based Filtering
Users rate items and we build a model of user preferences based on the item attributes.  
```
User likes Item -> Item has attribute [1, 2, 3, 4] -> User might like Item' with attributes [1, 2], Item'' with attibutes [2, 3], etc. 
```
