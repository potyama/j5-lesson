import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import re


if __name__ == "__main__":
    data = pd.read_csv(
        "C:Users/potyama/j5-lesson/intelligent/3/data/lsmCompe_train.csv", names=["x", "y"])
    data_list = data.values
    # print(data)

    x_p = []
    y_p = []
    x_datalist = 0
    y_datalist = 0
    pow_datalist = 0
    multibyte_datalist = 0
    data_num = 0

    for i in data_list:
        x_p.append(i[0])
        y_p.append(i[1])

        x_datalist += i[0]
        # print(x_datalist)

        y_datalist += i[1]
        # print(y_datalist)

        pow_datalist += pow(i[0], 2)
        # print(pow_datalist)

        multibyte_datalist += i[0] * i[1]
        # print(multibyte_datalist)

        data_num += 1
        # print(data_num)

    array1 = np.array([[pow_datalist, x_datalist], [x_datalist, data_num]])
    array_inv = np.linalg.inv(array1)
    array2 = np.array([[multibyte_datalist], [y_datalist]])

    array_ans = np.dot(array_inv, array2)
    print(array_ans[0][0])
    print(array_ans[1][0])

    x = np.arange(0, 733, 1)
    y = array_ans[0][0] * x + array_ans[1][0]

plt.scatter(x_p, y_p, marker=".")
plt.plot(x, y)
plt.show()
