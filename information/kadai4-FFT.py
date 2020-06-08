import numpy as np
import matplotlib.pyplot as plt
import time

t1 = time.time()

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

F = np.fft.fft(C)
F = np.abs(F) ** 2

t2 = time.time()
elapsed_time = t2-t1
print(f"経過時間：{elapsed_time}")

plt.plot(t, F)
plt.show()