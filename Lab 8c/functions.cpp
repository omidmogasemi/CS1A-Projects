#include <iostream>
#include <iomanip>
#include <string>
#include "functions.h"
using namespace std;

/***********************************************************
*
* FUNCTION displayMatrix
*__________________________________________________________
* This function will display the chosen matrix with its
* name in a formatted style - returns nothing.
*__________________________________________________________
* PRE-CONDITIONS
* name: String type has to be previously defined
* rows: Number of rows in matrix has to be previously defined
* cols: Number of columns in matrix has to be previously defined
* m: Matrix type has to be previously defined
*
* POST-CONDITIONS
* This function will return nothing.
************************************************************/
void displayMatrix(const string name, // OUT - Matrix name
		           const int rows,    // CALC - Number of rows in matrix
				   const int cols,    // CALC - Number of columns in matrix
				   const Matrix m)    // OUT - Matrix itself
{
	//Declare variables
	int rowIndex;     // CALC - What row is being output
	int columnIndex;  // CALC - What column is being output

	//OUTPUT - Matrix/case name
	cout << name << ":\n";

	//PROCESSING - Output the matrix according to how many rows and columns
	//             it has
	for (rowIndex = 0; rowIndex < rows; rowIndex++)
	{
		for (columnIndex = 0; columnIndex < cols; columnIndex++)
		{
			cout << right << setw(3) << m[rowIndex][columnIndex] << " ";
		}
		cout << "\n";
	}
}

/***********************************************************
*
* FUNCTION addMatrices
*__________________________________________________________
* This function will add two matrices and output their
* results using the displayMatrix function. Before adding
* the two matrices, it will ensure that the matrices can be
* legally added - returns nothing.
*__________________________________________________________
* PRE-CONDITIONS
* m1name: First matrix name must be previously defined
* m1rows: Number of rows in first matrix must be previously
*         defined
* m1cols: Number of columns in second matrix must be
*         previously defined
* m1: The first matrix must be previously defined
* m2name: Second matrix name must be previously defined
* m2rows: Number of rows in second matrix must be previously
*         defined
* m2cols: Number of columns in second matrix must be
*         previously defined
* m2: The second matrix must be previously defined
*
*
* POST-CONDITIONS
* This function will return nothing.
************************************************************/
void addMatrices(const string m1name, // CALC - First matrix name
				 const int m1rows,    // CALC - Number of rows in first matrix
				 const int m1cols,    // CALC - Number of columns in first
				                      //        matrix
				 const Matrix m1,     // CALC - Contents of first matrix
				 const string m2name, // CALC - Second matrix name
				 const int m2rows,    // CALC - Number of rows in second matrix
				 const int m2cols,    // CALC - Number of columns in second
				                      //        matrix
				 const Matrix m2)     // CALC - Contents of second matrix
{
	//Declare variables
	Matrix addMatrix = {0};     // CALC - New matrix formed from the addition
	                            //        of the two existing matrices
	string addition = "Sum is"; // OUT - Indicates what operation is occurring

	//PROCESSING - Check if this operation is legal on these matrices
	if (m1rows != m2rows && m1cols != m2cols)
	{
		cout << "\nThis operation is not possible for these matrices!\n";
		return;
	}

	// PROCESSING - Create a new array that will be the result of the two
	//              existing matrices added together
	for (int i = 0; i < m1rows; i++)
	{
		for (int j = 0; j < m1cols; j++)
		{
			addMatrix[i][j] = m1[i][j] + m2[i][j];
		}
	}

	//OUTPUT - Output the results to the user
	displayMatrix(addition, m1rows, m1cols, addMatrix);
}

/***********************************************************
*
* FUNCTION subMatrices
*__________________________________________________________
* This function will subtract two matrices and output their
* results using the displayMatrix function. Before subtracting
* the two matrices, it will ensure that the matrices can be
* legally subtracted - returns nothing.
*__________________________________________________________
* PRE-CONDITIONS
* m1name: First matrix name must be previously defined
* m1rows: Number of rows in first matrix must be previously
*         defined
* m1cols: Number of columns in second matrix must be
*         previously defined
* m1: The first matrix must be previously defined
* m2name: Second matrix name must be previously defined
* m2rows: Number of rows in second matrix must be previously
*         defined
* m2cols: Number of columns in second matrix must be
*         previously defined
* m2: The second matrix must be previously defined
*
*
* POST-CONDITIONS
* This function will return nothing.
************************************************************/
void subMatrices(const string m1name, // CALC - First matrix name
		 	 	 const int m1rows,    // CALC - Number of rows in first matrix
				 const int m1cols,    // CALC - Number of columns in first
									  //        matrix
				 const Matrix m1,     // CALC - Contents of first matrix
				 const string m2name, // CALC - Second matrix name
				 const int m2rows,    // CALC - Number of rows in second matrix
				 const int m2cols,    // CALC - Number of columns in second
									  //        matrix
				 const Matrix m2)     // CALC - Contents of second matrix
{
	//Declare variables
	Matrix subMatrix = {0};               // CALC - New matrix formed from the
	                                      //        subtraction of the two
	                                      //        existing matrices
	string subtraction = "Difference is"; // OUT - Indicates what operation
	                                      //       is occurring

	//PROCESSING - Check if this operation is legal on these matrices
	if (m1rows != m2rows && m1cols != m2cols)
	{
		cout << "\nThis operation is not possible for these matrices!\n";
		return;
	}

	//PROCESSING - Create a new array that will be the result of the two
	//              existing matrices subtracted
	for (int i = 0; i < m1rows; i++)
	{
		for (int j = 0; j < m1cols; j++)
		{
			subMatrix[i][j] = m1[i][j] - m2[i][j];
		}
	}

	//OUTPUT - Output the results to the user
	displayMatrix(subtraction, m1rows, m1cols, subMatrix);
}

/***********************************************************
*
* FUNCTION multMatrices
*__________________________________________________________
* This function will multiply two matrices and output their
* results using the displayMatrix function. Before adding
* the two matrices, it will ensure that the matrices can be
* legally multiplied - returns nothing.
*__________________________________________________________
* PRE-CONDITIONS
* m1name: First matrix name must be previously defined
* m1rows: Number of rows in first matrix must be previously
*         defined
* m1cols: Number of columns in second matrix must be
*         previously defined
* m1: The first matrix must be previously defined
* m2name: Second matrix name must be previously defined
* m2rows: Number of rows in second matrix must be previously
*         defined
* m2cols: Number of columns in second matrix must be
*         previously defined
* m2: The second matrix must be previously defined
*
*
* POST-CONDITIONS
* This function will return nothing.
************************************************************/
void multMatrices(const string m1name, // CALC - First matrix name
				  const int m1rows,    // CALC - Number of rows in first matrix
				  const int m1cols,    // CALC - Number of columns in first
									   //        matrix
				  const Matrix m1,     // CALC - Contents of first matrix
				  const string m2name, // CALC - Second matrix name
				  const int m2rows,    // CALC - Number of rows in second matrix
				  const int m2cols,    // CALC - Number of columns in second
									   //        matrix
				  const Matrix m2)     // CALC - Contents of second matrix
{
	//Declare variables
	Matrix multiplicationAr = {0};        // CALC - New matrix formed from the
	                                      //        multiplication of the
	                                      //        two existing matrices
	string multiplication = "Product is"; // OUT - Indicates what operation
	                                      // is occurring

	//PROCESSING - Check if this operation is legal on these matrices
	if (m1cols != m2rows && m2cols != m1rows)
	{
		cout << "\nThis operation is not possible for these matrices!\n";
		return;
	}

	//PROCESSING - Create a new array that will be the result of the two
	//              existing matrices multiplied
	for (int i = 0; i < m1rows; i++)
	{
		for (int j = 0; j < m2cols; j++)
		{
			multiplicationAr[i][j] = 0;
			for (int k = 0; k < m2rows; k++)
			{
				multiplicationAr[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}

	//OUTPUT - Output the results to the user
	displayMatrix(multiplication, m1rows, m2cols, multiplicationAr);
}
