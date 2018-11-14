#include <stdio.h>
#include <stdlib.h>
#include "___.h"
#include <unistd.h>
#include <time.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>
#include <sys/ioctl.h>

#define SEC 1000000
#define END '@'
#define DELIM '#'

#define HEART_H 7
#define HEART_W 17

#define gotoxy(x,y) printf("\033[%d;%dH",(x),(y))

#define UP(x) printf("\033[%dA", (x)); 		// Move up X lines;
#define DOWN(x) printf("\033[%dB", (x)); 	// Move down X lines;
#define RIGHT(x) printf("\033[%dC", (x)); 	// Move right X column;
#define LEFT(x) printf("\033[%dD", (x)); 	// Move left X column;
#define CLEAR printf("\033[2J"); // Clear screen


typedef struct Params {
	UJ amount;
	// UJ max_len;
	// UJ max_line;
} pParams;
/*
typedef struct Background {
	C col[27];						//<	max len of colour str
	C ch;
} pBackground;
*/

typedef struct Numbers {
	H bck_col;	
	C ch;				
	H hrt_col;	
	C bl_str;			
	H str_col;
} pNumbers;

typedef struct Background {
	C bck_col[17];		//< 20				//<	max len of colour str
	C ch;				//<	1
	C hrt_col[17];		//<	20
	C blink[3];			//<	3
	C bln_col[17];		//<	21
	C string[6];		//<	6
	C str_col[17];		//<	21
} pBackground;

typedef struct winsize pTerminal_conf;

typedef pParams* params;
typedef pBackground* background;
typedef pTerminal_conf* ter_conf;
typedef pNumbers* numbers;



#ifdef __linux__

#define ESC_SQ "\x1b"

#define CWHT 	"\x1b[0;0m\x1b[37m\0"
#define CBLU 	"\x1b[0;0m\x1b[34m\0"

#define CRED 	"\x1b[0;0m\x1b[31m\0"
#define CNRM 	"\x1b[0;0m\0"

#endif 
#ifdef __APPLE__

#define ESC_SQ "\033"

#define CWHT 	"\033[0;0m\033[37m\0"
#define CBLU 	"\033[0;0m\033[34m\0"

#define CRED 	"\033[0;0m\033[31m\0"
#define CNRM 	"\033[0;0m\0"

#endif

//<	add your colours
	
// ext V get_background(FILE *db, background back, I ptr);
// ext V get_params(FILE *idx, params par);
