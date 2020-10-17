import numpy as np
import matplotlib.pyplot as plt
from random import randint


def S_NRZ(signal):
    result = [i*(-1) for i in signal]
    return np.array(result)


def D_NRZ(signal):
    result = [0 if i % 2 == 0 else 1 for i in signal]
    return np.array(result)


def S_RZ(signal):
    result = []
    for i in signal:
        result.append(0)
        result.append(i*-1)
        result.append(i*-1)
        result.append(0)
    return np.array(result)

def D_RZ(signal):
    result = []
    for i in signal:
        result.append(0)
        if i % 2 == 0:
            result.append(1)
            result.append(1)
        else:
            result.append(-1)
            result.append(-1)
            result.append(0)
    return np.array(result)

def AMI(signal):
    result = []
    flag = False
    for i in signal:
        result.append(0)
        if i %2 == 0:
            if flag:
                result.append(-1)
                result.append(-1)
                flag = False
            else:
                result.append(1)
                result.append(1)
                flag = True
        else:
            result.append(0)
            result.append(0)
            result.append(0)
    return np.array(result)


def MANCHESTER(signal):
    result = []
    for i in signal:
        if i % 2 == 0:
            result.append(0)
            result.append(1)
        else:
            result.append(1)
            result.append(0)
    return np.array(result)


def FFT_AND_PLOT(signal,name):
    t = np.arange(0,len(signal))
    F=np.fft.fft(signal)
    plt.plot(t,np.abs(F)**2,label=name)


if __name__ == "__main__":
    signal = [randint(0, 1) for i in range(1024)]
    signal = [int(i) for i in "0100110001100101011101000111010101110011011011100110111101110100011101110110000101101100011011000110111101110111011010010110111001110100011010000110010101110110011000010110110001101100011001010111100101101111011001100110010001100101011100110111000001100001011010010111001000101100010010010111001101100001011110010111010001101111011110010110111101110101011101000110111101100100011000010111100100101100011011010111100101100110011100100110100101100101011011100110010001110011011100110110111101100101011101100110010101101110011101000110100001101111011101010110011101101000011101110110010101100110011000010110001101100101011101000110100001100101011001000110100101100110011001100110100101100011011101010110110001110100011010010110010101110011011011110110011001110100011011110110010001100001011110010110000101101110011001000111010001101111011011010110111101110010011100100110111101110111001011000100100101110011011101000110100101101100011011000110100001100001011101100110010101100001011001000111001001100101011000010110110100101110"]
    snrz = S_NRZ(signal)
    dnrz = D_NRZ(signal)
    srz = S_RZ(signal)
    drz = D_RZ(signal)
    ami = AMI(signal)
    man = MANCHESTER(signal)
    FFT_AND_PLOT(snrz, "S_NRZ     ")
    FFT_AND_PLOT(dnrz, "D_NRZ     ")
    FFT_AND_PLOT(srz, "S_RZ      ")
    FFT_AND_PLOT(drz, "D_RZ      ")
    FFT_AND_PLOT(ami, "AMI       ")
    FFT_AND_PLOT(man, "MANCHESTER")
    plt.legend()
    plt.show()