# Probability Theory, Bayes' Rule, Parametric Method, Parametric Classification, Maximum Likelihood (ML), Maximum a Posteriori (MAP)

### Probability Theory
The unobservable values are made observable through a deterministic function and its probability can be drawn.  
```
x = f(z) where x is observable when function f makes unobservable z observable
```
A variable X is bernoulli if it has binary outcome. The probability of one outcome is *p* and the other is *1-p*. Then the expected value is E(X) = *p* and variance is Var(X) = *p(1-p)*. Variance is the expected deviation from the mean, or E[(e - mean)<sup>2</sup>]

### Classification
These problems attempt to sort data into groups based on characteristics of each datapoint. Classification can be binary or n-ary.  
The input is a vector of features and the output is a class chosen from a set of classes.  
How this is predicted can be done in a few ways. We could use a threshold, *P(C = class<sub>1</sub> | features)* or we can choose the class with highest probability based on Bayes' Rule. Given classes *C<sub>1</sub>, C<sub>2</sub>, C<sub>3</sub>...*, we classify an instance with feature set {f<sub>1</sub>, f<sub>2</sub>, f<sub>3</sub>...} by choosing the *C<sub>i</sub>* with the highest *P(C<sub>i</sub> | x)*

### Parametric Methods
Define the model based on parameters. Or in other words, we are trying to maximize the likelihood that the data is modeled by a set of parameters, theta.  
For a points that follow a normal distribution, the model would probably include parameters like the mean and variance.  

### Maximum Likelihood Estimation
*l(&theta;|X)* is the likelihood of &theta; given sameple X.  
*L(&theta;|X) = $\sum_{t=1}^{N}$ log(p(x<sup>t</sup> | &theta;))*  
then is the log likelihood, it does not alter the parameters at all.  
The maximum likelihood estimator is then *&theta;<sup>*</sup> = argmax<sub>&theta;</sub>L(&theta;|X)* which is a maximization of the log likelihood.  
With something like a bernoulli distribution, the parameter is just the sample mean. With multinomial distributions, gaussian distributions, etc., the parameters are estimated differently.  
Maximum likelihood uniform prior is *&theta;<sub>ML</sub> = argmax<sub>&theta;</sub>p(X|&theta;)*

### Maximum a Posteriori Estimation
*&theta;<sub>MAP</sub> = argmax<sub>&theta;</sub>p(&theta;|X)*

### Parametric Classification
Discriminant: *g<sub>i</sub> = p(x|C<sub>i</sub>)P(C<sub>i</sub>)* which is the product of the likelihood and prior. It can also be expressed as *g<sub>i</sub> = log(p(x|C<sub>i</sub>)) + log(P(C<sub>i</sub>))*  
Depending on what we're working with (multivariate or otherwise), the *p(x|C<sub>i</sub>)* will be different. 

### Multivariate Data
Refers to data where each instance has many features. In this case, you can arrange the instances in a matrix of their feature vectors where each column is made up of an instance's feature vector. Of course, rows and columns are interchangeable. For N instances with d features, we get an N by d matrix.   
Here, the mean E(x) is a vector of the feature-wise means. Covariance is a d by d matrix. 

### Questions
Why are the prior, sample mean, and sample variance included in the discriminant?  
How exactly does the discriminant work? It helps locate the class with mean closest to the sample.   
What is Mahalanobis distance and naive bayes?