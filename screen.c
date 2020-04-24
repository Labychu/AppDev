#include <stdio.h>
#include "screen.h"
#include <string.h>

void clrscr(void) {
	printf("%c[2J", ESC);
}

void setFgColor(int fg) {
	printf("%c[1;%dm", ESC, fg);
}

void setBgColor(int bg) {
	printf("%c[1;%dm", ESC, bg);
}

void setColors(int fg, int bg){
	setFgColor(fg);
	setBgColor(bg(bg));
}

void resetColor(void) {
	printf("%c[0m", ESC);
}

void gotoXY(int row, int col) {
	printf("%c[%d;%dH", ESC, row, col);
}

void drawBar(int col, int height) {
	for (int i = 0; i < height; i++) {
		gotoXY(i, col);
		#ifdef UNICODE
			printf("%s", BAR);
		#else 
			printf("%c", '|');
		#endif
	}
}

void drawRect(int row, int col, int height, int width) {
	for (int i = row; i < row + height; i++) {
		for (int j = col; j < col + width; j++) {
			gotoXY(i, j);
#ifdef UNICODE
			printf("%s", BAR);
#else
			printf("%s", '|');
#endif
		}
		printf("\n");
	} 
}

Position getScreenSize(void) {
	// in this function, we will use terminal query function to query cursor
	// position, the terminal should return a string back to the program
	// if  a query string "0x1B[6n" is issued

	Position pos;
	char *ret;  // an empty string to get report
	gotoXY(999, 999);
	printf("%c[6n", ESC);
	scanf("%s", ret);  // Get the report from the terminal
#ifdef DEBUG
	printf("%s\n", ret);
#endif   
	// We will decode the returned string
	if (strlen(ret) > 0) {  // if we got the cursor pos report
		char dumb; // dummy char to consume excessive symbols
		int row, col;
		sscanf(ret, "%c%c%d%c%d%c", &dumb, &dumb, &row, &dumb, &col, &row);
		pos.row = row;
		pos.col = col;
	}
	else {
		pos.row = 0;
		pos.col = 0;
	}
	return pos;
}
