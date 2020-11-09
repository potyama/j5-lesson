def d(m):
    sum1 = 0.0
    for n in range(3*m+2):
        a = ((-1)**n)
        b = 2*n + 1
        sum1 += a/b * (1/5)**(2*n+1)

    sum2 = 0.0
    for n in range(m):
        a = ((-1)**n)
        b = 2*n + 1
        sum2 += a/b * (1/239)**(2*n+1)

    return (16*sum1) - (4*sum2)

print(d(5))