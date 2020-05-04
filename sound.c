#include "sound.h"

void sendDataPHP(int maxVal, int peakNum) {
	// Send the max value of the sound in dB in decimal and the
	// number of peaks in the chart.
	char postdata[1000];
	sprintf(postdata, "maxVal=%d&peakNum=%d&ID=e1900323", maxVal, peakNum);
	sendpost(URL, postdata);
}

//function definitions
WAVHeader readWAVHeader(FILE *fptr) {
	WAVHeader myHeader;
	fread(&myHeader, sizeof(myHeader), 1, fptr);
	return myHeader;
}

void displayWAVHeader(WAVHeader header) {
	double duration;
	// Display the header od a .wav file
	// Includes: chunk ID, chunk size, number of channels, sample rate,
	// bits per sample and duration.
	for (int i = 0 ; i < 4 ; i++) {
		printf("%c", header.chunkID[i]);
	}
	printf("\n");
	printf("Chunk size: %d\n", header.chunkSize);
	printf("Number of channels: %d\n", header.numChannels);
	printf("Sample rate: %d\n", header.sampleRate);
	printf("Bits per sample: %d\n", header.bitsPerSample);
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
		// Calculate the value of sound in each set of data
		// according to the formula
		fread(&samples, sizeof(samples), 1, fptr);
		double sum = 0;
		for (int k = 0; k < SIZE; k++) {
			sum += samples[k] * samples[k];
		}
		double dB = 20 * log10(sqrt(sum / SIZE));
		// Find the max peak
		if (dB > maxPeak) maxPeak = (int)dB;
		// Find the number of peaks
		if (i == 0 && dB > 70) peak++;
		if (dB > 70 && old < 70) peak++;
		old = dB;
		// if SDEBUG is defined -> print out all dB values as an array
		// else print all dB values as a bar graph, the higher dB is the higher th bar.
		#ifdef SDEBUG
			printf("dB[%d] = %lf\n", i, dB);
		#else
			// if dB > 70 -> the bar is red
			int fg = dB > 70 ? RED : WHT;
			setFgColor(fg);
			// the max dB value is too big, devide all
			// by 3 for display purpose
			drawBar(i + 1, (int)dB / 3);
		#endif
	}
	resetColor();
	// Dis play sample rate at left most conner of window
	gotoXY(1, 1);
	setFgColor(CYN);
	printf("Sample rate: %d", SAMPLERATE);
	// Display duration with 3 numbers after '.' in the
	// middle of the first line
	gotoXY(1, 130 / 2);
	setFgColor(MAG);
	printf("Duration: %0.3lf", (double) header.subchunk2Size / header.byteRate);
	gotoXY(1, 130);
	// Display the number of peaks in the right most of the window
	setFgColor(YEL);
	printf("Number of peaks: %d\n", peak);
	resetColor();
	// Send the PHP POST string which includes the highest peak,
	// number of peaks and student ID.
	sendDataPHP(maxPeak, peak);
}

// EOF
