#include <stdio.h>
#include "sound.h"

//function definitions
WAVHeader readWAVHeader(FILE *fptr) {
	WAVheader myHeader; 
	fread(&myHeader, sizeof(myHeader), 1, fptr); 
	return myHeader; 
}

void displayWAVHdr(WAVHeader header) {
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
	duration = (double) header.subchunk2Size/header.byteRate;
	printf("Duration: %lf seconds\n", duration);  
}
