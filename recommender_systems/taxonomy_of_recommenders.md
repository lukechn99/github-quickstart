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
**All** systems use *users*, *items*, and *ratings* as the three basic building blocks.  
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
Later on, other items will be compared to the model to see if it is a possible match for the user. This will be a vector dot product between the attributes of the potential item and the user model.  

### Personalized Collaborative Filtering
Uses the opinions of other people. We use a "common core" which is a sparse matrix of ratings with users on the rows and items on the columns. This is realistic because each given user is unlikely to have rated every item. In real life, a user may have rated <1% of the total items. 
User-User Collaborative filtering lets users select other users that have similar taste and then fills in the blanks for the user based on their community. Trust-based recommendations allows you to use your social network (people you trust).   
Item-Item Collaborative filtering precomputes similarity among items and triagulates for recommendations. Use the items that I have rated, and see what other items are similar to that one. When examining a new item, it looks at whether the item is similar or dissimilar to other items you have liked or disliked.   
Dimensionality Reduction takes the tastes of the user and reduces the number of choices to compare against using a lower-dimensionality matrix.  
