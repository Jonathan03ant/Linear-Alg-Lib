all: _matrix.so

Matrix_i.o: Matrix_i.c Matrix_i.h
	gcc -c -fPIC Matrix_i.c

BasicOps.o: BasicOps.c BasicOps.h
	gcc -c -fPIC BasicOps.c

matrix_wrap.c: matrix_wrap.i
	swig -python matrix_wrap.i -o matrix_wrap.c 

matrix_wrap.o: matrix_wrap.c
	gcc -c -fPIC matrix_wrap.c -I/opt/homebrew/opt/python@3.12/Frameworks/Python.framework/Versions/3.12/include/python3.12

_matrix.so: matrix_wrap.o Matrix_i.o BasicOps.o 
	gcc -shared matrix_wrap.o Matrix_i.o BasicOps.o -o _matrix.so -L/opt/homebrew/opt/python@3.12/Frameworks/Python.framework/Versions/3.12/lib -lpython3.12

clean:
	rm -f *.o *.so matrix_wrap.c matrix.py
