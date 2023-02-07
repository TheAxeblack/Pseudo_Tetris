CC = gcc
OPTIONS = -W -Wall -g -std=c89 -pedantic -O3 `pkg-config --cflags MLV`
DEBUG = -W -Wall -pedantic -std=c89 -g `pkg-config --cflags MLV`
MLV = `pkg-config --libs-only-l MLV` `pkg-config --libs-only-other --libs-only-L MLV`

TXT_FILES = $(wildcard src/*.c)
DAT_FILES = $(patsubst src/%.c, obj/%.o, $(TXT_FILES))
DEB_FILES = $(patsubst src/%.c, obj/%.do, $(TXT_FILES))

all:
	make bin/prog
	make bin/debug

prog:
	bin/prog

debug:
	bin/debug

bin/prog: $(DAT_FILES)
	$(CC) $(OPTIONS) $(DAT_FILES) -o $@ $(MLV)

bin/debug: $(DEB_FILES)
	$(CC) $(DEBUG)  $(DEB_FILES) -o $@ $(MLV)

obj/%.do: src/%.c
	$(CC) $(DEBUG)  -Iinc -c $< -o $@

obj/%.o : src/%.c
	$(CC) $(OPTIONS) -Iinc -c $< -o $@

clean :
	rm -rf obj/* */*~ bin/*