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
Luke likes Star Wars -> Star Wars has attribute [sci-fi, action, adventure, fantasy] -> Luke might like Harry Potter with attributes [action, adventure, fantasy], Fast and Furious with attibute [action], etc. 
```
User models will have a keyword vector or taste vector. After a few movie ratings, it may look like the following:  
```
|-----------|-----|
| Action    | 5.0 |
| Sci-fi    | 4.7 |
| Adventure | 3.2 |
| Fantasy   | 4.5 |
| Romance   | 2.2 |
| Melodrama |-0.7 |
|-----------|-----|
```
