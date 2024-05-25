CC=gcc
CFLAGS=-std=c11 -Wpedantic -Wall -Wextra
LDLIBS=-lm
RM=rm -f
OBJ=main.o conversion.o auxiliaryFunction.o
EXE=main

$(EXE):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) $(LDLIBS)
main.o:main.c conversion.h auxiliaryFunction.h
	$(CC) $(CFLAGS) -c main.c
conversion.o:conversion.c conversion.h auxiliaryFunction.h
	$(CC) $(CFLAGS) -c conversion.c
auxiliaryFunction.o: auxiliaryFunction.c auxiliaryFunction.h
	$(CC) $(CFLAGS) -c auxiliaryFunction.c
clean:
	$(RM) $(OBJ)
