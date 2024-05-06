CC=gcc
CFLAGS=-std=c11 -Wpedantic -Wall -Wextra
LDLIBS=-lm
RM=rm -f
OBJ=main.o convertion.o auxiliaryFunction.o
EXE=main

$(EXE):$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXE) $(LDLIBS)
main.o:main.c convertion.h auxiliaryFunction.h
	$(CC) $(CFLAGS) -c main.c
conversion.o:convertion.c convertion.h auxiliaryFunction.h
	$(CC) $(CFLAGS) -c convertion.c
auxiliaryFunction.o: auxiliaryFunction.c auxiliaryFunction.h
	$(CC) $(CFLAGS) -c auxiliaryFunction.c
clean:
	$(RM) $(OBJ) $(EXE)
