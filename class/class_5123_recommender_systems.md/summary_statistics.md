Can we just take average ratings? Just because McDonalds get the most people, it may also get a higher score, but is it really good?  
When Amazon shows us the customer reviews, it shows the average and a distribution.  
In many cases averages can be misleading because of intensity and number of ratings.  
Normalization of user scores can be helpful when peoples' standards are different, your 4* average might be my 2* average. **It can improve performance by 50%!**  
The example of Zagat and its dilution of scores over time shows that there are elements at play that are unforeseeable. People who rated mediocre restaurants badly may not go back and so there are no more bad ratings. Standards change  

### Display Approaches
Possible ways to **display** preference could be average, net, percent above x%, distribution, etc.  
Average doesn't do a good job of showing popularity of an item, 5* could be one rating  
Net upvotes shows popularity but doesn't reflect controversy.  
Positive votes could
Showing th efull distribution is basically just giving the user the raw data, but it also makes it more complicated for the user to comprehend
Maybe we could use an aggregate of all these simple displays to show a gradient. For example we could use a limiting function like e^1/x or something to reflect the full distribution.  
We could also let the user select their own metric, like Reddit letting you sort by best, hottest, newest, etc. 

### Average Rating
Shows of the people who vote, how many liked it but doesn't show the popularity

### Net Upvotes
Shows the popularity but loses the dimension of controversy

### % Greater than 4*
Only shows the positive
