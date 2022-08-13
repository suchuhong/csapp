CC = /usr/bin/gcc
CFLAGS = -Wall -g -O2 -Werror -std=gnu99

EXE = program

SRC = ./src

CODE = $(SRC)/memory/instruction.c $(SRC)/disk/code.c $(SRC)/main.c

.PHONY: program
main:
	$(CC) $(CFLAGS) -I$(SRC) $(CODE) -o $(EXE)

run:
	./$(EXE)
	