# Class Notes

### Rationale
Look at the strengths and weaknesses of each recommender.  
You could create a hybrid of UUCF and IICF, but what's good or bad? IICF is not serendipitious, and UUCF is seredipitious, so perhaps mixing the two will create balanced recommendations. Take rating matrices Rii and Ruu and average out corresponding values. But this has drawbacks because you could achieve similar things by dampening the UUCF ratings. UUCF and IICF together really has strengths coming out when you use IICF and sequentially funnel the smaller set of results into UUCF. Additionally, you could generate recommendations based on UUCF and calculate the predicted ratings for those recommendations with IICF and throw out the items with low IICF scores.  
Sometimes one algorithm works well for users with mainstream taste while another works well for those with niche taste but neither work well for users in the middle. Maybe a hybrid of those two could look like selecting the good recommendations with mainstream and then filter out the ones that are too popular with the other algorithm. 
Alternatively, you could use IICF + CBF. Content Based Filtering doesn't actually tell you what's good, only what genres/actors there are for a movie. Hybridizing the two, you could use a **switching hybrid** where you use IICF when there are more than some K ratings and use CBF when it has less. You could also use **confidence levels** to tell which one you should use.  

### Classic Models
Switching hybrids were built on the idea that sometimes you need a fall-back based on the situation. For example, if there isn't enough information to make a prediction for you then we fall back to popular items.  
Blending hybrids with weighted combinations naturally came after, so that instead of falling back completely, the different recommenders were blended together based on their weighted average confidence.  
Sequential hybrids were built with the idea that you would chain the results of one recommender to another. One common problem with this is that after the first recommender, the rest of the data becomes overfit. It's easier to avoid overfit when you compute on a sparse matrix.  
Post hoc tuning can be used to artificially arrange the results across a wider area to increase engagement, you could take the top recommendations and assemble them into the recommendation list, etc.

### Modern Models
SVD++ is an example of hybridization that happens before recommendation happens. You mix the implicit and explicit data before SVD. The drawback to this is that you lose the identity of what was explicit and implicit.  
You could beef up the input by switching from a ratings matrix (User by Item) -> ratings tensor (User by Item by Context by... ).  
You could also just throw the data into a deep learning model and let it create the model. 

### Strengths and Weakness
With hybridization, you lose the nuances and scrutability of the recommendations. Hybridized models are also very inefficient. 

### Ensemble Design
Combine the content, collaborative, and knowledge based approaches to produce a more robust recommendation. Some ways you can do this are by averaging the Rij or using each output sequentially as input for the next recommender. 

### Monolithic Design
