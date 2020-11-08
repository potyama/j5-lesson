import numpy as np

def f(x):
    return (1/np.sqrt(2*np.pi)) * np.exp(-x**2)

N = 100000
a = -5
b = 5

x = (b-a)*np.random.rand(N)
I = np.average(2*f(x))
print(I)