CC=gcc
CFLAGS=-Wall -Wextra
BIN=main
SRC=main.c
OBJ=main.o
LIBOBJ=linkedlist.o utils.o
LIB=liblinkedlist.a

all: $(BIN)

lib: $(LIB)

$(BIN): $(OBJ) $(LIB) 
	$(CC) -o $@ $(OBJ) -L. -llinkedlist

$(LIB): $(LIBOBJ) 
	ar crs $@ $(LIBOBJ) 

%.o: %.c
	$(CC) -c $< -o $@


