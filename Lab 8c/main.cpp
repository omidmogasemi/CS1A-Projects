/*************************************************************************
 * AUTHOR	  : Omid Mogasemi
 * STUDENT ID : 1093893
 * LAB #8c	  : MATH ANYONE matrix
 * CLASS      : CS1A
 * SECTION	  : MTWTh: 10:00a - 1:35p";
 * DUE DATE   : 8/6/2018
 *************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "printHeader.h"
#include "functions.h"
using namespace std;

/********************************************************************
 *
 * MATH ANYONE matrix
 * __________________________________________________________________
 * This program reads two integer matrices from the input file
 * named matrices.txt and uses it to populate array variables. It
 * then uses these array variables alongside functions to compute
 * and then display the addition, subtraction, and multiplication of
 * their respective matrices.
 * __________________________________________________________________
 * INPUT:
 * matrix1 - The first matrix -> input from matrices.txt
 * matrix2 - The second matrix -> input from matrices.txt
 * matrix1name - Name of the first matrix -> input from matrices.txt
 * matrix2name - Name of the second matrix -> input from matrices.txt
 * m1desiredRows - Desired number of rows for the first matrix ->
 *                 input from matrices.txt
 * m1desiredColumns - Desired number of columns for the first matrix
 *                    -> input from matrices.txt
 * m2desiredRows - Desired number of rows for the second matrix ->
 *                 input from matrices.txt
 * m2desiredColumns - Desired number of columns for the second matrix
 *                    -> input from matrices.txt
 * selection - User's menu choice
 *
 * OUTPUT:
 * N/A
 *
 *******************************************************************/

int main()
{
	//Declare variables
	Matrix matrix1;       // IN - The first matrix
	Matrix matrix2;       // IN - The second matrix
	string matrix1name;   // IN - Name of the first matrix
	string matrix2name;   // IN - Name of the first matrix
	int m1desiredRows;    // IN - Desired number of rows for the first matrix
	int m1desiredColumns; // IN - Desired number of columns for the first
	                      //      matrix
	int m2desiredRows;    // IN - Desired number of rows for the second matrix
	int m2desiredColumns; // IN - Desired number of columns for the second
	                      //      matrix
	int m1rows;           // CALC - Index for the rows in the first matrix
	int m1columns;        // CALC - Index for the columns in the first matrix
	int m2rows;           // CALC - Index for the rows in the second matrix
	int m2columns;        // CALC - Index for the columns in the second matrix
	bool check = true;    // CALC - Loop control variable
	int selection;        // IN - User's menu choice

	printHeader("MATH ANYONE matrix", "8c");

	//Declare file stream variable and open the input file
	ifstream inFile;
	inFile.open("E:\\matrices.txt");
		if (!inFile)
		{
			cout << "Problem opening input file E:\\matrices.txt";
			return 1;
		}

	//PROCESISNG - Read the name, dimensions, and values for the first matrix
	inFile >> matrix1name >> m1desiredRows >> m1desiredColumns;
	for (m1rows = 0; m1rows < m1desiredRows; m1rows++)
	{
		for (m1columns = 0; m1columns < m1desiredColumns; m1columns++)
		{
			inFile >> matrix1[m1rows][m1columns];
		}
	}

	//PROCESISNG - Read the name, dimensions, and values for the second matrix
	inFile >> matrix2name >> m2desiredRows >> m2desiredColumns;
	for (m2rows = 0; m2rows < m1desiredRows; m2rows++)
	{
		for (m2columns = 0; m2columns < m2desiredColumns; m2columns++)
		{
			inFile >> matrix2[m2rows][m2columns];
		}
	}

	//PROCESSING - Run the menu until the user changes the LCV to false
	while (check)
	{
		//OUTPUT - Menu statement
		cout << "\nChoose an operation:\n"
			 << "1. Addition\n"
			 << "2. Subtraction\n"
			 << "3. Multiplication\n"
			 << "4. Display Matrices\n"
			 << "5. Exit\n"
			 << "Selection:";

		//INPUT - User menu choice
		cin >> selection;
		cout << "\n";

		//PROCESSING - Check if the user gives bad input for the choice
		if (!cin >> selection)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Please enter an integer value!\n\n";
				continue;
			}

		//PROCESSING - Check if the user gave bad input for their shape choice
		if (selection < 1 || selection > 5)
		{
			cout << "Please enter a number between 1 and 5!\n\n";
			continue;
		}

		//PROCESSING - Decide what operation should occur based on the
		//             user's input
		switch (selection)
		{
		//PROCESSING - Addition case
		case 1:
			addMatrices(matrix1name, m1desiredRows, m1desiredColumns,
					    matrix1,
					    matrix2name, m2desiredRows, m2desiredColumns,
						matrix2);
			break;
		//PROCESSING - Subtraction case
		case 2:
			subMatrices(matrix1name, m1desiredRows, m1desiredColumns,
					    matrix1,
				        matrix2name, m2desiredRows, m2desiredColumns,
						matrix2);
			break;
		//PROCESSING - Multiplication case
		case 3:
			multMatrices(matrix1name, m1desiredRows, m1desiredColumns,
						 matrix1,
				         matrix2name, m2desiredRows, m2desiredColumns,
						 matrix2);
		    break;
		//PROCESSING - Display case
		case 4:
			displayMatrix(matrix1name, m1desiredRows, m1desiredColumns,
					      matrix1);
			displayMatrix(matrix2name, m2desiredRows, m2desiredColumns,
					      matrix2);
			break;
		//PROCESSING - Exit case
		case 5:
			check = false;
			break;
		}
	}

	inFile.close();
	return 0;
}
