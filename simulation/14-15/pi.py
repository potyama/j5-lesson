import numpy as np


alpha = 1000000
beta = 0
ran_x = np.random.rand(alpha)
ran_y = np.random.rand(alpha)
ran_point = np.hypot(ran_x,ran_y)

for i in ran_point:
    if i <= 1:
        beta += 1


Pie = 4*beta/alpha

print("Pi: {} ".format(Pie))