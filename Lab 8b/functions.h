#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <string>
using namespace std;

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
                       const string key);     // In - The answer key

/****************************************************************
* getGradeScore
*   This function uses a student's percent score to calculate
*   that student's score as a letter grade - returns the
*   student's letter grade.
***************************************************************/
char getGradeScore(const double percent); // CALC - The student's percent score

#endif /* FUNCTIONS_H_ */
