# Support Vector Machines

While many linear discriminants are valid for dividing classes, we want to make it so that it the discriminant is maximally distant from both classes.  

We call the linear discriminant $w^Tx+w_0=0$ the hyperplane. Every data point $x^t$ has a distance $d^t$ from the hyperplane, and we have two.

In the past, we've classified a data point as beinging to a class based on whether the discriminant is positive or negative, but now we actually want it to be some distance away.

\[w^Tx^t+w_0 \geq +1\]

\[w^Tx^t+w_0 \leq -1\]

For datapoints classified as 1 or -1 respectively. 