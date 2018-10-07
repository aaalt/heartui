#include <stdio.h>
#include <stdlib.h>
#include "___.h"
#include <unistd.h>
#include <time.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>
#include "config.h"
#include "dat.h"

#include <sys/ioctl.h>
#include "kbhit.h"
#include <pwd.h>
#include <sys/types.h>
#include <dirent.h>
#include "rows.h"
#include "make_palette.h"

V draw_side(S col, C ch, I w, I dif)
{
	O("%s", col);
	DO((w - HEART_W)/2 + dif, {O("%c", ch);});
	fflush(stdout);
}


V show_img(background heart_par, ter_conf _ter_conf)								//< print img 
{
	I j, dif, k = 0, height = _ter_conf->ws_row;
	struct winsize a;
	ter_conf _ter_var = &a;
	C cnrm[7] = "\x1b[0;0m";

	gotoxy(0, 0);
	// CLEAR;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, _ter_conf);															//<	get window size

	if (_ter_conf->ws_col < HEART_W || _ter_conf->ws_row < HEART_H) {										//<	in case of small screen
		DO(_ter_conf->ws_row, {DO(_ter_conf->ws_col, {O(" ");});O("\n");});									//<	draw blank screen
		R;
	}

	O("%s", heart_par->bck_col);																			//<	set background colour
	DO((_ter_conf->ws_row - HEART_H)/2 - 1, {DO(_ter_conf->ws_col, {O("%c", heart_par->ch);}); O("\n");}); 		//< draw top
	fflush(stdout);

	dif = (_ter_conf->ws_col % 2) ? 0 : 1;													
	// dif = 1;
	/*	row_1()		*/
	draw_side(heart_par->bck_col, heart_par->ch, _ter_conf->ws_col, 0);								//<	draw left
	row_1(heart_par->bck_col, heart_par->ch, heart_par->hrt_col, cnrm);
	draw_side(heart_par->bck_col, heart_par->ch, _ter_conf->ws_col, dif);
	O("\n");

	/*	row_2()		*/
	draw_side(heart_par->bck_col, heart_par->ch, _ter_conf->ws_col, 0);
	row_2(heart_par->hrt_col, heart_par->blink, heart_par->bln_col, cnrm);
	draw_side(heart_par->bck_col, heart_par->ch, _ter_conf->ws_col, dif);
	O("\n");

	/*	row_3()	*/
	draw_side(heart_par->bck_col, heart_par->ch, _ter_conf->ws_col, 0);
	row_3(heart_par->hrt_col, cnrm);
	draw_side(heart_par->bck_col, heart_par->ch, _ter_conf->ws_col, dif);
	O("\n");

	/* row_4()	*/
	draw_side(heart_par->bck_col, heart_par->ch, _ter_conf->ws_col, 0);
	row_4(heart_par->bck_col, heart_par->ch, heart_par->hrt_col, heart_par->string, heart_par->str_col, cnrm);
	draw_side(heart_par->bck_col, heart_par->ch, _ter_conf->ws_col, dif);
	O("\n");

	/*	row_5()	*/
	draw_side(heart_par->bck_col, heart_par->ch, _ter_conf->ws_col, 0);
	row_5(heart_par->bck_col, heart_par->ch, heart_par->hrt_col, cnrm);
	draw_side(heart_par->bck_col, heart_par->ch, _ter_conf->ws_col, dif);
	O("\n");

	/*	row_6()	*/
	draw_side(heart_par->bck_col, heart_par->ch, _ter_conf->ws_col, 0);
	row_6(heart_par->bck_col, heart_par->ch, heart_par->hrt_col, cnrm);
	draw_side(heart_par->bck_col, heart_par->ch, _ter_conf->ws_col, dif);
	O("\n");

	/*	row_7()	*/

	draw_side(heart_par->bck_col, heart_par->ch, _ter_conf->ws_col, 0);
	row_7(heart_par->bck_col, heart_par->ch, heart_par->hrt_col, cnrm);
	draw_side(heart_par->bck_col, heart_par->ch, _ter_conf->ws_col, dif);
	O("\n");


	dif = (_ter_conf->ws_row % 2) ? 0 : 1;

	DO((_ter_conf->ws_row - HEART_H)/2 + dif, {DO(_ter_conf->ws_col, {O("%c", heart_par->ch);}); O("\n");}); 	//< draw down
	// DO((_ter_conf->ws_row - HEART_H)/2 + dif - 3, {DO(_ter_conf->ws_col, {O("%c", heart_par->ch);}); O("\n");}); 	//< draw down (test mode)

	// O("w %d * h %d\n", _ter_conf->ws_col, _ter_conf->ws_row);

	fflush(stdout);
}


V window_dif_change(background heart_par, ter_conf _ter_conf, I pause)
{
	struct winsize a;
	ter_conf _ter_var = &a;
	I j, i, p = SEC/60;
	j = pause/p;

	show_img(heart_par, _ter_conf);
	// O("w %d * h %d\n", _ter_conf->ws_col, _ter_conf->ws_row);
	for (i = 0; i < j; i++) {
		usleep(p);
		ioctl(STDOUT_FILENO, TIOCGWINSZ, _ter_var);
		if (_ter_var->ws_col != _ter_conf->ws_col || _ter_var->ws_row != _ter_conf->ws_row)	
			show_img(heart_par, _ter_conf);
	}
}


V draw_heart(S* col_palette, S* blink_st_palette, S* blink_col_palette, S* str_st_palette, S* str_col_palette)										//< print rand img
{
	I pos, i, j, pause = SEC, n, num = 0;

	pParams para = {0};
	params par = &para;

	pBackground back_;
	pNumbers nmb_;
	
	numbers nmb = &nmb_;
	background heart_par = &back_;
	
	struct winsize a;
	ter_conf _ter_conf = &a;

	O("draw_heart();\n");


	CLEAR;
	for (;;) {
		make_struct_nmb(nmb);

		num_to_back(nmb, heart_par, col_palette, blink_st_palette, blink_col_palette, str_st_palette, str_col_palette);
		
		pause = (pause == (SEC * 6)/7) ? (SEC*1)/2 : (SEC * 6)/7;	//< set pause
		// pause = SEC * 3 /2;
		window_dif_change(heart_par, _ter_conf, pause);	

		if(kbhit())													//< break if any key pressed
    		break;	
	}

	O("%s\n", CNRM);												//<	set back to normal

	free_array(col_palette, lines());
	free_array(blink_st_palette, 2);
	free_array(blink_col_palette, 2);
	free_array(str_st_palette, 5);
	free_array(str_col_palette, 3);

/*	fclose(db);
	fclose(idx);*/
}
