#include "vectors.h"

vector* createVector(int size) {
    vector* v = (vector*)malloc(sizeof(vector));
    if (v == NULL){
        perror("Failed to allocate a memory for vector v");
    }

    v->size = size;
}

vector* initVector (vector* v, double* values){
    
}