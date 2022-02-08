# Probability Theory, Bayes' Rule, Parametric Method, Parametric Classification, Maximum Likelihood (ML), Maximum a Posteriori (MAP)

## Probability Theory
The unobservable values are made observable through a deterministic function and its probability can be drawn.  
```
x = f(z) where x is observable when function f makes unobservable z observable
```
A random variable X is bernoulli if it has binary outcome. The probability of one outcome is $p$ and the other is $1-p$. Then the expected value is $E(X) = p$ and variance is $Var(X) = p(1-p)$. Variance is the expected deviation from the mean, or $E[(e - mean)^{2}]$  
Bernoulli probability: $P(X=i)=p^{i}(1-p)^{1-i}$, $i=\{0,1\}$

## Bayes' Rule
$P(C|x)=\frac{P(C)p(x|C)}{p(x)}$  
Where $P(C)$ is the *prior*, the prior knowledge of the probabiliy of the class regardless of what data we're currently looking at. The $\sum_{i=0}^{n}P(C_i)=1$, which just says that the probability of all classes added together has to be 100%.  
$p(x|C)$, the *class likelihood*, is the probability that an data point belonging to the class $C$ has value $x$.  
$p(x)$, the *evidence* is the probability of $x$ occuring independent of other events. It is calculated as the $\sum_{k=1}^{K}P(C_k|x)P(C_k)$ which is the sum of the probability of seeing $x$ in each class.  

## Classification
These problems attempt to sort data into groups based on characteristics of each datapoint. Classification can be binary or n-ary.  
The input is a vector of features and the output is a class chosen from a set of classes.  
How this is predicted can be done in a few ways. We could use a threshold, $P(C = class_1|features)$ or we can choose the class with highest probability based on Bayes' Rule. Given classes $C_1, C_2, C_3...$, we classify an instance with feature set $\{f_1, f_2, f_3...\}$ by choosing the *C<sub>i</sub>* with the highest $P(C_i|x)$

## Parametric Methods
Define the model based on parameters. Or in other words, we are trying to maximize the likelihood that the data is modeled by a set of parameters, theta.  
For a points that follow a normal distribution, the model would probably include parameters like the mean and variance.  

## Maximum Likelihood Estimation
$l(\theta|X)$ is the likelihood of $\theta$ given sample X. It is calulated as the product of all $p(x_i|\theta)$  

We want to find $\theta$ that maximizes $l(\theta|X)$  
Using log likelihood simplifies some calulations because now we can use a summation instead of Pi notation. Using the log product rule.  

$L(\theta|X) = log(l(\theta|X)) = \sum_{t=1}^{N} log(p(x_t|\theta))$  
then is the log likelihood, it does not alter the parameters at all.  
The maximum likelihood estimator is then *&theta;<sup>*</sup> = argmax<sub>&theta;</sub>L(&theta;|X)* which is a maximization of the log likelihood. (Alpaydin 66)  

MLE is used with ALL kinds of distributions. Bernoulli is $K=2$ classes and can be generalized to multinomial distributions where $K>2$. The Gaussian distribution is used when inputs are numeric. 
For multinomial distributions, MLE spits out a series of probabilities that correspond to the available classes. 
$\hat{p}=\frac{\sum_{t}x^{t}_i}{N}$

With something like a bernoulli distribution, the parameter is just the sample mean. With multinomial distributions, gaussian distributions, etc., the parameters are estimated differently.  
Maximum likelihood uniform prior is *&theta;<sub>ML</sub> = argmax<sub>&theta;</sub>p(X|&theta;)*

## Maximum a Posteriori Estimation
*&theta;<sub>MAP</sub> = argmax<sub>&theta;</sub>p(&theta;|X)*

## Parametric Classification
Discriminant: *g<sub>i</sub> = p(x|C<sub>i</sub>)P(C<sub>i</sub>)* which is the product of the likelihood and prior. It can also be expressed as *g<sub>i</sub> = log(p(x|C<sub>i</sub>)) + log(P(C<sub>i</sub>))*  
Depending on what we're working with (multivariate or otherwise), the *p(x|C<sub>i</sub>)* will be different.  
Classification needs to determine the class *given* the data, so it is always a P(C|x) type of problem (posterior form which has prior, ...)  
Then the posteriors form a discriminant.  
This is different from gaussian density estimation because it uses new parameters for each class as opposed to a gaussian distribution which just has one mean and variance. In fact, each class of the classification could have its own gaussian distribution. In this case, the gaussians are the likelihood functions *P(C<sub>i</sub>)*.  
*g<sub>i</sub> = p(x|C<sub>i</sub>)P(C<sub>i</sub>)*
Once we have a model (made up of parameters like mean and variance for a gaussian), we try the new data point *x* with each model using the discriminant function form and see which model yields the highest score. *x* is classified as belonging to that class. 

## Densities
Bernouli Density
Multinomial Density
Gaussian Density


## Multivariate Data
Refers to data where each instance has many features. In this case, you can arrange the instances in a matrix of their feature vectors where each column is made up of an instance's feature vector. Of course, rows and columns are interchangeable. For N instances with d features, we get an N by d matrix.   
Here, the mean E(x) is a vector of the feature-wise means. Covariance is a d by d matrix.  
S<sub>i</sub> is the estimate for the covariance, it replaces the variance used for bivariate classification.  
When variances are the same, the discriminant can be reduced to a nearest mean classifier because it no longer relies on the variance. 

## Model Selection
With limited data, we want a simpler model to avoid overfitting. More data means we can use more complicated models. 

## Example
**Given** a set of N iid (independent and identically distributed) rv (random value) $X=\{x_1, x_2, ...\}$ that follow $P(x|\lambda)=\lambda e^{-\lambda x}$, such that 0<= x < inf and &lambda; > 0  
*P(x|&lambda;)* is a probability density function.  

**Find the MLE** of $\lambda$: $L(\lambda|X)$  
$=L(\lambda|x_1, x_2, ...)$  
$=log(\prod(P(x_i| \lambda)))$  
$=\sum(log(P(x_i|\lambda)))$  
$=\sum(log(\lambda^{-\lambda x}))$  
$=\sum(log(\lambda) - \lambda x_i)$  
Then we take the partial derivative and set it equal to zero which will help us find the maximum of the Log: $\frac{\delta L(\lambda|X)}{\delta \lambda}=\frac{N}{\lambda}-\sum x_i=0$

**Find the MAP** of $\lambda$ where $P(\lambda|\alpha,\beta) = \lambda^{\alpha-1}e^{-\beta \lambda}$  
We use the general form $P(\lambda|x)=P(X|\lambda)*P(\lambda|\alpha,\beta)$  
$\lambda_{MAP}=\frac{\alpha+N-1}{\sum x_i+\beta}$

## Questions
Why are the prior, sample mean, and sample variance included in the discriminant for parametric classification?  
How exactly does the discriminant work? It helps locate the class with mean closest to the sample.   
What is Mahalanobis distance and naive bayes?  
What is gaussian density? It is the y-axis of the bell curve gaussian distribution graph.  
On slide 13/34 of Bayes_Parametric_Multivariate.pdf, how do we maximize the log-likelihood with respect to p? Is it a partial derivative?