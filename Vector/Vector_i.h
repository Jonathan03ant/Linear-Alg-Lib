#ifndef VECTOR_I_H
#define VECTOR_I_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double* vector;
	int size;
} Vector;

Vector* createVector(int);
Vector* initVector(Vector*, double*);
double getElement(Vector*, int);
int getSize(Vector*);

void printVector(Vector*);
void freeVector(Vector*);
#endif
