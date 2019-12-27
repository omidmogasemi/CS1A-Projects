/*************************************************************************
 * AUTHOR	  : Omid Mogasemi
 * STUDENT ID : 1093893
 * LAB #3c	  : EIE IO process
 * CLASS      : CS1A
 * SECTION	  : MTWTh: 10:00a - 1:35p";
 * DUE DATE   : 7/3/2018
 *************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

/********************************************************************
 *
 * EIE IO process
 * __________________________________________________________________
 * This program takes values from the input file inData.txt and uses
 * each line to calculate different outputs. The first line of
 * inData.txt will be used for calculating aspects relating to a
 * rectangle. The second line of the .txt file will be used for
 * calculating aspects relating to a circle. The third line line
 * will be used to output both a name and age. The fourth line will
 * be used for outputting the beginning balance and interest rate,
 * and then use those to calculate the balance at the end of the
 * month. It will use the fifth line to calculate and output the
 * character that comes after it in the ASCII data set.
 *
 * __________________________________________________________________
 * INPUT:
 * 	length: Length of the rectangle -> input from inData.txt
 * 	width: Width of the rectangle -> input from inData.txt
 * 	radius: Radius of the circle -> input from inData.txt
 * 	firstName: First name of the person -> input from inData.txt
 *	lastName: Last name of the person -> input from inData.txt
 *	age: Age of the person -> input from inData.txt
 *	beginningBalance: Beginning account balance -> input from inData.txt
 *	interestRate: Interest Rate -> input from inData.txt
 *	upperLetter: The uppercase letter -> input from inData.txt
 *
 * OUTPUT:
 * 	rectangleArea: Area of the rectangle -> output to outData.txt
 * 	perimeter: Perimeter of the rectangle -> output to outData.txt
 * 	circleArea: Area of the circle -> output to outData.txt
 *  circumference: Circumference of the circle -> output to outData.txt
 *  endBalance: The balance at the end of the month -> output to outData.txt
 *  next: The next letter in the ASCII sequence -> output to outData.txt
 *******************************************************************/

//Declare PI as a constant and assign it its value
const double PI = 3.1416;       //CALC - Help to find area and circumference
                                //       of a circle

int main()
{
	//Declare file stream variables
	ifstream inFile;
	ofstream outFile;

	//Associate the file stream variables with the I/O sources
	inFile.open("E:\\inData.txt");
	if (!inFile )
	{
		cout << "Problem opening input file E:\\inData.txt";
		return 1;
	}

	outFile.open("E:\\outData.txt");
	if (outFile.fail() )
	{
		cout << "Problem opening output file E:\\outData.txt";
		exit(1);
	}

	//Declare constants for header output
	const char PROGRAMMER[] = "Omid Mogasemi";         //OUTPUT - author name
	const char CLASS[]       = "CS1A";                 //OUTPUT - class name
	const char SECTION[]    = "MTWTh: 10:00a - 1:35p"; //OUTPUT - class section
	const char LAB_NUM[]         = "3c";               //OUTPUT - lab number
	const char LAB_NAME[]   = "EIE IO process";        //OUTPUT - lab name

	//Output the class heading to the screen
	cout << left;
	cout << "***************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n***************************************\n\n";
	cout << right;

	//Output the class heading to the output file
	outFile << left;
	outFile << "***************************************";
	outFile << "\n* PROGRAMMED BY : " << PROGRAMMER;
	outFile << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	outFile << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	outFile << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	outFile << "\n***************************************\n\n";
	outFile << right;

	//Declare all variables
	double length;              //INPUT - length of the rectangle
	double width;               //INPUT - width of the rectangle
	double radius;              //INPUT - Radius of the circle
	string firstName;           //INPUT - First name of the person
	string lastName;            //INPUT - Last name of the person
	int age;                    //INPUT - Age of the person
	double beginningBalance;    //INPUT - Beginning balance
	double interestRate;        //INPUT - Interest Rate
	char upperLetter;           //INPUT - Uppercase letter
	double rectangleArea;       //CALC & OUT - Area of the rectangle
	double perimeter;           //CALC & OUT - Perimeter of rectangle
	double circleArea;          //CALC & OUT - Area of the circle
	double circumference;       //CALC & OUT - Circumference of the circle
	double yearlyInterestRate;  //CALC - Find the yearly interest rate
	double monthlyInterest;     //CALC - Help to find the monthly interest rate
	double monthlyInterestRate; //CALC - Find the monthly interest rate
	double endBalance;          //CALC & OUT - The end balance
	char next;                  //CALC & OUT - Next letter in ASCII sequence

	//Assign inputs for variables to be taken from the inFile
	inFile >> length;
	inFile >> width;
	inFile >> radius;
	inFile >> firstName;
	inFile >> lastName;
	inFile >> age;
	inFile >> beginningBalance;
	inFile >> interestRate;
	inFile >> upperLetter;

	//Assign calculations for all other variables
	rectangleArea = length * width;
	perimeter = 2 * (length + width);
	circleArea = PI * (radius * radius);
	circumference = 2 * PI * radius;
	yearlyInterestRate = interestRate / 100;
	monthlyInterestRate = yearlyInterestRate / 12;
	monthlyInterest = beginningBalance * monthlyInterestRate;
	endBalance = beginningBalance + monthlyInterest;
	next = upperLetter + 1;

	//Make all outputs read with a decimal point and two zeroes to the right
	cout << fixed << setprecision(2);
	outFile << fixed << setprecision(2);

	//OUTPUT - Rectangle and all of its information
	cout << "Rectangle:" << endl;
	cout << "Length = " << length << ", width = " << width << ", area = " <<
			rectangleArea << ", perimeter = " << perimeter << endl;
	outFile << "Rectangle:" << endl;
	outFile << "Length = " << length << ", width = " << width << ", area = "
			<< rectangleArea << ", perimeter = " << perimeter << endl;

	//OUTPUT - Circle and all of its information
	cout << "Circle:" << endl;
	cout << "Radius = " << radius << ", area = " << circleArea <<
		 ", circumference = " << circumference << endl;
	outFile << "Circle:" << endl;
	outFile << "Radius = " << radius << ", area = " << circleArea <<
	         ", circumference = " << circumference << endl;

	//OUTPUT - Name and age
	cout << "Name: " << firstName << " " << lastName << ", age: " << age
		 << endl;
	outFile << "Name: " << firstName << " " << lastName << ", age: " << age
		    << endl;

	//OUTPUT - Beginning balance, interest rate, and end balance
	cout << "Beginning balance = $" << beginningBalance << ", interest rate = "
		 << interestRate << endl;
	cout << "Balance at the end of the month = $" << endBalance << endl;
	outFile << "Beginning balance = $" << beginningBalance <<
				", interest rate = " << interestRate << endl;
	outFile << "Balance at the end of the month = $" << endBalance << endl;

	//OUTPUT - Given letter and the next letter in the ASCII data set
	cout << "The character that comes after " << upperLetter <<
			 " in the ASCII set is " << next << endl;
	outFile << "The character that comes after " << upperLetter <<
				 " in the ASCII set is " << next << endl;

	//Close the input and output files
	inFile.close();
	outFile.close();

	return 0;

}
