#include <stdio.h>
#include <unistd.h>
#include "comm.h"
#include "sound.h"

int main(void) {
	Position p = getScreenSize();
	char postdata[1000];
	printf("%d %d\n", p.col, BARS);
	/*if (p.col < BARS) {
		printf("Your screen size is too small.\n");
		return 1;
	}*/
	clrscr();
	FILE *fptr = fopen("1.wav", "rb");
	if (!fptr) {
		printf("Cannot open file.\n");
		return 1;
	}
	WAVHeader header = readWAVHeader(fptr);
	displayWAVHeader(header);
	getchar();
	clrscr();
	WAVData(header, fptr);
	fclose(fptr);
	return 0;
}
