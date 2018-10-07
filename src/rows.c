#include <stdio.h>
#include <stdlib.h>
#include "___.h"


V row_1(S back_col, C back_c, S heart_col, S norm)
{
	O("%s%c", back_col, back_c);
	if (back_c == ':') 												//<	if ':'	--> ':''
		O("\'");
	else 
		O("%s ", norm);							//<	if ' '	--> set nrm && ' '
	
	O("%s.:::.%s", heart_col, back_col);	

	if (back_c == ':') 												//<	if ':' --> '':''
		O("\':\'");
	else 																		//<	if ' '	-->	'   '
		O("   ");

	O("%s.:::.", heart_col);

	if (back_c == ':') 												//<	if ':' --> set background colour && '':'
		O("%s\'%c", back_col, back_c);
	else 																		//< if ' ' --> set nrm && ' ' && set background colour && ' '
		O("%s %s%c", norm, back_col, back_c);
}

V row_2(S heart_col, S blink, S blink_col, S norm)
{
	O("%s %s:::::::.:::%s%s%s::%s ", norm, heart_col, blink_col, blink, heart_col, norm);
}

V row_3(S heart_col, S norm)
{
	O("%s %s:::::::::::::::%s ", norm, heart_col, norm);
}



V row_4(S back_col, C back_c, S heart_col, S string, S str_col, S norm)
{
	if (back_c == ':') 
		O("%s.", back_col);
	else 
		O("%s ", norm);

	O("%s\'::::%s%s%s::::\'", heart_col, str_col, string, heart_col);
	
	O("%s", norm);

	if (back_c == ':') 
		O("%s.", back_col);
	else  {
		O(" ");
	}
}

V row_5(S back_col, C back_c, S heart_col, S norm)
{
	O("%s%c%c", back_col, back_c, back_c);

	if (back_c == ':') 
		O(".");
	else  
		O("%s ", norm);

	O("%s\':::::::::\'", heart_col);

	if (back_c == ':') 
		O("%s.", back_col);
	else  
		O("%s %s", norm, back_col);
	O("%c%c", back_c, back_c);
}

V row_6(S back_col, C back_c, S heart_col, S norm)
{
	I i;
	O("%s%c%c%c%c", back_col, back_c, back_c, back_c, back_c);

	if (back_c == ':') 
		O(".");
	else  
		O("%s ", norm);

	O("%s\':::::\'", heart_col);

/*	if (back_c == ':') 
		O("%s.", back_col);
	else  
		O("%s %s%c%c%c%c", norm, back_col, back_c, back_c, back_c, back_c);
*/

	if (back_c == ':') 
		O("%s.", back_col);
	else 
		O("%s %s", norm, back_col);
	O("%c%c%c%c", back_c, back_c, back_c, back_c);
	fflush(stdout);
}

V row_7(S back_col, C back_c, S heart_col, S norm)
{
	O("%s%c%c%c%c%c%c", back_col, back_c, back_c, back_c, back_c, back_c, back_c);

	if (back_c == ':') 
		O(".");

	else  
		O("%s ", norm);

	O("%s\':\'", heart_col);

	if (back_c == ':') 
		O("%s.", back_col);
	else  
		O("%s %s", norm, back_col);

	O("%c%c%c%c%c%c", back_c, back_c, back_c, back_c, back_c, back_c);
}

