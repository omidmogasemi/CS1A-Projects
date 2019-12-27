#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include "functions.h"
using namespace std;

/***********************************************************
*
* FUNCTION getPercentScore
*__________________________________________________________
* This function will determine a student's total score
* as a percent from 0-100 by comparing each answer from
* the student to the answer key, and giving the student
* 2 points for a correct answer, 0 points for a blank answer,
* and deducting 1 point from the student for each incorrect
* answer - returns the student's percentage score.
*__________________________________________________________
* PRE-CONDITIONS
* answers: Student's answers must be previously defined
* key: Official answer key must be previously defined
*
* POST-CONDITIONS
* This function will return the percentage score of a student.
* percentScore: Will contain the percentage score of a student
************************************************************/
double getPercentScore(const string answers, // IN - The student's answers
		               const string key)     // In - The answer key
{
	//Declare variables
	double totalScore = 0.0;        // CALC - The total score of a student
	double percentScore;            // OUT - The percent score of a student
	const int pointsPossible = 40;  // CALC - The max points possible for a
	                                //        student

	//PROCESSING - Compare each answer from the student to the correct
	//             answer from the answer key and tally points based
	//             on each student response
	for (unsigned int i = 0; i < answers.length(); i++)
	{
		//PROCESSING - Give the student 0 points if they left an answer blank
		if (answers[i] == key[i])
		{
			totalScore += 2.0;
		}
		//PROCESSING - Give the student 2 points if they got the answer right
		else if (answers[i] == '_')
		{
			totalScore += 0.0;
		}
		//PROCESSING - Take 1 point from the student if they got the answer
		//             wrong
		else if (answers[i] != key[i])
		{
			totalScore -= 1.0;
		}
	}

	//PROCESSING - Set the student's total score to 0 if they got a negative
	//             total score
	if (totalScore < 0)
	{
		return 0;
	}

	percentScore = (totalScore/pointsPossible) * 100;
	return percentScore;
}

/***********************************************************
*
* FUNCTION getGradeScore
*__________________________________________________________
* This function uses a student's percent score to calculate
* that student's score as a letter grade - returns the
* student's letter grade.
*__________________________________________________________
* PRE-CONDITIONS
* percent: Student's percent score must be previously defined
*
* POST-CONDITIONS
* This function will return the student's grade as a letter.
* grade: Will contain the student's grade as a letter
************************************************************/
char getGradeScore(const double percent)  // CALC - The student's percent score
{
	//Declare variables
	char grade;                // OUT - The student's letter grade

	//PROCESSING - Determine the student's letter grade based on what
	//             percentage grade they earned
	if (percent >= 90)
		grade = 'A';
	else if (percent >= 80)
		grade = 'B';
	else if (percent >= 70)
		grade = 'C';
	else if (percent >= 60)
		grade = 'D';
	else if (percent < 60)
		grade = 'F';

	return grade;
}

/***********************************************************
*
* FUNCTION nameSearch
*__________________________________________________________
* This function searches through the names file
* studentNames.txt until it finds a name that has a
* corresponding ID which matches the ID that was just read
* with the test scores in the main function. Once it finds
* that the ID read with the names matches the ID just read
* in main, it will then assign the matching first and last
* name to be the first and last name at the same index
* as the corresponding ID and test answers - returns
* nothing.
*__________________________________________________________
* PRE-CONDITIONS
* lastName: Assignment type variable must be previously declared
* firstName: Assignment type variable must be previously declared
*
* POST-CONDITIONS
* This function will return the student's grade as a letter.
* grade: Will contain the student's grade as a letter
* lastName will be assigned a value.
* firstName will be assigned a value.
************************************************************/
void nameSearch(string& lastName,  // CALC - Student's last name
				string& firstName, // CALC - Student's first name
				string IDs)        // CALC - Student's ID
{
	//Declare variables
	string firstNamePlaceholder;  // IN - Student's first name
	string lastNamePlaceholder;   // IN - Student's last name
	string readInID;              // IN - Student's corresponding ID
	bool found = false;           // CALC - Loop control variable

	//Declare file stream variable and open the input file
	ifstream inFile;
	inFile.open("E:\\studentNames.txt");
	if (!inFile)
	{
		cout << "Problem opening input file E:\\testScores.txt";
		exit(1);
	}

	//PROCESSING - Run the loop until either the LCV is triggered to be true
	//             or the file's end is met
	while (!inFile.eof() && !found)
	{
		//INPUT - Read in the first and last name and student ID
		inFile >> firstNamePlaceholder >> lastNamePlaceholder >> readInID;
		inFile.ignore(1000, '\n');

		//PROCESSING - Check if the ID given with the studen't name is
		//             the same as the ID being passed. If this is true,
		//             the the first and last name at that index will be
		//             assigned. If not, the computer will keep searching
		//             for a match.
		if (readInID == IDs)
		{
			lastName = lastNamePlaceholder;
			firstName = firstNamePlaceholder;
			found = true;
		}
	}
	inFile.close();
}

/***********************************************************
*
* FUNCTION tableSort
*__________________________________________________________
* This function sorts all of the values in the table
* alphabetically by last name by checking if one last
* name is greater in value than the other and then doing
* a simple swap - returns nothing.
*__________________________________________________________
* PRE-CONDITIONS
* stuAr[]: Array of student info must be previously defined
* SIZE: Assignment type variable must be previously defined
*
* POST-CONDITIONS
* This function will return nothing.
* stuAr[j] and stuAr[j+1] will be swapped.
************************************************************/
void tableSort(studentInfo stuAr[], // CALC - All of the student's info
			   const int SIZE)      // CALC - Max size of the array
{
	studentInfo temp;  // CALC - Create a temporary variable so the swap
	                   //      - may be completed

	//PROCESSING - Swap the names into alphabetical order
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE - 1 - i; j++)
		{
			//PROCESSING - Check if two last names are the same
			if (stuAr[j].lastName == stuAr[j+1].lastName)
			{
				//PROCESSING - Perform the swap if the first name is larger
				if (stuAr[j].firstName > stuAr[j+1].firstName)
				{
					temp = stuAr[j];
					stuAr[j] = stuAr[j+1];
					stuAr[j+1] = temp;
				}
			}

			//PROCESSING - Perform the swap if the last name is larger
			else if (stuAr[j].lastName > stuAr[j+1].lastName)
			{
				temp = stuAr[j];
				stuAr[j] = stuAr[j+1];
				stuAr[j+1] = temp;
			}
		}
	}
}
