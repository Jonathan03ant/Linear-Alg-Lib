all: main

main: main.c EntityVector.c BasicOperations_V.c
	gcc -o main main.c EntityVector.c BasicOperations_V.c -I. -lm

clean:
	rm -f main
