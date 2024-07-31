#ifndef MATRIX_I_H
#define MATRIX_I_H

#include <stdio.h>
#include <stdlib.h>

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
void freeMatrix(Matrix*);

#endif