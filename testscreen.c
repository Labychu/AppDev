#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(void) {
	gotoXY(1, 1);
	clrscr();
	printf("Screen size: row=%d, col=%d\n", cur.row, cur.col);
	printf("Today we will make some animations. Press any key to continue\n");
	getchar();
	getchar();
	/*
	int ff, bb;
	float step = (float)cur.col / cur.row;
	for (int i = 1; i <= cur.row; i++) {
		clrscr();
		setFgColor(RED);
		drawRect(i, i * 3, 2, 4);
		setFgColor(GRN);
		gotoXY(cur.row - i, (i - 1) * step + 1);
		printf("HELLO\n");
		usleep(500000);
	}
	getchar();
	resetColor();
	*/
	clrscr();
	printf("Color is set back to default\n");
	getchar();
	FILE *fptr = fopen("1.wav", "r");
	WAVHeader header = readWAVHeader(fptr);
	fclose(fptr);
	displayWAVHeader(header);
	sprintf(postdata, "", );
	return 0;
}
