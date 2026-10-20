#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;

class Matrix
{
private :
    int** data ;
    int row , col ;
public :

        Matrix operator+  (Matrix mat1); // Add if same dimensions
		Matrix operator-  (Matrix mat1); // Subtract if same dimensions
		Matrix operator*  (Matrix mat1); // Multiply if col1 == row2
		Matrix operator+  (int scalar);  // Adds a scalar
		Matrix operator-  (int scalar);  // Subtracts a scalar
		Matrix operator*  (int scalar);  // Multiplies by a scalar
		Matrix transpose  ();  // Return new matrix with the transpose
		bool   isSquare   ();  // True if square matrix
		bool   isIdentity ();  // True if square and identity


		Matrix operator+= (Matrix mat1); // Current matrix changes & adds mat1 to itself and return *this
		Matrix operator-= (Matrix mat1); // Current matrix changes & subtracts mat1 from itself and return *this
		Matrix operator+= (int scalar);  // Current matrix changes & adds scalar to itself and return *this
		Matrix operator-= (int scalar);  // Current matrix changes & subtracts scalar from itself and return *this
		Matrix operator++ ();   		 // Adds 1 to each element and return *this
		Matrix operator-- ();    		 // Subtracts 1 from each element and return *this
		bool   operator== (Matrix mat1); // True if mat1 is identical to current matrix
		bool   operator!= (Matrix mat1); // True if mat1 is not same as current matrix
		bool   isSymmetric ();  		 // True if current matrix is square and symmetric


		friend istream& operator>> (istream& in, Matrix& mat);
		// Input matrix like this (dim 2 x 3) cin >> 4 6 8 9 12 123
       	// and return istream to allow cascading input like cin >> matrix1 >> matrix2;
       	friend void createMatrix (int row, int col, int num[], Matrix& mat);
       	friend ostream& operator<< (ostream& out, const Matrix& mat);

};

#endif // MATRIX_H
