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

/*
        func 2.3 
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
        func 2.4
    * takes in double pointer of vectors and adds them together
*/

Vector* addVectors(int numOfVectors, Vector** vectors){
    if (numOfVectors < 0 || vectors == NULL){
        perror("Not enough vectors for this Operation");
    }

    int size = vectors[0]->size;
    Vector* result = createVector(size);

    if (result == NULL){
        perror("Failed to allocate memory for the result vector");
        return NULL;
    }

    /*
        * Now we can loop through numVectors and add them all together
    */

    for (int i = 0; i < numOfVectors; i++){
        for (int j = 0; j < size; j++){
            result->vector[j] += vectors[i]->vector[j];
        }
    }

    
    return result;
}

/*
        func 2.5
    * takes in double pointer of vectors and Subtract them
*/

Vector* subtractVectors(int numOfVectors, Vector** vectors){
    if (numOfVectors < 2 || vectors == NULL){
        perror("Not enough Vectors for this Operation");
        return NULL;
    }

    int size = vectors[0]->size;
    Vector* result = createVector(size);

    if (result == NULL){
        perror("Failed to allocate memory for the result vector");
        return NULL;
    }

    /*
        * Now we can loop through numVectors and add them all together
        * before that, we need to copy the elements of the first Vector in our result Vector 
    */


    for (int i = 0; i < numOfVectors; i++){
        for (int j = 0; j < size; j++){
            if (i == 0){
                result->vector[j] = vectors[i]->vector[j];
            }else{
                result->vector[j] -= vectors[i]->vector[j];
            }
        }
    }

    return result;
}

/*
        func 2.6
    * Multiplies a vector by a scalar value
*/

Vector* scalarMultiplyVector(Vector* vector, double scalar){
    if (vector == NULL || scalar == 0){
        perror("Input Vector NUll or Multiplier is Zero");
        return NULL;
    }

    int size = vector->size;
    Vector* result = createVector(size);

    if (result == NULL){
        perror("Failed to allocate memory for result vector");
    }

    for (int i = 0; i < size; i++){
        result->vector[i] = vector->vector[i] * scalar;
    }

    return result;
}

/*
        func 2.7
    * returns the unit vector of V
*/

Vector* findUnitVector(Vector* vector){
    if (vector == NULL){
        perror("Vector is NULL");
    }

    int size = vector->size;
    Vector* result = createVector(size);

    double magnitude = 0.0;

    for (int i = 0; i < size; i++){
        magnitude += vector->vector[i] * vector->vector[i];
    }

    magnitude = sqrt(magnitude);

    for (int i = 0; i < size; i++){
        result->vector[i] = vector->vector[i] / magnitude;
    }
    return result;

}

double dotProduct(Vector* v, Vector* w){
    
    double result = 0.0;
    int size = w->size;

    for (int i = 0; i < size; i++){
        result += v->vector[i] * w->vector[i];
    }
    return result;
}

void freeVector(Vector* vector){
    free(vector->vector);
    free(vector);
}
