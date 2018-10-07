

#include <stdio.h>
#include <stdlib.h>
#include "___.h"
#include <unistd.h>
#include <time.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>


#include "config.h"

#include <limits.h>

/* wtites into ptr the block of unique img pattern */

V include_n_cnt(S str_1, S str_2, I *i)
{
	// include_string(str_1, str_2, *i, max);
	scpy(str_1 + *i, str_2, scnt(str_2));
	*i += scnt(str_2);
}



// background fill_heart(S background_colour, C background_char, S heart_colour, S blink, S blink_colour, S string, S string_colour)		//< compose img into dat straight to ptr

background fll_heart(H background_colour, C background_char, H heart_colour, C blink, C blink_colour, C string, C string_colour)
{
	C line[PATH_MAX];
	I i = 0, len = 0, j, m_line = 0;
/*
	C cap[6] = 			 ".:::.\0";
	C sec_line[12] = 	":::::::.:::\0";
	C th_line[16] = 	":::::::::::::::\0";
	C fourth_line_1[6] = 	"\'::::\0";
	C fourth_line_2[6] =		"::::\'\0";
	C fifth_line[12] = 		"\':::::::::\'\0";
	C sixth_line[8] =		"\':::::\'\0";
	C sev_line[4] = 		"\':\'\0";
*/

//<		|:'.:::.':'.:::.':|		//<		|  .:::.   .:::.  |
//<		| :::::::.:::.|:: |		//<		| :::::::.:::.|:: |
//<		| ::::::::::::::: |		//<		| ::::::::::::::: |
//<		|.'::::мудак::::'.|		//<		| '::::мудак::::' |
//<		|::.':::::::::'.::|		//<		|   ':::::::::'   |
//<		|::::.':::::'.::::|		//<		|     ':::::'     |
//<		|::::::.':'.::::::|		//<		|       ':'       |



	pParams par_;
	params par = &par_;
	pBackground bck_;
	background bck = &bck_;
/*
	strcpy(bck->bck_col, background_colour);
	bck->ch = background_char;
	strcpy(bck->hrt_col, heart_colour);
	strcpy(bck->blink, blink);
	strcpy(bck->bln_col, blink_colour);
	strcpy(bck->string, string);
	strcpy(bck->str_col, string_colour);*/
/*	bck->bck_col = background_colour;
	bck->ch = background_colour;
	bck->hrt_col = heart_colour;
	bck->blink = blink;
	// bck->bln_col = blink_colour;
	bck->string = string;
	bck->str_col = string_colour;
*/

	R bck;
																//<		bck 	img pattern 
	// fwrite(bck, SZ(pBackground), 1, ptr);						//<	|_______|_______________________|
																//<	write in bck info

/*
	strcat(line, background_colour);
	i = scnt(background_colour);
	line[i++] = DELIM;
	line[i++] = background_char;
	line[i++] = DELIM;
	strcat(line, )
*/


	// len += SZ(pBackground);
	// clear_str(line, i+1);

	/*	first line 	*/
/*
	include_n_cnt(line, background_colour, &i);		//<	background colour
	line[i++] = background_char;												//<	' ' || ':'
	if (background_char == ':') 												//<	if ':'	--> ':''
		line[i++] = '\'';
	else {
		include_n_cnt(line, CNRM, &i);								//<	if ' '	--> set nrm && ' '
		line[i++] = ' ';
	}
	include_n_cnt(line, heart_colour, &i);					//<	set heart colour
	include_n_cnt(line, cap, &i);									//<	write cap
	include_n_cnt(line, background_colour, &i);		//<	write background colour
	if (background_char == ':') {												//<	if ':' --> '':''
		line[i++] = '\'';
		line[i++] = ':';
		line[i++] = '\'';
	}
	else {																		//<	if ' '	-->	'   '
		for (j = 0; j < 3; j++)
			line[i++] = ' ';
	}
	include_n_cnt(line, heart_colour, &i);					//<	set heart colour
	include_n_cnt(line, cap, &i);									//<	write cap
	if (background_char == ':') {												//<	if ':' --> set background colour && '':'
		include_n_cnt(line, background_colour, &i);
		line[i++] = '\'';
		line[i++] = background_char;
	}
	else {																		//< if ' ' --> set nrm && ' ' && set background colour && ' '
		include_n_cnt(line, CNRM, &i);
		line[i++] = ' ';
		include_n_cnt(line, background_colour, &i);
		line[i++] = background_char;
	}
	line[i] = DELIM;															//< DELIM
	len += ++i;
	line[i] = 0;
	fwrite(line, SZ(C), i, ptr);												//< write in
	clear_str(line, i+1);														//< clear line
	m_line = MAX(m_line, i);
	i = 0;
*/
	/*	second line */
/*
	include_n_cnt(line, CNRM, &i);												//<	set nrm
	line[i++] = ' ';															//<	' '
	include_n_cnt(line, heart_colour, &i);										//<	set heart col
	include_n_cnt(line, sec_line, &i);											//<	sec line
	include_n_cnt(line, blink_colour, &i);										//<	blink colour
	include_n_cnt(line, blink, &i);												//<	blink
	include_n_cnt(line, heart_colour, &i);										//<	heart colour
	line[i++] = ':';															//< '::'
	line[i++] = ':';
	include_n_cnt(line, CNRM, &i);												//<	set nrm
	line[i++] = ' ';															//<	' '
	line[i] = DELIM;															//<	DELIM
	len += ++i;
	line[i] = 0;
	fwrite(line, SZ(C), i, ptr);												//<	write in
	clear_str(line, i+1);														//<	clear line
	m_line = MAX(m_line, i);
	i = 0;

	*/
	/*	third line 	*/
/*
	include_n_cnt(line, CNRM, &i);
	line[i++] = ' ';
	include_n_cnt(line, heart_colour, &i);
	include_n_cnt(line, th_line, &i);
	include_n_cnt(line, CNRM, &i);
	line[i++] = ' ';
	line[i] = DELIM;
	len += ++i;
	line[i] = 0;
	fwrite(line, SZ(C), i, ptr);
	clear_str(line, i+1);
	m_line = MAX(m_line, i);
	i = 0;
*/
	/*	fourth line */
/*	
	if (background_char == ':') {
		include_n_cnt(line, background_colour, &i);
		line[i++] = '.';
	}
	else {
		include_n_cnt(line, CNRM, &i);
		line[i++] = ' ';
	}
	include_n_cnt(line, heart_colour, &i);
	include_n_cnt(line, fourth_line_1, &i);
	include_n_cnt(line, string_colour, &i);
	include_n_cnt(line, string, &i);
	include_n_cnt(line, heart_colour, &i);
	include_n_cnt(line, fourth_line_2, &i);

	if (background_char == ':') {
		include_n_cnt(line, background_colour, &i);
		line[i++] = '.';
	}
	else {
		include_n_cnt(line, CNRM, &i);
		line[i++] = ' ';
	}
	line[i] = DELIM;
	len += ++i;
	line[i] = 0;
	fwrite(line, SZ(C), i, ptr);
	clear_str(line, i+1);
	m_line = MAX(m_line, i);
	i = 0;
*/
	/*	fifth line 	*/
/*
	include_n_cnt(line, background_colour, &i);
	line[i++] = background_char;
	line[i++] = background_char;
	if (background_char == ':') 
		line[i++] = '.';
	else  {
		include_n_cnt(line, CNRM, &i);
		line[i++] = ' ';
	}
	include_n_cnt(line, heart_colour, &i);
	include_n_cnt(line, fifth_line, &i);
	if (background_char == ':') {
		include_n_cnt(line, background_colour, &i);
		line[i++] = '.';
	}
	else  {
		include_n_cnt(line, CNRM, &i);
		line[i++] = ' ';
		include_n_cnt(line, background_colour, &i);
	}
	line[i++] = background_char;
	line[i++] = background_char;
	line[i] = DELIM;
	len += ++i;
	line[i] = 0;
	fwrite(line, SZ(C), i, ptr);
	clear_str(line, i+1);
	m_line = MAX(m_line, i);
	i = 0;
*/
	/*	sixth line 	*/
/*
	include_n_cnt(line, background_colour, &i);
	for (j = 0; j < 4; j++)
		line[i++] = background_char;

	if (background_char == ':') 
		line[i++] = '.';
	else  {
		include_n_cnt(line, CNRM, &i);
		line[i++] = ' ';
	}
	include_n_cnt(line, heart_colour, &i);
	include_n_cnt(line, sixth_line, &i);
	if (background_char == ':') {
		include_n_cnt(line, background_colour, &i);
		line[i++] = '.';
	}
	else  {
		include_n_cnt(line, CNRM, &i);
		line[i++] = ' ';
		include_n_cnt(line, background_colour, &i);
	}
	for (j = 0; j < 4; j++)
		line[i++] = background_char;
	line[i] = DELIM;
	len += ++i;
	line[i] = 0;
	fwrite(line, SZ(C), i, ptr);
	clear_str(line, i+1);
	m_line = MAX(m_line, i);
	i = 0;
*/
	/*	seventh line*/
/*
	include_n_cnt(line, background_colour, &i);
	for (j = 0; j < 6; j++)
		line[i++] = background_char;

	if (background_char == ':') 
		line[i++] = '.';
	else  {
		include_n_cnt(line, CNRM, &i);
		line[i++] = ' ';
	}
	include_n_cnt(line, heart_colour, &i);
	include_n_cnt(line, sev_line, &i);
	if (background_char == ':') {
		include_n_cnt(line, background_colour, &i);
		line[i++] = '.';
	}
	else  {
		include_n_cnt(line, CNRM, &i);
		line[i++] = ' ';
		include_n_cnt(line, background_colour, &i);
	}
	for (j = 0; j < 6; j++)
		line[i++] = background_char;
	line[i] = END;
	len += ++i;
	line[i] = 0;
	fwrite(line, SZ(C), i, ptr);
	
	par->max_line = MAX(m_line, i);
	par->max_len = len;
*/
	// O("one filled heart!\n");
	// R par;
}


