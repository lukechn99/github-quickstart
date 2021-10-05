# Nearest Neighbor (User based collaborative filtering)
Grouping by the people who are most similar to you based on your preferences.  
This assumes we can get meaningful information from strangers, information filtering, or just the practice of basing recommendations based on your own personal information retrieval and search is much older.  
A possible improvement on collaborative filtering over using strangers is to use those who are close to you either in proximity, community, or some other association. But oftentimes random other people who are similar in taste to you is actually more accurate than a family member or friend.  
The concept is that the sheer size of the pool of people that the random neighbors are selected from is likely to be more accurate than selecting from a smaller pool of people close to you.  
We need categorical filtering of which recommendations to use. People constantly move through space and through time and so tastes and needs will also constantly change. However, those who correlate with you as you move through space and time might be a good neighbor to recommend. For example, you liked the same things in elementary school and now you like the same things in high school or you liked the same restaurants in China and then you liked some of the same restaurants in America.  

### Unary vs binary vs multimodal

### Similarity metric

### How many neighbors
If weighting factors are good enough, then the farther out neighbors should be insignificant enough to get ride of the noise. We limit the size of the neighborhood because we don't want a bunch of suggestions that just give common recommendations. The neighborhood size can be limited by threshold or count.  
*select item -> find nearest neighbors* or *find nearest neighbors -> select item*  
Benefits of item selection first are that every rating is relevant and there's a smaller neighborhood to compute with. Selection of nearest neighbors before filtering for item means more diversity of opinion. 

### Weighting
Discount for low confidence, those with not much in common to evaluate; two item correlation of 1.0 vs ten item correlation of 0.9

### Normalization
r - r_bar  
user i: [5, 4, 4, 5, 2, 4], r_bar = 4  
user j: [1, 2, 3, 2, 2, 2], r_bar = 2
user i: [1, 0, 0, 1, -2, 0]  
user j: [-1, 0, 1, 0, 0, 0]
but this doesn't seem standardized. If we used another method of standardization like r / r_bar then it would look like...  
[1.25, 1, 1, 1.25, 1]  
[0.5, 1, 1.5, 1, 1, 1]  
I suppose r - r_bar could be fairly standard because it centers around 0. What could be more accurate is (r - r_bar) / r_bar  
z-score (often works worse than the regular standardization, this is not known why, but problably because ratings typically follow a bi-modal distribution and not a normal distribution)

### Data selection
Rule out older data, gift data (but should we? If they are a gifter then maybe recommending more gifts, aka knowing their friends, would be a good idea), 

### Runtime
Item * User^2 to do correlation calculation  

# Other metrics
### Accuracy and error
Mean absolute error is used for correction  
Counting bad errors looks only at extreme errors - 1* when it's supposed to be 5*  
Mean squared error amplifies big errors over small errors  
Root mean squared error

### Diversity
Diversity is a set property that is not assigned to an item but rather a set of items. It should be a diversity of various attributes/properties of an item. You may want to compare intrinsic similarity between every pair of items and then include only the most diverse items in your top-k list. When given a diverse list, people rated the individual items worse but rated the list as a whole better. You can handle more choices as the list is more diverse. 

### Serendipity
Didn't know about, think you'd like, or think would be recommended plus the component of actually liking it gives the feeling of seredipity. "You didn't think you'd like that, but you liked it!" Is this a good place to apply negative correlations? For example if you don't usually like horror movies with attributes [a, b, c] and we use negative correlation with some other heuristic to find horror movies that only have [d, e].

### Top-N decision support metrics
normalized discounted cumulative gain looks at how good the first few items are. 

### Precision and recall
% of what you return that's good  
% of what's good that you return  
But we never really get feedback on the percents

### Questions
An interesting problem is taking your taste in books to try and recommend shoes.  
What about negative correlations? How large do you want to make the neighborhood so that you kep out the negative correlations?  
Undiscovered items are likely to never be recommended based on user-user collaborative filtering, however item-item might recommend it if it is similar enough to the user's items. Is that the best way?  
There are unoptimal products that shouldn't be recommended in terms of its attributes.  
Do fireworks give satisfaction? That feeling of wrapping up at the end is strong. Maybe that can contribute to the feeling of "satisfaction"