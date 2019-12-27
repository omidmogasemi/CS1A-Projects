#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 30;  // CALC - Max array size possible

//Declare struct that contains all info related to the student
struct studentInfo
{
	string ids;          // IN & OUT - Each student's ID
	string answers;      // IN & OUT - The student's test answers
	string lastName;     // IN & OUT - Each student's last name
	string firstName;    // IN & OUT - Each student's first name
	double percentScore; // IN & OUT - Each student's score as a percent
	char gradeScore;     // IN & OUT - Each student's score as letter grade
};

/****************************************************************
* getPercentScore
*   This function will determine a student's total score
*   as a percent from 0-100 by comparing each answer from
*   the student to the answer key, and giving the student
*   2 points for a correct answer, 0 points for a blank answer,
*   and deducting 1 point from the student for each incorrect
*   answer - returns the student's percentage score.
***************************************************************/
double getPercentScore(const string answers, // IN - The student's answers
                       const string key);    // In - The answer key

/****************************************************************
* getGradeScore
*   This function uses a student's percent score to calculate
*   that student's score as a letter grade - returns the
*   student's letter grade.
***************************************************************/
char getGradeScore(const double percent); // CALC - The student's percent score

/****************************************************************
* nameSearch
*   This function searches through the names file
* 	studentNames.txt until it finds a name that has a
* 	corresponding ID which matches the ID that was just read
* 	with the test scores in the main function. Once it finds
* 	that the ID read with the names matches the ID just read
* 	in main, it will then assign the matching first and last
* 	name to be the first and last name at the same index
* 	as the corresponding ID and test answers - returns
* 	nothing.
***************************************************************/
void nameSearch(string& lastName,  // CALC - Student's last name
				string& firstName, // CALC - Student's first name
				string IDs);       // CALC - Student's ID

/****************************************************************
* tableSort
*   This function sorts all of the values in the table
* 	alphabetically by last name by checking if one last
* 	name is greater in value than the other and then doing
* 	a simple swap - returns nothing.
***************************************************************/
void tableSort(studentInfo stuAr[],  // CALC - All of the student's info
		   	   const int SIZE);      // CALC - Max size of the array

#endif /* FUNCTIONS_H_ */
