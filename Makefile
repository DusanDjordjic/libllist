CC=gcc
CFLAGS=-Wall -Wextra -O2
BIN=main
DBIN=dmain
SRC=main.c
OBJ=main.o
LIBOBJ=llist.o
LIB=libllist.a

all: $(BIN)

lib: $(LIB)

debug: $(DBIN)

$(BIN): $(OBJ) $(LIB) 
	$(CC) -o $@ $(OBJ) -L. -lllist

$(LIB): $(LIBOBJ) 
	ar crs $@ $(LIBOBJ) 

$(DBIN): $(OBJ) $(LIB)
	$(CC) -g -o $@ $(OBJ) libllist

%.o: %.c
	$(CC) -c $< -o $@


