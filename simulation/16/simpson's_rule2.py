import numpy as np

def f(x):
    return (1/np.sqrt(2*np.pi)) * np.exp((-x**2)/2)

N = 10000
a = -5
b = 5
h = (b-a)/(2*N)
S = 0
for i in range(2*N):
    if i == 0 or i == 2*N:
        S += f(a + i*h)
    elif i%2 == 1:
        S += 4 * f(a + i*h)
    else:
        S += 2 * f(a + i*h)

S = S*h/3

print(S)