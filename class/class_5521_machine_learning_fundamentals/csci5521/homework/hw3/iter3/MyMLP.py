import numpy as np

'''
this programming assignment will test the implementation of MLP (1 hidden layer, 1 output layer)
Here are the things you should implement:
--------------------
(1) You need to implement Normalizer, which basically normalize the data with mean and std
(2) You also need to implement process_label, which converts the label into one hot representations, (e.g. if there are 3 classes (0,1,2), 1 => [0, 1, 0])
(3) Next you are going to implement two activation functions, tanh and softmax, please refer to the notes for the formula
(4) The following things are the implemtantion of MLP, predict() will predict the labels of the given data, with your computed parameters (weight1/2, bias1/2)
(5) You will then implement fit, which use the preprocessed data and labels to
train the parameters (weight1/2, bias1/2) based on gradient descent
(6) get_hidden will return the features of hidden layer tanh(x@weight_1+bias_1)
(7) Lastly, you need to visualize the hidden features in 2d/3d. The code has already been available.
--------------------
Please submit written answers to the written part.
'''

class Normalization:
    def __init__(self,):
        self.mean = np.zeros([1,64]) # means of training features
        self.std = np.zeros([1,64]) # standard deviation of training features

    def fit(self,x):
        """
        you need to normalize the data according to instructions fit() compute 
        the mean and variance from training data, and store them
        """
        # compute the statistics of training samples (i.e., means and std)
        self.mean = np.mean(x, axis=0)
        self.std = np.std(x, axis=0)
        pass # placeholder

    def normalize(self,x):
        """
        you need to normalize the data according to instructions
        normalize() does (x-mean)/(std+1e-15) to normalize the data, 
        the mean and std is computed in previous fit() function
        """
        # normalize the given samples to have zero mean and unit variance (add 1e-15 to std to avoid numeric issue)
        x = (x-self.mean)/(self.std+1e-15)
        return x

def process_label(label):
    """
    you need to convert the label into one hot encodings we try process_label() 
    on a randomlized list: e.g. [1,2]=>[[0,1,0,0,0,0,0,0,0,0],[0,0,1,0,0,0,0,0,0,0]]
    """
    # convert the labels into one-hot vector for training
    one_hot = np.zeros([len(label),10])
    for idx, l in enumerate(label):
        one_hot[idx, l] = 1

    return one_hot

def tanh(x):
    """
    Please use exp(x)-exp(-x)/exp(x)+exp(-x)
    """
    # implement the hyperbolic tangent activation function for hidden layer
    x = np.clip(x,a_min=-100,a_max=100) # for stablility, do not remove this line
    
    f_x = (np.exp(x)-np.exp(-x))/(np.exp(x)+np.exp(-x))

    return f_x

def softmax(x):
    """
    Please use exp(xi)/sum_i=1toN exp(xi) to compute
    """
    # implement the softmax activation function for output layer
    f_x = np.exp(x) / sum(np.exp(x))

    return f_x

class MLP:
    def __init__(self,num_hid):
        # initialize the weights
        self.weight_1 = np.random.random([64,num_hid])
        self.bias_1 = np.random.random([1,num_hid])
        self.weight_2 = np.random.random([num_hid,10])
        self.bias_2 = np.random.random([1,10])

    def fit(self, train_x, train_y, valid_x, valid_y):
        """
        This function will train on the training set, and use the validation error to determine when to stop
        Since the lr is given, the final parameters should be consistent to one set of fixed values
        """
        # learning rate
        lr = 5e-3
        # counter for recording the number of epochs without improvement
        count = 0
        best_valid_acc = 0

        # normalize the data
        norm = Normalization()
        norm.fit(train_x)
        train_x = norm.normalize(train_x)

        """
        Stop the training if there is no improvment over the best validation accuracy for more than 50 iterations
        """
        w = self.weight_1
        w_0 = self.bias_1
        x = train_x
        v = self.weight_2
        v_0 = self.bias_2
        r = train_y
        # print(r.shape)
        while count<=50:
            # training with all samples (full-batch gradient descents)
            # implement the forward pass (from inputs to predictions)

            # starting with data, dot multiply with weights
            alpha = x @ w + w_0

            # input into tanh activation function
            z = tanh(alpha)

            # dot multiply
            beta = z @ v + v_0

            # input into softmax activation function
            y = softmax(beta)

            # implement the backward pass (backpropagation)
            # compute the gradients w.r.t. different parameters
            delta_v = z.T @ (y - r)
            delta_v_0 = np.sum(y - r, axis=0) # y - r results in a 1000x4, so we sum over n to get a 1x4

            delta_w = x.T @ np.multiply((1 - np.power(z,2)), (y - r) @ v.T)
            delta_w_0 = np.sum(np.multiply((1 - np.power(z,2)), (y - r) @ v.T), axis=0) # this results in a 1000x10 so we sum to get 1x10

            # print(delta_v_0.shape, delta_w_0.shape)

            # update the parameters based on sum of gradients for all training samples
            v = v - lr*delta_v
            v_0 = v_0 - lr*delta_v_0
            w = w - lr*delta_w
            w_0 = w_0 - lr*delta_w_0

            # evaluate on validation data
            predictions = self.predict(valid_x) # predictions are length 10 vectors
            # print(valid_x.shape, predictions.reshape(-1).shape, valid_y.reshape(-1).shape)
            valid_acc = np.count_nonzero(predictions.reshape(-1)==valid_y.reshape(-1))/len(valid_x)

            # compare the current validation accuracy with the best one
            if valid_acc>best_valid_acc:
                best_valid_acc = valid_acc
                count = 0
            else:
                count += 1

        return best_valid_acc

    def predict(self,x):
        w = self.weight_1
        w_0 = self.bias_1
        v = self.weight_2
        v_0 = self.bias_2

        # generate the predicted probability of different classes
        alpha = x @ w + w_0

        # input into tanh activation function
        z = tanh(alpha)

        # dot multiply
        beta = z @ v + v_0

        # input into softmax activation function
        class_probabilities = softmax(beta)

        # convert class probability to predicted labels
        y = np.zeros([len(x),]).astype('int') # placeholder
        for idx, probabilities in enumerate(class_probabilities):
            y[idx] = np.argmax(probabilities)

        return y

    def get_hidden(self,x):
        """
        You need to compute the z(value for the hidden layer; with tanh included) and retrieve it.
        """
        # extract the intermediate features computed at the hidden layers (after applying activation function)
        z = tanh(x@self.weight_1+self.bias_1)

        return z

    def params(self):
        return self.weight_1, self.bias_1, self.weight_2, self.bias_2
