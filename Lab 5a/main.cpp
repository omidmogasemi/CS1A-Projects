/*************************************************************************
 * AUTHOR	  : Omid Mogasemi
 * STUDENT ID : 1093893
 * LAB #5a	  : SWITCH SWITCH
 * CLASS      : CS1A
 * SECTION	  : MTWTh: 10:00a - 1:35p";
 * DUE DATE   : 7/13/2018
 *************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/********************************************************************
 *
 * SWITCH SWITCH
 * __________________________________________________________________
 * This program mimics a simple integer calculator using a switch
 * statement. The program will prompt the user for two integer
 * numbers and the operation to be performed as input. It will then
 * output the numbers, the operator, and the result, using a for
 * loop to prompt the user for input seven times. It will also check,
 * in the case of division, for any remainder and if the denominator
 * is zero, and output an appropriate message.
 *
 * __________________________________________________________________
 * INPUT:
 * 	num1: The first integer -> input from user
 *  num2: The second integer -> input from user
 *  oper: The chosen operator -> input from user
 *
 * OUTPUT:
 *  answer: The answer to the selected operation
 *  remainder: The remainder to a division operation
 *
 *******************************************************************/

int main()
{
	//Declare constants for header output
	const char PROGRAMMER[] = "Omid Mogasemi";
	const char CLASS[]       = "CS1A";
	const char SECTION[]    = "MTWTh: 10:00a - 1:35p";
	const char LAB_NUM[]         = "5a";
	const char LAB_NAME[]   = "SWITCH SWITCH";

	//OUTPUT - class heading
	cout << left;
	cout << "***************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n***************************************\n";
	cout << right;

	//Declare variables
	int num1;           //INPUT - First integer
	int num2;           //INPUT - Second integer
	char oper;          //INPUT - Chosen operator
	int answer;         //CALC & OUT - Answer to the operation
	int remainder;      //CALC & OUT - Remainder in a division operation

	//PROCESSING - Start a loop that will run 7 times
	for(int i = 0; i < 7; i++)
	{
		//OUTPUT & INPUT - Prompt the user for their 2 integers and input them
		cout << "\nEnter two integers: ";
		cin >> num1;
		cin >> num2;
		cout << "\nEnter operator: + , - , * , / : ";
		cin >> oper;

		//PROCESSING - Check for each possible operator case
		switch (oper)
		{
		//PROCESSING & OUTPUT - Addition case
		case '+':
			answer = num1 + num2;
			cout << "\n" << num1 << " " << oper << " " << num2 << " = "
			     << answer << endl;
			break;
		//PROCESSING & OUTPUT - Subtraction case
		case '-':
			answer = num1 - num2;
			cout << "\n" << num1 << " " << oper << " " << num2 << " = "
			     << answer << endl;
			break;
		//PROCESSING & OUTPUT - Multiplication case
		case '*':
			answer = num1 * num2;
			cout << "\n" << num1 << " " << oper << " " << num2 << " = "
				 << answer << endl;
			break;
		//PROCESSING & OUTPUT - Division case
		case '/':
			if (num2 == 0)
			{
				cout << "\n" << num1 << " " << oper << " " << num2
				     << " = " << "ERROR\n";
			}
			else
			{
				answer = num1 / num2;
				remainder = num1 % num2;
				cout << "\n" << num1 << " " << oper << " " << num2
				     << " = " << answer << "R" << remainder << endl;
			}
			break;
		//PROCESSING & OUTPUT - Default case
		default:
			cout << "\n" << num1 << " " << oper << " " << num2 << " = "
			     << "ILLEGAL" << endl;
		}

		//Clear the input buffer and prompt the user to continue
		cin.ignore(1000, '\n');
		cout << "Press ENTER to continue. . .";
		cin.ignore(1000, '\n');
	}

	return 0;
}
