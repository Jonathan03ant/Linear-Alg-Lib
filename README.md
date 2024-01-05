# Linear Algebra Library
#### Note: The library is still under development. Future updates will include more advanced Linear Algebra operations.
#### It's important to note that the library has not been compiled into a static library file at this stage. However, you can still explore and contribute to the development of this library by checking out the source code.


## Current Features
### Matrices Branch
* Matrix creation and initialization: You can create a matrix with specified rows and columns using the ```createMatrix``` function in EntityMatrix.c, and initialize it with specific values using the ```initMatrix``` function.

* Basic matrix operations: The library currently supports addition, subtraction, transpose and scalar multiplication of matrices. These operations are implemented in the ```BasicOperations.c``` file, with functions like ```addMatrices```, ```subtractMatrix```, and ```scalarMultiply```.

* Memory management: The library provides a freeMatrix function in ```EntityMatrix.c``` to deallocate memory used by matrices when they are no longer needed.

### Vector Branch
* Vector creation and initialization: You can create a vector with specified dimensions using the ```createVector``` function in ```EntityVector.c```, and initialize it with specific values using the ```initVector``` function.

* Basic vector operations: The library currently supports addition, subtraction, and scalar multiplication of vectors. These operations are implemented in the ```VectorOperations.c``` file, with functions like ```addVectors```, ```subtractVectors```, and ```scalarMultiplyVector```.

* You can find the unit vector of a given vector using the ``findUnitVector``` function, and find the dot product of two vectors using the ```dotProduct``` function.

## Future Work
The library is still under development. Future updates will include more advanced linear algebra operations including Eigen values, Eigen vectors, and Orthogonality property.

## Usage
Please refer to the source code for more details on how to use each function.

## Contribution
I welcome contributions to this project. As I am in the early stages of development, there are many opportunities to contribute. I am particularly interested in contributions that help me implement more complex linear algebra operations.

This project follows the facade design pattern. This means that I aim to provide a simple interface to complex systems. As I implement more complex operations, I will continue to maintain a simple and intuitive interface for users. This will involve abstracting the complexity of these operations behind simple function calls.

If you're interested in contributing, please start by checking out the current code. Get a feel for the project structure and the current state of development. Then, check out the issues page to see what I'm currently working on. If you see an issue you'd like to work on, feel free to assign it to yourself and start coding.

When you're ready to submit your code, create a pull request. Please provide a detailed description of your changes. This will help me understand what you've done and why. I'll review your code as soon as I can.

#### This README will be updated continously 


