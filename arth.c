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
        | data[0]   | ----> | matrixBlock[0][0]   |
        +-----------+       +---------------------+
        | data[1]   | ----> | matrixBlock[1][0]   |
        +-----------+       +---------------------+
        | data[2]   | ----> | matrixBlock[2][0]   |
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





