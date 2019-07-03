all: main

main: ListaEncadeada.o main.o
	gcc main.o ListaEncadeada.o -o main

ListaEncadeada.o: ListaEncadeada.c ListaEncadeada.h
	gcc -c ListaEncadeada.c -o ListaEncadeada.o

main.o: main.c ListaEncadeada.h
	gcc -c main.c -o main.o

run:
	./main