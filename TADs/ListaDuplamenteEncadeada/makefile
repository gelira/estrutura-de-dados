all: main

main: ListaDuplamenteEncadeada.o main.o
	gcc ListaDuplamenteEncadeada.o main.o -o main

ListaDuplamenteEncadeada.o: ListaDuplamenteEncadeada.c ListaDuplamenteEncadeada.h
	gcc -c ListaDuplamenteEncadeada.c -o ListaDuplamenteEncadeada.o

main.o: main.c ListaDuplamenteEncadeada.h
	gcc -c main.c -o main.o

run:
	./main