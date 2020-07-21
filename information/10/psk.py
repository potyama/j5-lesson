import numpy as np
import matplotlib.pyplot as plt


def psk(signal):
    psk_signal = []
    N = 128
    t = np.arange(0, N, 1)
    fc = 2

    psk_0 = np.cos(2*np.pi*t/N * fc)
    psk_1 = np.cos((2*np.pi*t/N * fc) + np.pi)

    for i in signal:
        if i == -1:
            psk_signal.extend(psk_0)
        else:
            psk_signal.extend(psk_1)

    demodulate = []

    for i in signal:
        demodulate.extend(np.cos(2*np.pi*t/N*fc))

    psk_signal = np.array(psk_signal)
    demodulate = np.array(demodulate)
    psk_signal *= demodulate

    return psk_signal


signal = [1, -1, -1, -1, 1, 1, 1, -1]

plt.plot(range(len(psk(signal))), psk(signal))
plt.show()