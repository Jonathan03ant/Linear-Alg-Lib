#include "defs.h"


int main(){
    Matrix* A = createMatrix(2, 3);
    double values[] = {3, 4, 1, 4, 9, 12.1};
    initMatrix(A, values);
    printMatrix(A);

    return 0;

}