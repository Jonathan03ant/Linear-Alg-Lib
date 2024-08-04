import numpy as np
import ctypes
from MatrixLib import matrix

def test_populate_matrix():
    print("Testing create and init matrix; then priting\n")
    row, col = 2, 2
    MatrixA = matrix.createMatrix(row, col)
    if MatrixA is None:
        print("Failed to create matrix\n")
        return
    print("Matrix created\n")
    
    values = np.array([-2.0, 1.0, 1.0, 1.0], dtype=ctypes.c_double)
    matrix.initMatrix(MatrixA, values.ctypes.data_as(ctypes.POINTER(ctypes.c_double)))
    print("Matrix initialized\n")
    
    matrix.printMatrix(MatrixA)
    
if __name__ == "__main__":
    test_populate_matrix()