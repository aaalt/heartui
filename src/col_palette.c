#include <stdio.h>
#include <stdlib.h>
#include "___.h"
#include <unistd.h>

#include <unistd.h>
#include <string.h>


//<	0	colour_0
//<	1	colour_1
//<	2	.
//<		.
//<	m	.
//<	n	\0


V reverse(S s)
 {
     I i, j;
     C c;
 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }

S itoa(I n, S str)
{
	I i, max;
	str[0] = n % 10 + '0';
	for(i = 1;(n/=10) > 0;i++) 
		str[i] = n % 10 + '0';
	
	str[i] = '\0';
	reverse(str);
	R str;
}


S col(I a, I b, S colour)						//< returns "\x1b[0;0m\x1b[(a);(b)m"
{
	C str[50];
	colour = malloc(SZ(C) * 30);
	strcat(colour, "\x1b[0;0m\x1b[");
	strcat(colour, itoa(a, str));
	strcat(colour, ";");
	strcat(colour, itoa(b, str));
	strcat(colour, "m");
	R colour;
}


V draw_palette(S* colour, I len)
{
	I i, k = 0;
	C str[8] = ":: ::\0";

	for (i = 0; i < len; i++) {

		if (k < 4) {
			O("%s'%s'%s\t", colour[i], str, "\x1b[0;0m");
			k++;
		}
		else {
			O("%s'%s'%s\n", colour[i], str, "\x1b[0;0m");
			k = 0;
		}
	}
	O("\n\n");
}

#ifdef __linux__

I lines()
{
	I cnt, i, j;
/*
	cnt = 0;
	for (i = 0; i < 98; i++) {
		i =	(IN(48, i, 89))	? 	90 	:
			(IN(10, i, 29))	?	30	:
			(IN(37, i, 39))	?	40	:
			(IN(5, i, 6))	?	7	: i;

		for (j = 1; j < 97; j++) {
			if (i == 8) {
				j = (IN(9, j, 39))	?	40	:
					(IN(0, j, 6))	?	7	: j;
				if (j > 47)
					break;
			}
			if (i > 9 && j == 39)
				j++;

			j = (IN(48, j, 89))	?	90	:
				(IN(10, j, 29))	?	30	:
				(IN(5, j, 6))	?	7	: j;

			if (j == 8)
				j++;

			cnt++;
		}
	}
	cnt++;
*/
	cnt = 918;
	R cnt;
}

S* make_palette()
{
	I i, j, cnt = 0, line = lines(), k = 0;
	S* colour = malloc(SZ(S) * line);
	// C str[8] = ":: ::\0";
	for (i = 0; i < line + 1; i++)
		colour[i] = malloc(SZ(C) * 20);

	colour[cnt] = col(0,8, colour[cnt]);					//<	add 0;8
	// O("%d\t%s'%s'%s  [%d;%dm \t",cnt, colour[cnt], str, "\x1b[0;0m", i, j);
	// k++;

	cnt++;

	for (i = 0; i < 98; i++) {
		i =	(IN(48, i, 89))	? 	90 	:
			(IN(10, i, 29))	?	30	:
			(IN(37, i, 39))	?	40	:
			(IN(5, i, 6))	?	7	: i;

		for (j = 1; j < 97; j++) {

			if (i == 8) {
				j = (IN(9, j, 39))	?	40	:
					(IN(0, j, 6))	?	7	: j;
				if (j > 47)
					break;
			}


			j = (IN(48, j, 89))		?	90	:
				(IN(10, j, 29))		?	30	:
				(IN(5, j, 6))		?	7	: 
				(i > 9 && j == 39)	? 	40	: 
				(j == 8)			?	9	: j;

	
			colour[cnt] = col(i, j, colour[cnt]);
			/*if (k < 2) {
				O("%d\t%s'%s'%s  [%d;%dm \t",cnt, colour[cnt], str, "\x1b[0;0m", i, j);
				k++;
			}
			else {
				O("%d\t%s'%s'%s  [%d;%dm\n", cnt, colour[cnt], str, "\x1b[0;0m", i, j);
				k = 0;
			}*/
			cnt++;
		}
	}
	// O("\ntotal colours: %d\n", cnt);
	colour[cnt][0] = 0;
	R colour;
}

#endif

#ifdef __APPLE__

I lines()
{
	I i, j, cnt;
	
	/*for (i = 0; i < 98; i++) {

		i =	(IN(48, i, 89))	? 90	:
			(IN(10, i, 29))	? 30	:
			(IN(38, i, 40))	? 41	:
			(IN(5, i, 6))	? 7		: i;

		for (j = 1; j < 98; j++) {

			if (i > 89 && j > 89)
				break;

			if (j == 40 ||  j == 92)
				j++;

			j = (IN(49, j, 89))	? 90	:
				(IN(10, j, 29))	? 30	:
				(IN(5, j, 8))	? 9		: j;		

			if (i == 30 && IN(2, j, 30))
				j = 31;

			if (j == 30 && IN(2, i, 97))
				j++;

			cnt++;
		}
		// O("%d\t", i);
	}
*/
	cnt = 850;
	R cnt;
}

S* make_palette()
{
	I i, j, cnt = 0, line = lines();
	S* colour = malloc(SZ(S) * line);


	for (i = 0; i < line + 1; i++)
		colour[i] = malloc(SZ(C) * 20);

	colour[cnt] = col(0,8, colour[cnt]);					//<	add 0;8
	cnt++;

	for (i = 0; i < 98; i++) {

		i =	(IN(48, i, 89))	? 90	:
			(IN(10, i, 29))	? 30	:
			(IN(38, i, 40))	? 41	:
			(IN(5, i, 6))	? 7		: i;

		for (j = 1; j < 98; j++) {

			if (i > 89 && j > 89)
				break;

			// if (j == 40 || j == 92)
				// j++;

			j = (IN(49, j, 89))			? 90	:
				(IN(10, j, 29))			? 30	:
				(IN(5, j, 8))			? 9		:
				(j == 40 || j == 92)	? j+1 	: j;		

			if (i == 30 && IN(2, j, 30))
				j = 31;

			if (j == 30 && IN(2, i, 97))
				j++;


			colour[cnt] = col(i, j, colour[cnt]);
			cnt++;
		}
	}
	colour[cnt][0] = 0;
	// draw_palette(colour, line);
	// O("\ntotal colours: %d\n", cnt);
	R colour;
}

#endif

//<	0	colour_0
//<	1	colour_1
//<	2	.
//<		.
//<	m	.
//<	n	\0


/*
I main()
{
	draw_palette(make_palette(), lines());
	make_palette();
	O("total by lines(): %d\n", lines());
	R0;
}

*/