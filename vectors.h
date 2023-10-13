#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


typedef struct {
    double* vector;
    int size;
}

vector* createVector(int);
vector* initVector(vector*, double*);