import numpy as np

class GaussianDiscriminant:
    # used for the first two cases
    def __init__(self,k=2,d=8,priors=None,shared_cov=False):
        self.mean = np.zeros((k,d)) # mean
        self.shared_cov = shared_cov # using class-independent covariance or not
        if self.shared_cov:
            self.S = np.zeros((d,d)) # class-independent covariance (S1=S2)
        else:
            self.S = np.zeros((k,d,d)) # class-dependent covariance (S1!=S2)
        if priors is not None:
            self.p = priors
        else:
            self.p = [1.0/k for i in range(k)] # assume equal priors if not given
        self.k = k
        self.d = d

    def fit(self, Xtrain, ytrain):
        # Using Lecture 5: Bayes Decision Theory, Parametric Methods, and Multivariate Methods, 39:00
        # count the occurences of each class
        class1count = sum([c == 1 for c in ytrain])
        class2count = len(ytrain) - class1count
        
        # compute the mean for each class
        # m = [s/instances.size for s in instances.sum(axis=0)]
        # split the data by class
        C1 = Xtrain[:15,:]
        C2 = Xtrain[15:,:]

        # means are probably not the same, so the decision needs to involve mean
        # print(np.sum(C1, axis=0))
        # self.mean[0] = [s/len(Xtrain) for s in np.sum(C1, axis=0)]
        # self.mean[1] = [s/len(Xtrain) for s in np.sum(C2, axis=0)]
        self.mean[0] = np.mean(Xtrain[ytrain==1], axis=0)
        self.mean[1] = np.mean(Xtrain[ytrain==2], axis=0)

        if self.shared_cov:
            # compute the class-independent covariance
            self.S = np.cov(Xtrain.transpose())
        else:
            # compute the class-dependent covariance
            # self.S[0] = np.cov(C1.transpose())
            # self.S[1] = np.cov(C2.transpose())
            self.S[0] = np.cov(Xtrain[ytrain==1], rowvar=False)
            self.S[1] = np.cov(Xtrain[ytrain==2], rowvar=False)

    def predict(self, Xtest):
        # predict function to get predictions on test set
        predicted_class = np.ones(Xtest.shape[0]) # placeholder
        for i in np.arange(Xtest.shape[0]): # for each test set example

            # calculate the value of discriminant function for each class
            pred = []
            for c in np.arange(self.k):
                if self.shared_cov:
                    discriminant = -0.5*np.dot(np.dot((Xtest[i] - self.mean[c]).transpose(), np.linalg.inv(self.S)), (Xtest[i] - self.mean[c]))# - np.log(0.3)
                    pred.append(discriminant)
                else:
                    discriminant = -0.5*np.log(np.linalg.det(self.S[c]))-0.5*np.dot(np.dot((Xtest[i] - self.mean[c]).transpose(), np.linalg.inv(self.S[c])), (Xtest[i] - self.mean[c]))# + np.log(len(self.S[c]) / (len(self.S[0]) + len(self.S[1])))
                    pred.append(discriminant)
            # determine the predicted class based on the values of discriminant function
            if pred[0] > pred[1]:
                predicted_class[i] = 1
            else:
                predicted_class[i] = 2
        return predicted_class

    def params(self):
        if self.shared_cov:
            return self.mean[0], self.mean[1], self.S
        else:
            return self.mean[0],self.mean[1],self.S[0,:,:],self.S[1,:,:]


class GaussianDiscriminant_Diagonal:
    # used for the third case
    def __init__(self,k=2,d=8,priors=None):
        self.mean = np.zeros((k,d)) # mean
        self.S = np.zeros((d,)) # variance
        if priors is not None:
            self.p = priors
        else:
            self.p = [1.0/k for i in range(k)] # assume equal priors if not given
        self.k = k
        self.d = d
    def fit(self, Xtrain, ytrain):
        # compute the mean for each class
        self.mean[0] = np.mean(Xtrain[ytrain==1], axis=0)
        self.mean[1] = np.mean(Xtrain[ytrain==2], axis=0)

        # compute the variance of different features
        self.S = np.var(Xtrain)

    def predict(self, Xtest):
        # predict function to get prediction for test set
        predicted_class = np.ones(Xtest.shape[0]) # placeholder

        for i in np.arange(Xtest.shape[0]): # for each test set example
            # calculate the value of discriminant function for each class
            for c in np.arange(self.k):
                pass

            # determine the predicted class based on the values of discriminant function

        return predicted_class

    def params(self):
        return self.mean[0], self.mean[1], self.S
