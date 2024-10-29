all: _Vector.so

_Vector.so: Vector_i.o BasicOps.o
	gcc -shared Vector_i.o BasicOps.o -o -L/opt/homebrew/opt/python@3.12/Frameworks/Python.framework/Versions/3.12/lib -lpython3.12
Vector_i.o: Vector_i.c Vector_i.h
	gcc -c fPIC Vector_i.c
BasicOps.o: BasicOps.c BasicOps.h
	gcc -c fPIC BasicOps.c 
clean:
	rm -f *.o *.so

