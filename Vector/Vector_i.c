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

/*
	TAKES: A Vector pointer `v` and an array of `double` values `values`
	RETURNS: void
	Initializes the vector with the provided values, or zeros if `values` is NULL.
*/

void initVector(Vector* v, double* values){
	if (v == NULL || v->vector == NULL) {
        perror("Vector is NULL or not properly allocated");
        return;
    }

	for (int i=0; i < v->size; i++){
		if (values != NULL){
			v->vector[i] = values[i];
		} else {
			v->vector[i] = 0.0;
		}
	}
}

double getElementVector(Vector* v, int index) {
    if (v == NULL) {
        perror("Error: Vector is NULL");
        return -1.0; // Returning a special value indicating an error
    }

    if (index < 0 || index >= v->size) {
        perror("Error: Index out of range");
        return -1.0; // Returning a special value indicating an error
    }

    return v->vector[index];
}