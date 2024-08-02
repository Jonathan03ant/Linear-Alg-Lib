all: _Matrix.so

_Matrix.so: Matrix_i.o BasicOps.o 
	gcc -shared Matrix_i.o BasicOps.o -o _Matrix.so -L/opt/homebrew/opt/python@3.12/Frameworks/Python.framework/Versions/3.12/lib -lpython3.12

Matrix_i.o: Matrix_i.c Matrix_i.h
	gcc -c -fPIC Matrix_i.c

BasicOps.o: BasicOps.c BasicOps.h
	gcc -c -fPIC BasicOps.c

clean:
	rm -f *.o *.so matrix_wrap.c matrix.py
