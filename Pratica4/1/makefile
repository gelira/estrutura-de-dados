all: main

main: ListaDuplamenteEncadeada.o main.o
	gcc ListaDuplamenteEncadeada.o main.o -o main

ListaDuplamenteEncadeada.o: ListaDuplamenteEncadeada.h ListaDuplamenteEncadeada.c
	gcc -c ListaDuplamenteEncadeada.c -o ListaDuplamenteEncadeada.o

main.o: ListaDuplamenteEncadeada.h main.c
	gcc -c main.c -o main.o

run:
	./main