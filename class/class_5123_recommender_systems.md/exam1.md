### Non-Personalized Recommendation

### Nearest Neighbor Collaborative Filtering
Pearson correlation between user U and user V only looks at the subset of rated items between U and V.  
First compute the mean for each user by adding all of their ratings and dividing by the number of ratings. Or you could also only average the item ratings shared between U and V as defined by the traditional Pearson correlation:  
```
For U: {1, 2, 5, 6, 7, 8}, V: {2, 3, 5, 6, 8, 9}, then U and V is {2, 5, 6, 8}

One way of finding the mean for U is (1 + 2 + 5 + 6 + 7 + 8) / 6
The other is (2 + 5 + 6 + 8) / 4
```

Then the Pearson correlation between U and V is 
```
sum( (item - mean) * (item - mean)
```

Vector Cosine look like A dot B / magA * magB

### Metrics