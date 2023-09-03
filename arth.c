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


    /*
    *Allocate Memory for the Array of Pointers to Rows:
    +-----------+           +---------------+
    | double*   |   ---->   | [ double ]    |
    +-----------+           +---------------+
    | double*   |   ---->   | [ double ]    |
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
    func1.2 finitMatrix
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
Matrix* addMatrices (int numMatrices, ...) {
    
    va_list matrices;
    va_start(matrices, numMatrices);

    Matrix* firstMatrix = va_arg(matrices, Matrix*);
    int r = firstMatrix->numRow;
    int c = firstMatrix->numCol;

    Matrix* result = createMatrix(r, c);
    if (result == NULL) {
        perror("Error: Memory allocation failed for result matrix.\n");
        va_end(matrices);
        return NULL;
    }

    /*
        *Now we can loop through va_args and add the matrices to the result matrix
    */

    for (int i = 0; i < numMatrices; i++) {
        //Extracting the first matrix
        Matrix* matrix = va_arg(matrices, Matrix*);

        /*
            *Error Handling for Incompatible Matrices (different Dimension)
        */
        if ((result->numRow != matrix->numRow) || (result->numCol != matrix->numCol)){
            perror("Error: Matrices have incompatible dimensions for addition.\n");
            va_end(matrices);
            return NULL;
        }

        /*
            *Matrix Addition Implementation
        */
        for (int i   = 0; i < result->numRow; i++){
            for (int j = 0; j < result->numCol; j++){
                result->data[i][j] += matrix->data[i][j];
            }
       }
    }
    va_end(matrices);
    return result;

}