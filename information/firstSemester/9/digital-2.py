import numpy as np
import matplotlib.pyplot as plt

def ask(signal):
    ask_signal = []
    N = 128
    t = np.arange(0, N, 1)
    fc = 4

    ask_0 = np.sin(2*np.pi*t/N * fc) *  0
    ask_1 = np.sin(2*np.pi*t/N * fc)

    for i in signal:
        if i == 0:
            ask_signal.extend(ask_0)
        else:
            ask_signal.extend(ask_1)

    return ask_signal

def fsk(signal):
    fsk_signal = []
    N = 128
    t = np.arange(0, N, 1)
    f0 = 2
    f1 = 4

    fsk_0 = np.sin(2*np.pi*t/N * f0)
    fsk_1 = np.sin(2*np.pi*t/N * f1)

    for i in signal:
        if i == 0:
            fsk_signal.extend(fsk_0)
        else:
            fsk_signal.extend(fsk_1)

    return fsk_signal

def psk(signal):
    psk_signal = []
    N = 128
    t = np.arange(0, N, 1)
    fc = 4

    psk_0 = np.sin(2*np.pi*t/N * fc)
    psk_1 = np.sin(2*np.pi*t/N * fc + np.pi)

    for i in signal:
        if i == 0:
            psk_signal.extend(psk_0)
        else:
            psk_signal.extend(psk_1)

    return psk_signal


signal = np.random.choice([0, 1], 8)

print(signal)

plt.plot(range(len(ask(signal))), ask(signal))
plt.show()

plt.plot(range(len(fsk(signal))), fsk(signal))
plt.show()

plt.plot(range(len(psk(signal))), psk(signal))
plt.show()