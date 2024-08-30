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

Vector* subtracktVectors(int num, Vector** vectors){
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
        * before that, we need to copy the elements of the first Vector in our result Vector 
    */


    for (int i = 0; i < num; i++){
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
