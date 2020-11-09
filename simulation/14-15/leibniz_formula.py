pi = 0

for i in range(1000000):
    pi += (1 / (i * 4 + 1) - 1 / (i * 4 + 3))

print(pi*4)