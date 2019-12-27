/*************************************************************************
 * AUTHOR	  : Omid Mogasemi
 * STUDENT ID : 1093893
 * LAB #5b	  : SWITCH SWITCH plus
 * CLASS      : CS1A
 * SECTION	  : MTWTh: 10:00a - 1:35p";
 * DUE DATE   : 7/20/2018
 *************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;

/********************************************************************
 *
 * SWITCH SWITCH plus
 * __________________________________________________________________
 * This program acts as a basic calculator which will take both
 * integer and floating point numbers which it will read from file
 * inputPartb.txt and write output to a file named resultsPartb.txt.
 * It will be able to handle addition, subtraction, multiplication,
 * division, and exponents. If both operands have a zero decimal
 * fraction, it will output the result as an integer. If not, it will
 * output all results as floating point results to four fixed decimal
 * places, and will run until the end of the input file is reached.
 * __________________________________________________________________
 * INPUT:
 * 	num1: The first integer -> input from inputPartb.txt
 *  num2: The second integer -> input from inputPartb.txt
 *  oper: The chosen oper -> input from inputPartb.txt
 *
 * OUTPUT:
 *  answer: The answer to the selected operation
 *  remainder: The remainder to a division operation
 *  divAnswer: The answer to the division of two integer values
 *******************************************************************/

int main()
{

	//Declare constants for header output
	const char PROGRAMMER[] = "Omid Mogasemi";
	const char CLASS[]       = "CS1A";
	const char SECTION[]    = "MTWTh: 10:00a - 1:35p";
	const char LAB_NUM[]         = "5b";
	const char LAB_NAME[]   = "SWITCH SWITCH plus";

	//OUTPUT - class heading
	cout << left;
	cout << "***************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n***************************************\n";
	cout << right;

	//Declare filestream variables
	ifstream inFile;
	ofstream outFile;

	//Associate the file stream variables with the I/O sources
	inFile.open("E:\\inputPartb.txt");
	if (!inFile)
	{
		cout << "Problem opening input file E:\\inputPartb.txt";
		return 1;
	}

	outFile.open("E:\\resultsPartb.txt");
	if (outFile.fail())
	{
		cout << "Problem opening output file E:\\resultsPartb.txt";
		exit(1);
	}

	//OUTPUT - class heading to file
	outFile << left;
	outFile << "***************************************";
	outFile << "\n* PROGRAMMED BY : " << PROGRAMMER;
	outFile << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	outFile << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	outFile << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	outFile << "\n***************************************\n";
	outFile << right;

	//Declare variables
	double num1;        //INPUT - First integer
	double num2;        //INPUT - Second integer
	char oper;          //INPUT - Chosen oper
	double answer;      //CALC & OUT - Answer to the operation
	int remainder;      //CALC & OUT - Remainder in a division operation
	int line = 1;       //CALC - Determine which line of the input file is
	                    //       being read from.
	int divAnswer;      //CALC & OUT - The answer to the division of two
	                    //             integer values

	//INPUT - Numbers 1 and 2 from the file
	inFile >> num1;
	inFile >> num2;

	while(!inFile.eof())
	{
		//INPUT - Chosen operator to use
		inFile >> oper;

		//PROCESSING - Check to see if the result numbers should be output in
		//             decimal or integer format.
		if (!(fabs(static_cast<float>(static_cast<int>(num1)) == num1) &&
		   (fabs(static_cast<float>(static_cast<int>(num2)) == num2))))
		{
			outFile << fixed << setprecision(4);
			num1 = static_cast<double>(num1);
			num2 = static_cast<double>(num2);
		}
		else
		{
			outFile << fixed << setprecision(0);
			num1 = static_cast<int>(num1);
			num2 = static_cast<int>(num2);
		}
		//PROCESSING - Check for each possible operator case
		switch (oper)
		{
		//PROCESSING & OUTPUT - Addition case
		case '+':
			answer = num1 + num2;
			outFile << "\n" << num1 << " " << oper << " " << num2 << " = "
					<< answer;
			break;
		//PROCESSING & OUTPUT - Subtraction case
		case '-':
			answer = num1 - num2;
			outFile << "\n" << num1 << " " << oper << " " << num2 << " = "
					<< answer;
			break;
		//PROCESSING & OUTPUT - Multiplication case
		case '*':
			answer = num1 * num2;
			outFile << "\n" << num1 << " " << oper << " " << num2
							<< " = " << answer;
			break;
		//PROCESSING & OUTPUT - Division case
		case '/':
			//PROCESSING & OUTPUT - If denominator is 0 situation
			if (num2 == 0)
			{
				cout << "\n" << "ERROR encountered on line " << line;
				outFile << "\n" << num1 << " " << oper << " " << num2
						<< " = ERROR";
			}
			else
			{
				//PROCESSING - Determine if the output should have a remainder
				if (!(fabs(static_cast<float>(static_cast<int>(num1)) == num1)
				   &&
				   (fabs(static_cast<float>(static_cast<int>(num2)) == num2))))
				{
					answer = num1 / num2;
					outFile << "\n" << num1 << " " << oper << " " << num2
			                << " = " << answer;
				}
				else
				{
					divAnswer = num1 / num2;
					remainder = static_cast<int>(num1) % static_cast<int>(num2);
					outFile << "\n" << num1 << " " << oper << " " << num2
					        << " = " << divAnswer << "R" << remainder;
				}
			}
			break;
		//PROCESSING & OUTPUT - Exponent case
		case '^':
			//PROCESSING & OUTPUT - Check for a case if both numbers are 0
			if (num1 == 0 && num2 == 0)
			{
				cout << "\n" << "ERROR encountered on line " << line;
				outFile << "\n" << num1 << " " << oper << " " << num2
				        << " = ERROR";
			}
			else
			{
				answer = pow(num1, num2);
				outFile << "\n" << num1 << " " << oper << " " << num2
				<< " = " << answer;
			}
			break;
		//PROCESSING & OUTPUT - Default case
		default:
			cout << "\nILLEGAL operator encountered on line " << line;
			outFile << "\n" << num1 << " " << oper << " " << num2
					<< " = ILLEGAL";

		}
		//PROCESSING - Increment the line value
		line++;

		//INPUT - Read the next two numbers to be evaluated
		inFile >> num1;
		inFile >> num2;
	}

	//PROCESSING - Close the input and output files
	inFile.close();
	outFile.close();

	return 0;
}
