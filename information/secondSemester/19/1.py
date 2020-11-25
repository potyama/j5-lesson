import random
import numpy as np
import matplotlib.pyplot as plt


def PSK(_signal):
    psk_signal = []
    N = 128
    t = np.arange(0, N, 1)
    fc = 2

    psk_0 = np.cos(2 * np.pi * t / N * fc)
    psk_1 = np.cos((2 * np.pi * t / N * fc) + np.pi)

    for i in _signal:
        if i == -1:
            psk_signal.extend(psk_0)
        else:
            psk_signal.extend(psk_1)

    return psk_signal

def PN(_signal, _pn):
    pn_result = []

    for i in range(len(_signal)):
        pn_result.append(_signal[i] * _pn[i])

    return pn_result

def Spectre(_signal):
    f = np.fft.fftshift(_signal)
    F = np.fft.fft(f)
    result = np.fft.fftshift(F)

    return result

def Plot(_signal):
    plt.plot(range(len(_signal)), _signal)
    plt.show()


signal = np.random.choice([-1, 1], np.random.choice([1024, 1028], 1))

#1
signal_psk = PSK(signal)
Plot(signal_psk)
Plot(Spectre(signal_psk))

#2
pn = []
for _ in range(len(signal_psk)):
    pn.append(random.choice([-1, 1]))

signal_pn = PN(signal_psk, pn)
Plot(signal_pn)
Plot(Spectre(signal_pn))

#3
rev_signal_pn = PN(signal_pn, pn)
Plot(rev_signal_pn)
Plot(Spectre(rev_signal_pn))

