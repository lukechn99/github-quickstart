# Dimensionality Reduction
Project data from a higher dimension to a lower dimension because it can be approximated in a lower dimension without losing too much data. It can be applied to dimensions that are highly correlated or dependent.  
*the curse of dimensionality* happens as the number of dimensions increases, we need more and more data to fully learn about those dimensions.  
Reducing can lower time complexity and space complexity, saves cost of observing features, more robust and simple models that don't overfit as much, simpler to explain, and easier to visualize.  

## Feature Selection vs Extraction
*Selection*: you choose k features to look at where k < d (the number of total dimensions) and ignore the rest  
You need to be somewhat knowledgeable in order to choose the most representative features. There are 2<sup>d</sup> subsets of d features to choose from, so you really need to be knowledgeable. One way to automate feature selection is to do a forward seach or backward search (AI) on all features. Forward search builds the feature set by selecting the best feature at each layer of exploration. Backward search starts with all features in the set and throws out the least helpful. Helpful features are ones that make classification easier. The first iteration will run through all d features to find the best one, and then (d - 1), and so on. To result in a time complexity of O(d<sup>2</sup>)

*Extraction*: project the original d dimensions to k < d new dimensions 

## Principal Components
A coordinate system where new dimensions/variables are linear combinations of the original ones, are orthogonal (uncorrelated) with one another, and capture the original variance. Keep the old dimensions that reflect the ost variance.  
BASICALLY, given a set of datapoints, we want to center the data and then rotate the axis so that we get the variance along an axis. If we have a cloud of datapoints, we will scoot the xy axis so that the origin is at the center of the cloud, and then rotate the axis. Of course, the principal components are not limited to x and y axis. There can be an n-dimensional space that we are ***centering and rotating***. In terms of which principal components are most useful, VARIANCE = KNOWLEDGE. We want to pick the PCs with the highest variance because they tell us the most. So the criteria for picking PC is that it represents the greatest variability in data and is orthogonal to previous PCs. The number of PCs that we want to find should be equal to the dimensions of the data. In 2D data, there are two orthogonal PCs.  

## Finding Principal Components
PCs are expressed as vectors. We project data points onto PCs so this becomes a question of vector and matrix manipulation.  
Assuming the data is centered, we want to find *w*, which is the PC, while maximizing the variance of the data $max_w(w^{T}XX^{T}w)$ such that $w^{T}w=1$ (so we can constrain the length and look at the direction of the PC). Where $XX^{T}$ is the sample covariance and the PCs are the eigenvectors of the sample covariance. Which is just the matrix representation of the typical scalar way of calculating variance: 
$\frac{1}{n-1}\sum_{i=1}^{n}(w^{T}x_i)^{2}$  
The first PC is found when $Var(w^{T}x$ is maximized. Maximized for $\lambda_1$, the max eigenvalue of $XX^{T}$ and $PC_1$ is the corresponding eigenvector. Future PCs need to be the next biggest eigenvalue and be orthogonal to all previous ones. 

## Choosing K for Principal Component Analysis
We want to choose a $k < d$ such that $\frac{\lambda_1+\lambda_2+...+\lambda_k}{\lambda_1+\lambda_2+...+\lambda_k+...+\lambda_d} > 0.9$  
Or in other words, we want to retain 90%+ of the data. 

## Steps for Computing Principal Component Analysis
1. Subtract the mean of the dataset from each datapoint to center the data (only after $\nu=0$ can we use $XX^{T}$ as the covariance matrix)
2. For the covariance matrix $XX^{T}$
3. Find the eigenvalues and eigenvectors of the covariance matrix
4. Rearrange the eigenvectors and eigenvalues
5. Select a subset of eigenvectors to use as the basis while paying attention to maintaining the PoV

# Linear Discriminant Analysis
We have labels to help us unlike in PCA. When we have labels, we don't want lower dimensions with most variance. Instead we want lower dimensions so that when projected onto the dimension, we get labeled data points of the same class to cluster together. 
Find a low dimensional space such that when data is projected, it is still well separated. We want variance within classes to be small and large difference between classes (means of each class are far apart)

Maximize $J(w)=\frac{(m_1-m_2)^{2}}{S_1+S_2}$  
The denominator is the sum of within squares difference. 

## Example
With data points for class A: {(2, 1), (3, 2)} and class B: {(5, 5), (6, 4)}  
**Find $w_1$ using unbiased estimation of covariance using PCA**  
Find the mean of the data $m=\frac{1}{4}((2,1)+(3,2)+(5,5)+(6,4))=(4,3)$  
Find the covariance: $cov(x)=\frac{1}{n-1}XX^{T}=\frac{1}{3}XX^{T}=$ where X is the 2x4 matrix with the centered data points.  
Set the determinant of 

**Find w using LDA**  
$w=c*s_w^{-1}(m_1-m_2)$ where $s_w$ and $m_1$ and $m_2$ are all matrices. They make a vector for $w$



## Review
How to find eigenvalues and eigenvectors  
We use lagrange for the optimization with contraints problem that comes up when we saw that $||w||=1$  
Lagrange works as $L(x,\lambda)=f(x)+\lambda(g(x)-c)$

## Funny Quotes
"How to choose k...? When I have a pretty big D"

## Questions
"We are trying to reach the conclusion that $w_2$ is an eigenvector", but why don't we know? Can't we just find all the eigenvectors and sort them in order?