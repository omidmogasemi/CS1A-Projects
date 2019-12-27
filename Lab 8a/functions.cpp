#ifndef FUNCTIONS_CPP_
#define FUNCTIONS_CPP_

#include <iostream>
#include <iomanip>
#include <string>
#include "functions.h"
using namespace std;

/***********************************************************
*
* FUNCTION getMenuPick
*__________________________________________________________
* This function prompts the user to choose an operation
* from the menu and takes the user's input. It checks
* for bad input from the user as well - returns an
* enumerator based on the user's input.
*__________________________________________________________
* PRE-CONDITIONS
* MenuPick: Function type has to be previously defined
*
* POST-CONDITIONS
* This function will return an enumerator based on the
* user's input.
************************************************************/
MenuPick getMenuPick()
{
	//Declare variables
	int selection;      // IN - User's desired menu choice
	bool check = true;  // CALC - Whether the menu loop should end

	while (check)
	{
		//OUTPUT - Prompt the user with the menu
		cout << "Please select from one of the following options:\n" <<
				"1. Read names from file\n" <<
				"2. Display names\n" <<
				"3. Sort names ascending\n" <<
				"4. Sort names descending\n" <<
				"5. Count name\n" <<
				"6. Exit program\n" <<
				"Selection:";
		//INPUT - Read in the user's menu choice
		cin >> selection;

		//PROCESSING - Use the user's menu choice to determine which
		//             calculation should be ran.
		switch (selection)
		{
		case 1:
			return READ_DATA;
		case 2:
			return DISPLAY;
		case 3:
			return SORT_ASC;
		case 4:
			return SORT_DEC;
		case 5:
			return COUNT;
		case 6:
			return EXIT;
		//PROCESSING - If the user gave bad input
		default:
			//PROCESSING - Fix the I/O stream and re-prompt the user if they
			//             give an invalid input
			if (!cin >> selection)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\nPlease enter an integer value!\n\n";
				continue;
			}
			//PROCESSING - in the case of poor number input, inform
			//             and re-prompt the user
			else
			{
				cout << "\nPlease enter a number between 1 and 6!\n\n";
				continue;
			}
		}
	}
}

/***********************************************************
*
* FUNCTION bubbleSort
*__________________________________________________________
* This function takes an array of strings and uses
* the swap function to sort them in either ascending or
* descending order based on user input from the main
* function - returns nothing.
*__________________________________________________________
* PRE-CONDITIONS
* strAr[]: String Array has to be previously defined
* SIZE: Assignment size has to be previously defined
* ascending: Assignment order has to be previously defined
*
* POST-CONDITIONS
* This function will swap all of the strings in the array
* based on if it must be ascending or descending order.
************************************************************/
void bubbleSort(string strAr[],        // IN - All of the strings in an array
                const int SIZE,        // CALC - The maximum size of the array
                const bool ascending)  // CALC - Whether or not the sort is
                                       //        ascending or descending
{
	int i, j;  // CALC - Used to run the for loops

	//PROCESSING - Run until every value in the array has been accounted for
	for (i = 0; i < SIZE - 1; i++)
	{
		for (j = 0; j < SIZE - 1 - i; j++)
		{
			//PROCESSING - Swap the two strings if ascending order is desired
			if (ascending)
			{
				if (strAr[j] > strAr[j+1])
				{
					strAr[j].swap(strAr[j+1]);
				}
			}
			//PROCESSING - Swap the two strings if descending order is desired
			else
			{
				if (strAr[j] < strAr[j+1])
				{
				strAr[j].swap(strAr[j+1]);
				}
			}
		}
	}
}

/***********************************************************
*
* FUNCTION count
*__________________________________________________________
* This function counts the occurrences of a name in the
* list of names - returns the number of occurrences.
*__________________________________________________________
* PRE-CONDITIONS
* strAr[]: String Array has to be previously defined
* SIZE: Assignment size has to be previously defined
* ascending: Assignment order has to be previously defined
*
* POST-CONDITIONS
* This function will calculate and return the number of
* occurrences.
* instances: Will contain the number of times a name occurs
************************************************************/
int count(const string strAr[],  // IN - All of the strings in an array
		  const string key,      // IN - The name the user wants to count
		  const int SIZE)        // CALC - The maximum size of the array
{
	int index;         // CALC - Used to run through the entire array
	int instances = 0; // CALC - The number of times a name has occurred

	//PROCESSING - Run until the entire array is accounted for
	for (index = 0; index < SIZE; index++)
	{
		//PROCESSING - If the key name value/string is matched, then increase
		//             the counter by 1
		if (strAr[index] == key)
		{
			instances++;
		}
	}

	return instances;
}



#endif /* FUNCTIONS_CPP_ */
