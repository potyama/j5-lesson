import time

def func(x):
    return x * x - 2.0

def dfunc(x):
    return 2 * x

t1 = time.perf_counter()

a = 2.0
eps = 0.000000001
for i in range(1000):
    b = a - (func(a)/dfunc(a))
    if abs(a-b)< eps:
        break;
    else:
        a = b

t2 = time.perf_counter()
elapsed_time = t2-t1
print('time = {:.10f}'.format(elapsed_time))

print(b)
