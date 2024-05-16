all: main
main: main.o EntityVector.o BasicOperations_V.o
	gcc -o main main.o EntityVector.o BasicOperations_V.o
main.o: main.c
	gcc -c main.c
EntityVector.o: EntityVector.c
	gcc -c EntityVector.c
BasicOperations_V.o: BasicOperations_V.c
	gcc -c BasicOperations_V.c
clean:
	rm -rf *.o main