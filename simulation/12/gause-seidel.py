import numpy as np


def gauss_seidel(A, b):
    D = np.diag(A)
    R = A - np.diag(D)
    X = np.full(len(b), 0.)
    n = 300


    for i in range(n):
        err = 0.
        for j in range(len(X)):
            S = X[j]
            X[j] = (b[j] - np.dot(R[j], X)) / D[j]
            err += abs((X[j] - S) / X[j])
            if err < 1e20:
                return X

A = np.array([[7, 1, 10],
              [1, 8, 3],
              [2, 3, 9]])

b = np.array([10, 8, 6])

x = gauss_seidel(A, b)
print(x)