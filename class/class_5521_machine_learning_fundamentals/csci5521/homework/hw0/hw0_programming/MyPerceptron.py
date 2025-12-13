"""
Below is the pseudo code that you may follow to create your python user defined function.

Your function is expected to return :-
    1. number of iterations / passes it takes until your weight vector stops changing
    2. final weight vector w
    3. error rate (fraction of training samples that are misclassified)

def keyword can be used to create user defined functions. Functions are a great way to
create code that can come in handy again and again. You are expected to submit a python file
with def MyPerceptron(X,y,w) function.

"""
# Hints
# one can use numpy package to take advantage of vectorization
# matrix multiplication can be done via nested for loops or
# matmul function in numpy package


# Header
import numpy as np
import math
MAX_ITER = math.inf

# Implement the Perceptron algorithm
def MyPerceptron(X,y,w0=[1.0,-1.0]):
    k = 0 # initialize variable to store number of iterations it will take
          # for your perceptron to converge to a final weight vector
    w=w0
    error_rate = 1.00

    # loop until convergence (w does not change at all over one pass)
    # or until max iterations are reached
    while k < MAX_ITER:
        k += 1
    # (current pass w ! = previous pass w), then do:
        prev_w = w

        # for each training sample (x,y):
        for i in range(len(X)):
            # if actual target y does not match the predicted target value, update the weights
            pred_y = w[0] * X[i][0] + w[1] * X[i][1]
            print("pred ", pred_y)
            if pred_y * y[i] <= 0:
                print("adjusting because of ", y[i])
                w[0] = w[0] + y[i] * X[i][0]
                w[1] = w[1] + y[i] * X[i][1]

            # calculate the number of iterations as the number of updates
        print("done")
            
        if all(np.equal(w, prev_w)):
            print(k)
            break


    # make prediction on the csv dataset using the feature set
    # Note that you need to convert the raw predictions into binary predictions using threshold 0
    

    # compute the error rate
    # error rate = ( number of prediction ! = y ) / total number of training examples
    for i in range(len(X)):
        if np.dot(X[i], w) < 0 and y[i] == 1:
            error_rate += 1
        elif np.dot(X[i], w) > 0 and y[i] == -1:
            error_rate += 1

    return (w, k, error_rate/len(X))
