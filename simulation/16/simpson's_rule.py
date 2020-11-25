def f(x):
    return 4*(x ** 3) - 10*(x ** 2) + 4*x + 5

N = 100000
a = 0
b = 2
h = (b-a)/(2*N)

S = 0
for i in range(2*N):
    if i == 0 or i == 2*N:
        S += f(a + i*h)
    elif i%2 == 1:
        S += 4 * f(a + i*h)
    else:
        S += 2 * f(a + i*h)

S = S*h/3

print(S)