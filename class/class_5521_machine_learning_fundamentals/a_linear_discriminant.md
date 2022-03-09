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
**Training** phase consists of estimating the discriminant parameters by minimizing training error.   
**Testing** phase for a single class discriminant consists of testing for whether the discriminant evaluates to >0 or <0. We can also use the sigmoid form of the determinant which converts the discriminant to a posterior and and evaluate whether the posterior is >0.5 or <0.5.  

## Example
The posterior follows a Bernoulli distribution because the posterior (y) is squeezed by the sigmoid function. Taking the posterior, you can find the likelihood and then the Error $E=-log(l)$ the negative is so that we can say we minimize the error. Of course we could also not use it and just maximize. 
E is log likelihood, we use gradient descent to optimize it.  

Q: Cross Entropy: $E(w|X)=-\sum_t (r^tlogy^t+(1-r^t)log(1-y^t))$  
Find the update equation of $w_j$  
$w_j=w_j+\delta w_j$, $\delta w_j=-\eta \frac{\delta E}{\delta w_j$