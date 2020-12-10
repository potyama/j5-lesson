import numpy as np

def f(x):
    return 4*(x ** 3) - 10*(x ** 2) + 4*x + 5

N = 100
a = 0
b = 2

x = (b-a)*np.random.rand(N)
I = np.average(2*f(x))
print(I)