### Scales
needs to be enough to represent all opinions, but too much choice doesn't add much.  
Does it make sense to have high fidelity? 5* vs 10* vs inf slider  
Scales are often not meaningful without context: the prestige of an A+ depends on the difficulty of the class  

### Ratings, consistency, improvement
Rate-rerate reliability can tell you how accurate your inputs are. RRR can judge your method of collecting ratings, your user-base, etc.    
There are many variabilities between ratings, one of the most simple things that can change your opinion is simply time.  
To reduce noise in the data, you can put many items together and by having a feel for the context, people can rate better.  

### Confidence & explanations
How would you generate a confidence interval for a recommendation? 4.2* +/- 0.05*  
There is no model to come up with a confidence interval. You could potentially do it with enough empirical data from the same person. But that's really hard and maybe not worth it.  
Could you use other ways to convey confidence? For example, this 4.2* was rated by 1038 people, of whom 790 were very similar to you.  
You could also simply provide a tag of high variability or low variability could be enough.  
We can explain things with analoguous relationships for item-based recommendations. 
Explanations help you trust the product recommendation, trust the platform, and to refine the recommender because you can give feedback if the recommendations and their explanations were totally off. 

### Displays, layout, context
We can learn this empirically with eye trackers. It is important to do this because some things are effectively not visible based on where you put things.  

### Human-recommender interaction
human feedback and refine the recommender
```
dataset     algorithms  concrete    abstract        concrete
-------------------------------------------------------------------------
                        nDCG        perceived       6 mo. ret
                                    correctness     
                        diversity   perceived       intra-session time
                                    usefulness
                        popular     perceived       session length
                                    newness
                        top-k       perceived       CTR
                                    fairness        
                                                    purchase rate
```
You can optimize for the right hand concrete by sacrificing from others.  
What if the optimization harms people? It's possible