import numpy as np


def jacobi_method(A, b):
    D = np.diag(A)
    R = A - np.diag(D)
    X = np.full(len(b), 0.)
    n = 70

    for i in range(n):
        X1 = (b - np.dot(R, X)) / D
        if np.fabs((X1 - X) / X1).sum() < 1e20:
            return X1
        X = X1

A = np.array([[7, 1, 10],
              [1, 8, 3],
              [2, 3, 9]])

b = np.array([10, 8, 6])

x = jacobi_method(A, b)
print(x)