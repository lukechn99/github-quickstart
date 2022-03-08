# Linear Discrimination
In the likelihood based model, we assumed a model for $p(x|C_i)$, but in discriminant-based classification, there is no density estimation. We just assumed a model and directly work towards the parameters for that model. We just estimate the boundaries. 

## Some Terms
Discriminant: $g_i(x)$ or $g(x)$ or $g_i(x|w_i,w_{i0})$  
Discriminant in pairwise separation: $g_{ij}(x)$ or $g_{ij}(x|w_{ij},w_{ij0})$  
Error: $E$ or $E(w)$, or $E(w,w_0|X)$  
Log likelihood ratio: $ln\frac{p(x|C_1)}{p(x|C_2)}$  
Log-odds: $logits(P(C_1|x))=log\frac{P(C_1|x)}{1-P(C_1|x)}$ doess the inverse of the sigmoid, it transforms 0-1 into -inf to inf. 

## Linear Discrimination
We only care about the boundary between classes. Usually a linear boundary.  
A point will belong to $C_1$ if $g(x) < 0$

## Example
The posterior follows a Bernoulli distribution because the posterior (y) is squeezed by the sigmoid function. Taking the posterior, you can find the likelihood and then the Error $E=-log(l)$ the negative is so that we can say we minimize the error. Of course we could also not use it and just maximize. 
E is log likelihood, we use gradient descent to optimize it.  

Q: Cross Entropy: $E(w|X)=-\sum_t (r^tlogy^t+(1-r^t)log(1-y^t))$  
Find the update equation of $w_j$  
$w_j=w_j+\delta w_j$, $\delta w_j=-\eta \frac{\delta E}{\delta w_j$