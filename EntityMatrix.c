#include "EntityMatrix.h"
/*
    Fun1.1 fcreateMatrix
    * creates a matrix with row and int
*/
Matrix* createMatrix (int row, int col){

    Matrix* m = (Matrix*)malloc (sizeof(Matrix));
    if (m == NULL)
        perror ("Matrix allocation failed");
    
    m->numRow = row;
    m->numCol = col;


    /*
    *Allocate Memory for the Array of Pointers to Rows:
    First pointer points to the block of memory that contains the rows
    Second pointer points to the first row, Row
    ----> MBLOCK-----> ARRAY OF #s
    +-----------+           +---------------+
    | double* (R1)  |   ---->   | [ double ]    |
    +-----------+           +---------------+
    | double* (R2)  |   ---->   | [ double ]    |
    +-----------+           +---------------+
    */

    m->data = (double**) malloc (row * sizeof(double*));

    if (m->data == NULL) {
        perror("Data* allocation failed!");
        free(m); //*no Matrix
        return NULL;
    }

    double* m_block = (double*) malloc(row * col * sizeof(double));
    if (m_block == NULL){
        free(m->data); //*no Data
        free(m); //*no Matrix
        return NULL;
    }

    /*
        *inititializing the Array of pointers to the rows    
        matrix->data:
        +-----------+       +---------------------+
        | data[0]   | ----> | matrixBlock[0][0]   | 0 + number of columns as an entry to the matrix block
        +-----------+       +---------------------+
        | data[1]   | ----> | matrixBlock[1][0]   | 1 + number of columns as an entry to the matrix block
        +-----------+       +---------------------+
        | data[2]   | ----> | matrixBlock[2][0]   | 2 + number of columns as an entry to the matrix block
        +-----------+       +---------------------+
    */

    for (int i =0; i < row; i++){
        m->data[i] = &m_block [i * col];
    }

    /*
        *initializing the values of the matrix (each data[i[]])
    */

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            m->data[i][j] = 0.0;
        }
    }

    return m;
}

/*
    func1.2 initMatrix
    * implementing a function to copy the values from 'double* values' to the Matrix
    Matrix M has already been created and is available for initialization
*/

void initMatrix (Matrix* m, double* values) {


    int r = m->numRow;
    int c = m->numCol;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            m->data[i][j] = values[(i * c) + j];
    }
}

}

void printMatrix (Matrix* m){
    int r = m->numRow;
    int c = m->numCol;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++){
            printf("%.1lf ", m->data[i][j]);
        }
        printf("\n");
    }
}

/*
    func___ Adding Function
    * uses stdarg.h library for argument Matrices
*/



void freeMatrix(Matrix* m) {
    if (m != NULL) {
        // Free the matrix data
        if (m->data != NULL) {
            free(m->data[0]); // Free the contiguous data block
            free(m->data);    // Free the array of pointers to rows
        }
        // Free the Matrix structure
        free(m);
    }
}