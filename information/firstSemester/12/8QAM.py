import numpy as np
import matplotlib.pyplot as plt


def qam(signal):
    qpsk_signal_1 = []
    qpsk_signal_2 = []
    N = 128
    t = np.arange(0, N, 1)
    fc = 2

    qpsk_0 = np.cos(2 * np.pi * t / N * fc)
    qpsk_1 = np.sin(2 * np.pi * t / N * fc)
    qpsk_2 = -np.cos(2 * np.pi * t / N * fc)
    qpsk_3 = -np.sin(2 * np.pi * t / N * fc)

    for i in signal:
        if i == 0 or i == 1:
            qpsk_signal_1.extend(qpsk_0)
        elif i == 2 or i == 3:
            qpsk_signal_2.extend(qpsk_1)
        elif i == 4 or i == 5:
            qpsk_signal_1.extend(qpsk_2)
        else:
            qpsk_signal_2.extend(qpsk_3)

    plt.plot(range(len(qpsk_signal_1)), qpsk_signal_1)
    plt.show()

    plt.plot(range(len(qpsk_signal_2)), qpsk_signal_2)
    plt.show()


#signal = [0, 1, 1, 2, 3, 2, 3, 1, 0, 2]
signal = np.random.choice([0, 7], np.random.choice([5, 20], 1))

qam(signal)