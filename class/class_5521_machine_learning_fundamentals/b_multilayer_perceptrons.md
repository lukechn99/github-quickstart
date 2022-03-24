# Multilayer Perceptrons
Perceptrons are the basic unit

The linear decision boundary is determined from 

Threshold function evaluates to 0 or 1

Perceptrons can be used to replace certain components in regression and classification models

We want to find the weights that match up to the inputs

With multiple perceptrons, each input is linked to each perceptron and each perceptron has a link to each input. In this case, the $w$ becomes a matrix $W$ that holds all of the weights for those perceptrons. 

## Training
Similar to gradient descent method is used to train the weights $w$.  
We can do this in an online method where data streams in and in a batch method where we train on a body of data at once. 

$m$

Sometimes, no configuration of weights can represent a dataset, so we need a multilayer perceptron.  
With a multilayer perceptron, we can update weight parameters by backpropagating errors to update weights at lower layers.  

For **Regression**, we start with input $x$, and end up at output $z_h=sigmoid(w_h^Tx)$ where $w$ values are the weights applied to $x$. Then $z_h$ becomes the input for the second layer which spits out an output of $y^t=\sum_{h=1}^{H}v_hz_h^t+v_0$ where $v$ values are the weights applied to $z$. And there may be many more layers involved as well. **This forms the forward propagation of a multilayer perceptron**.  

Then we want to adjust the weights and make them more accurate, so we backpropagate the error in the final output. $E(W,\nu|X)=\frac{1}{2}\sum_t(r^t-y^t)^2$, then we take the gradient with respect to $\nu_h$ to minimize the error (?). Then 

$$\Delta \nu_h=\eta \sum_t(r^t-y^t)z_h^t$$ 

and 

$$\Delta w_{hj} = -\eta \frac{\delta E}{\delta w_{hj}}$$
$$=-\eta \sum_t \frac{\delta E}{\delta y^t}\frac{\delta y^t}{\delta z_h^t}\frac{\delta z_h^t}{\delta w_{hj}}$$

Which brings us back to our original weights $w$

$$=-\eta \sum_t -(r^t-y^t) \nu_h z_h^t (1-z_h^t)x_j^t$$
$$=\eta \sum_t (r^t-y^t) \nu_h z_h^t (1-z_h^t)x_j^t$$

I assume that from here, we set the gradient equal to 0 and solve for the weights to find the most accurate ones. 

**When data is not linearly separable in the original feature space, we can transpose it to another space where it can be separable**. When looking at the plot of a boolean XOR, the points cannot be linearly separated in terms of $x_1$ and $x_2$, but with perceptrons, we can transform the input into some $z_1$ and $z_2$ that are linearly separable. 

**XOR Example**:  
----|----|----|

AND: $w = [-1.5, 1, 1]^T$  
OR: $w = [-0.5, 1, 1]^T$  
NAND: $w = [1.5, -1, -1]^T$  
NOT: $w = [0.5, -1]^T$  
We always want to try to find a line that can linearly separate the data, and then we try to derive the weights from that line.  
More complex booleans or problems that have multilayered booleans should use a multiplayered perceptron. 

## Questions
What is the first input for? It's to tip the scale in an activation function. There is an "input = 1" and weight that simply don't correlate to any actual input feature, but exist for tipping the activation. $-0.5$ is chosen for a boolean regression problem where booleans are represented as 1 and 0 because it's an intermediary value.   
For learning the boolean AND, are we giving the threshold function to the perceptron? $y = S(x_1 + x_2 - 1.5)$