CC=gcc
CFLAGS=-Wall -Wextra
BIN=main
SRC=main.c
OBJ=main.o
LIBOBJ=linkedlist.o utils.o
LIB=libll.a

all: $(BIN)

lib: $(LIB)

$(BIN): $(OBJ) $(LIBOBJ)
	$(CC) -o $@ $(OBJ) $(LIBOBJ) 

$(LIB): $(LIBOBJ) 
	ar crs $@ $(LIBOBJ) 

%.o: %.c
	$(CC) -c $< -o $@


