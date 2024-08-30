#ifndef BASICOPS_H
#define BASICOPS_H

#include <stdio.h>
#include <stdlib.h>
#include "Matrix_i.h"



Matrix* addMatrices(int, Matrix**);
Matrix* subtractMatrix(int, Matrix**);
Matrix* scalarMultiply (Matrix*, double);
Matrix* transposeMatrix(Matrix*);
Matrix* multiplication(Matrix*, Matrix*);

#endif

