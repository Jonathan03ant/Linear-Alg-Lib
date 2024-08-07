#include "Matrix_i.h"
/*
    Fun1.1 fcreateMatrix
    * creates a matrix with row and int
    * allocates memory for the matrix  data
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
        *The rows are stored in a contiguous block of memory which are dynamic 
            (hence a double pointer)
        * Second pointer points to the first row, Row
        ----> MBLOCK-----> ARRAY OF #s
        +-----------+           +---------------+
        | double* (R1)  |   ---->   | [ double ]    |
        +-----------+           +---------------+
        | double* (R2)  |   ---->   | [ double ]    |
        +-----------+           +---------------+

        however, on the memory, the rows are stored in a contiguous block of memory
        Double* R1 points to the first element of the first row
        Double* R2 points to the first element of the second row

        Pointer[Array first row], Pointer[Array second row], Pointer[Array third row]
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
    TAKES: Matrix Pointer to be initialized, An array of double values
    RETURNS: void
    # Initializes the Matrix with arg2 parameter values
*/
void initMatrix (Matrix* m, double* values) {

    /*
        *Need some kind of error checking here to esure the double values match the matrix dimention
    */

    if (m == NULL || values == NULL) {
        perror("Matrix or values is NULL");
        return;
    }

    int r = m->numRow;
    int c = m->numCol;


    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            m->data[i][j] = values[(i * c) + j];
        }
    }

}

/*
    TAKES: Matrix* m
    RETURNS: void
    # Prints the matrix values
*/
void printMatrix (Matrix* m){
    int r = m->numRow;
    int c = m->numCol;
    printf("Printing Matrix %d x %d\n", r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++){
            printf("%.1lf ", m->data[i][j]);
        }
        printf("\n");
    }
}

/*
    TAKES: Matrix* m
    RETURNS: void
    # Double Array(values) are freed first
    # Then  Double pointer is freed
    # Finally Mattrix structure is freed
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