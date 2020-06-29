import time

def func(x):
    return x*x - 2

def bm(a, b):
    c = 0
    for i in range(5):
        c = (a+b)/2.0
        if(func(c)*func(a) < 0.001):
            b = c
        else:
            a = c
    return c

if __name__ == "__main__":
    t1 = time.perf_counter()

    a = 0.0
    b = 2.0
    x = bm(a, b)

    t2 = time.perf_counter()
    elapsed_time = t2 - t1
    print('time = {:.10f}'.format(elapsed_time))

    print(x)
