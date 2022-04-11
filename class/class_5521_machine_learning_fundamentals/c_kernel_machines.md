# Support Vector Machines

While many linear discriminants are valid for dividing classes, we want to make it so that it the discriminant is maximally distant from both classes.  

We call the linear discriminant $w^Tx+w_0=0$ the hyperplane. Every data point $x^t$ has a distance $d^t$ from the hyperplane, and we have two support vectors parallel to the hyperplane. We also call the datapoints closest to the hyperplane as the support vectors, these points help define the line.

$$d^t=\frac{|w^Tx^t+w_0|}{||w||}$$

$$\rho=\frac{2}{||w||}$$

In the past, we've classified a data point as beinging to a class based on whether the discriminant is positive or negative, but now we actually want it to be some distance away. The distance between support vectors is called $\rho$ and we want to maximize this value.

$w^Tx^t+w_0 \geq +1$ for data $x^t$ that is class $r^t=1$, and

$w^Tx^t+w_0 \leq -1$ for data $x^t$ that is in class, $r^t=-1$

Or $r^t(w^Tx^t+w_0)\geq 1$

We want to maximize $\rho$ which means minimizing $||w||$ subject to the constraint that $r^t(w^Tx^t+w_0) \geq 1$. In total there will be one contraint for each data point, so many contraints. We construct a dual problem by using a lagrange multiplier $\alpha^t$

We have $min\frac{1}{2}||w||^2$ subject to $r^t(w^Tx^t+w_0)\geq 1$

Apply the lagrange and get rid of linear constraints.

Objective function: $L_p=\frac{1}{2}||w||^2-\sum_t \alpha^t[r^t(w^Tx^t+w_0)-1]$

$L_p=\frac{1}{2}||w||^2-\sum_t \alpha^tr^t(w^Tx^t+w_0)+\sum_t \alpha^t$

And then we have the gradients for the weights as...

$\frac{\delta L_p}{\delta w} = ARX$

$\frac{\delta L_p}{\delta w_0} = AR$

converting from a primal to a dual problem by expanding and then plugging in the gradients:  
$L_d=\frac{1}{2}w^Tw+\sum_t \alpha^t$

$=-\frac{1}{2} \sum_t \sum_s \alpha^t \alpha^s r^t r^s(x^t)^Tx^s+\sum_t\alpha^t$

We replace $w$ with alpha in the dual form.

The new constraints are $\sum_t \alpha^tr^t=0$ and $\alpha^t>0$

## Soft Margin Classification

Allows for some of the support vector points to be outside fo the margins. $r^t(w^Tx^t+w_0) \geq 1 - \xi^t$  we add on the slack variable $\xi$

The soft error is $\sum_t \xi^t$

The new primal is $L_p=\frac{1}{2}||w||^2+C\sum_t \xi^t-\sum_t\alpha^t[r^t(w^Tx^t+w_0)-1+\xi^t]-\sum_t\mu^t\xi^t$. This new primal function has the two obejctive functions that are being minimized, the lagrange multiplier $\alpha$, and a langrage multiplier on the slack variable.

## Hinge Loss

One of the many loss functions that exist.

$L_{hinge}=0$ if $y^tr^t \geq 1$ which means there was a correct prediction, otherwise

$L_{hinge}=1-y^tr^t$ which is however much difference there was between 1 and the prediction

## Questions

What is primal versus dual problem?

What is $\alpha$? The lagrange multiplier

Why a dual? What exactly is the significance of the kernel?
