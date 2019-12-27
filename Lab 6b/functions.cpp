#include <iostream>
#include <iomanip>
#include <string>
#include "functions.h"
using namespace std;

/***********************************************************
*
* FUNCTION menu
*__________________________________________________________
* This function prompts the user to enter their desired
* shape choice, alongside its dimension and what
* character they would like to use to build the shape -
* returns nothing.
*__________________________________________________________
* PRE-CONDITIONS
* choice: User's choice to be previously declared
* dimension: User's desired dimensions to be previously defined
* character: User's desired character to be previously defined
* flag: The successful input indicator to be previously defined
*
* POST-CONDITIONS
* This function will output prompts for the three desired
* inputs.
* choice: Will contain user's choice
* dimension: Will contain user's dimension
* character: Will contain user's character
* flag: Will tell if the user input is valid or not
************************************************************/
void menu(int& choice,     // IN - The user's shape choice
		  int& dimension,  // IN - The user's desired dimension
		  char& character, // IN - The user's desired character
		  bool& flag)      // CALC - Check if the input is valid
{
	//OUTPUT - Prompt the user
	cout << "Enter your choice of shape:\n"
			"1. square\n"
			"2. right triangle\n"
			"3. pyramid\n"
			"4. upside-down pyramid\n"
			"5. exit the program\n";

	cout << "choice: ";
	cin >> choice;

	//PROCESSING - Check if the user gives bad input for the choice
	if (!cin >> choice)
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\nInvalid selection!\n\n";
		flag = false;
		return;
	}

	//PROCESSING - Check if the user input meets the exit condition
	if (choice == 5)
	{
		flag = false;
		return;
	}

	//PROCESSING - Check if the user gave bad input for their shape choice
	if (choice < 1 || choice > 5)
	{
		cout << "\nInvalid selection!\n\n";
		flag = false;
		return;
	}

	//OUTPUT & INPUT - Prompt the user for their desired dimension and read it
	cout << "dimension (2-20): ";
	cin >> dimension;

	//PROCESSING - Check if the user's provided dimension is wrong
	if (!(dimension > 1 && dimension < 21))
	{
		cout << "\nInvalid dimension!\n\n";
		flag = false;
		return;
	}

	//OUTPUT & INPUT - Prompt the user for their desired character and read it
	cout << "character: ";
	cin >> character;
	cout << "\n";
}


/***********************************************************
*
* FUNCTION drawSquare
*__________________________________________________________
* This function will draw a square with the user's desired
* character with a dimension as specified previously by
* the use - returns nothing.
*__________________________________________________________
* PRE-CONDITIONS
* dimension: User's desired dimension has to be previously defined.
* character: User's desired character has to be previously defined.
*
* POST-CONDITIONS
* This function will output a square.
************************************************************/
void drawSquare(int dimension,   // CALC - The dimension of the square
		        char character)  // CALC & OUT - The character used to make
                                 //              the square
{
	//PROCESSING & OUTPUT - Print out as many characters according to the
	//                      provided dimension in a square
	for (int i=0; i < dimension; i++)
	{
		for (int j=0; j < dimension; j++)
		{
			cout << character << " ";
		}
		cout << "\n";
	}

}

/***********************************************************
*
* FUNCTION drawTriangle
*__________________________________________________________
* This function will draw a triangle with the user's desired
* character with a dimension as specified previously by
* the user - returns nothing.
*__________________________________________________________
* PRE-CONDITIONS
* dimension: User's desired dimension has to be previously defined.
* character: User's desired character has to be previously defined.
*
* POST-CONDITIONS
* This function will output a triangle.
************************************************************/
void drawTriangle(int dimension,   // CALC - The dimension of the triangle
                  char character)  // CALC & OUT - The character used to make
                                   //              the triangle

{
	//PROCESSING & OUTPUT - Print out as many characters according to the
	//                      provided dimension in a triangle
	for (int i=0; i < dimension; i++)
	{
		for (int j=0; j <= i; j++)
		{
			cout << character << " ";
		}
		cout << "\n";
	}
}

/***********************************************************
*
* FUNCTION drawPyramid
*__________________________________________________________
* This function will draw a pyramid with the user's desired
* character with a dimension as specified previously by
* the user - returns nothing.
*__________________________________________________________
* PRE-CONDITIONS
* dimension: User's desired dimension has to be previously defined.
* character: User's desired character has to be previously defined.
*
* POST-CONDITIONS
* This function will output a pyramid.
************************************************************/
void drawPyramid(int dimension,   // CALC - The dimension of the pyramid
                 char character)  // CALC & OUT - The character used to make
                                  //              the pyramid

{
	//PROCESSING & OUTPUT - Print out as many characters according to the
	//                      provided dimension in a pyramid
	for (int i = 1; i <= dimension; i++)
	{
		for (int j = 1; j <= dimension-i; j++)
		{
			cout << " ";
		}
		for (int k = 1; k <= i; k++)
		{
			cout << character << " ";
		}
		cout << "\n";
	}
}

/***********************************************************
*
* FUNCTION drawDimaryp
*__________________________________________________________
* This function will draw an upside-down pyramid with the
* user's desired character with a dimension as specified
* previously by the user - returns nothing.
*__________________________________________________________
* PRE-CONDITIONS
* dimension: User's desired dimension has to be previously defined.
* character: User's desired character has to be previously defined.
*
* POST-CONDITIONS
* This function will output an upside-down triangle.
************************************************************/
void drawDimaryp(int dimension,    // CALC - The dimension of the upside
		                           //        down pyramid
                 char character)   // CALC & OUT - The character used to make
                                   //              the upside-down pyramid

{
	string spaceCounter = " ";   //CALC & OUT - Counts how many spaces are
	                             //             present and need to be output

	//PROCESSING & OUTPUT - Print out as many characters according to the
	//                      provided dimension in an upside-down pyramid
	for (int i=0; i < dimension; i++)
	{
		for (int j = dimension; j > i; j--)
		{
			cout << character << " ";
		}
		cout << "\n" << spaceCounter;
		spaceCounter += " ";
	}
}




