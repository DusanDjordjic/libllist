CC=gcc
CFLAGS=-Wall -Wextra
BIN=main
DBIN=dmain
SRC=main.c
OBJ=main.o
LIBOBJ=linkedlist.o utils.o
LIB=liblinkedlist.a

all: $(BIN)

lib: $(LIB)

debug: $(DBIN)

$(BIN): $(OBJ) $(LIB) 
	$(CC) -o $@ $(OBJ) -L. -llinkedlist

$(LIB): $(LIBOBJ) 
	ar crs $@ $(LIBOBJ) 

$(DBIN): $(OBJ) $(LIB)
	$(CC) -g -o $@ $(OBJ) -L. -llinkedlist

%.o: %.c
	$(CC) -c $< -o $@


