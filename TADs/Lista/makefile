all: main

main: lista.o main.o
	gcc lista.c main.o -o main

lista.o: lista.c lista.h
	gcc -c lista.c -o lista.o

main.o: main.c lista.h
	gcc -c main.c -o main.o

run:
	./main
