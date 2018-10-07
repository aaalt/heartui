#include <stdio.h>
#include <stdlib.h>
#include "___.h"
#include <unistd.h>
#include <time.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>
#include "config.h"
#include "draw.h"
#include "square.h"
#include <sys/stat.h>
#include <dirent.h>
#include <limits.h>
#include "make_palette.h"


V free_array(S* array, I len)
{
	for(I i = 0; i < len; i++)
		free(array[i]);
	free(array);
}


C blstr_mask(C blink, C str)
{
	C ch = str;

	ch += blink * 16;
	R ch;
}

C get_blink(C ch)
{
	C c = ch/16;
	R c;
}

C get_str(C ch)
{
	C c = ch%16;
	R c;
}

V make_struct_nmb(numbers par, I len)
{
	I n;;
	I k;
	k = rand()%len;
	n = rand()%10;
	n = (n > 4) ? 0 : n;					//< blank string more often

	par->bck_col = rand()%len;

	par->ch = (rand()%2) ? ' ' : ':';

	par->hrt_col = k;
	par->bl_str = blstr_mask(rand()%2, n);
	par->str_col = rand()%3;
}



V num_to_back(numbers par, background back, S* col_palette, S* blink_st_palette, S* blink_col_palette, S* str_st_palette, S* str_col_palette)		//< NEED col_palette[]; blink_st_palette[]; blink_col_palette[]; str_st_palette[]; str_col_palette[];
{
	strcpy(back->bck_col, col_palette[par->bck_col]);
	back->ch = par->ch;
	strcpy(back->hrt_col, col_palette[par->hrt_col]);
	strcpy(back->blink, blink_st_palette[get_blink(par->bl_str)]);
	strcpy(back->bln_col, blink_col_palette[get_blink(par->bl_str)]);
	strcpy(back->string, str_st_palette[get_str(par->bl_str)]);

	if (!get_str(par->bl_str))
		strcpy(back->str_col, col_palette[par->hrt_col]);
	else 
		strcpy(back->str_col, str_col_palette[par->str_col]);
}


V make_arrays()													//< compose db and idx
{
	C bck_chr[3] = " :\0";
	S blnk_col[2]   = {CWHT, CRED};
	S str[5];

	C bl1[3]		=   ".|\0";
	C bl2[3]		=   "::\0";
	C str_0[6]		=   ":::::\0";
	C str_2[6]		=   "MYDAK\0";
	C str_3[6]		=   " love\0";
	C str_4[6]		=   " you \0";
	C str_1[6]		=	"pain \0";

	S* blink_st_palette = malloc(SZ(S) * 2);
	S* blink_col_palette = malloc(SZ(S) * 2);
	S* str_st_palette = malloc(SZ(S) * 5);
	S* str_col_palette = malloc(SZ(S) * 3);
	S* col_palette = make_palette();
	
	blink_st_palette[0] = malloc(SZ(C) * 3);
	blink_st_palette[1] = malloc(SZ(C) * 3);

	blink_col_palette[0] = malloc(SZ(C) * 17);
	blink_col_palette[1] = malloc(SZ(C) * 17);

	str_st_palette[0] = malloc(SZ(C) * 17);
	str_st_palette[1] = malloc(SZ(C) * 17);
	str_st_palette[2] = malloc(SZ(C) * 17);
	str_st_palette[3] = malloc(SZ(C) * 17);
	str_st_palette[4] = malloc(SZ(C) * 17);

	str_col_palette[0] = malloc(SZ(C) * 17);
	str_col_palette[1] = malloc(SZ(C) * 17);
	str_col_palette[2] = malloc(SZ(C) * 17);

	strcpy(blink_st_palette[0], bl1);
	strcpy(blink_st_palette[1], bl2);
	strcpy(blink_col_palette[0], CWHT);
	strcpy(blink_col_palette[1], CRED);
	strcpy(str_st_palette[0], str_0);
	strcpy(str_st_palette[1], str_1);
	strcpy(str_st_palette[2], str_2);
	strcpy(str_st_palette[3], str_3);
	strcpy(str_st_palette[4], str_4);
	strcpy(str_col_palette[0], CRED);
	strcpy(str_col_palette[1], CWHT);
	strcpy(str_col_palette[2], CBLU);
	draw_heart(col_palette, blink_st_palette, blink_col_palette, str_st_palette, str_col_palette);
}