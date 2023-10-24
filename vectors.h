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
Vector* addVectors(int, Vector**);
Vector* subtractVectors(int, Vector**);
Vector* scalarMultiplyVector(Vector*, double);

Vector* findUnitVector(Vector*);
Vector* findNormalVector(Vector*);
Vector* dotProduct(Vector*, Vector*);
Vector* crossProduct(Vector*, Vector*);