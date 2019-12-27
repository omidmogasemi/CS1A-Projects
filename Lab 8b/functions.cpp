#include <iostream>
#include <iomanip>
#include <string>
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
	double totalScore = 0.0;          // CALC - The total score of a student
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
