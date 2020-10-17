import numpy as np
import matplotlib.pyplot as plt


def psk(signal):
    psk_signal = []
    psk_row_signal = []
    N = 128
    t = np.arange(0, N, 1)
    fc = 2

    psk_0 = np.cos(2 * np.pi * t / N * fc)
    psk_1 = np.cos((2 * np.pi * t / N * fc) + np.pi)

    for i in signal:
        if i == -1:
            psk_signal.extend(psk_0)
            psk_row_signal.extend([1]*N)
        else:
            psk_signal.extend(psk_1)
            psk_row_signal.extend([-1]*N)

    plt.plot(range(len(psk_row_signal)), psk_row_signal)
    plt.show()

    demodulate = []

    for i in signal:
        demodulate.extend(np.cos(2 * np.pi * t / N * fc))

    psk_signal = np.array(psk_signal)
    demodulate = np.array(demodulate)
    psk_signal *= demodulate

    psk_signal = np.fft.fftshift(psk_signal)
    psk_signal = np.fft.fft(psk_signal)
    psk_signal = np.fft.fftshift(psk_signal)

    psk_signal[:512-16] = 0
    psk_signal[512+16:] = 0

    psk_signal = np.fft.fftshift(psk_signal)
    psk_signal = np.fft.ifft(psk_signal)
    psk_signal = np.fft.fftshift(psk_signal)

    return psk_signal


signal = [1, -1, -1, -1, 1, 1, 1, -1]

plt.plot(range(len(psk(signal))), psk(signal))
plt.show()
