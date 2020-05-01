#include <stdio.h>
#include <math.h>
#include "sound.h"

//function definitions
WAVHeader readWAVHeader(FILE *fptr) {
	WAVHeader myHeader;
	fread(&myHeader, sizeof(myHeader), 1, fptr); 
	return myHeader; 
}

void displayWAVHeader(WAVHeader header) {
	double duration;
	for (int i = 0 ; i < 4 ; i++) {
		printf("%c", header.chunkID[i]);
	}
	printf("\n");
	printf("Chunk size: %d\n", header.chunkSize);
	printf("Number of channels: %d\n", header.numChannels);
	printf("Sample rate: %d\n", header.sampleRate);
	printf("Bits per sample: %d\n", header.bitsPerSample);  
	// to be continued
	duration = (double) header.subchunk2Size / header.byteRate;
	printf("Duration: %lf seconds\n", duration);  
}

void WAVData(WAVHeader header, FILE *fptr) {
	// For sample rate of 16k sps, we need to
	// read 2000 samples to calculate a "Fast"
	// decibel value. A decibel value is
	// always calculated by the RMS 
	// (ROOT MEAN SQUARE) formula.
	short samples[SIZE];
	double old = 0;
	int peak = 0;
	int maxPeak = 0;
	for (int i = 0; i < BARS; i++) { // 5s of wav file = 40 sets of data
		fread(&samples, sizeof(samples), 1, fptr);
		double sum = 0;
		for (int k = 0; k < SIZE; k++) {
			sum += samples[k] * samples[k];
		}
		double dB = 20 * log10(sqrt(sum / SIZE));
		// Find the max peak
		if (dB > maxPeak) maxPeak = (int)dB;
		if (i == 0 && dB > 70) peak++;
		if (dB > 70 && old < 70) peak++;
		old = dB;
		#ifdef SDEBUG
			printf("dB[%d] = %lf\n", i, dB);
		#else
			int fg = dB > 70 ? RED : WHT;
			setFgColor(fg);
			drawBar(i + 1, (int)dB / 3);
		#endif
	}
	resetColor();
	gotoXY(1, 1);
	setFgColor(CYN);
	printf("Sample rate: %d", SAMPLERATE);
	gotoXY(1, 130 / 2);
	setFgColor(MAG);
	printf("Duration: %0.3lf", (double) header.subchunk2Size / header.byteRate);
	gotoXY(1, 130);
	setFgColor(YEL);
	//displayWAVHeader(header);
	printf("Number of peaks: %d\n", peak);
	resetColor();
}

// EOF
