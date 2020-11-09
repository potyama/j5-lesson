import numpy as np


sum = 0.0
for n in range(5):
    a = np.math.factorial(4 * n) * (1103 + 26390 * n)
    b = (396**n * np.math.factorial(n))**4
    sum += a/b

pi = (2*np.sqrt(2))/(99**2) * sum
print(1/pi)