#include "defs.h"

/*
    Fun1.1 fcreateMatrix
*/
Matrix* createMatrix (int row, int col){

    Matrix* m = (Matrix*)malloc (sizeof(Matrix));
    if (m == NULL)
        perror ("Matrix allocation failed");
    
    m->numRow = row;
    m->numCol = col;
    m->data = (double**) malloc (row * sizeof(double*));

    /*
    +-----------+           +---------------+
    | double*   |   ---->   | [ double ]    |
    +-----------+           +---------------+
    | double*   |   ---->   | [ double ]    |
    +-----------+           +---------------+
    */
    if (m->data == NULL) {
        perror("Data* allocation failed!");
        free(m);
        return NULL;
    }

    
}