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

V make_struct_nmb(numbers par)
{
	I len = lines();
	I n = rand()%5;
	I k;
	k = rand()%len;
	par->bck_col = rand()%len;

	par->ch = (rand()%2) ? ' ' : ':';

	par->hrt_col = k;
	par->bl_str = blstr_mask(rand()%2, n);
	par->str_col = (!n) ? k : rand()%3;
}



V num_to_back(numbers par, background back, S* col_palette, S* blink_st_palette, S* blink_col_palette, S* str_st_palette, S* str_col_palette)		//< NEED col_palette[]; blink_st_palette[]; blink_col_palette[]; str_st_palette[]; str_col_palette[];
{
	strcpy(back->bck_col, col_palette[par->bck_col]);
	back->ch = par->ch;
	strcpy(back->hrt_col, col_palette[par->hrt_col]);
	strcpy(back->blink, blink_st_palette[get_blink(par->bl_str)]);
	strcpy(back->bln_col, blink_col_palette[get_blink(par->bl_str)]);
	strcpy(back->string, str_st_palette[get_str(par->bl_str)]);
	strcpy(back->str_col, str_col_palette[par->str_col]);
}


V make_arrays()													//< compose db and idx
{
	FILE *db, *idx;
	I addr;
	params par;
	pParams p = {0};

    // C cur_dir[PATH_MAX];
    // DIR *d;

	/*  make your own combination   */

	C bck_chr[3] = " :\0";

	// S bck_col[6]	= {CWHT, CBLU, CCYN, BCYN, BPNKCW, BMGNCW};
	// S hrt_col[3]	= {CRED, CWHT, BPNKCW};

    //< ^

    //< blink 2 
    //< str 5 


	// S blnk[2];
	S blnk_col[2]   = {CWHT, CRED};
	S str[5];
	// S str_col[3]	= {CRED, CWHT, CBLU};

	C bl1[3]		=   ".|\0";
	C bl2[3]		=   "::\0";
	C str_1[6]		=   ":::::\0";
	C str_2[6]		=   "MYDAK\0";
	C str_3[6]		=   " love\0";
	C str_4[6]		=   " you \0";
	C str_0[6]		=	"pain \0";
														//< NEED col_palette[]; blink_st_palette[]; blink_col_palette[]; str_st_palette[]; str_col_palette[];

	S* blink_st_palette = malloc(SZ(S) * 2);
	S* blink_col_palette = malloc(SZ(S) * 2);
	S* str_st_palette = malloc(SZ(S) * 5);
	S* str_col_palette = malloc(SZ(S) * 3);
	S* col_palette = make_palette();
	

	// O("init\n");

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

	// O("init\n");

	strcpy(blink_st_palette[0], bl1);
	// O("init\n");
	strcpy(blink_st_palette[1], bl2);
	strcpy(blink_col_palette[0], CWHT);
	strcpy(blink_col_palette[1], CRED);
	strcpy(str_st_palette[0], str_0);
	strcpy(str_st_palette[1], str_1);
	strcpy(str_st_palette[2], str_2);
	strcpy(str_st_palette[3], str_3);
	// O("init\n");
	strcpy(str_st_palette[4], str_4);
	// O("init\n");
	strcpy(str_col_palette[0], CRED);
	strcpy(str_col_palette[1], CWHT);
	// O("init\n");
	strcpy(str_col_palette[2], CBLU);

	O("init\n");
	draw_heart(col_palette, blink_st_palette, blink_col_palette, str_st_palette, str_col_palette);

/*
	blnk[0] = bl1; blnk[1] = bl2;
	str[0] = str_1; str[1] = str_2; str[2] = str_3; str[3] = str_4, str[4] = str_0;

    getcwd(cur_dir, SZ(cur_dir));                                               //< if /bin doesn't exist
    if (!dir_exists(strcat(cur_dir, "/bin/")))
         mkdir(cur_dir, S_IRUSR | S_IWUSR | S_IXUSR);

	db = 	fopen("bin/db.dat", "w+b");
	idx = 	fopen("bin/idx.dat", "w+b");

	par = &p;

	total = 2 * len * len * 2 * 5 * 3 - 2;
	struct_array = malloc(SZ(background) * total);
	for (i = 0; i < total; i++)
		struct_array[i] = malloc(SZ(pBackground));

	num = 0;
*/
	/*  if you changed settings ^ don't forget to modify cycles' params	 */
/*
	for (i = 0; i < 2; i++){										//< background character
		for (j = 0; j < len; j++) {									//< background colour
			// O("im here!\n");
			for (k = 0; k < len; k++){								//< heart colour
				O("T\n");
				if (!k && !j)
					k++;
				for (l = 0; l < 2; l++) {							//< blink style
					// m = l;										//< blink colour
						for (n = 0; n < 5; n++) {					//< string style

							for (o = 0; o < 3; o++) { 				//< string colour
								// par_str = (!n) ? k : o;
								O("T\n");
								struct_array[num]->bck_col = j;
								struct_array[num]->ch = (i) ? ' ' : ':';
								// O("T\n");

								struct_array[num]->hrt_col = k;
								struct_array[num]->bl_str = blstr_mask(l, n);
								struct_array[num]->str_col = (!n) ? k : o;;

								num++;
								// par->max_len = MAX(par->max_len, heart_par->max_len);
								// par->max_line = MAX(par->max_line, heart_par->max_line);

								par->amount++;
								// fwrite(&addr, SZ(I), 1, idx);
							}	
						}
				}
				// O("%d  \t", k);
			}

			if (!(j%100)) {
				O("[make_db]  included %d\n", (i + 1) * (j + 1) * con);

			}
		}
		O("HALF DONE\n");
	}
	
	rewind(idx);
	fwrite(par, SZ(pParams), 1, idx);

	for (i = 0; i < total; i++) {
		O("%d  ", i);
		fflush(stdin);
		fwrite(struct_array[i], SZ(pBackground), 1, db);
	}

	O("\nWROTE STRUCTS IN DB\n");

    for (i = 0; i < len; i++)
        free(palette[i]);
    free(palette);


    O("ALL FINE in making db && idx\n");

	fclose(db);
	fclose(idx);*/



}