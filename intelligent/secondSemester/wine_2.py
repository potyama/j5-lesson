import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.utils.testing import all_estimators
from sklearn.metrics import accuracy_score
import warnings
from sklearn.metrics import classification_report

warnings.simplefilter("ignore")

wine = pd.read_csv("./csv/winequality-white.csv", sep=";", encoding="utf-8")
y = wine["quality"]
x = wine.drop("quality", axis=1)

newlist = []
for v in list(y):
    if v <= 4:
        newlist += [0]
    elif v <= 7:
        newlist += [1]
    else:
        newlist += [2]
y = newlist

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2, train_size=0.8, shuffle=True)

allAlgorithms = all_estimators(type_filter="classifier")
optimalAlgorithm = []
score = 0.0

for (name, algorithm) in allAlgorithms:
    try:
        clf = algorithm()
        clf.fit(x_train, y_train)

        y_pred = clf.predict(x_test)
        if score <= accuracy_score(y_test, y_pred):
            optimalAlgorithm = name
            score = accuracy_score(y_test, y_pred)

        print(name, "の正解率 = ", accuracy_score(y_test, y_pred))
    except:
        print(" - ERROR:", name)
        pass

print("最適なアルゴリズムは", optimalAlgorithm)
