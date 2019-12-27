/*************************************************************************
 * AUTHOR	  : Omid Mogasemi
 * STUDENT ID : 1093893
 * LAB #8a	  : HOORAY
 * CLASS      : CS1A
 * SECTION	  : MTWTh: 10:00a - 1:35p";
 * DUE DATE   : 8/1/2018
 *************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "printHeader.h"
#include "functions.h"
using namespace std;

/********************************************************************
 *
 * HOORAY
 * __________________________________________________________________
 * This program reads in a list of up to 25 first names from an
 * input file nameData.txt and allows the user to display the
 * names, sort those names in ascending or descending order, count
 * the number of occurrences of a user chosen name, or exit the
 * program.
 * __________________________________________________________________
 * INPUT:
 * userChoice: User's desired choice from the menu -> input from
 *             function getMenuPick()
 * strAr[SIZE]: List of all names -> input from nameData.txt
 * key: The name the user wants to count the number of occurrences of
 * nameCount: The number of occurrences of a chosen name -> input
 *            from function count(strAr, key, index);
 * OUTPUT:
 * index: The amount of names in the file
 * counter: The number displayed when listing names
 * nameCount: The number of occurrences of a chosen name
 * timeOutput: Whether or not the word time is plural
 *******************************************************************/

const int SIZE = 25;   // CALC - The maximum size of the array

int main()
{
	printHeader("HOORAY", "8a");

	//Declare variables
	bool check = true;  // CALC - Whether or not the program loop should stop
	string strAr[SIZE]; // IN - Each string in an array of size
	int index = 0;      // CALC & OUT - How many values are the in array
	int indexDisplay;   // CALC - A copy of the index in order to display
	                    //        all names properly
	int counter;        // CALC - A number counter to properly number each
	                    //        name being displayed
	string key;         // IN - The name the user wants to count
	bool ascending;     // CALC - Whether the user wants to sort by ascending
	                    //        or descending
	int nameCount;      // IN & OUT - The number of occurrences of a chosen
	                    //            name
	string timeOutput;  // OUT - Whether or not the word time is plural

	//Associate the file stream variables with the input source
	ifstream inFile;

	//PROCESSING - Run a loop that will go until the user does an action
	//             that will trigger the check variable to be false
	while (check)
	{
		//PROCESSING - Call the menu function and store its return value
		MenuPick userChoice;         // CALC - The user's menu choice
		userChoice = getMenuPick();

		switch (userChoice)
		{
		case READ_DATA:
			index = 0;

			//PROCESSING - Set each string in the array to 0 to avoid
			//             problems if strings have already been read
			for (int i = 0; i < SIZE; i++)
			{
				strAr[i] = "";
			}

			//PROCESSING - Open the input file and check for file failure
			inFile.open("nameData.txt");
			if (!inFile)
			{
				cout << "Problem opening input file E:\\sideData.txt";
				return 1;
			}

			//INPUT - Read from the input file until the file end or the index
			//        reaches the max array size
			inFile >> strAr[0];
			while (!inFile.eof() && index < SIZE)
			{
				index++;
				if (index < SIZE)
				{
					inFile >> strAr[index];
				}
			}

			//PROCESSING - Decide what to output based on if there is nothing
			//             in the input file or if it contains names
			if (strAr[0] == "")
			{
				cout << "\n0 names read from file e:\\nameData.txt\n\n";
				index = 0;
			}
			else
			{
			cout << "\n" << index
				 << " names read from file e:\\nameData.txt\n\n";
			}

			//Close the input file
			inFile.close();
			break;
		case DISPLAY:
			//OUTPUT - If there are no names read yet
			if (index == 0)
			{
				cout << "\nNo names to display!\n\n";
				break;
			}

			//PROCESSING - Initialize the variables that allow the names to be
			//             properly displayed
			indexDisplay = 0;
			counter = 1;
			cout << "\n";

			//OUTPUT - The list of names to be displayed
			while (indexDisplay < index)
			{
				cout << right << setw(2) << counter++ << ": " << left
				     << strAr[indexDisplay] << "\n";
				indexDisplay++;
			}
			cout << "\n";
			break;
		case SORT_ASC:
			//OUTPUT - Sorting statement
			cout << "\nSorting in ascending order. . .\n\n";

			//PROCESSING - Sort the names in ascending order
			ascending = true;
			bubbleSort(strAr, index, ascending);
			break;
		case SORT_DEC:
			//OUTPUT - Sorting statement
			cout << "\nSorting in descending order. . .\n\n";

			//PROCESSING - Sort the names in descending order
			ascending = false;
			bubbleSort(strAr, index, ascending);
			break;
		case COUNT:
			//OUTPUT - Prompt the user for a name to count
			cout << "Enter a name to count: ";
			cin >> key;

			//PROCESSING & OUTPUT - The name and how many times it occurs
			nameCount = count(strAr, key, index);
			timeOutput = (nameCount != 1) ? "times" : "time";
			cout << "\nName " << key << " occurs "
				 << nameCount << " " << timeOutput << "\n\n";
			break;
		case EXIT:
			//OUTPUT - Exit statement
			cout << "\nThank you for using my name program.";
			//PROCESSING - Make the loop-control variable false
			check = false;
			break;

		}

	}



	return 0;
}
