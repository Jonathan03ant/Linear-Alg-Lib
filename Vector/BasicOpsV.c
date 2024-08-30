#include "BasicOpsV.h"

Vector* addVectors (int num, Vector** vectors){
    if (num < 0 || vectors == NULL){
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
    for (int i = 0; i < num; i++){
        for (int j = 0; j < size; j++){
            result->vector[j] += vectors[i]->vector[j];
        }
    }

    return result;

}