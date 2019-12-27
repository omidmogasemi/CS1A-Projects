/*************************************************************************
 * AUTHOR	  : Omid Mogasemi
 * STUDENT ID : 1093893
 * LAB #8b	  : MATH ANYONE
 * CLASS      : CS1A
 * SECTION	  : MTWTh: 10:00a - 1:35p";
 * DUE DATE   : 8/3/2018
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
 * MATH ANYONE
 * __________________________________________________________________
 * This program grades a true/false test, using the test answers
 * stored in the file testScores.txt alongside the students' IDs and
 * test answers. It will take the first entry in the file, the answer
 * key, and use that to calculate and output each student's percent
 * score as well as their letter grade. Lastly, it will output the
 * maximum and minimum percent score for each student corresponding
 * to their ID alongside the class average.
 * __________________________________________________________________
 * INPUT:
 * answerKey: The actual answers to the T/F test -> input from testScores.txt
 * idsAr[SIZE]: The students' IDs -> input from testScores.txt
 * answersAr[SIZE]: The students' answers to the T/F test ->
 *                  input from testScores.txt
 * percentScore: The percent score of each student ->
 *               input from function getPercentScore
 * gradeScore: The letter grade of each student ->
 *             input from function gradeScore
 *
 * OUTPUT:
 * idsAr[SIZE]: The students' IDs
 * answersAr[SIZE]: The students' answers to the T/F test
 * percentScore: The percent score of each student
 * gradeScore: The letter grade of each student
 * minScore: The lowest test score
 * minScoreID: The student ID belonging to the lowest test score
 * maxScore: The highest test score
 * maxScoreID: The student ID belonging to the highest test score
 * averageScore: The average test score for the entire class
 *
 *******************************************************************/

const int SIZE = 30;

int main()
{
	printHeader("MATH ANYONE", "8b");

	//Declare variables
	string answerKey;       // IN & CALC - The test's answer key
	int index = 0;          // CALC - How many values are in the array
	string idsAr[SIZE];     // IN & OUT - Each student's ID
	string answersAr[SIZE]; // IN & OUT - The student's test answers
	double percentScore;    // IN & OUT - Each student's score as a percent
	char gradeScore;        // IN & OUT - Each student's score as letter grade
	double maxScore = -2.0; // CALC - The highest score in the class
	string maxScoreID;      // OUT - The ID of the student with the high score
	double minScore = 101.0;// CALC - The lowest score in the class
	string minScoreID;      // OUT - The ID of the student with the low score
	double totalScore;      // CALC - The cumulative percent score of the
	                        //        entire class
	double averageScore;    // OUT - The average percent score of the entire
	                        //       class


	//PROCESSING - Declare file stream variable and open the input file
	ifstream inFile;
	inFile.open("E:\\testScores.txt");
		if (!inFile)
		{
			cout << "Problem opening input file E:\\testScores.txt";
			return 1;
		}

	//OUTPUT - The header of the results table
	cout << left << setw(33) << "StudentID Answers" << right << setw(14)
		 << "% Score Grade\n";

	//INPUT - Read in the answer key
	inFile >> answerKey;

		//PROCESSING - Run the loop until either the file's end is reached
		//             or the max array size has been reached
		while (!inFile.eof() && index < SIZE)
		{
			//INPUT - Read in the student's ID and answers
			inFile >> idsAr[index] >> answersAr[index];
			inFile.ignore(1000, '\n');

			//PROCESSING - Calculate the student's percent and letter grade
			percentScore = getPercentScore(answersAr[index], answerKey);
			gradeScore = getGradeScore(percentScore);

			//OUTPUT - The student's ID, their answers, their percentage
			//         score, and their letter grade
			cout << fixed << setprecision(1);
			cout << left << setw(10) << idsAr[index] << setw(21)
				 << answersAr[index];
			cout << right << setw(9) << percentScore << setw(6) << gradeScore;
			cout << "\n";

			//PROCESSING - Determine if the student's score is either the
			//             highest or lowest score in the class so far
			if (percentScore > maxScore)
			{
				maxScore = percentScore;
				maxScoreID = idsAr[index];
			}

			if (percentScore < minScore)
			{
				minScore = percentScore;
				minScoreID = idsAr[index];
			}

			//PROCESSING - Update the total score and index
			totalScore += percentScore;
			index++;
		}

		//PROCESSING - Find the average score
		averageScore = totalScore / index;

		//OUTPUT - The maximum, minimum, and average scores of the class
		cout << fixed << setprecision(1);
		cout << "\n\n";
		cout << "Min score is " << right << setw(5) << minScore
			 << "% for Student ID " << minScoreID << "\n";
		cout << "Max score is " << right << setw(5) << maxScore
			 << "% for Student ID " << maxScoreID << "\n";
		cout << "Average   is " << right << setw(5) << averageScore << "%";

	return 0;
}
