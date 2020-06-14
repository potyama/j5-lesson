import pandas as pd

if __name__ == "__main__":
    test = pd.read_csv(
        "C:Users/potyama/j5-lesson/intelligent/3/data/lsmCompe_train.csv", names=["x", "y"])
    test_list = test.values

    a = 2.63417868563063
    b = 992.787762663198

    for i in test_list:
        y = a * i[0] + b
        print(y)
