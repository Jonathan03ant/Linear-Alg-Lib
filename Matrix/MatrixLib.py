import ctypes

# Load the shared object file
matrix = ctypes.CDLL('/Users/jonathan/Library/Mobile Documents/com~apple~CloudDocs/iUTG/Projects/DevOps/Linear-Alg-Lib/Matrix/_Matrix.so')

# Define the Matrix struct
class Matrix(ctypes.Structure):
    _fields_ = [("numRow", ctypes.c_int),
                ("numCol", ctypes.c_int),
                ("data", ctypes.POINTER(ctypes.POINTER(ctypes.c_double)))]

# Define argument and return types for the functions
matrix.createMatrix.argtypes = [ctypes.c_int, ctypes.c_int]
matrix.createMatrix.restype = ctypes.POINTER(Matrix)

matrix.initMatrix.argtypes = [ctypes.POINTER(Matrix), ctypes.POINTER(ctypes.c_double)]
matrix.initMatrix.restype = None

matrix.printMatrix.argtypes = [ctypes.POINTER(Matrix)]
matrix.printMatrix.restype = None


