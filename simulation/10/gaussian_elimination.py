import numpy as np
import pandas as pd

def Gaussian_elimination(A, n):
    cnt_calc = 0
    for i in range(n):
        for j in range(i + 1, n + 1):
            A[i][j] /= A[i][i]

            for k in range(i + 1, n):
                A[k][j] -= A[i][j] * A[k][i]
                cnt_calc += 1

    X = np.zeros(n)
    for i in reversed(range(n)):
        X[0][i] = A[i][n]

        for j in range(i + 1, n):
            X[0][i] -= A[i][j] * X[0][j]
            cnt_calc += 1

    return X, cnt_calc


if __name__ == '__main__':

    #A = pd.read_csv('A100.csv', header=None)
    #B = pd.read_csv('b100.csv', header=None)
    A = pd.read_csv('A1000.csv', header=None)
    B = pd.read_csv('b1000.csv', header=None)

    A = np.array(A)
    B = np.array(B)

    X = np.hstack((A, B))
    N = len(X)

    x, cnt_calc = Gaussian_elimination(X, N)

    for i in range(N):
        print('x_{} = {}'.format(i + 1, x[0][i]))
print('count = {}'.format(cnt_calc))