import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def func(a, b):
    y = np.sin(a)+2*a*np.cos(b)+0.2*a**2+0.2*b**2
    return y

a = 5.0
b = 6.0
c = func(a, b)

eta = 0.01

def ｄx(a, b):
    y = np.cos(a) + 2.0 * np.cos(b) + 0.4 * a
    return y

def ｄy(a,b):
    y = -2 * np.sin(b) + 0.4 * b
    return y

para_a = []
para_b =[]
para_c =[]

epsilon = 0.0001
old_para_a = a
old_para_b = b

ct = 0
for i in range(1000):
    para_a.append(a)
    para_b.append(b)
    para_c.append(c)

    a = a - eta * dx(a, b)
    b = b - eta * dy(a, b)
    c = func(a, b)

    if abs(old_para_a - a) < epsilon and abs(old_para_b - b) < epsilon:
        break
    old_para_a = a
    old_para_b = b

    ct+=1

print('a=', a)
print('b=', b)


x = np.arange(-10.0, 10.0, 1)
y = np.arange(-10.0, 10.0, 1)
X, Y = np.meshgrid(x, y)
Z = func(X, Y)
fig = plt.figure()
ax = Axes3D(fig)
ax.plot_wireframe(X, Y, Z)
ax.plot(para_a, para_b, para_c,marker="o",linestyle='None', color='red')
plt.show()

