import numpy as np
import matplotlib.pyplot as plt

def mathfunc(x):
    y = 0.7*x+1.2
    return y

xmin = -1.0
xmax = 4.0
num = 20

np.random.seed(5)

dataX = (xmax - xmin) * np.random.rand(num) + xmin
dataX = np.sort(dataX)


dataY = mathfunc(dataX)


dataY += np.random.normal(loc=0.0, scale=0.5, size=num)


def objectfunc(a, b, x):
    y  = a * x + b
    return y

def error_func(a, b, x, y):
    error = 1.0/2.0 * sum((y - objectfunc(a, b, x))**2)
    return error

def d_a(a, b):
    z =  sum((dataY - a * dataX - b)*(-dataX))
    return z

def d_b(a, b):
    z =  sum((dataY - a * dataX - b)*(-1))
    return z

eta = 0.01
a = 10
b = 10

eps = 0.0001
old_para_a = a
old_para_b = b

history = np.zeros((0,4))

ct = 0
for i in range(1000):

    a = a - eta * d_a(a, b)
    b = b - eta * d_b(a, b)
    err = error_func(a, b, dataX, dataY)

    history = np.vstack((history, [ct, err, a, b]))

    if abs(old_para_a - a) < eps and abs(old_para_b - b)< eps :
        break

    old_para_a = a
    old_para_b = b

    ct+=1

print('a=', a)
print('b=', b)

def func(x):
    y = a*x+b
    return y

xmin = -1.0
xmax = 4.0
num = 100
x = np.linspace(xmin, xmax, num)
y = mathfunc(x)

plt.plot(x, y, color='red')
plt.scatter(dataX, dataY)
plt.xlim(xmin, xmax)
plt.grid(True)
plt.show()