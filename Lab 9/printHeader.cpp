#include <iostream>
#include <iomanip>
#include <string>
#include "printHeader.h"
using namespace std;

/***********************************************************
*
* FUNCTION PrintHeader
*__________________________________________________________
* This function receives an assignment name and
* number then outputs the appropriate header -
* returns nothing.
*__________________________________________________________
* PRE-CONDITIONS
* labName: Assignment Name has to be previously defined
* labNum : Assignment Number has to be previously defined
*
* POST-CONDITIONS
* This function will output the class heading.
************************************************************/
void printHeader(string labName, // IN - Assignment Name
                 string labNum)  // IN - assignment number
{
	//Declare constants for header output
	const char PROGRAMMER[] = "Omid Mogasemi";
	const char CLASS[]       = "CS1A";
	const char SECTION[]    = "MTWTh: 10:00a - 1:35p";

	//OUTPUT - class heading
	cout << left;
	cout << "***************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB #" << setw(9) << labNum << ": " << labName;
	cout << "\n***************************************\n";
	cout << right;

}
