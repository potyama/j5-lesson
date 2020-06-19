import time

def f (x):
    return x * x - 2.0

def regula_falsi(a, b):
    ipu = 0.00000000001
    while True:
        c = (a * f(b) - b*f(a))/ (f(b) - f(a))

        w = f(c)

        if abs(w) < ipu :
            break
        elif w < 0:
            a = c
        else:
            b = c
    return c

a = 0.0
b = 2.0

t1 = time.perf_counter()

ans = regula_falsi(a, b)

t2 = time.perf_counter()
elapsed_time = t2-t1
print('time = {:.10f}'.format(elapsed_time))

print(ans)