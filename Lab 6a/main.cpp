/*************************************************************************
 * AUTHOR	  : Omid Mogasemi
 * STUDENT ID : 1093893
 * LAB #6a	  : FLIP FLOP
 * CLASS      : CS1A
 * SECTION	  : MTWTh: 10:00a - 1:35p";
 * DUE DATE   : 7/24/2018
 *************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

/********************************************************************
 *
 * FLIP FLOP
 * __________________________________________________________________
 * This program simulates a coin flip that will repeatedly continue
 * until three consecutive heads are flipped. Once this is
 * accomplished, the program will then output to the user the total
 * number of coin flips that were done and the average number of
 * heads flipped.
 * __________________________________________________________________
 * INPUT:
 * name: User name -> input from function getName();
 * gender: User gender -> input from function getGender();
 *
 * OUTPUT:
 * genderOutput: Used to address the user as Mr. or Ms.
 * result: The result of each of the user's coin flips.
 *
 *******************************************************************/

/********************************************************************
 * getName
 *  This function prompts the user for their name and reads it in
 *  as user input
 *  - returns the user name.
 *******************************************************************/
string getName();
/********************************************************************
 * getGender
 *  This function reads prompts the user for their gender and reads
 *  it in as user input until the user provides a proper gender
 *  - returns the user's gender.
 *******************************************************************/
char getGender();
/********************************************************************
 * flipCoin
 *  This function simulates the coin flip
 *  - returns the result of the coin flip
 *******************************************************************/
bool flipCoin();
/********************************************************************
 * calcAverageHeads
 * This function calculates the percent of the coin flips that result
 * in a head in the form of an integer
 * - returns the percentage of coin flips that result in heads
 *******************************************************************/
float calcAverageHeads(int hcnt,  // CALC - Number of heads rolled
		               int tcnt); // CALC - Number of tails rolled
/********************************************************************
 * displayResults
 *  This function displays to the user the number of tosses it took
 *  to get 3 heads in a row and what their percentage of flipped
 *  heads were
 *  returns nothing -> This will output the flip results as mentioned
 *  above.
 *******************************************************************/
void displayResults(int tcnt,   // OUT - Total number of flips
		            float avg); // OUT - The average number of times a flip
                                //       resulted in a head


int main()
{
	//Declare constants for header output
	const char PROGRAMMER[] = "Omid Mogasemi";
	const char CLASS[]       = "CS1A";
	const char SECTION[]    = "MTWTh: 10:00a - 1:35p";
	const char LAB_NUM[]         = "6a";
	const char LAB_NAME[]   = "FLIP FLOP";

	//OUTPUT - class heading
	cout << left;
	cout << "***************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n***************************************\n";
	cout << right;

	//PROCESSING - Declare variables
	string name;            //INPUT - User name
	char gender;            //INPUT - User gender
	string genderOutput;    //OUTPUT - If the user is Mr. or Ms.
	int headCount = 0;      //CALC - The total number of heads flipped
	int tailCount = 0;      //CALC - The total number of tails flipped
	int headInARow = 0;     //CALC - The total number of heads flipped in a row
	string result;          //OUT - The total number of flipped rolls
	int totalCount = 0;     //CALC - The total number of flips completed

	//OUTPUT - Welcome statement to the user
	cout << "Welcome to coin toss! Get 3 heads in a row to win!\n\n";

	//OUTPUT - Assign variables to their respective functions
	name = getName();
	gender = getGender();

	//cout << (to... instead
	//PROCESSING - Check to see if the person is a Mr. or Ms. for future output
	genderOutput = (toupper(gender) == 'M') ? "Mr." : "Ms.";

	//OUTPUT - Instructions to user
	cout << "\nTry to get 3 heads in a row. Good luck " << genderOutput
		 << " " << name << "!\n\n";

	srand(time(NULL));

	//PROCESSING - Flip the coin until 3 heads are encountered in a row
	while (headInARow < 3)
	{
		cin.ignore(1000, '\n');
		cout << "Press <Enter> to flip";
		cin.ignore(1000, '\n');

		result = (flipCoin()) ? "HEADs" : "TAILs";
		cout << result;

		if (result == "HEADs")
		{
			headCount++;
			headInARow++;
		}
		else
		{
			tailCount++;
			headInARow = 0;
		}
	}

	//PROCESSING & OUTPUT - Determine the total number of times the coin is
	//                      flipped and display the final results
	totalCount = headCount + tailCount;
	displayResults(totalCount, calcAverageHeads (headCount, tailCount));


	return 0;
}

/********************************************************************
 *
 * FUNCTION getName
 * __________________________________________________________________
 *  This function prompts the user for their name and reads it in
 *   as user input - returns the user name.
 * __________________________________________________________________
 * PRE-CONDITIONS
 * 		N/A
 *
 * POST-CONDITIONS
 *		This function will output a prompt to acquire the user name.
 *******************************************************************/
string getName()
{
	string name;
	//OUTPUT - Question about name
	cout << left << setw(29) << "What is your name?";
	//INPUT - Read in user's name
	getline(cin, name);
	return name;
}

/********************************************************************
 *
 * FUNCTION getGender
 * __________________________________________________________________
 * This function reads prompts the user for their gender and reads
 *   it in as user input until the user provides a proper gender
 *   - returns the user's gender.
 * __________________________________________________________________
 * PRE-CONDITIONS
 * 		N/A
 *
 * POST-CONDITIONS
 *		This function will output a prompt to acquire the user gender.
 *******************************************************************/
char getGender()
{
	char gender;

	//PROCESSING - Check to see if the user has provided a proper gender
	do
	{
		cout << left << setw(29) << "What is your gender(M/F)?";
		cin >> gender;
	}
	while (toupper(gender) != 'M' && toupper(gender) != 'F');

	return gender;
}

/********************************************************************
 *
 * FUNCTION flipCoin
 * __________________________________________________________________
 * This function calculates the percent of the coin flips that result
 *   in a head in the form of an integer returns the percentage of
 *   coin flips that result in heads
 * __________________________________________________________________
 * PRE-CONDITIONS
 * 		stdlib.h & time.h header files
 * 		srand(time(NULL)) function call
 *
 * POST-CONDITIONS
 *		N/A
 *******************************************************************/
bool flipCoin()
{
	bool flipCoin;
	int myRandomNumber;
	myRandomNumber = rand() % 2;

	//PROCESSING - Result of the coin flip (heads or tails)
	if (myRandomNumber == 1)
		flipCoin = true;
	else
		flipCoin = false;

	return flipCoin;
}

/********************************************************************
 *
 * FUNCTION calcAverageHeads
 * __________________________________________________________________
 * This function calculates the percent of the coin flips that result
 *   in a head in the form of an integer. - returns the percentage of
 *   coin flips that result in heads
 * __________________________________________________________________
 * PRE-CONDITIONS
 * 		hcnt: Must be previously defined
 * 		tcnt: Must be previously defined
 *
 * POST-CONDITIONS
 *		N/A
 *******************************************************************/
float calcAverageHeads(int hcnt, // CALC - Number of heads rolled
		               int tcnt) // CALC - Number of tails rolled
{
	return static_cast<int>(static_cast<double>(hcnt)/(hcnt + tcnt) * 100);
}

/********************************************************************
 *
 * FUNCTION displayResults
 * __________________________________________________________________
 * This function displays to the user the number of tosses it took
 *   to get 3 heads in a row and what their percentage of flipped
 *   heads were returns nothing -> This will output the flip results as mentioned
 *   above.
 * __________________________________________________________________
 * PRE-CONDITIONS
 * 		tcnt: Must be previously defined
 * 		avg: Must be previously defined
 *
 * POST-CONDITIONS
 *		This function will output the flip results to the user.
 *******************************************************************/
void displayResults(int tcnt,    // OUT - Total number of flips
		            float avg)   // OUT - The average number of times a flip
                                 //       resulted in a head
{
	//OUTPUT - Flip results
	cout << "\nIt took you " << tcnt << " tosses to get 3 heads in a row.\n";
	cout << "On average you flipped heads " << avg << "% of the time.";
}
