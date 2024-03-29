# Implementing algorithms from scratch
### Statistics with Numpy
Indexing with Numpy can be done like  

To extract samples with label 0
```
x = X[y==0,]
```

Extract samples with first feature larger than 0.5?
```
x = X[X[:, 0] > 0.5]
```

When calculating mean with ```np.mean()``` pay attention to the axis as ```np.mean(X,axis=0)``` will average along the rows and ```np.mean(X,axis=1)``` is along the column

### Matrices
Matrix operations can be performed.  

For 
```
n, m, k, c = 100, 10, 5, 10
x = np.random.random([n,m])
y = np.random.random([n,c])
z = np.random.random([n,k])
v = np.random.random([k,c])
```
How do we implement
![matrix](/images/matrix.png)

```
delta = x.T.dot(y.dot(v.T)*z)
```
We are using matrix multiplication to simultaneously perform the summation and multiplication. 

### ML Code Organization
Organize as "data processing", "training", and "evaluation".  


Training uses two loops, outer loop for each epoch, where a epoch runs through the data once, and the inner loop is for training

Evaluation compares prediction against ground truth. 

### Analyzing Results
Look at differences, identify the reasons behind the differences, connect settings/parameters to results

### Libraries
*Can't be used in this class*  
Sci-kit learn  
Pytorch and Tensorflow for deep learning  
Kaggle for activities to practice ML