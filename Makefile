CC = gcc
FILES = *.c
FLAGS = -Wall -Werror -Wconversion -std=c99
NAME = evento_pesca

clear:
	clear

evento_pesca:
	$(CC) $(FILES) $(FLAGS) -o evento_pesca

run: evento_pesca
	./evento_pesca
