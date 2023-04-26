CC = gcc
CFLAGS = -W -Wall -g -std=c89 -pedantic -O3 `pkg-config --cflags MLV`
DEBUGFLAGS = -W -Wall -pedantic -std=c99 -g `pkg-config --cflags MLV`
LDLIBS = `pkg-config --libs-only-l MLV` `pkg-config --libs-only-other --libs-only-L MLV`

SRCDIR = src
OBJDIR = obj
BINDIR = bin

SRCFILES = $(wildcard $(SRCDIR)/*.c)
OBJFILES = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCFILES))
DBGFILES = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.do, $(SRCFILES))

.PHONY: all clean

all: $(BINDIR)/prog $(BINDIR)/debug

$(BINDIR)/prog: $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $@ $(LDLIBS)

$(BINDIR)/debug: $(DBGFILES)
	$(CC) $(DEBUGFLAGS) $(DBGFILES) -o $@ $(LDLIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(OBJDIR)/%.do: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(DEBUGFLAGS) -Iinc -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -rf $(OBJDIR) $(BINDIR)