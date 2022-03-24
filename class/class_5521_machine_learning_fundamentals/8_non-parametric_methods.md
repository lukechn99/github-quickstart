# Non-Parametric Methods

## Parametrics Methods
Data is assumed to come from some known model like a gaussian distribution or bernoulli distribution.

## Non-Parametric Methods
No assumed distribution. However, similar inputs have similar outputs and functions change smoothly.  
We rely on neighboring datapoints to interpolate from instead of having a global model.  
We use a sample set to derive an estimator of the PDF and CDF and decide on a neighborhood size for the neighborhoods.  

## Cumulative Density Function
$\hat{F}(x)=\frac{number \ of \ data \ points \ < \ input \ data}{total \ number \ of \ data points \ (N)}$

## Probability Density Function
$\hat{p}(x)=\frac{1}{h}[\frac{number \ of \ data \ points \ less \ than \ x+h \ minus \ number \ of \ data \ points \ less \ than \ x}{N}]$   
Where $h$ is the bin size (neighborhood size)

## Histogram Estimator
$\hat{p}(x)=\frac{number \ of \ datapoints \ in \ bin}{Nh}$  
Where $\hat{p}(h)$ is the height of each column and $h$ is the width of each column.  
The smaller the $h$, the more accurate each bucket is, however, the less datapoints we're able to consider per bucket. The higher the $h$, the smoother the overall curve. 

## The Naive Estimator
Whereas the histogram method (of using a fixed estimator) is fixed, the naive estimator doesn't have fixed bins and can move around and stays centered around $x$.  
$\hat{p}(x)=\frac{number \ of \{ x-h<x^t\leq x+h\}}{2Nh}$  
It is a moving window centered on $x$. 
This form is equivalent to saying that $\hat{p}(x)=\frac{1}{Nh}\sum_{t=1}^{N}w(\frac{x-x^t}{h})$ where $w(u)=\frac{1}{2}$ if $|u|<1$ and 0 otherwise 
The naive estimator gives a much bumpier histogram graph. 

## Kernel Estimator
While the naive estimator uses a uniform kernel function $w$, the kernel estimator uses a more generic form of $K(u)$ in the kernel estimator $\hat{p}(x)=\frac{1}{Nh}\sum_{t=1}^{N}K(\frac{x-x^t}{h})$. For example if the kernel function for a gaussian kernel would be $K(u)=\frac{1}{\sqrt{2\pi}}exp[-\frac{u^2}{2}]$  
The kernel becomes the weighted average of points nearby.  
Ends at 40 minute mark in the lecture. 

## k-Nearest Neighbor Estimator
Rather than fix the distance $h$, we fix $k$, the number of neighbors.  
$\hat{p}(x)=\frac{k}{2Nd_k(x)}$  
This effectively creates a smaller $h$ for denser areas and a larger $h$ for sparse areas.  

## Non-Parametric Classification
The formulation of the discriminant is still the same: $discriminant \ (or posterior)=likelihood*prior$
$g_i(x)=\hat{p}(x|C_i)\hat{P}(C_i)=\frac{1}{Nh^d}\sum_{t=1}^{N}K(\frac{x-x^t}{h})r_i^t$  
How this works is that when a new datapoint comes in, its classification is determined based on what's nearby and how close those points are. The closer the point, the more weight it has on the classification. 

With kNN classification, we choose the class with most neighbors within a neighborhood of size $k$. 

## k and h
Small values mean single instances matter more. Bigger k and h values means we average over more instances and create a smoother curve. We can finetune k and h

## Main Idea
```
Kernel Estimator
    |- uniform
    |   |- different uniform
    `- Gaussian
        |- different Gaussian
KNN
    `- KNN with different Ks
```

## Example


## Questions
So does that mean non-parametric methods don't find global parameters?  
What do the curves tell you?