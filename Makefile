CC= gcc
OPTIONS= -W -Wall -std=c89 -pedantic -O3
OPTIONS_MLV1= `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV`
OPTIONS_MLV2= `pkg-config --libs-only-l MLV`

titouan: tetris.o game.o main.c
	$(CC) $(OPTIONS_MLV1) $(OPTIONS) main.c tetris.o game.o -o titouan $(OPTIONS_MLV2)
game.o: game.c tetris.h
	$(CC) $(OPTIONS_MLV1) $(OPTIONS) -c game.c $(OPTIONS_MLV2)
tetris.o: tetris.c tetris.h
	$(CC) $(OPTIONS_MLV1) $(OPTIONS) -c tetris.c $(OPTIONS_MLV2)
clean:
	rm -rf *.o titouan