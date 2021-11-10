### Cheatsheet

```
|---> Ratings and Preferences
|       |---> Implicit
|       |       |---> what you click on
|       |       |---> what you buy
|       |       |---> what you put in cart, view, search
|       |       `---> duration of interaction
|       |---> Explicit
|       `---> Context and characteristics
|               |---> location
|               |---> demographic
|               `---> season/weather
|---> Recommendations
|       |---> Hybrid
|       |---> Non-personalized
|       |       `---> Cold start problem
|       `---> Personalized
|               |---> Neighborhood Based Collaborative Filtering
|               |       |---> UUCF
|               |       |---> IICF
|               |       `---> Better when there's lots of data known about the item
|               |---> Model Based Collaborative Filtering
|               |       `---> Latent Factor Model
|               |---> Trust based
|               `---> Content Based Recommender System
|                       `---> Good for new items where collaboration isn't possible and there's lots of item information
|---> Summary statistics
|       `---> 
`---> Evaluation
        |---> User studies
        |       |---> Field experiments (A/B studies)
        |       `---> Lab experiments (explicit engagement)
        |---> Online evaluation
        |       `---> A/B testing
        `---> Offline evaluation
                |---> Accuracy measures
                |       |---> MAE
                |       |---> RMSE
                |       `---> Top-K metrics
                |               |---> nDCG@k
                |               `---> Precision@K
                `---> Evaluation goals
```