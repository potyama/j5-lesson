import math
import numpy as np
import matplotlib.pyplot as plot

def s(t):
    f = 4
    return np.cos(2 * np.pi * f * t)

def am(t):
    A = 1
    alpha = 1
    fc = 32
    return A * (alpha * s(t) + 1) * np.cos(2 * math.pi * fc * t)

t = np.arange(0, 10, 0.01)

f = np.fft.fft(am(t))
plot.plot(t, am(t))
plot.show()

plot.plot(np.arange(len(f)), np.abs(f))
plot.show()