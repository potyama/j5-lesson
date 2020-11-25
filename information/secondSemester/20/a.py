import secrets
import numpy as np
import matplotlib.pyplot as plt

def Manchester(_signal):
    manchester_coding = []

    for i in _signal:
        if i == 0:
            manchester_coding.extend('0')
            manchester_coding.extend('1')
        else:
            manchester_coding.extend('1')
            manchester_coding.extend('0')

    return manchester_coding

def coding_4b5b(_signal):
    coding_4b5b = []

    for i in _signal:
        if i in {'0'}:
            coding_4b5b.extend("11110")
        elif i in {'1'}:
            coding_4b5b.extend('01001')
        elif i in {'2'}:
            coding_4b5b.extend('10100')
        elif i in {'3'}:
            coding_4b5b.extend('10101')
        elif i in {'4'}:
            coding_4b5b.extend('01010')
        elif i in {'5'}:
            coding_4b5b.extend('01011')
        elif i in {'6'}:
            coding_4b5b.extend('01110')
        elif i in {'7'}:
            coding_4b5b.extend('01111')
        elif i in {'8'}:
            coding_4b5b.extend('10010')
        elif i in {'9'}:
            coding_4b5b.extend('10011')
        elif i in {'a'}:
            coding_4b5b.extend('10110')
        elif i in {'b'}:
            coding_4b5b.extend('10111')
        elif i in {'c'}:
            coding_4b5b.extend('11010')
        elif i in {'d'}:
            coding_4b5b.extend('11011')
        elif i in {'e'}:
            coding_4b5b.extend('11100')
        elif i in {'f'}:
            coding_4b5b.extend('11101')

    return coding_4b5b

def Plot(_signal):
    plt.plot(range(len(_signal)), _signal)
    plt.show()

signal = np.random.choice([0, 1], np.random.choice([10, 10], 1))
signal2 = secrets.token_hex(10)
signal_manchester = Manchester(signal)
signal_4b5b= coding_4b5b(signal2)

print(signal)


print(signal_manchester)
Plot(signal_manchester)

print(signal2)

print(signal_4b5b)
Plot(signal_4b5b)