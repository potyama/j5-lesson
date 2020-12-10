import numpy as np

def f(x):
    return 4*(x ** 3) - 10*(x ** 2) + 4*x + 5

N = 100
a = 0
b = 2
h = (b-a)/N
x = np.linspace(a, b, N+1)

S = h * (np.sum(f(x)) - f(x[0])/2 - f(x[N])/2)

print(S)