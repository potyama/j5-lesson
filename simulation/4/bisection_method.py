def func(x):
    return x*x - 2


def bm(a, b):
    c = 0
    for i in range(5):
        c = (a+b)/2.0
        if(func(c)*func(a) < 0):
            b = c
        else:
            a = c
    return c


if __name__ == "__main__":
    a, b = map(int, input().split())
    x = bm(a, b)

    print(x)
