import numpy as np
import matplotlib.pyplot as plt
import time

t1 = time.time()

def dft(x, N):
    X = np.zeros(N, dtype=complex)
    for k in range(len(x)):
        re = 0
        im = 0
        for n in range(N):
            re += x[n] * np.cos((-2*np.pi*k*n)/N)
            im += x[n] * np.sin((-2*np.pi*k*n)/N)
        X[k] = np.complex(re, im)
    return X

#N = 128
#N = 1024
N = 2048
t = np.arange(0, N)
#(1)
#C = np.sin(2*np.pi*t/N * 10)
#(2)
#C = np.sin(2*np.pi*t/N)+np.sin(2*np.pi*t/N * 10)
#(3)
C = np.sin(2*np.pi*t/N)+np.sin(2*np.pi*t/N * 10) +np.sin(2*np.pi*t/N * 20)/5
C = dft(C, N)
C = np.abs(C) ** 2

t2 = time.time()
elapsed_time = t2-t1
print(f"経過時間：{elapsed_time}")

plt.plot(t, C)
plt.show()