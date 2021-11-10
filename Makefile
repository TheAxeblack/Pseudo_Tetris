CC= gcc
OPTIONS= -W -Wall -std=c89 -pedantic -O3

titouan: tetris.o main.c
	$(CC) $(OPTIONS) main.c tetris.o -o titouan
tetris.o: tetris.c tetris.h
	$(CC) $(OPTIONS) -c tetris.c