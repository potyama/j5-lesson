import numpy as np


def jacobi_method(A, b):
    # 線形連立方程式をヤコビ法で解く
    x_old = np.empty_like(b)
    err = 1e12

    D = np.diag(A)
    R = A - np.diagflat(D)

    while err > 1e-7:
        x = (b-np.dot(R, x_old))/D
        err = np.linalg.norm(x-x_old)/np.linalg.norm(x)
        x_old = x

    return x

A = np.array([[7, 1, 10],
              [1, 8, 3],
              [2, 3, 9]])

b = np.array([10, 8, 6])

x = jacobi_method(A, b)
print(x)