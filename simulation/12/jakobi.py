import numpy as np

def jakobi(A, b):
    D = np.diag(A)
    R = A - np.diagflat(D)
    err = 1e-9

    x_old = np.empty_like(b)

    while 1e12 > err:
        x = (b - np.dot(R, x_old)) / D
        err = np.linalg.norm(x - x_old)/ np.linalg.norm(x)
        x_old = x

    return x


A = np.array([[7, 1, 2],
              [1, 8, 3],
              [2, 3, 9]])

b = np.array([10, 8, 6])

x = jakobi(A, b)
print(x)