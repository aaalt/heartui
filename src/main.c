#include <stdio.h>
#include <stdlib.h>
#include "___.h"
#include "config.h"
#include <unistd.h>
#include <time.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>
#include "draw.h"
#include "dat.h"
#include "kbhit.h"


I main()
{
	srand(time(NULL));
	kbinit();

	// if (access("bin/db.dat", F_OK) == -1) 
		make_arrays();

	// draw_heart();
	kbfini();
	R0;
}