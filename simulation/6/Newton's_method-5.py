def func(x):
    return x * x - 2.0

def dfunc(x):
    return 2 * x

a = 2.0
eps = 0.000000001
for i in range(5):
    b = a - (func(a)/dfunc(a))
    if abs(a-b)< eps:
        break;
    else:
        a = b
print(b)
