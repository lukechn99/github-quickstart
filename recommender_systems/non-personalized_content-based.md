# Non-Personalized and Content-Based
Data needs to be gathered about a user before recommendations can be made

### Preference Data
Can be explicit (directly ask for input, like a star rating) or implicit (user interactions)   

### Explicit (ratings)
Some explicit rating systems will give you a guide or assistance such as what others rated. Other rating systems let you rate up or down, and other systems can do just up ratings. Up and down is typically for more ephemeral objects. Here there is a balance between the amount of user effort needed and how much information the final recommendation should have. For example, Reddit uses high rating and a time decay to recommend posts. There are comparative interfaces that pitch one choice against another.  
Consumption ratings are done right after the time of consumption.  
Memory ratings are provided some time after consumption.  
Expectation ratings are used for items that most users won't have much experience with, such as a house.  

### Implicit (implicit feedback recommenders)
Tracking clicks and purchases show the user's action based on preference (theoretically). Although there isn't explicit feedback, the volume of feedback is much greater. Metrics on a user's listening or watching is usually a good predictor of how much they will likely rate it even if they don't actually rate it. Alongside tracking clicks, there is implicit implicit data where links that the user *doesn't* click may be downgraded.  
Implicit data is more natural to collect than explicit data and can often be just as meaningful. 

### Output of a Recommender System (how to display)
Outputs can be predictions or recommendations. Predictions are more quantifiable while assigning a value. This can be helpful, but it's also falsibiable or debatable. Sometimes it is better to not give the user a chance to disagree than to overprovide information in a prediction. Recommendations provide good choices by default, but risks being perceived as the only list.  
Outputting in a hard and explicit way can feel too aggressive and users can push back. Organic presentations where recommendations are placed prominently is more subtle. Although two systems could use the same recommender, the presentation could be different. 

### Notes
Reddit is a non-personalized recommender based on upvotes and demographic of the user  
You don't always have to rank based on the score, a 5 star might not be a good idea if the item only has one rating, also some systems should only recommend new things like news headlines, you don't want to recommend a one year old headline even if popular  
Damped mean uses a value k to make the mean change very little in the first few ratings
Time decay makes the recommendation score smaller as time passes. Earlier votes have more impact than later votes (Reddit formula)

### Ideas
Could we alter MovieLens so that it recommends apart from the score? What types of movies have high scores and good fit but shouldn't be recommended?
Inverse time decay, movies should be impacted more by recent ratings than old ones since movies are always changing trends
