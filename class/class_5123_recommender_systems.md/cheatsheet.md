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
|       |---> Non-personalized
|       |       |---> 
|       |       `---> 
|       `---> Personalized
|               |---> CF (collab. filtering)
|               |       |---> UUCF
|               |       `---> IICF
|               `---> CBF (content based filtering)
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