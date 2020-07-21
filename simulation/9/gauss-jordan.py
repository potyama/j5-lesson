def sweep_method(N, X):
    for i in range(N):
        pivot = X[i][i]
        for j in range(i, N + 1):
            X[i][j] = X[i][j] / pivot

        for k in range(N):
            sweep = X[k][i]
            for j in range(i, N + 1):
                if k != i:
                    X[k][j] -= sweep * X[i][j]

    return X


X = [[2, 3, 4, 6],
    [3, 5, 2, 5],
    [4, 3, 30, 32]]
N = 3
A = sweep_method(N, X)

for l in range(N):
    print(A[l][N])
