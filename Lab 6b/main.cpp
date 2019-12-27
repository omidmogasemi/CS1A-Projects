/*************************************************************************
 * AUTHOR	  : Omid Mogasemi
 * STUDENT ID : 1093893
 * LAB #6a	  : STAY IN SHAPE
 * CLASS      : CS1A
 * SECTION	  : MTWTh: 10:00a - 1:35p";
 * DUE DATE   : 7/27/2018
 *************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include "printHeader.h"
#include "functions.h"
using namespace std;

/********************************************************************
 *
 * STAY IN SHAPE
 * __________________________________________________________________
 * This program prompts the user to choose a shape, its dimensions,
 * and what character it will be draw with, utilizing functions
 * to read the user input and output their result. It will keep
 * prompting the user to choose a shape, its dimensions, and a
 * character to use until the user meets the exit condition.
 * __________________________________________________________________
 * INPUT:
 * N/A
 * OUTPUT:
 * N/A
 *******************************************************************/

int main()
{
	printHeader("STAY IN SHAPE", "6b");

	//PROCESSING - Declare variables
	int choice;       //CALC - The user's list choice
	int dimension;    //CALC - The dimension of the shape
	char character;   //CALC - The character used for making the shape
	bool flag = true; //CALC - Check if the user input is valid

	//PROCESSING - Continue to run as long as the user input is valid
	while (flag)
	{
		menu(choice, dimension, character, flag);

		//PROCESSING - Check if the flag is true (i.e. if inputs are correct)
		//             and that the user does not want to terminate the
		//             program
		if (!flag && choice != 5)
		{
			flag = true;
			continue;
		}

		//PROCESSING - Check which function to execute per the user's choice
		switch (choice)
		{
		case 1:
			drawSquare(dimension, character);
			break;
		case 2:
			drawTriangle(dimension, character);
			break;
		case 3:
			drawPyramid(dimension, character);
			break;
		case 4:
			drawDimaryp(dimension, character);
			break;
		case 5:
			flag = false;
			break;
		default:
			cout << "\nInvalid selection!\n";
		}

		cout << "\n";
	}
	return 0;
}
