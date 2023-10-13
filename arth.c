#include "defs.h"
#include "vectors.h"

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

/*
    * maybe need to check for error in a case where inappropriate matrix or values
*/
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


Matrix* addMatrices(int numMatrices, Matrix** matrices) {
    /*
        * Error checking //Compatibility
    */

    if (numMatrices < 1 || matrices == NULL){
        perror("At least two matrices must be specified");
        return NULL;
    }

    int r = matrices[0]->numRow;
    int c = matrices[0]->numCol;

    /*
        * Checking Matrix Dimension
    */

    for (int i = 1; i < numMatrices; i++){
        if(matrices[i]->numRow != r || matrices[i]->numCol != c){
            perror("Matrices have incompatible dimensions for addition");
            return NULL;
        }
    }

    /*
        * Creating Result Matrix
    */

    Matrix* result = createMatrix(r, c);
    if (result == NULL) {
        perror("Error: Memory allocation failed for the result matrix.\n");
        return NULL;
    }

    /*
        * Now we can loop through numMatrices and add the matrices to the result matrix
    */

    for (int i = 0; i < numMatrices; i++) {
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                result->data[j][k] += matrices[i]->data[j][k];
            }
        }
    }
    printf("\nAddition\n");
    return result;
}

Matrix* subtractMatrix (int numMatrices, Matrix** matrices){
    /*
        * Error checking //Compatibility
    */

    if (numMatrices < 2 || matrices == NULL){
        perror("At least two matrices must be specified");
        return NULL;
    }

    /*
        * Checking Matrix Dimension
    */

    int r = matrices[0]->numRow;
    int c = matrices[0]->numCol;

    for (int i = 1; i <numMatrices; i++){
        if(matrices[i]->numRow!= r || matrices[i]->numCol != c){
            perror("Matrices have incompatible dimensions for addition");
            return NULL;
        }
    }

    Matrix* result = createMatrix(r, c);

    /*
        * Now we can loop through numMatrices and add the matrices to the result matrix
    */
   
    for (int i = 0; i < numMatrices; i++){
        for (int j = 0; j < r; j++){
            for (int k = 0; k < c; k++){
                /*
                    * frist option is if we only have one matrix, then we copy the value of the first
                    * if we have more than one matrix, we will decrement the result
                */
                if (i == 0){
                    result->data[j][k] = matrices[i]->data[j][k];
                }else{
                    result->data[j][k] -= matrices[i]->data[j][k];
                }

            }
        }
    }
    printf("\nSubtraction\n");
    return result;

}
Matrix* scalarMultiply (Matrix* matrix, double scalar) {
    /*
        *Error checking

    */
    if (matrix == NULL || scalar == 0){
        perror("Input Matrix NULL or Scalar = 0");
        return NULL;
    }

    Matrix* result = createMatrix(matrix->numRow, matrix->numCol);
        if (result == NULL){
            perror("Memory Allocation Failed for 'Result' Matrix");
            return NULL;
        }

    /*
        * Looping over the matrix to multiply it by the Scalar value;
    */

    for (int i = 0; i < matrix->numRow; i++){
        for (int j = 0; j < matrix->numCol; j++){
            result->data[i][j] = matrix->data[i][j] * scalar;
        }
    }
    printf("\nScalar Multiplicatioin\n");
    return result;
}

Matrix* transposeMatrix (Matrix* matrix) {
    if (matrix == NULL){
        perror("Input Matrix is Null");
    }

    Matrix* result = createMatrix(matrix->numCol, matrix->numRow);
    if (result == NULL){
            perror("Memory Allocation Failed for 'Result' Matrix");
            return NULL;
        }
    
    /*
        *now we can loop through the matrix rows and invert the low and col
    */

    for (int i = 0; i < matrix->numRow; i++){
        for (int j = 0; j < matrix->numCol; j++){
            result->data[j][i] = matrix->data[i][j];
        }
    }

    printf("\nMatrix Transpose\n");
    return result;
}

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
