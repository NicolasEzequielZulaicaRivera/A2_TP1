CC = gcc
FILES = *.c
FLAGS = -Wall -Werror -Wconversion -std=c99
NAME = evento_pesca

clear:
	clear

evento_pesca: $(FILES)
	$(CC) $(FILES) $(FLAGS) -o evento_pesca

run: evento_pesca
	./evento_pesca

zip:
	zip A2_TP1.zip *.c *.h *.pdf *.md Makefile

check: evento_pesca
	valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./evento_pesca
