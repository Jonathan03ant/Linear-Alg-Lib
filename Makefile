all: main

main: main.o EntityMatrix.o BasicOperations.o
	gcc -o main main.o EntityMatrix.o BasicOperations.o
main.o: main.c
	gcc -c main.c
EntityMatrix.o: EntityMatrix.c
	gcc -c EntityMatrix.c
BasicOperations.o: BasicOperations.c
	gcc -c BasicOperations.c
clean:
	rm -rf *.o
