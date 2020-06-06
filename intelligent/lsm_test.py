import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import re

if __name__ == "__main__":
    test = pd.read_csv(
        "C:/Users/potyama/j5-lesson/intelligent/data/lsmCompe_test.csv", names=["x", "y"])
    test_list = test.values

    a = 2.63417868563063
    b = 992.787762663198

    for i in test_list:
        y = a * i[0] + b
        print(y)
