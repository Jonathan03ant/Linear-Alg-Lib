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
    


if __name__ == "__main__":
    test_populate_matrix()
    