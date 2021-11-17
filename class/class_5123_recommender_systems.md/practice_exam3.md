### CSci 5123:  Practice Exam 3(b) – note, there would only be 3 questions, but I’m providing an extra for practice.   
1. Evaluation – Beyond Metrics. You found a paper that evaluated a particular recommender algorithm on a public dataset and reported that the algorithm yielded an RMSE of 0.84 on that dataset. The researchers provided not only the recommender code and the dataset, but also a matrix of actual predicted values produced by the algorithm for each user/item pair.  Still, when you tried to compute RMSE 
(using your own tools), you found an RMSE of 0.92, not 0.84.   
a. What might you have done differently from the original authors that could lead to the 
different value? Explain why this would produce a different result.   
b. What does providing a matrix of actual predicted values suggest might have been done 
wrong (or at least unusually) in the authors’ evaluation?  Explain why this is an unusual 
or wrong way of conducting the evaluation.   

```
a). It could be that the sample matrix of predicted values is simply not representative of their entire dataset. For this sample, the RMSE could have been higher. 

b). 
```

2. Attack detection and resistance. A large number of recommender system attack defenses depend on making it harder for attackers to add ratings (or other data) into the system, or at least harder to have that data affect the recommendations shown to others.  Give two examples of different defense strategies that take this approach, and briefly explain how they protect against attackes.   

```
One approach is to force users to undergo some kind of test of human-ness like a reCaptcha or other test that makes it hard to add ratings. 

Require login for users and tie that login to an email or (even better) a phone number or some other identifying information so that one user cannot use multiple accounts for leverage. 
```
 
3. Group Recommendations. 
Assuming you are recommending for a group of 3 people (A, B, and C) who have individual 
predicted scores P(A,i), P(B,i), P(C,i) for each item i, and mean predictions P-bar(A), P-bar(B), and 
P-bar(C).  Give two different social value functions that could be used for evaluating the group 
recommendations for the group and identify a strength and weakness of each one.   

```
One function is to average the user's predicted scores and use that as the group score. The strength of this is that we represent all users equally. The weakness of doing it this way is that we lose the nuances of each individual user and might end up with some that love the recommendation and some that hate it. 

Another way we could recommend for this group is to minimize misery. With this approach we take the lowest predicted score for an item out of all group members and use that score as the score for the group. The strength of this is that we can pick an item based on least misery and guarantee that everyone in the group will like it at least that much. 
```

4. Explain in your own terms what learning-to-rank refers to in recommender systems.  Include a 
very high-level (1-2 sentence) description of both the goals and the mechanism of the 
technique.   

```
Learning to rank looks at items relative to each other. 
```


### Actual exam
