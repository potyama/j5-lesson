#coding: utf-8
# Python警察になってきてしまってつらいお気持ちです。

import random


class shape:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def triangle(self):
        area = self.x * self.y / 2
        print(area)
        return area

    def rectangle(self):
        area = self.x * self.y
        print(area)
        return area

    def square(self):
        area = self.x * self.x
        print(area)
        return area


if __name__ == "__main__":
    data_list = [i for i in range(1, 100 + 1)]
    s1 = shape(data_list[random.randint(0, 100)],
               data_list[random.randint(50, 100)])

    area_list = []
    while True:
        ore = random.randint(0, 100)
        if ore < 60:
            print("kasu")
            area_list.append(s1.triangle())
            break
        elif ore == 100:
            print("puro")
            area_list.append(s1.rectangle())
        else:
            print("iine!")
            area_list.append(s1.square())

    print(area_list)
    print(sorted(area_list))
    print(ore)
