%module matrix_module
%{
	#include "Matrix_i.h"
	#include "BasicOperations.h"
}

%include "BasicOperations.h"
%include "Matrix_i.h"
