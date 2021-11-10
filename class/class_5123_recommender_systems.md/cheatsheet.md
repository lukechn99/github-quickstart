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
|               |       `---> IICF
|               |---> Model Based Collaborative Filtering
|               |       `---> Latent Factor Model
|               |---> Trust based
|               `---> Content Based Recommender System
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