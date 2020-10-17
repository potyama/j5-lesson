from sklearn.svm import LinearSVC
from sklearn.metrics import accuracy_score

learn_data = [[0, 0], [1, 0], [0, 1], [1, 1]]
learn_label = [0, 0, 0, 1]

clf = LinearSVC()

clf.fit(learn_data, learn_label)

test_data = [[0, 0], [1, 0], [0, 1], [1, 1]]
test_label = clf.predict(test_data)

print(test_data, "の予測結果:", test_label)
print("正解率 = ", accuracy_score([0, 0, 0, 1], test_label))