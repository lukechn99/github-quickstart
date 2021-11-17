# Neural Networks
Why neural networks? Why have multi-level instead of latent factors?  
FunkSVD is tied to linear relationships and vector dot products. This 1D way of thinking about things limits how well you can discover latent factors. Neural networks break free of this linearity.  
A second benefit of neural networks is that the model NN use for IO makes it easy to train on heterogeous attributes, meaning the factors don't have to be of the same category. We can put genre, demographic, actors, relationships, and many other things in. 

### Tat-Seng Chua
Addressed this as a subset of the recsys problem. Each user-item pair has an observed interaction (can be good or bad) that is used to predict if a user will interact with something in the future.  
It looked at pointwise loss and pairwise loss which are error in a prediction and error in a ranking respectively.  
```
Input layer -> embedding layer (condenses the sparse input layer) -> neural CF layers (multiple layers to look for different latent factors) -> output layer  
```  
After many layers, you end up with an idea and lose the details.  
The depth of the network matters for how well it does. Generally, the more layers the better it is. 

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