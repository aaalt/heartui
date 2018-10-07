#include <stdio.h>
#include <stdlib.h>
#include "___.h"
#include "config.h"
#include <unistd.h>
#include <time.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>
// #include "draw.h"
#include "dat.h"
// #include "kbhit.h"


I main(I argc, S* argv)
{
	// srand(time(NULL));
	// kbinit();

	if (access("bin/db.dat", F_OK) == -1 || access("bin/idx.dat", F_OK) == -1 || (argc >= 2 && !strcmp(argv[argc-1], "f"))) {
		O("db doesn't exist\nstart making:\n"); 
		make_db();
	}
	else
		O("db already exists\n");

	// draw_heart();
	// kbfini();
	R0;
}