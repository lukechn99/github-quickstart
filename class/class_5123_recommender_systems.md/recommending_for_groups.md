# Recommendations for Groups
Let there be a group value function gvf(item) = gvf(R<sub>1i</sub>, R<sub>2i</sub>, ...) when we want to calculate a rating for a group of people.  
We have to keep in mind that while it is natural to want to aggregate all users' preferences, sometimes groups of people take on a personality all of their own. So we treat the people not as individuals, but as a group.  
But if we take the group as a new entity, then we lose valuable information about each user and we can't let the group scores cross over to the users.  
Minimum misery is one way to address the issue of recommending a movie that is very polarized (some love some hate). Minimum misery is to represent the one that minimizes the grumpiest person. The issue with this is that the experience may be just mediocre for everything.  
Then there's an approach that just ditches the unhappy person.  
Another question to ask is whether or not all users' opinions matter equally.  
- Not all users are equal
- Items can be selected from the corpus of all items or a defined subset
- The average of all user predictions can wipe out information on the extremes
- Users might rate towards a bias that must be accounted for


### Questions
Maybe instead of using the user-group to recommend movies, you could use the viable movie-group to recommend the best users to watch with. This is actually applied in dating. 