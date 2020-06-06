/*Modifed by Achyut Sapkota(National Institute of Technology, Kisarazu College)
 for Frequency, Volume and Filename Options during run time. See below for information on original file and license conditions*/

/*
This example program makes use of the simple
sound library to generate a sine wave and write the
output to sound.wav.
For complete documentation on the library, see:
http://www.nd.edu/~dthain/courses/cse20211/fall2013/wavfile
Go ahead and modify this program for your own purposes.
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>

#include "wavfile.h"

const int NUM_SAMPLES = (WAVFILE_SAMPLES_PER_SECOND*2);

int main()
{
	short waveform[NUM_SAMPLES];
	char SoundFile[256];
	double frequency;
	int VolumeLevel;
	printf("Frequency\n");
	scanf("%lf",&frequency);
	printf("Select Volume Level\n");
	scanf("%d",&VolumeLevel);
	printf("Sound File Name\n");
	scanf( "%s" , SoundFile );
	int volume = 1000*VolumeLevel;
	int length = NUM_SAMPLES;

	int i;
	for(i=0;i<length;i++) {
		double t = (double) i / WAVFILE_SAMPLES_PER_SECOND;
		waveform[i] = volume*sin(frequency*t*2*M_PI);
	}

	FILE * f = wavfile_open(strcat(SoundFile,".wav"));
	if(!f) {
		printf("couldn't open sound.wav for writing: %s",strerror(errno));
		return 1;
	}

	wavfile_write(f,waveform,length);
	wavfile_close(f);

	return 0;
}
