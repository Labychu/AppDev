#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(void) {
	Position cur = getScreenSize();
	char postdata[1000];
	sprintf(postdata, "row=%d&col=%d&id=e1900315", cur.row, cur.col);
	sendpost(URL, postdata);
	gotoXY(1, 1);
	printf("Screen size: row=%d, col=%d\n", cur.row, cur.col); 
	printf("Today we will make some animations. Press any key to continue\n");
	getchar();
	getchar(); 
	int ff, bb;
	float step = (float)cur.col / cur.row;  
	for (int i = 1; i <= cur.row; i++)
	{
		clrscr();
		setFgColor(RED);
		drawRect(i, i * 3, 2, 4);
		setFgColor(GRN);  
		gotoXY(cur.row - i, (i - 1) * step + 1);
		printf("HELLO\n");
		usleep(500000);  
	}

	getchar(); 
	resetColors();
	clrscr();
	printf("Color is set back to default\n");
	getchar();
	FILE *fptr = fopen("test.wav", "r");
	WAVHeader header = readWAVHeader(fp);
	fclose(fptr);
	displayWAVHeader(header);  
	return 0;
}