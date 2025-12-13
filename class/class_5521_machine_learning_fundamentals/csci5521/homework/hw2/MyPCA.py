import numpy as np

'''
Implementations for PCA():

fit() generally does the following things:
1. center X (X = X-mean)
2. get covariance matrix (use np.cov, don't need to set ddof this time)
3. get the eigen values and eigen vectors (can use np.linalg.eigh)
4. select eigenvectors until the sum of corresponding eigenvalues reach(>=) 90%, save them in self.W

predict() generally does the following things:
1. center X (X = X-mean) use your precomputed mean from training to center your data
2. project the centered_X onto the lower dimensions (dimensions specified by the selected eigen vectors)
'''

class PCA():
    def __init__(self,num_dim=None):
        self.num_dim = num_dim
        self.mean = np.zeros([1,784]) # means of training data
        self.W = None # projection matrix

    def fit(self,X):
        # normalize the data to make it centered at zero (also store the means as class attribute)
        self.mean = np.mean(X, axis=0)
        X = X-self.mean

        # finding the projection matrix that maximize the variance (Hint: for eigen computation, use numpy.eigh instead of numpy.eig)
        # since it's not a square matrix, we need XX^T a.k.a. the sample covariance
        sample_covariance = (1/(len(X)-1)) * np.dot(X.T,X)
        
        eigh = np.linalg.eigh(sample_covariance)
        eigenvectors = eigh[1][:,::-1]  # principle components
        eigenvalues = eigh[0][::-1]

        if self.num_dim is None:
            # select the reduced dimension that keep >90% of the variance
            numerator = 0
            denominator = np.sum(eigenvalues)
            # store the projected dimension
            self.num_dim = 0
            
            while numerator/denominator < 0.9:
                numerator += eigenvalues[self.num_dim]
                self.num_dim += 1

        # determine the projection matrix and store it as class attribute
        print("eigen",eigenvectors.shape)
        self.W = eigenvectors[:, :self.num_dim]

        # project the high-dimensional data to low-dimensional one
        # print(X.T.shape, self.W.shape)
        X_pca = np.dot(X, self.W)

        return X_pca, self.num_dim

    def predict(self,X):
        # normalize the test data based on training statistics
        X = X-self.mean

        # project the test data
        X_pca = np.dot(X, self.W) # placeholder

        return X_pca

    def params(self):
        return self.W, self.mean, self.num_dim
