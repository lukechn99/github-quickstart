Essentially we try to optimize for the patterns found in the training data. 

We have a generating function that generates values and feeds it to a model. 
We want to train a function (model) h(x) that approximates the real unknown function f(x)  
structured data is a table, unstructured is something like a picture or text

### Classifications
binary classification: f({cat, non-cat}) = {1, 0}

### Process
We have training data, often a vector of length k  
Then we create the input matrix by putting together all the training data together, either as columns or rows

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

### Loss Function
loss_fn(y<sub>pred</sub>, y<sub>truth</sub>) = float: error  
Measures how well the model was trained. It measures the distance between the prediction and label/ground truth/truth. The goal is to minimize the value of the loss function.  
A loss function used on logistic regression is  
```
L(ypred, ytrue) = -(ytruelog(ypred) + (1-ytrue)log(1-ypred))
```  
Then we take the average of L() over all datapoints and try to minimize this. The two parameters that can change how much loss we have are W and B. So we can continually tweak W and B to get close to 0 loss.  
```
J(w, b) = avg(L(ypred, ytrue))
```

### Gradient Descent
For gradient descent, we just have J(w) = avg(L(ypred, ytrue))  
So the loss just optimizes w, we calculate derivatives/gradients to move w towards the lowest j. 

Forward propagation calculates the values