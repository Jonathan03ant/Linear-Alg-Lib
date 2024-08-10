import numpy as np
import ctypes
from MatrixLib import matrix
import logging

logging.basicConfig(
    filename = "matrix_test.log",
    filemode = "w",
    level = logging.DEBUG,
    format='%(asctime)s %(levelname)s == %(message)s == %(funcName)s == %(lineno)d'
)

def test_populate_matrix():
    try:
        logging.info("____FUNC1: test_populate_matrix()")
        
        row, col = 2, 2
        MatrixA = matrix.createMatrix(row, col)
        logging.info("Matrix created")
        
        values = np.array([-2.0, 1.0, 1.0, 1.0], dtype=ctypes.c_double)
        matrix.initMatrix(MatrixA, values.ctypes.data_as(ctypes.POINTER(ctypes.c_double)))
        logging.info("Matrix initialized")
        
        MatrixB = matrix.createMatrix(row, col)
        values = np.array([1.0, 4.0, 1.0, 1.0], dtype=ctypes.c_double)
        matrix.initMatrix(MatrixB, values.ctypes.data_as(ctypes.POINTER(ctypes.c_double)))
        
        matrix.printMatrix(MatrixA)
        matrix.printMatrix(MatrixB)
        
        logging.info("**********passed********\n\n")
        
    except Exception as e:
        logging.error("Error Exception: %s", e)
        return
    
def test_add_matrix():
    try:
        logging.info("____FUNC2: test_add_matrix()")
        row, col = 3, 3
        A = matrix.createMatrix(row, col)
        values = np.array([1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0], dtype=ctypes.c_double)
        matrix.initMatrix(A, values.ctypes.data_as(ctypes.POINTER(ctypes.c_double)))
        
        B = matrix.createMatrix(row, col)
        values = np.array([1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0], dtype=ctypes.c_double)
        matrix.initMatrix(B, values.ctypes.data_as(ctypes.POINTER(ctypes.c_double)))
        
        C = matrix.addMatrix(2, A, B)
        matrix.printMatrix(C)
    except Exception as e:
        logging.error("Error Exception: %s", e)
        return
    


if __name__ == "__main__":
    test_populate_matrix()
    test_add_matrix()
    