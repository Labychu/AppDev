#include <stdio.h>
#include <unistd.h>
#include "screen.h"

int main(void) {
	printf("Press any key to continue\n");
	getchar();	//wait for the user to press a key
	
	for (int i = 0; i < 15; i++) {
		setColors(RED, BLK);
		clrscr();
		drawRect(i + 1, i * 3, 2, 4);
		gotoXY(15 - i, i * 3);
		setColors(GRN, BLK);
		printf("Hello\n");
		usleep(500000);
	}

	for (int i = 0; i < 15; i++) {
		setColors(RED, BLK);
		clrscr();
		drawRect(15 - i, i * 3 + 45, 2, 4);
		gotoXY(i, i * 3 + 45);
		setColors(GRN, BLK);
		printf("Hello\n");
		usleep(500000);
	}

	resetColor();
	clrscr();
	printf("Press any key to continue\n");
	getchar();  // Wait for user to press a key
	printf("Default color\n");
	return 0;
}
