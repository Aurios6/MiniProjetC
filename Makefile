CC=gcc
CFLAGS=-std=c11 -Wpedantic -Wall -Wextra
LDLIBS=-lm
RM=rm -f
OBJ=main.o conversion.o
EXE=main

$(EXE):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) $(LDLIBS)
main.o:main.c conversion.h
	$(CC) $(CFLAGS) -c main.c
conversion.o:conversion.c conversion.h
	$(CC) $(CFLAGS) -c conversion.c
clean:
	$(RM) $(OBJ)
