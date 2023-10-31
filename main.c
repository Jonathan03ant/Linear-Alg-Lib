#include "BasicOperations.h"

int main() {
    // Create two matrices A and B
    Matrix* A = createMatrix(2, 3);
    Matrix* B = createMatrix(2, 3);

    // Initialize matrices A and B with values
    double valuesA[] = {3, 4, 1, 4, 9, 12.1};
    double valuesB[] = {2, 1, 0, 4, 22, 5.2};
    initMatrix(A, valuesA);
    initMatrix(B, valuesB);

    // Print matrices A and B
    printf("Matrix A:\n");
    printMatrix(A);
    printf("\n");

    printf("Matrix B:\n");
    printMatrix(B);
    printf("\n");

    // Create an array of matrices and add them
    Matrix* matrices[] = {A, B};
    Matrix* result = addMatrices(2, matrices);
    printf("Result Matrix:\n");
    printMatrix(result);
    Matrix* result2 = subtractMatrix(2, matrices);
    printf("Result Matrix:\n");
    printMatrix(result2);
    Matrix* result3 = scalarMultiply(A, 2.0);
    printMatrix(result3);
    Matrix* result4 = transposeMatrix(A);
    

    printMatrix(result4);


    // Free memory for matrices
    freeMatrix(result);
    freeMatrix(result2);
    freeMatrix(A);
    freeMatrix(B);

    return 0;
}

