#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*
    Struct def: 
                contains row, col and data of the matrix
                data is a double pointer 
*/

typedef struct {
    int numRow;
    int numCol;
    double** data;
} Matrix;

Matrix* createMatrix (int, int);
void initMatrix (Matrix*, double*);
void printMatrix (Matrix*);


Matrix* addMatrices(int, Matrix**);
Matrix* subtractMatrix(int, Matrix**);
Matrix* scalarMultiply (Matrix*, double);
Matrix* transposeMatrix(Matrix*);


void freeMatrix(Matrix*);