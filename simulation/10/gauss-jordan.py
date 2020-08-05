import numpy as np
import pandas as pd

def sweep_method(X, N):
    cnt_calc = 0

    for i in range(N):
        for j in range(i + 1, N + 1):
            X[i][j] /= X[i][i]

            for k in range(N):
                if k != i:
                    X[k][j] -= X[i][j] * X[k][i]
                    cnt_calc += 1

    return X, cnt_calc


if __name__ == '__main__':

    A = pd.read_csv('A100.csv', header=None)
    B = pd.read_csv('b100.csv', header=None)
    #A = pd.read_csv('A1000.csv', header=None)
    #B = pd.read_csv('b1000.csv', header=None)

    A = np.array(A)
    B = np.array(B)

    X = np.hstack((A, B))
    N = len(X)

    x, cnt_calc = sweep_method(X, N)

    for i in range(N):
        print('x_{} = {}'.format(i + 1, x[0][i]))
print('count = {}'.format(cnt_calc))