/*************************************************************************
 * AUTHOR	  : Omid Mogasemi
 * STUDENT ID : 1093893
 * LAB #4a	  : IF ONLY
 * CLASS      : CS1A
 * SECTION	  : MTWTh: 10:00a - 1:35p";
 * DUE DATE   : 7/5/2018
 *************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstdlib>
using namespace std;

/********************************************************************
 *
 * IF ONLY
 * __________________________________________________________________
 * This program will read three triangle side lengths from a file
 * named sideData.txt located in the E drive and determine whether
 * or not these three sides represent those of a valid triangle. If
 * they do not, it will output an error message to the screen. If the
 * sides do represent those of a valid triangle, then the program will
 * output their lengths alongside the perimeter and area of the
 * triangle to both the screen and a file named results.txt located
 * in the E drive.
 *
 * __________________________________________________________________
 * INPUT:
 * 	a: First triangle side to be input -> input from sideData.txt
 * 	b: Second triangle side to be input -> input from sideData.txt
 * 	c: Third triangle side to be input -> input from sideData.txt
 *
 * OUTPUT:
 * 	area: The area of the triangle -> output to results.txt
 * 	perimeter: The perimeter of the triangle -> output to results.txt
 *******************************************************************/
int main()
{
	//Declare filestream variables
	ifstream inFile;
	ofstream outFile;

	//Associate the file stream variables with the input source
	inFile.open("E:\\sideData.txt");
	if (!inFile )
	{
		cout << "Problem opening input file E:\\sideData.txt";
		return 1;
	}

	//Declare constants for header output
	const char PROGRAMMER[] = "Omid Mogasemi";         //OUTPUT - author name
	const char CLASS[]       = "CS1A";                 //OUTPUT - class name
	const char SECTION[]    = "MTWTh: 10:00a - 1:35p"; //OUTPUT - class section
	const char LAB_NUM[]         = "4a";               //OUTPUT - lab number
	const char LAB_NAME[]   = "IF ONLY";               //OUTPUT - lab name

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

	//Assign variables a, b, and c to read from the inFile sideData.txt
	inFile >> a;
	inFile >> b;
	inFile >> c;

	//Check to see if the sides provided represent a valid triangle
	if (!((a+b > c) && (a + c > b) && (b + c > a)))
	{
		cout << "Error! Values " << a << ", " << b << ", and " << c
				<< " do not represent a triangle." << endl;
		return 1;
	}

	//Associate the file stream variables with the output source
	outFile.open("E:\\results.txt");
	if (outFile.fail() )
	{
		cout << "Problem opening output file E:\\results.txt";
		exit(1);
	}

	//Output the class heading to the outFile
	outFile << left;
	outFile << "***************************************";
	outFile << "\n* PROGRAMMED BY : " << PROGRAMMER;
	outFile << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	outFile << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	outFile << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	outFile << "\n***************************************\n\n";
	outFile << right;

	//Make all outputs read with a decimal point and two zeroes to the right
	cout << fixed << setprecision(2);
	outFile << fixed << setprecision(2);

	//OUTPUT - three sides of the triangle as per the file input to the screen
	cout << "The triangle has sides of length " << a << ", " << b
			<< " and " << c << "." << endl;
	//OUTPUT - three sides of the triangle as per the file input to the file
	outFile << "The triangle has sides of length " << a << ", " << b
			<< " and " << c << "." << endl;

	//Initialize the area
	s = (0.5) * (a + b + c);
	area = sqrt(s * (s - a)* (s - b)* (s - c));

	//Initialize the perimeter
	perimeter = (a + b + c);

	//OUTPUT - Area of the triangle
	cout << left << setw(35) << "The area of this triangle is:" << right
		 << setw(6) << area << endl;
	//OUTPUT - Output area of the triangle to the file
	outFile << left << setw(35) << "The area of this triangle is:" << right
			<< setw(6) << area << endl;

	//OUTPUT - Perimeter of the triangle
	cout << left << setw(35) << "The perimeter of this triangle is:" << right
		 << setw(6) << perimeter << endl;
	//OUTPUT - Output perimeter of the triangle to the file
	outFile << left << setw(35) << "The perimeter of this triangle is:" << right
			<< setw(6) << perimeter << endl;

	//Close the files
	inFile.close();
	outFile.close();

	return 1;
}
