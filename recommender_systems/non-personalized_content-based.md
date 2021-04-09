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
