# Supervised Learning
Supervised Learning uses labelled data. The other two types, unsupervised and reinforcement, use other methods. 

# Classification
Classification problems use discrete class labels. 

### Features
A feature vector is an n-dimensional vecture used to represent an object. Feature vectors live in the feature space which has the same number of dimensions as the data it holds. Feature extraction is often hand-coded; this was more common in older days. Today, we do feature extraction with deep learning. 

### Empirical Error, Generalization Error
We have a training set X   
We have a hypothesis class *H = {h}* which takes an input of x and outputs a class label. *H* represents the type model (linear or quadratic) and *h* is the specific linear, quadratic, or plane that it corresponds to. The ultimate goal is to have *Error(h|H) = 0* for some really good *h*. The case when we have h|H is called **realizable learning**. However, if the function needed to make the error 0 is not found in H, then it is an **unrealizable learning** and we just try to approximate the best we can.    
The empirical error rate is calculated by counting the number of times the calculated value is different from the predicted on the *training set* (error increases by 1 when the output from H(x) doesn't match the label on training data)  
The generalization error comes from the performance on the *testing set*  

ex. If we plot all cars on a graph based on engine size and price to classify which ones are family cars, we can imagine a scatter graph where some points are known to be family cars and some aren't (provided by the training data). Then we decide that drawing a rectangle around all of the family car points is a good hypothesis class *H*, and then we decide on a set of boundaries for the rectangle such that the rectangle includes all family car points and excludes all other points *h*. If this is possible, we have realizable learning and we can look for a more generalized rectangle *h<sub>1</sub>* that stretches as far out as possible while maintaining accuracy and more specific rectangle *h<sub>2</sub>* that shrinks as far in as possible while still including all family car points. The actual *h* that you should choose should be equally distant from both *h<sub>1</sub>* and *h<sub>2</sub>*.  

Sometimes you won't get a simple rectangle to separate data so well. You could potentially use a complicated looking blob to represent the data, but it is generally better to stick to simpler models because it is easier to train, easier to explain, and generalizes better. It is not good to train your model to accomodate the noise

### Multi-class classification
With more than one class, we can extrapolate 

# Regression
Regression problems use continuous functions 

### Model
The model *g(x)* is a function that changes based on the type of regression used. For linear regression, *g(x)* is a linear function. 

### Empirical Error
Empirical error for regression for some model *g* based on training set X is calculated with squared error, calculated with the label minus predicted all squared, rather than the discrete 1-0 error used by classification problems. 

We take the sum of (r<sup>t</sup> - (*w<sub>1</sub>* **x**<sup>t</sup> + *w<sub>0</sub>*))<sup>2</sup> to calculate error. We can see that error is minimized as *w<sub>1</sub>* and *w<sub>0</sub>* approach their correct values. We solve by setting the gradient to 0 and solve through differentiation. Simply speaking, setting the gradient to 0 and solving for x is how we find the minimum (argmin) of a concave function. 

### Generalization Error
Typically, generalization error = empirical error + model complexity, and the goal is to get a low generalization error, so it is advantageous to choose a simpler model. A high model complexity usually results in **overfitting** which means it is trained to fit the noise in the data; this results in a very low empirical error, because it fits the training data completely, but causes very high generalization error. 

# K-fold Cross Validation
Split the dataset into k number of folds, each fold is split and shuffled into a training set and testing set. Each fold is individually used to train and test the model and an accuracy score is collected. 

### Questions
What is majority signal rule?