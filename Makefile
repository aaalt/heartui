all: 
	gcc -o img_pop src/main.c src/draw.c src/kbhit.c src/square.c src/dat.c src/col_palette.c src/rows.c

heart:
	./img_pop

clean:
	rm ./img_pop 