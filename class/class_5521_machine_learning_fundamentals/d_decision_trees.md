# Decision Trees

These trees are made up of decision nodes and label nodes (leaves). The decision nodes represent some attribute of the data that we are splitting by. For example imagine we are predicting loan data. Attributes are age, income, net worth, etc. and the label is a yes or no for whether or not a loan is given. The we want to choose the attribute that discriminates best among labels first and continue from there.

## Feature Selection

We use an impurity measure to determine how much entropy, or how good the split is. The methods for feature selection include:

Entropy: $\phi(p,1-p)=-plog_2p-(1-p)log_2(1-p)$

Gini index: $\phi(p,1-p)=2p(1-p)$

Misclassification error: $\phi(p,1-p)=1-max(p, 1-p)$

All of these functions roughly peak when $p$ and $1-p$ are close to $\frac{1}{2}$ and go to zero as either $p$ or $1-p$ go to 1 or 0.

## Pruning

Fitting exactly to the data causes high variance, low bias, and high model complexity. As model complexity increases, both training error and test error will decrease down to a point. However, after that point, as the model complexity continues increasing, training error continues decreasing while testing error will start increasing. When we prune a tree, either by setting a limit on depth at creation or by cutting off subtrees after creation, we decrease the complexity. A decision tree, left to itself, will tend to overfit and so a random forest method or some kind of pruning is usually needed.

## Ensemble Methods (Bagging and Random Forest)

The whole is greater than the sum of the parts and this holds true for ML; 3 classifiers with 70% accuracy together will give about 78% accuracy.

Bagging uses different randomly selected samples of the data set to generate diverse classifiers.

Random forests average multiple deep decision trees trained on different parts of the data set to reduce variance. Splits are decided on by looking at a random subset of attributes and not all of them. Then majority vote is used among the different trees to decide on a classification.

## Questions

How would you rebalance a decision tree as more information comes in?

Is the only reason to choose an SVM over a linear discriminant the generalizability/margins?
