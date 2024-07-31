import sys
sys.path.append('/Users/jonathan/Library/Mobile Documents/com~apple~CloudDocs/iUTG/Projects/DevOps/Linear-Alg-Lib/Matrix/Matrix.so')
import Matrix

# Create two 2x2 identity matrices
identity_matrix1 = Matrix.createMatrix(2, 2)
Matrix.initMatrix(identity_matrix1, [1, 0, 0, 1])

identity_matrix2 = Matrix.createMatrix(2, 2)
Matrix.initMatrix(identity_matrix2, [1, 0, 0, 1])

# Add the two matrices
sum_matrix = Matrix.addMatrices(2, [identity_matrix1, identity_matrix2])

# Print the result
print("Sum of matrices:")
print(Matrix.printMatrix(sum_matrix))
