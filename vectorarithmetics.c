#include "vectors.h"



/*
        func2.1
        * creates a vector object with default values.
*/
Vector* createVector(int size) {
    Vector* v = (Vector*)malloc(sizeof(Vector));
    if (v == NULL){
        perror("Failed to create a memory for Vector Data");
        return NULL;
    }

    v->size = size;
    v->vector = (double*)malloc(size * sizeof(double));
    if (v->vector == NULL){
        perror("Failed to allocate memory for vector V");
        free(v);
        return NULL;
    }
    return v;
}

/*
        func2.2
        * Initializes a vector from a pointer vector values
*/
Vector* initVector (Vector* v, double* values, int size){
    /*
        *checking errors
    */
    if (v == NULL || values == NULL){
        perror("Invalid Vector input or Values");
        return NULL;
    }

    if ((v->size) != size){
        perror("Invalid matching between Vector size and # of values");
        return NULL;
    }

    for (int i = 0; i < v->size; i++){
        v->vector[i] = values[i];
    }
    return v;

}

void printVector (Vector* v){
    printf("Vector Size: %d\n", v->size);
    for (int i = 0; i < v->size; i++){
        printf("%.2lf\n", v->vector[i]);
    }
    printf("\n");
}
