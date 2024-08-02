import ctypes
import logging
import numpy as np

logging.basicConfig(level=logging.INFO,
                    format="%(levelname)s == %(message)s ==  %(funcName)s == %(lineno)d",
                    handlers=[
                        logging.FileHandler("Matrix.log"),
                        logging.StreamHandler()
                    ])

# Load the shared object file
matrix_lib = ctypes.CDLL('/Users/jonathan/Library/Mobile Documents/com~apple~CloudDocs/iUTG/Projects/DevOps/Linear-Alg-Lib/Matrix/_Matrix.so')

# Define the Matrix struct
class Matrix(ctypes.Structure):
    _fields_ = [("numRow", ctypes.c_int),
                ("numCol", ctypes.c_int),
                ("data", ctypes.POINTER(ctypes.POINTER(ctypes.c_double)))]

# Define argument and return types for the functions
matrix_lib.createMatrix.argtypes = [ctypes.c_int, ctypes.c_int]
matrix_lib.createMatrix.restype = ctypes.POINTER(Matrix)

matrix_lib.initMatrix.argtypes = [ctypes.POINTER(Matrix), ctypes.POINTER(ctypes.c_double)]
matrix_lib.initMatrix.restype = None

matrix_lib.printMatrix.argtypes = [ctypes.POINTER(Matrix)]
matrix_lib.printMatrix.restype = None

# Create a matrix
rows, cols = 2, 2
A = matrix_lib.createMatrix(rows, cols)
logging.info(f"Matrix A: {A.contents} Created")

# Initialize the matrix with values
c_values = np.array([-2.0, 1.0, 1.0, 1.0], dtype=ctypes.c_double)
matrix_lib.initMatrix(A, c_values.ctypes.data_as(ctypes.POINTER(ctypes.c_double)))
logging.info(f"Matrix A: {A.contents} Initialized")

# Print the matrix
print("Printing Matrix\n")
matrix_lib.printMatrix(A)
