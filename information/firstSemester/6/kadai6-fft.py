import wave
import array
import numpy as np
import matplotlib.pyplot as plt

#load wav file
wr = wave.open("holst_mono_clip.wav", "rb")
print("Channel num:", wr.getnchannels())
print("Sample size:", wr.getsampwidth())
print("Sampling rate:", wr.getframerate())
print("Frame num:", wr.getnframes())
print("Sec:", float(wr.getnframes())/wr.getframerate())

n_sample = wr.getnframes()
f = wr.readframes(n_sample)
f = np.frombuffer(f, dtype = "int16")

start_wav = int(0 * wr.getframerate())
end_wav = int(20.0 * wr.getframerate())

N = end_wav - start_wav
N_half = int(N/2)
f = f[start_wav:end_wav]

#filter in frequency domain
F = np.fft.fft(f)
F = np.fft.fftshift(F)

#original spectrum
plt.plot(range(len(F)), np.abs(F))
plt.show()

#low pass filter
#F[0:N_half-15000] = 0
#F[N_half+15000:(-1)] = 0

# high pass filter
F[N_half-15000:N_half+15000] = 0

# filtered spectrum
plt.plot(range(len(F)), np.abs(F))
plt.show()

#convert to time domain
F = np.fft.fftshift(F)
f2 = np.fft.ifft(F)

#save wav file
w = wave.Wave_write("holst_mono_filtered.wav")
w.setparams((
    1,
    2,
    wr.getframerate(),
    wr.getnframes(),
    "NONE", "not compressed"
))
w.writeframes(array.array('h', f2).tostring())
w.close()