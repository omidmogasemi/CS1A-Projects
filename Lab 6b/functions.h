#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <string>

/****************************************************************
* menu
*  This function prompts the user to enter their desired
*  shape choice, alongside its dimension and what
*  character they would like to use to build the shape.
*  - returns nothing -> This will output the choice menu.
***************************************************************/
void menu(int& choice,     // IN - The user's shape choice
		  int& dimension,  // IN - The user's desired dimension
		  char& character, // IN - The user's desired character
		  bool& flag);     // CALC - Check if the input is valid

/****************************************************************
* drawSquare
*  This function will draw a square with the user's desired
*  character with a dimension as specified previously by
*  the user.
*  - returns nothing -> This will output the square.
***************************************************************/
void drawSquare (int dimension,   // CALC - The dimension of the square
                 char character); // CALC & OUT - The character used to make
                                  //              the square


/****************************************************************
* drawTriangle
*  This function will draw a triangle with the user's desired
*  character with a dimension as specified previously by
*  the user.
*  - returns nothing -> This will output the triangle.
***************************************************************/
void drawTriangle(int dimension,   // CALC - The dimension of the triangle
                  char character); // CALC & OUT - The character used to make
                                   //              the triangle

/****************************************************************
* drawPyramid
*  This function will draw a pyramid with the user's desired
*  character with a dimension as specified previously by
*  the user.
*  - returns nothing -> This will output the pyramid.
***************************************************************/
void drawPyramid(int dimension,   // CALC - The dimension of the pyramid
                 char character); // CALC & OUT - The character used to make
                                  //              the pyramid

/****************************************************************
* drawDimaryp
*  This function will draw an upside-down pyramid with the
*  user's desired character with a dimension as specified
*  previously by the user.
*  - returns nothing -> This will output the upside-down pyramid.
***************************************************************/
void drawDimaryp(int dimension,   // CALC - The dimension of the upside
		                          //        down pyramid
                 char character); // CALC & OUT - The character used to make
                                  //              the upside-down pyramid


#endif /* FUNCTIONS_H_ */
