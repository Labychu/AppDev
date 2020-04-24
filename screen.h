// usually in a header file, following info are included:
// 1. function declarations 
// 2. constant definations
// 3. conditional compilation

// constant def
#define ESC 0x1B
#define UNICODE
#define BAR "\u2590"
enum FG{BLK=30,RED,GRN,YEL,BLU,MAG,CYN,WHT};
#define bg(c) (c + 10)   // macro definition
//#define DEBUG // for conditional compilation

typedef struct {
	int row;
	int col;
} Position;


// function declarations
void clrscr(void);
void setFgColor(int);
void setBgColor(int);
void setColors(int, int);
void resetColor(void);
void gotoXY(int, int);
void drawBar(int, int);
void drawRect(int, int, int, int);
Position getScreenSize(void);
