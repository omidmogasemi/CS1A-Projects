/*************************************************************************
 * AUTHOR	  : Omid Mogasemi
 * STUDENT ID : 1093893
 * LAB #9	  : MATH ANYONE records
 * CLASS      : CS1A
 * SECTION	  : MTWTh: 10:00a - 1:35p";
 * DUE DATE   : 8/8/2018
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
 * MATH ANYONE records
 * __________________________________________________________________
 * This program grades a true/false test, using the test answers
 * stored in the file testScores.txt alongside the students' IDs and
 * test answers. It will take the first entry in the file, the answer
 * key, and use that to calculate student's percent score as well as
 * their letter grade. It will also take the names of the students
 * from the file studentNames.txt as well as corresponding IDs and
 * use these to match the names up with their respective test
 * scores/answers. Then, it will output these names with their
 * corresponding IDs and answers sorted alphabetically by last name.
 * Lastly, it will output maximum and minimum percent score for
 * each student corresponding to their ID alongside the class average.
 * __________________________________________________________________
 * INPUT:
 * answerKey: The actual answers to the T/F test -> input from testScores.txt
 * students[SIZE]: The student's ID, test answers, test score, and
 *                 test grade.
 *
 * OUTPUT:
 * students[SIZE]: The student's first name, last name, student ID,
 *                  test answers, test score, and test grade.
 * minScore: The lowest test score
 * minScoreID: The student ID belonging to the lowest test score
 * maxScore: The highest test score
 * maxScoreID: The student ID belonging to the highest test score
 * averageScore: The average test score for the entire class
 *
 *******************************************************************/

int main()
{
	printHeader("MATH ANYONE records", "9");

	//Declare variables
	studentInfo students[SIZE]; // IN & OUT - The student's first name, last
	                            //            name, ID, answers, percent
	                            //            score, and letter grade
	string answerKey;           // IN & CALC - The test's answer key
	int index = 0;              // CALC - How many values are in the array
	double maxScore = -2.0;     // CALC - The highest score in the class
	string maxScoreID;          // OUT - The ID of the student with the high
	                            //       score
	double minScore = 101.0;    // CALC - The lowest score in the class
	string minScoreID;          // OUT - The ID of the student with the low
	                            //       score
	double totalScore;          // CALC - The cumulative percent score of the
	                            //        entire class
	double averageScore;        // OUT - The average percent score of the
	                            //       entire class


	//PROCESSING - Declare file stream variable and open the input file
	ifstream inFile;
	inFile.open("E:\\testScores.txt");
	if (!inFile)
	{
		cout << "Problem opening input file E:\\testScores.txt";
		return 1;
	}

	//INPUT - Read in the answer key
	inFile >> answerKey;

	//PROCESSING - Run the loop until either the file's end is reached
	//             or the max array size has been reached
	while (!inFile.eof() && index < SIZE)
	{
		//INPUT - Read in the student's ID and answers
		inFile >> students[index].ids >> students[index].answers;
		inFile.ignore(1000, '\n');

		//PROCESSING - Assign a name to the answers and ID just read in
		nameSearch(students[index].lastName, students[index].firstName,
				   students[index].ids);

		//PROCESSING - Calculate the student's percent and letter grade
		students[index].percentScore = getPercentScore(students[index].answers,
									   answerKey);
		students[index].gradeScore = getGradeScore
				                     (students[index].percentScore);

		//PROCESSING - Determine if the student's score is either the
		//             highest or lowest score in the class so far
		if (students[index].percentScore > maxScore)
		{
			maxScore = students[index].percentScore;
			maxScoreID = students[index].ids;
		}

		if (students[index].percentScore < minScore)
		{
			minScore = students[index].percentScore;
			minScoreID = students[index].ids;
		}

		//PROCESSING - Update the total score and index
		totalScore += students[index].percentScore;
		index++;
	}

	//PROCESSING - Sort the entire table alphabetically by last name
	tableSort(students, index);

	//PROCESSING - Find the average score
	averageScore = totalScore / index;

	//OUTPUT - The header of the results table
	cout << left << setw(15) << "Last Name" << setw(15) << "First Name"
		 << setw(33) << "StudentID Answers" << right << setw(14)
		 << "% Score Grade\n";

	//OUTPUT - The student's first & last name, ID, their answers, their
	//        percentage score, and their letter grade
	for (int i = 0; i < index; i++)
	{
		cout << fixed << setprecision(1);
		cout << left << setw(15) << students[i].lastName
			 << left << setw(15) << students[i].firstName;
		cout << left << setw(10) << students[i].ids << setw(21)
			 << students[i].answers;
		cout << right << setw(9) << students[i].percentScore << setw(6)
			 << students[i].gradeScore;
		cout << "\n";
	}

	//OUTPUT - The maximum, minimum, and average scores of the class
	cout << fixed << setprecision(1);
	cout << "\n\n";
	cout << "Min score is " << right << setw(5) << minScore
		 << "% for Student ID " << minScoreID << "\n";
	cout << "Max score is " << right << setw(5) << maxScore
		 << "% for Student ID " << maxScoreID << "\n";
	cout << "Average   is " << right << setw(5) << averageScore << "%";

	inFile.close();
	return 0;
}
