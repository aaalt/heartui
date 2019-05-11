all: 
	gcc -g -o bin/img_pop src/main.c src/draw.c src/kbhit.c src/square.c src/dat.c src/col_palette.c src/rows.c

heart:
	./bin/img_pop

clean:
	rm bin/img_pop 