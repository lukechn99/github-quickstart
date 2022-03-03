# Clustering

## K-means algorithm (centroid-based method)
The goal is to represent the data as k clusters with each cluster having a mean.  
Create cluster prototype, a $\mu_k$, randomly. 

For each datapoint, it can only be assigned to one class

There is a distortion measure which is the objective function
$J=\sum_{n=1}^{N}\sum_{k=1}^{K}r_{nk}||X_n-\mu_k||^2$
Where the double bars represent the L2 norm, aka the distance between two points in a d-dimensional space. The $r_{nk}$ component just filters out all means that belong to clusters we don't care about. If we were to try out $||X_n-\mu_k||^2$ for all $\mu_k$, then we should find the value is smallest for when $k$ is the cluster that best fits the data point $x_n$. So we want to minimize $J$ which is the sum of the distance from all data points to their cluster means. We want to tune $r_{nk}$ and $\mu_k$ to minimize $J$. The objective function is designed to be used in unsupervised learning because no labels are used and the distances of the datapoints are used to speak for themselves.   

**Expectation-step**: minimize $J$ with respect to $r_{nk}$ and keep $\mu_k$ fixed  
**Maxmimization-step**: minimize $J$ with respect to $\mu_k$ and keep $r_{nk}$ fixed. When $r_{nk}$ is fixed, we don't need the inner summation anymore and jsut use $2\sum_{n=1}^{N}r_{nk}(x_n-\mu_k)=0$

This gives us a local search which is less computationally expensive than optimizing globally.  
Intuitively speaking, we want to 1). choose a $k$ such that $||X_n-\mu_k||^2$ is the smallest one and 2). choose $r_{nk}$ for the smallest one.  

**How to we assign k?** We can try out different K and see which has highest accuracy. 

As we iterate through this optimization process, $J$ should be monotonically decreasing.  

As new data comes in, we can use a learning rate to adjust the cluster mean with some learning rate weight.  

## Latent Variables, Expectation Maximization (EM) for Gaussian Mixtures
With expectation maximization, instead of an absolute clustering, data points are given an expected value.  
EM can be used for k-means, for gaussian mixtures, and other problems.

You can use a latent variable $z$ that represents 1 or 0 based on cluster classification  

For this we use a prior, $p(z_k)=\pi_k$ which is the probability of that cluster occuring, $p(x|z_k=1)=N(x|\mu_k, \sum_k)$ which models a gaussian distribution. *Using the Gaussian mixture assumes an underlying distribution for the data*. 

The log likelihood is the objective function: $ln(p(X|\pi,\mu,\sigma))=\sum_{n=1}^{N}ln\{\sum_{k=1}^{K}\pi_kN(x_n|\mu_k,\sigma_k)\}$

Using gaussian mixtures is more accurate than k-means, but also need more information/parameters like nu, sigma, and pi. 

## Example
Q: $x_1=3, x_2=4, x_3=5, x_5=9, x_6=11$  
Perform **k-means clustering** with k=2  
1). initialize means: $m_1=0$, $m_2=9$. We choose these means randomly  
2). assignment: $cluster_1=\{x_1,x_2\}$, $cluster_2=\{x_3,x_4,x_5,x_6\}$  
3). update means: $m_1=3.5$ and $m_2=8$  
4). assignment: $cluster_1=\{x_1,x_2,x_3\}$, $cluster_2=\{x_4,x_5,x_6\}$  
5). update means: $m_1=4$ and $m_2=9$  
6). We are done since re-assignment would not change anything. We would also be done if changes are reasonably small. At this time, we've minimized the objective function  

Find the **distortion measure/reconstruction error $J$** to check the final results and see how well we minimized $J$

7). $J=\sum_{n=1}^{N}\sum_{k=1}^{K}r_{nk}||X_n-\mu_k||^2=(3-4)^2+(4-4)^2+(5-4)^2+(7-9)^2+(9-9)^2+(11-9)^2=10$