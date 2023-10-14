#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


typedef struct {
    double* vector;
    int size;
}Vector;

Vector* createVector(int);
Vector* initVector(Vector*, double*, int);
void printVector(Vector*);