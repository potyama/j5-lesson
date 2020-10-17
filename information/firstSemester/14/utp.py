import numpy as np
import matplotlib as plt

def utp(f):
    a = 1.967 * np.sqrt(f) + 0.023 * f + 0.050
    b = 35.3 - 15 * np.log10(f/100)
    c = 23.8 - 20 * np.log10(f/100)

    print(f)
    print(a)
    print(b)
    print(c)

utp(1.0)
utp(4.0)
utp(10.0)
utp(20.0)
utp(25.0)
utp(31.25)
utp(62.5)
utp(100)