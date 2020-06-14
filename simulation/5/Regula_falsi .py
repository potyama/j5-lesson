def f (x):
    return x * x - 2.0

def regula_falsi(a, b):
    ipu = 0.000000000000001
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
ans = regula_falsi(a, b)
print(ans)