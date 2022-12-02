BINDIR=bin
OBJDIR=obj
SRCDIR=src

OS=$(shell uname -o)
ifeq ($(OS), Msys)
BINFILE=ss.exe
endif
ifeq ($(OS), GNU/Linux)
BINFILE=ss
endif

BIN=$(BINDIR)/$(BINFILE)
OBJ=$(OBJDIR)/*.o
CFILES=$(SRCDIR)/*.c

CC=gcc

debug: CFLAGS=-g -pedantic -Wall -I/C/CSFML/include
debug: build compile

release: CFLAGS=-O2 -Wall
release: build compile

compile: $(BIN)
$(BIN) : $(OBJ)
	$(CC) -o $(BIN) $(OBJ) -lcsfml-window -lcsfml-graphics -L/C/CSFML/lib/gcc

build: $(OBJ)
$(OBJ) : $(CFILES)
	$(CC) -c $(CFILES) $(CFLAGS)

	@mkdir -p $(BINDIR)
	@mkdir -p $(OBJDIR)
	@mv *.o $(OBJDIR)/

clean:
	rm $(OBJ) $(BINDIR)/*

distclean: clean
	rmdir $(BINDIR) $(OBJDIR)

run:
	$(BIN)


