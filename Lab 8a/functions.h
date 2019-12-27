#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <string>
using namespace std;

enum MenuPick {READ_DATA,   // Read names from file
			       DISPLAY,     // Display names
				   SORT_ASC,    // Sort names ascending
				   SORT_DEC,    // Sort names descending
				   COUNT,       // Count name
				   EXIT         // Exit program
	           };

/****************************************************************
* getMenuPick
*   This function prompts the user to choose an operation
*   from the menu and takes the user's input. It checks
*   for bad input from the user as well - returns an
*   enumerator based on the user's input.
***************************************************************/
MenuPick getMenuPick();

/****************************************************************
* bubbleSort
*   This function takes an array of strings and uses
*   the swap function to sort them in either ascending or
*   descending order based on user input from the main
*   function - returns nothing.
***************************************************************/
void bubbleSort(string strAr[],        // IN - All of the strings in an array
		        const int SIZE,        // CALC - The maximum size of the array
		        const bool ascending); // CALC - Whether or not the sort is
                                       //        ascending or descending

/****************************************************************
* count
*   This function counts the occurrences of a name in the
*   list of names - returns the number of occurrences.
***************************************************************/
int count(const string strAr[],  // IN - All of the strings in an array
		  const string key,      // IN - The name the user wants to count
		  const int SIZE);       // CALC - The maximum size of the array



#endif /* FUNCTIONS_H_ */
