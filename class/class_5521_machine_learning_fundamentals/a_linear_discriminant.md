# Linear Discrimination
In the likelihood based model, we assumed a model for $p(x|C_i)$, but in discriminant-based classification, there is no density estimation. We just assumed a model and directly work towards the parameters for that model. We just estimate the boundaries. 

In a likelihood model, we are assuming some type of model for the body of each class. In discriminant based methods, we are not assuming any distribution or model for the data, but rather, we model the boundary between classes. 

In a likelihood mode, we are taking data points and looking at the probability that it came from a certain class (discriminant). In discriminant based models, we are estimating the parameters for the boundary. 

## Some Terms
Discriminant: $g_i(x)$ or $g(x)$ or $g_i(x|w_i,w_{i0})$  
Discriminant in pairwise separation: $g_{ij}(x)$ or $g_{ij}(x|w_{ij},w_{ij0})$ This pairwise   
Error: $E$ or $E(w)$, or $E(w,w_0|X)$  
Log likelihood ratio: $ln\frac{p(x|C_1)}{p(x|C_2)}$  
Log-odds: $logits(P(C_1|x))=log\frac{P(C_1|x)}{1-P(C_1|x)}$ does the inverse of the sigmoid, it transforms 0-1 into -inf to inf. 

## Discriminant to Posterior
$P(C_1|x)=sigmoid(w^Tx+w_0)$ is how we get from discriminant to posterior  
The other way around, $log \frac{P(C_1 |x)}{1-P(C_1|x)}=w^Tx+w_0$

## Linear Discrimination
We only care about the boundary between classes. Usually a linear boundary.  
A point will belong to $C_1$ if $g(x) < 0$  
**Training** phase consists of estimating the discriminant parameters by minimizing training error. We use *gradient descent* to locally minimize the error. $w*=argmin_wE(w|X)$ which is the parameters $w$ that gives the lowest $E(w|X)$. The gradient is $\nabla_wE=[\frac{\delta E}{\delta w_1},\frac{\delta E}{\delta w_2}, ..., \frac{\delta E}{\delta w_d}]^T$ and $w$ starts off as random and then updates in the negative direction $w_i=w_i+\Delta w_i$ and $\Delta w_i=-\eta \frac{\delta E}{\delta w_i}$ Eta $\eta$ is a hyperparameter that helps convergence to the smallest error.  
We start the weights close to zero so that the sigmoid will cause the most drastic updates. We stop the updates when they show very small changes. Error directly correlates with the posterior. The likelihood of the parameters given the data $l(w, w_0|X)$ is a product. Then the error is minimized when we maximize the likelihoods. The textbook example of this sets $E=-log(l)$. However, I think it could also work as $E=\frac{1}{ln(l)}$ where the bigger $l$ becomes, the smaller $E$ is. This should also minimize the error. The entire error function doesn't say anything about $w$.  
$y=sigmoid(\alpha)=\frac{1}{1-g(x)}$  
All in all, we are taking some discriminant ($g(x)$), transforming it into posterior form with a sigmoid ($y$), and then minimizing the error which depends on $y$.     
**Testing** phase for a single class discriminant consists of testing for whether the discriminant evaluates to >0 or <0. We can also use the sigmoid form of the determinant which converts the discriminant to a posterior and and evaluate whether the posterior is >0.5 or <0.5.  

## Logistic Discrimination

$\Delta w_j=-\eta \sum_t (r^t -y^t)x_{j}^{t}$  
Where the smaller the difference between the ground truth label $r^t$ is from the predicted posterior $y^t$, then the smaller $\Delta$ will be and the less our $w$ will change, which means we're nearing the minimum. 

## Example
The posterior follows a Bernoulli distribution because the posterior (y) is squeezed by the sigmoid function. Taking the posterior, you can find the likelihood and then the Error $E=-log(l)$ the negative is so that we can say we minimize the error. Of course we could also not use it and just maximize. 
E is log likelihood, we use gradient descent to optimize it.  

Given that $E(w|X)=-\sum_t(r^t log(y^t)+(1-r^t)log(1-y^t)$ where $r^t$ is a label, so it's a constant, $E$ is a function of $y$, $y^t$ is a function of $\alpha^t$, and $\alpha^t =w^T x^t +w_0$

1). Find the update equation of $w_j$ which will use gradient descent. $w_j=w_j+\Delta w_j$ and $\Delta w_j=-\eta \frac{\delta E}{\delta w_j}=-\sum_t \frac{\delta E}{\delta y^t} \frac{\delta y^t}{\delta \alpha^t} \frac{\delta \alpha^t}{\delta w_j^t}$

Conventionally speaking,  
$\frac{\delta E}{\delta y^t}=(\frac{r^t}{y^t}-\frac{1-r^t}{1-y^t})$

$\frac{\delta y^t}{\delta \alpha^t}=y^t(1-y^t)$ which is specific to the sigmoid activation function. 

$\frac{\delta \alpha^t}{\delta w_j^t}=x_j^t$

So then...

$\frac{\delta E}{\delta w_j}=-\sum_t (\frac{r^t}{y^t}-\frac{1-r^t}{1-y^t}) y^t(1-y^t) x_j^t$

$\frac{\delta E}{\delta w_j}=-\sum_t (r^t-y^t) x_j^t$

2). What is the update equation of $w_0$?

It is the same except that $\frac{\delta \alpha^t}{\delta w_0^t}=1$ because the $w_0$ term of $\alpha^t$ has no $x$ term. 

$\frac{\delta E}{\delta w_j}=-\sum_t (r^t-y^t)$