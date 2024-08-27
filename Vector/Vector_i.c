#include "Vector_i.h"


/*
	TAKES IN SIZE
	ALLOCATES A MEMORY AND CREATE EMPTY VECTOR STRUCT
*/



Vector* createVector(int size){
	Vector* v = (Vector*)malloc(sizeof(Vector));
	    if (v == NULL){
        perror("Failed to create a memory for Vector Data");
        return NULL;
    }

	v->size = size;
	v->vector = (double*)malloc(sizeof(double));
	if (v->vector == NULL){
        perror("Failed to allocate memory for vector V");
        free(v);
        return NULL;
    }
    return v;

}