import numpy as np
import matplotlib.pyplot as plt

def func(a):
    y = (a+1.0)**2 * (a-1.0)**2
    return y

a = 1.2

eta = 0.01

def dfunc(a):
    y = 4*a * (a-1.0) * (a+1.0)
    return y

para_x = []
para_y =[]

epsilon = 0.001
old_para = a

ct = 0
for i in range(1000):
    para_x.append(a)
    para_y.append(0)

    a = a - eta * dfunc(a)
    if abs(old_para-a)<epsilon:
        break
    old_para = a
    ct+=1



print('a=', a)

xmin = -1.0
xmax = 4.5
num = 100
x = np.linspace(xmin, xmax, num)
y = func(x)


plt.plot(x, y)
plt.scatter(para_x, para_y, color='blue')
plt.xlim(xmin, xmax)
plt.grid(True)
plt.show()


