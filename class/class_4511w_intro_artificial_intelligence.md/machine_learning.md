Essentially we try to optimize for the patterns found in the training data. 

We have a generating function that generates values and feeds it to a model. 
We want to train a function (model) h(x) that approximates the real unknown function f(x)  
structured data is a table, unstructured is something like a picture or text

### Classifications
binary classification: f({cat, non-cat}) = {1, 0}

### Process
We have training data, often a vector of length k  
Then we create the input matrix by putting together all the training data together, either as columns or rows  
Overfit models will fail when given an outlier input

### Logistic Regression
part of the linear family of classification models. it is a nn without a hidden layer. It will find a decision boundary with which to make choices; it will learn what line or plane best separates the data. 
```
given x, generate output y = P(y=1|x)
```
This model uses weights and biases  
For a linear model, y = weight * x + bias  
Other model outputs will use a logistic sigmoid  
```
sig(z) = 1/(1 + e^-z)
```
Because y is a probability, we cannot use a line because that line will create probabilities above 1 and below 0. The logistic sigmoid will squeeze the probability to be between 0 and 1.  
```
y = sig(w * x + b)
```
When x has more than one dimension, then it is w dot x.  

## Loss Function

$lossFunction(y_{pred}, y_{truth}) = float$: error  
Measures how well the model was trained. It measures the distance between the prediction and label/ground truth/truth. The goal is to minimize the value of the loss function.  
A loss function used on logistic regression is  

```

L(ypred, ytrue) = -(ytruelog(ypred) + (1-ytrue)log(1-ypred))

```  

Then we take the average of L() over all datapoints and try to minimize this. The two parameters that can change how much loss we have are W and B. So we can continually tweak W and B to get close to 0 loss.  

```

J(w, b) = avg(L(ypred, ytrue))

```

## Gradient Descent

For gradient descent, we just have J(w) = avg(L(ypred, ytrue))  
So the loss just optimizes w, we calculate derivatives/gradients to move w towards the lowest j.

Forward propagation calculates the values

## Logistic Regression Training

Predates NN, and can even be said to be a shallow NN.

## Neural Networks

Standard - feed forward multi level perceptron NN, very general, not very good on specific fit  
Convolutional - sequences of vectors/matrices/tensors, more used in CV  

In standard NN, the hidden nodes each have a value that are produced like in logistic regression (like sig(w * x + b))  
Each layer has several nodes, we pass the activation from the previous layer to the new layer. The logistic regression process happens at each node of each layer.

![nn](/nn.png)

## Activation function

Sigmoid helps capture signal strength, is good for output layers.  
Besides sigmoid activation functions, there are others like ReLU (rectified linear unit, which basically converts negatives to 0, and integer z otherwise), there's also hyperbolic tangent which is kind of like sigmoid, except it centers around (0,0)

## Parameters vs. Hyperparameters

Hyperparameters are set before training, they can include learning rate, number of training iterations, number of hidden layers, size of hidden layers, choice of activation function

## Implementation

Train test split  
Define layers and the activation for the layer as well as a output layer  
Compile  
Fit to the training data  

## Supervised Learning, Unsupervised Learning, Reinforcement

- Supervised is NN (like taking a class, examples are given). You want to divide the data into 3 sets (training, validation, testing). Once trained, you can optionally tune hyperparameters on the validation data, and then test it on the test set. How big/many layers should the network have? Not necessarily the more the better. Too few will mean you might not classify correctly, and too many means the network may be overfit on the data. 
- Unsupervised is like coming up with concepts by yourself, it is becoming more popular because having labelled data is hard to come by. K-means is one example of unsupervised learning. It tries to group by classes/clusters using points in an n-dimensional space. 
- Reinforcement Learning is done through interactions with the environment
