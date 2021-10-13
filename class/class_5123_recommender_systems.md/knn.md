# K Nearest Neighbors & Metrics

### Case Examples
An email or advertisement that allows for one product have a few objectives in mind:  
- result in a purchase
- result in a click-through/visit, tracked through identity resolution and time to transaction, direct measure, 
- increase brand awareness
- increase lifetime value/purchasing
- inspire referrals/likes/tweets
All of these can be measured by aggregate change. These things can allow you to categorize people into those who like 50% discounts, those who like clearance, those who like new release, etc.  
Goals can also vary from wanting them to buy the advertised product versus buying something period.  
Should you advertise something like Amazon Prime when the renewal is already automatic? Maybe it would actually harm you.

### Offline Metrics
Accuracy: RMSE  
- RMSE is a prediction metric based on what we know about you and what we predicted about you
Decision-support/rank: Precision@k, nDCG@k, Area under ROC curve  
- How well do these items reflect what they're supposed to be?
- evaluating the top 1 prediction can be best done with Precision@K=1
- nDCG weights earlier items in K more
Coverage  
- coverage might be a good thing for Amazon where we want to be able to recommend most items for more cycling through
Characteristics of Top K: popularity, serendipity, novelty, intra-list similarity/diversity  
- Serendipity should be something not similar to what you've had, but match really well
Explainability  
- Some algorithms are harder to explain
Confidence
- How sure the algorithm is
The best metric to use varies with what you're recommending. Recommending 1 product should be measured with precision@k and nDCG@k, a list of 5 should probably be evaluated with intra-list similarity/diversity.  
We could use damping in user-user, so that those who are not as similar to you  
With limited inventory, you don't want to just recommend the most popular Airbnb  
Sometimes, you advertise the most popular and common item and then they buy extra things.  
We start with an outcome in mind and then optimize for that. Usually the outcome is an offline metric

### Questions
Intra-list similarity takes similarity pairwise and averages them, but what if we didn't average them and instead we looked at the distribution of pairwise similarities? Could we fit the distribution into a function that gives a better representation?