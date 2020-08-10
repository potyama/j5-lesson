import numpy as np

# Pivotの影響を受けるA, L P行列をk行を基準に入替え
def Pivot(A, L , k , P):
    n = A.shape[0]
    n_max = abs(A[k,k])
    pivot_n = k
    for i in range(k+1, n): # Pivotを行うため、最大の行を探索
        if n_max < A[i,k]:
            n_max = A[i,k]
            pivot_n = i

    # Pivot行列の入替え
    P_k = np.copy(P[k,:]) # '='だけでは参照渡しになるので copyを使用する
    P[k, :] = P[pivot_n, :]
    P[pivot_n, :] = P_k

    # A行列の入替え
    A_k = np.copy(A[k, :]) # '='だけでは参照渡しになるので copyを使用する
    A[k, :] = A[pivot_n, :]
    A[pivot_n, :] = A_k

    # L行列の入替え
    L_k = np.copy(L[k, :]) # '='だけでは参照渡しになるので copyを使用する
    L[k, :] = L[pivot_n, :]
    L[pivot_n, :] = L_k

    return A, L , P

def LU_decomposition(A):
    # 配列の作成
    L = np.zeros(A.shape)
    U = np.zeros(A.shape)
    P = np.eye(A.shape[0], A.shape[1])
    for i in range(A.shape[0]):
        # Pivot実行
        A, L, P = Pivot(A, L , i, P)

        # L, U 行列の計算
        for j in range(i, A.shape[1]):
            U[i, j] = A[i, j]  # U行列 i 行目を算出
            L[j, i] = A[j ,i] / U[i, i] # L行列 i 列目を算出

        # 次のA行列を計算
        for j in range(A.shape[0]):
            for k in range(A.shape[1]):
                A[j,k] =A[j,k] - L[j, i] * U[i, k]

    return L, U, F

def solve_lower(L, b):
    x = np.zeros(b.shape)

        for i in range(x.shape[0]):
            r = 0
            for j in range(0, i):
                r += L[i, j] * x[j]
            x[i] = b[i] - r

    return x


def solve_upper(U, z):
    x = np.zeros(z.shape)

    for i in reversed(range(x.shape[0])):
        r = 0
        for j in range(i + 1, x.shape[0]):
            r += U[i,j] * x[j]
        x[i] = (z[i] - r)/U[i,i]

    return x

A = ([[2, 4, 6],
     [1, 5, 15],
     [4, 10, 21]])

[L, U, F] =