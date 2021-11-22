CC= gcc
OPTIONS= -W -Wall -std=c89 -pedantic -O3

titouan: tetris.o game.o main.c
	$(CC) $(OPTIONS) main.c tetris.o game.o -o titouan
game.o: game.c tetris.h
	$(CC) $(OPTIONS) -c game.c
tetris.o: tetris.c tetris.h
	$(CC) $(OPTIONS) -c tetris.c
clean:
	rm -rf *.o