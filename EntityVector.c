#include "EntityVector.h"

/*
        func_Vec_entityObject 2.1
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
         func_Vec_entityObject 2.2
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

/*
    func_Vec_entityObject 2.3
    *Returns a vector element
*/
double getElementVector(Vector* v, int index){
    if (v == NULL){
        perror("Vector is NULL");
    }

    if (index < 0 || index >= v->size) {
        perror("Index out of range");
        return 0.0;
    }

    return (v->vector[index]);

}



/*
    func_Vec_entityObject 2.3 
    *Prints a Vector vertically
*/

void printVector (Vector* v){
    if (v == NULL) {
        printf("Vector is NULL\n");
        return;
    }

    printf("Vector Size: %d\n", v->size);
    for (int i = 0; i < v->size; i++) {
        printf("%.2lf\n", v->vector[i]);
    }
}


/*
    func_Vec_entityObject 2.4
    *Frees/Destroys vectors
*/
void freeVector(Vector* vector){
    free(vector->vector);
    free(vector);
}
