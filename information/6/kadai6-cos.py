import numpy as np
import matplotlib.pyplot as plt

N = 128
t = np.arange(0, N)
f = np.cos(2*np.pi*t/N*8)
F = np.fft.fft(f, N)
f2 = np.fft.ifft(F, N)

plt.subplot(131)
plt.plot(t, f)
plt.subplot(132)
plt.plot(t, np.abs(np.fft.fftshift(F)))
plt.subplot(133)
plt.plot(t, f2)
plt.show()