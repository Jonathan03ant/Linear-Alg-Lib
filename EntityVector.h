#ifndef ENTITYVECTOR_H
#define ENTITYVECTOR_H



#include <stdio.h>

#include <stdlib.h>

typedef struct {
    double* vector;
    int size;
}Vector;

Vector* createVector(int);
Vector* initVector(Vector*, double*, int);
double getElementVector(Vector*, int); // not implemented

void printVector(Vector*);
void freeVectors(Vector*);

#endif