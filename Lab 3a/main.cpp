/*************************************************************************
 * AUTHOR	  : Omid Mogasemi
 * STUDENT ID : 1093893
 * LAB #3a	  : EIE IO
 * CLASS      : CS1A
 * SECTION	  : MTWTh: 10:00a - 1:35p";
 * DUE DATE   : 6/29/2018
 *************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/********************************************************************
 *
 * EIE IO
 * __________________________________________________________________
 * This program will prompt the user for three sides of a triangle
 * and use them to output the area and perimeter of that triangle.
 *
 * __________________________________________________________________
 * INPUT:
 * 	a: First triangle side to be input -> input from user
 * 	b: Second triangle side to be input -> input from user
 * 	c: Third triangle side to be input -> input from user
 *
 * OUTPUT:
 * 	area: The area of the triangle
 * 	perimeter: The perimeter of the triangle
 *******************************************************************/
int main()
{
	//Declare constants for header output
	const char PROGRAMMER[] = "Omid Mogasemi";         //OUTPUT - author name
	const char CLASS[]       = "CS1A";                 //OUTPUT - class name
	const char SECTION[]    = "MTWTh: 10:00a - 1:35p"; //OUTPUT - class section
	const char LAB_NUM[]         = "3a";               //OUTPUT - lab number
	const char LAB_NAME[]   = "EIE IO";                //OUTPUT - lab name

	//Output the class heading to the screen
	cout << left;
	cout << "***************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n***************************************\n\n";
	cout << right;

	//Declare variables
	double a;         // INPUT - First triangle side
	double b;         // INPUT - Second triangle side
	double c;         // INPUT - Third triangle side
	double s;         // CALC - Used to compute the area of the triangle
	double area;      // CALC & OUT - Output the area of the triangle
	double perimeter; // CALC & OUT - Output the perimeter of the triangle

	//Prompt the user for the values of the three sides of the triangle
	cout << "Enter side a length: ";
	cin >> a;

	cout << "Enter side b length: ";
	cin >> b;

	cout << "Enter side c length: ";
	cin >> c;

	//Make all outputs read with a decimal point and two zeroes to the right
	cout << fixed << setprecision(2);

	//OUTPUT - three sides of the triangle as the user input
	cout << "\nThe triangle has sides of length " << a << ", " << b
			<< " and " << c << "." << endl;

	//Initialize the area
	s = (0.5) * (a + b + c);
	area = sqrt(s * (s - a)* (s - b)* (s - c));

	//Initialize the perimeter
	perimeter = (a + b + c);

	//OUTPUT - Area of the triangle
	cout << left << setw(35) << "The area of this triangle is:" << right
		 << setw(6) << area << endl;

	//OUTPUT - Perimeter of the triangle
	cout << left << setw(35) << "The perimeter of this triangle is:" << right
		 << setw(6) << perimeter << endl;



	return 0;
}
