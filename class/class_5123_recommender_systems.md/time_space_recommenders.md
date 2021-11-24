# Context

### Time and Place
Time
- Seasonality
    - anchor events
- time of day
- evolving preferences
    - life events
    - demographic evolving preferences
- product space changes
    - product aging/relevance
- sequential dependencies
- availability

Place
- where you are
    - travelling vs. at home
- place as a demographic
- things near me
- local preferences
- local availability/legality
- changes in how products are associated with each other in different places (fries and ketchup vs. fries and mayo)

### Time
Time decay could be that we consider the most recent N to be most important or the ratings within the last N time.  
Most recent N would work well with something like recommending research papers: it doesn't matter whether the last 10 items read were research papers on dogs or the last 100 items read were papers on dogs. If a person is doing research on dogs, it makes sense to keep recommending.  
I think it could be useful to use a feedback loop because different item categories have different time decay patterns. 
Maybe we only use the most recent in recommending something to you.  
Time is different for everyone. People eat dinner at different times, sleep and wake at different times, have different length days, etc.  
It's difficult to determine a hard time.  
Filter the candidates (pre-pre-filter), filter the input data (pre-filter), filter/re-rank the top-k (post-filter).  
Pre-filtering can be done by selecting a time and only recommending for that time. Post-filtering can be done by collapsing all times together and then filtering by time of day currently and season.  
Product space changes reflect the changes in society, product aging happens when a product loses its relevance. 

### Place
Place can be talked about in a hierarchy, in a category, but place is mostly hierarchy. Places may define taste, either in a soft way or with hard boundaries; sometimes the taste is a preference, but in other times taste cannot even be communicated across boundaries. Place can also act as a pre-filter or post-filter, acting as a constraint. When taking place into context, it's not just about preference anymore. It is also about what the person needs. Google Maps operates on the principle of reasonability. It is simply not reasonable to walk to Las Vegas, so those options are no longer recommended. 
