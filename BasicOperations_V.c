#include "BasicOperations_V.h"


/*
     func_vector_BasicOperation
    * takes in double pointer of vectors and adds them together, returns a vector (ptr)
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
     func_vector_BasicOperation
    * takes in double pointer of vectors and Subtract them, returns a vector(ptr)
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
     func_vector_BasicOperation
    * Takes in a Vector ptr and multiplier, returns Scalar Multiplication of the vector(ptr)
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
     func_vector_BasicOperation
    * Takes in a Vector Pointer, returns its unitVector(ptr)
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


/*
     func_vector_BasicOperation
    * Takes in two Vector Pointers, returns dotProduct (double)
*/
double dotProduct(Vector* v, Vector* w){
    
    double result = 0.0;
    int size = w->size;

    for (int i = 0; i < size; i++){
        result += v->vector[i] * w->vector[i];
    }
    return result;
}

