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

const int NUM_SAMPLES = (WAVFILE_SAMPLES_PER_SECOND*4);

int main()
{
        short  waveform[NUM_SAMPLES];
	char SoundFile[256];
	double frequency,tempvalue;
	int VolumeLevel,TotalHarmonics;
	printf("Frequency\n");
	scanf("%lf",&frequency);
	printf("TotalHarmonics\n");
	scanf("%d",&TotalHarmonics);
	printf("Print Volume Level\n");
	scanf("%d",&VolumeLevel);
	printf("Sound File Name\n");
	scanf( "%s" , SoundFile );
	int volume = 1000*VolumeLevel;
	int length = NUM_SAMPLES;

	int i,j;
	for(i=0;i<length;i++)
	  {
		double t = (double) i / WAVFILE_SAMPLES_PER_SECOND;
		tempvalue=0;
		for(j=1;j<=TotalHarmonics;j++)
		  {
		  tempvalue=tempvalue+(sin(j*frequency*2*M_PI -1) * t)/(2*j-1);
		  }
		waveform[i]=volume*tempvalue;
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
