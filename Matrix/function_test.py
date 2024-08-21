import numpy as np
import ctypes
from MatrixLib import matrix, Matrix
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
        logging.info("Matrix1 created")
        
        values = np.array([1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0], dtype=ctypes.c_double)
        matrix.initMatrix(A, values.ctypes.data_as(ctypes.POINTER(ctypes.c_double)))
        logging.info("Matrix1 initialized")
        
        B = matrix.createMatrix(row, col)
        logging.info("Matrix2 created")
        
        values = np.array([1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0], dtype=ctypes.c_double)
        matrix.initMatrix(B, values.ctypes.data_as(ctypes.POINTER(ctypes.c_double)))
        logging.info("Matrix2 initialized")
        

        matrices = (ctypes.POINTER(Matrix) * 2)(A, B)
        
        print("Adding matrices")
        logging.info("Adding matrices")
        C = matrix.addMatrices(2, matrices)
        matrix.printMatrix(C)
    except Exception as e:
        logging.error("Error Exception: %s", e)
        return
    
def test_subtract_matrix():
    try:
        logging.info("____FUNC3: test_subtract_matrix()")
        row, col = 3, 3
        A = matrix.createMatrix(row, col)
        logging.info("Matrix1 created")
        
        values = np.array([1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0], dtype=ctypes.c_double)
        matrix.initMatrix(A, values.ctypes.data_as(ctypes.POINTER(ctypes.c_double)))
        logging.info("Matrix1 initialized")
        
        B = matrix.createMatrix(row, col)
        logging.info("Matrix2 created")
        
        values = np.array([1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0], dtype=ctypes.c_double)
        matrix.initMatrix(B, values.ctypes.data_as(ctypes.POINTER(ctypes.c_double)))
        logging.info("Matrix2 initialized")
        

        matrices = (ctypes.POINTER(Matrix) * 2)(A, B)
        
        print("Subtracting matrices")
        logging.info("Subtracting matrices")
        C = matrix.subtractMatrix(2, matrices)
        matrix.printMatrix(C)
    except Exception as e:
        logging.error("Error Exception: %s", e)
        return
    
def test_scalar_multiplication():
    try:
        logging.info("____FUNC4: test_scalar_multiplication()")
        A = matrix.createMatrix(3, 1)
        logging.info("Matrix created")
        
        values = np.array([1.0, 2.0, 3.0], dtype=ctypes.c_double)
        matrix.initMatrix(A, values.ctypes.data_as(ctypes.POINTER(ctypes.c_double)))
        logging.info("Matrix initialized")
        
        result = matrix.scalarMultiply(A, 2.0)
        matrix.printMatrix(result)
    except Exception as e:
        logging.error("Error Exception: %s", e)
        return

def test_transpose_matrix():
    try:
        logging.info("____FUNC5: test_transpose_matrix()")
        A = matrix.createMatrix(3, 3)
        logging.info("Matrix created")
        
        values = np.array([1.0, 2.0, 4.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0], dtype=ctypes.c_double)
        matrix.initMatrix(A, values.ctypes.data_as(ctypes.POINTER(ctypes.c_double)))
        logging.info("Matrix initialized")
        
        result = matrix.transposeMatrix(A)
        matrix.printMatrix(result)
        
    except Exception as e:
        logging.error("Error Exception: %s", e)
        return
    
    
if __name__ == "__main__":
    test_populate_matrix()
    test_add_matrix()
    test_subtract_matrix()
    test_scalar_multiplication()
    test_transpose_matrix()
    