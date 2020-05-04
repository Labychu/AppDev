#include "sound.h" // includes stdio.h, math.h, comm.h and screen.h

int main(void) {
	// Check if the user screen is too small.
	// Need at least to be as big as the chart (BARS, defined in sound.h).
	Position p = getScreenSize();
	printf("%d %d\n", p.col, BARS);
	/*
	if (p.col < BARS) {
		printf("Your screen size is too small.\n");
		return 1;
	}*/
	clrscr();
	// Open the .wav file named test.wav
	FILE *fptr = fopen("test.wav", "rb");
	if (!fptr) {
		printf("Cannot open file.\n");
		return 1;
	}
	// Read and print out the header of the file.
	WAVHeader header = readWAVHeader(fptr);
	displayWAVHeader(header);
	getchar();
	clrscr();
	// Display the sound data as a chart.
	WAVData(header, fptr);
	// Close file pointer.
	fclose(fptr);
	return 0;
}
