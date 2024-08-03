
import ctypes
from log import setup_logger



    # Load the static library or .so Matrix file
    # Define the matrix struct in a class
    # Define the fields of the matrix struct in accordancee with ctype values

Matrix = ctypes.CDLL('/Users/jonathan/Library/Mobile Documents/com~apple~CloudDocs/iUTG/Projects/DevOps/Linear-Alg-Lib/Matrix/_Matrix.so')

class Matrix((ctypes.Structure)):
    _fields_ = [("numRow", ctypes.c_int),
                ("numCol", ctypes.c_int),
                ("data", ctypes.POINTER(ctypes.POINTER(ctypes.c_double)))]
    
    # Define the arg and return types for Matrix functions
    # Functions are from the .so file we imported
    # Appropriate definition for arg and ret is necessary
    
    
#Create a Matrix (Allocate a memory)
Matrix.createMatrix.argtypes = [ctypes.c_int, ctypes.c_int]
Matrix.createMatrix.resTypes = ctypes.POINTER(Matrix)

# Initialize the Matrix with double values
# For Matrix AxB, double values = no of rows * no of cols
Matrix.initMatrix.argtypes = [ctypes.POINTER(Matrix), ctypes.POINTER(ctypes.c_double)]
Matrix.initMatrix.resTypes = None

# Print the Matrix
Matrix.printMatrix.argtypes = [ctypes.POINTER(Matrix)]
Matrix.printMatrix.resTypes = None
