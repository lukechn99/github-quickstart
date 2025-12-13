"""
In this programming assignment, we are going to implement the decision tree with recursion. The recommended implementation order of the functions are:
1. compute_node_entropy: compute node entropy based with the given labels (sum -p*log2(p+1e-15), where p is the probability of each label)
2. compute_split_entropy: given the left and right labels of the split, first compute the entropy of left and right labels with (1), and then weighted combine them to get the split entropy
3. select_features: given the data and label, iterate through all possible features for split, and use (2) to compute the entropy. Select the feature index with best(lowest) entropy
4. generate_tree: given all the data/label and min_entropy, generate the tree with recursion: the structure could be like follow: (Stop Criteria; Find the feature of current split (3); recursively             call itself again with left/right data/labels). With this structure, the function will recursively find the feature and also the feature for their left/right children, until the stop criteria is reached
5. Decision_tree.predict: given each test data, you can traverse the tree to find its corresponding labels and return the labels
--------------------
Here are some clarifications:
For all test, we only test the functionality of each function, please report your answers in the pdf files.
To ensure a deterministic result, don't shuffle data.
"""

import numpy as np

class Tree_node:
    """
    Data structure for nodes in the decision-tree
    """
    def __init__(self,):
        self.feature = None # index of the selected feature (for non-leaf node)
        self.label = -1 # class label (for leaf node), -1 means the node is not a leaf node
        self.left_child = None # left child node
        self.right_child = None # right child node

class Decision_tree:
    """
    Decision tree with binary features
    """
    def __init__(self,min_entropy):
        self.min_entropy = min_entropy
        self.root = None

    def fit(self,train_x,train_y):
        # construct the decision-tree with recursion
        self.root = self.generate_tree(train_x,train_y)

    def predict(self,test_x):
        # iterate through all samples
        prediction = np.zeros([len(test_x),]).astype('int') # placeholder

        cur_node = self.root
        
        for i in range(len(test_x)):
            # traverse the decision-tree based on the features of the current sample till reaching a leaf node
            label = -1
            while cur_node != None:
                label = cur_node.label
                feature = cur_node.feature
                if feature != None and test_x[i, feature] == 0:
                    cur_node = cur_node.left_child
                elif feature != None:
                    cur_node = cur_node.right_child
                else:
                    cur_node = None
            prediction[i] = label
            cur_node = self.root
        return prediction

    def generate_tree(self,data,label):
        # initialize the current tree node
        cur_node = Tree_node()

        # compute the node entropy
        node_entropy = self.compute_node_entropy(label)

        # determine if the current node is a leaf node based on minimum node entropy (if yes, find the corresponding class label with majority voting and exit the current recursion)
        if node_entropy < self.min_entropy:
            # find most common label under this node
            dict = {}
            count, itm = 0, 0
            for item in label:
                dict[item] = dict.get(item, 0) + 1
                if dict[item] >= count :
                    count, itm = dict[item], item

            cur_node.label = itm
            return cur_node

        # select the feature that will best split the current non-leaf node
        selected_feature = self.select_feature(data,label)
        cur_node.feature = selected_feature

        # split the data based on the selected feature and start the next level of recursion
        left_data = data[data[:, selected_feature] == 0]
        left_label = label[data[:, selected_feature] == 0]
        right_data = data[data[:, selected_feature] == 1]
        right_label = label[data[:, selected_feature] == 1]

        # recursion
        cur_node.left_child = self.generate_tree(left_data, left_label)
        cur_node.right_child = self.generate_tree(right_data, right_label)

        return cur_node

    def select_feature(self,data,label):
        # iterate through all features and compute their corresponding entropy
        entropy = []
        for i in range(len(data[0])):

            # compute the entropy of splitting based on the selected features
            left = label[data[:, i] == 0]
            right = label[data[:, i] == 1]
            entropy.append(self.compute_split_entropy(left, right))

        # select the feature with minimum entropy
        best_feat = entropy.index(min(entropy[1:]))
        return best_feat

    def compute_split_entropy(self,left_y,right_y):
        # compute the entropy of a potential split (with compute_node_entropy function), left_y and right_y are labels for the two branches
        left_weight = len(left_y) / (len(left_y) + len(right_y))
        right_weight = len(right_y) / (len(left_y) + len(right_y))
        split_entropy = left_weight * self.compute_node_entropy(left_y) + right_weight * self.compute_node_entropy(right_y)

        return split_entropy

    def compute_node_entropy(self,label):
        # compute the entropy of a tree node (add 1e-15 inside the log2 when computing the entropy to prevent numerical issue)
        # calculate the probability 'p' of the label
        
        entropies = []
        for l in range(10):
            p = (label == l).sum() / max(len(label), 1)
        
            # sum -p*log2(p+1e-15)
            entropies.append(-p * np.log2(p+1e-15))
        node_entropy = np.sum(entropies)
        return node_entropy
