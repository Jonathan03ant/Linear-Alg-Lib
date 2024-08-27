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
void initVector(Vector* v, double* values) {
	if (v == NULL || v->vector == NULL) {
        perror("Vector is NULL or not properly allocated");
        return;
    }

	for (int i = 0; i < v->size; i++) {
		if (values != NULL) {
			v->vector[i] = values[i];
		} else {
			v->vector[i] = 0.0;
		}
	}
}

/*
	TAKES: A Vector pointer `v` and an integer `index`
	RETURNS: The element at the specified index of the vector as a double
	Performs bounds checking and returns a special value (-1.0) if the vector is NULL or if the index is out of range.
*/
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

/*
	TAKES: A Vector pointer `v`
	RETURNS: The size of the vector as an integer
	Performs a NULL check and returns -1 if the vector is NULL, otherwise returns the size of the vector.
*/
int getSizeVector(Vector* v) {
    if (v == NULL) {
        perror("Vector is NULL");
        return -1;
    }
    return v->size;
}

/*
	TAKES: A Vector pointer `v`
	RETURNS: void
	Prints the elements of the vector along with its size.
	Performs a NULL check before attempting to print the vector.
*/
void freeVector(Vector* vector) {
    if (vector != NULL) {
        free(vector->vector);
        free(vector);
    }
}