#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <string>
using namespace std;

//Declare variables
const int MAX_ROWS = 5;                  // CALC - Max number of rows in
                                         //        the array
const int MAX_COLS = 5;                  // CALC - Max number of columns in
                                         //        the array
typedef int Matrix[MAX_ROWS][MAX_COLS];  // CALC - Create alias Matrix


/****************************************************************
* displayMatrix
*   This function will display the chosen matrix with its
*   name in a formatted style - returns nothing.
***************************************************************/
void displayMatrix(const string name, // OUT - Matrix name
        		   const int rows,    // CALC - Number of rows in matrix
				   const int cols,    // CALC - Number of columns in matrix
				   const Matrix m);   // OUT - Matrix itself
/****************************************************************
* addMatrices
*   This function will add two matrices and output their
*   results using the displayMatrix function. Before adding
*   the two matrices, it will ensure that the matrices can be
*   legally added - returns nothing.
***************************************************************/
void addMatrices(const string m1name, // CALC - First matrix name
				 const int m1rows,    // CALC - Number of rows in first matrix
				 const int m1cols,    // CALC - Number of columns in first
									  //        matrix
				 const Matrix m1,     // CALC - Contents of first matrix
				 const string m2name, // CALC - Second matrix name
				 const int m2rows,    // CALC - Number of rows in second matrix
				 const int m2cols,    // CALC - Number of columns in second
									  //        matrix
				 const Matrix m2);    // CALC - Contents of second matrix
/****************************************************************
* subMatrices
*   This function will subtract two matrices and output their
*   results using the displayMatrix function. Before subtracting
*   the two matrices, it will ensure that the matrices can be
*   legally subtracted - returns nothing.
***************************************************************/
void subMatrices(const string m1name, // CALC - First matrix name
				 const int m1rows,    // CALC - Number of rows in first matrix
				 const int m1cols,    // CALC - Number of columns in first
									  //        matrix
				 const Matrix m1,     // CALC - Contents of first matrix
				 const string m2name, // CALC - Second matrix name
				 const int m2rows,    // CALC - Number of rows in second matrix
				 const int m2cols,    // CALC - Number of columns in second
									  //        matrix
				 const Matrix m2);    // CALC - Contents of second matrix
/****************************************************************
* multMatrices
*   This function will multiply two matrices and output their
*   results using the displayMatrix function. Before adding
*   the two matrices, it will ensure that the matrices can be
*   legally multiplied - returns nothing.
***************************************************************/
void multMatrices(const string m1name, // CALC - First matrix name
				  const int m1rows,    // CALC - Number of rows in first matrix
				  const int m1cols,    // CALC - Number of columns in first
									   //        matrix
				  const Matrix m1,     // CALC - Contents of first matrix
				  const string m2name, // CALC - Second matrix name
				  const int m2rows,    // CALC - Number of rows in second matrix
				  const int m2cols,    // CALC - Number of columns in second
									   //        matrix
				  const Matrix m2);    // CALC - Contents of second matrix

#endif /* FUNCTIONS_H_ */
