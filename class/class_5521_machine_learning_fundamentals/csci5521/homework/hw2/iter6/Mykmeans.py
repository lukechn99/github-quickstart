#import libraries
import numpy as np

'''
Implementations for Kmeans:
fit() generally does the following things:
1. init self.center as a (k,d) matrix, where k is the number of centers and d is the dimension of the data.
 self.center is initialized with points with pre-defined point index init_idx (e.g init_idx=[1,3] means the 
 first center is X[1], the second center is X[3])
 
2. Update centers iteratively. For the first for loop (for i in range(len(X)):), you will 
 (1) Update the cluster assignment of all data based on euclidean distance 
 (2)record the assignment in cluster_assignment 
 (3)Store that point 
 (4)add the count +1 for that class
 Please note that we have new_center['center'] and new_center['num_sample'] to store the point in 
 corresponding cluster and count the total number. As what we need later is the summation of points belongs 
 to a class, you can store sums rather than individual points
 After assigning the points, you can next update each centers by computing the average of all points assigned 
 to the center.(e.g all points assinged to C1/counts) (tip: recall we store points in new_center['center'] 
 and store count in new_center['num_sample'])

3. determine the center labels by choosing the majority of labels for points belonging to that cluster
 you also need to implement compute_error():, the error is the num of the square of euclidean distance between 
 the points and their assigned centers
 predict() generally does the following things:
 for each new data, choose a center that is most close to it, and use the label of that center as the 
 prediction result you also need to implment compute_error():, the error is the square sum of euclidean 
 distance between the points and their assigned centers
------------------------------
'''

class Kmeans:
    def __init__(self,k=8): # k is number of clusters
        self.num_cluster = k
        self.center = None # centers for different clusters
        self.cluster_label = np.zeros([k,]) # class labels for different clusters
        self.error_history = []

    def fit(self, X, y):
        print(X.shape, y.shape)
        # initialize the centers of clusters as a set of pre-selected samples
        init_idx = [1, 200, 500, 1000, 1001, 1500, 2000, 2005]
        # change the cluster centers to X[1], X[200], X[500], etc.
        self.center = np.array([X[i] for i in init_idx])

        num_iter = 0 # number of iterations for convergence

        # initialize the cluster assignment
        prev_cluster_assignment = np.zeros([len(X),]).astype('int')
        cluster_assignment = np.zeros([len(X),]).astype('int')
        is_converged = False

        # iteratively update the centers of clusters till convergence
        while not is_converged:

            # iterate through the samples and compute their cluster assignment (E step)
            for i in range(len(X)):
                # use euclidean distance to measure the distance between sample and cluster centers
                distances = [np.linalg.norm(X[i]-self.center[j], ord=2) for j in range(len(self.center))]

                # determine the cluster assignment by selecting the cluster whose center is closest to the sample
                # cluster_assignment[i] = min(distances,key=lambda item:item[0])[1]
                # print("distance: ", distances)
                cluster_assignment[i] = np.argmin(distances)

            # update the centers based on cluster assignment (M step)
            for i in range(len(self.center)): #iterates 8 times
                # https://python-course.eu/numerical-programming/numpy-boolean-indexing.php
                if X[cluster_assignment==i].size != 0:
                    self.center[i] = np.mean(X[cluster_assignment==i], axis=0)

            # compute the reconstruction error for the current iteration
            cur_error = self.compute_error(X, cluster_assignment)
            self.error_history.append(cur_error)

            # reach convergence if the assignment does not change anymore
            is_converged = True if (cluster_assignment==prev_cluster_assignment).sum() == len(X) else False
            prev_cluster_assignment = np.copy(cluster_assignment)
            num_iter += 1

        # compute the class label of each cluster based on majority voting (remember to update the corresponding class attribute)
        for i in range(len(self.cluster_label)): # should be len(8)
            # https://www.geeksforgeeks.org/find-the-most-frequent-value-in-a-numpy-array/
            # print(y, cluster_assignment)
            self.cluster_label[i] = np.bincount(y[cluster_assignment==i].astype('int')).argmax()

        # print(self.error_history)
        return num_iter, self.error_history

    def predict(self,X):
        # predicting the labels of test samples based on their clustering results
        prediction = np.ones([len(X),]) # placeholder

        # iterate through the test samples
        for i in range(len(X)):
            # find the cluster of each sample
            distances = [(np.linalg.norm(X[i]-self.center[j], ord=2), j) for j in range(len(self.center))]

            # use the class label of the selected cluster as the predicted class
            predicted_cluster = min(distances, key=lambda item:item[0])[1]
            prediction[i] = self.cluster_label[predicted_cluster]

        return prediction

    def compute_error(self,X,cluster_assignment):
        # compute the reconstruction error for given cluster assignment and centers
        error = sum([(np.linalg.norm(X[i]-self.center[cluster_assignment[i]], ord=2))**2 for i in range(len(X))])

        return error

    def params(self):
        return self.center, self.cluster_label
