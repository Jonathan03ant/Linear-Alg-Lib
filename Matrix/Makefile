all: _Matrix.so

_Matrix.so: matrix_wrap.o Matrix_i.o BasicOps.o 
	gcc -shared matrix_wrap.o Matrix_i.o BasicOps.o -o _Matrix.so -L/opt/homebrew/opt/python@3.12/Frameworks/Python.framework/Versions/3.12/lib -lpython3.12

matrix_wrap.o: matrix_wrap.c
	gcc -c -fPIC matrix_wrap.c -I/opt/homebrew/opt/python@3.12/Frameworks/Python.framework/Versions/3.12/include/python3.12

Matrix_i.o: Matrix_i.c Matrix_i.h
	gcc -c -fPIC Matrix_i.c

BasicOps.o: BasicOps.c BasicOps.h
	gcc -c -fPIC BasicOps.c

matrix_wrap.c: matrix_wrap.i
	swig -python -o matrix_wrap.c matrix_wrap.i

clean:
	rm -f *.o *.so matrix_wrap.c matrix.py

