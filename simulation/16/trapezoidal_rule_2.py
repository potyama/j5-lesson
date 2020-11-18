import numpy as np

def f(x):
    return (1/np.sqrt(2*np.pi)) * np.exp((-x**2)/2)

N = 100000
a = -5
b = 5
h = (b-a)/N
x = np.linspace(a, b, N+1)

S = h * (np.sum(f(x)) - f(x[0])/2 - f(x[N])/2)

print(S)