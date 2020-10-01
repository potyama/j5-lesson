VOLUME=20
P=0
Q=100

FREQUENCY = 20.wav 100.wav 500.wav 1000.wav 10000.wav 20000.wav 30000.wav 40000.wav
FREQUENCY_SIN = $(FREQUENCY:.wav=-sin.wav)
FREQUENCY_SQUARE = $(FREQUENCY:.wav=-square.wav)
FREQUENCY_SAWTOOTH = $(FREQUENCY:.wav=-sawtooth.wav)

#all: sin.out square.out sawtooth.out
all: $(FREQUENCY_SIN) $(FREQUENCY_SQUARE) $(FREQUENCY_SAWTOOTH)

clean:
	rm -f *.out
	rm -f *.wav

%.out: %.c wavfile.c
	gcc -o $@ $^ -lm


%-sin.wav: sin.out
	/bin/echo -e "$*\n$(VOLUME)\n$*-sin\n$(P)\n$(Q)" | ./$<

%-square.wav: square.out
	/bin/echo -e "$*\n$(VOLUME)\n$*-square\n$(P)\n$(Q)" | ./$<

%-sawtooth.wav: sawtooth.out
	/bin/echo -e "$*\n$(VOLUME)\n$*-sawtooth\n$(P)\n$(Q)" | ./$<


