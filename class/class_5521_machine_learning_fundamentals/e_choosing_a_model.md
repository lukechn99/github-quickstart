# How to Choose a Model

We should consider

- Is the data labelled? (supervised versus unsupervised learning)
- Amount of data? (model complexity)
- Type of data?
- Interpertability? (some applications need results to be interpretable)
- Goals and constraints? (Accuracy, speed, scalability, do we want to reduce the dimension of the data?)

## Types of Models

Parametric

- Simple data, simple model:
    - Linear discriminant
    - Logistic regression
    - Single perceptron
    - SVM
- Complex data
    - MLP
    - Decision Trees
    - SVM with kernel
    - NN + SVM

Non-parametric (no assumed distribution):

- Knn

There are combinations and ensembles of models

## Case Studies

Deciding whether or not to approve a budget for a product: We could use a decision tree if the interpertability is important. If not as important, then a random forest could provide more accuracy.

Detect pedestrians in an image: Convolutional neural network if there are many images.

Self driving cars: need a fast and simple model

Medical field diagnostics: accuracy and interpertability are most important.

Kernels are not limited to SVM but can be used in any scenario where it would be advantageous to transform data from one space to another space.
