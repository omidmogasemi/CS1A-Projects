/*************************************************************************
 * AUTHOR	  : Omid Mogasemi
 * STUDENT ID : 1093893
 * LAB #4b	  : IF ONLY package
 * CLASS      : CS1A
 * SECTION	  : MTWTh: 10:00a - 1:35p";
 * DUE DATE   : 7/9/2018
 *************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/********************************************************************
 *
 * IF ONLY package
 * __________________________________________________________________
 * This program receives the weight of 6 packages via user input and
 * outputs the total number of packages in each of 4 specified weight
 * categories in addition to the total cost for all of the packages
 * to be shipped.
 *
 * __________________________________________________________________
 * INPUT:
 * 	weight1: The weight of the first package -> input from user
 *  weight2: The weight of the second package -> input from user
 *  weight3: The weight of the third package -> input from user
 *  weight4: The weight of the fourth package -> input from user
 *  weight5: The weight of the fifth package -> input from user
 *  weight6: The weight of the sixth package -> input from user
 *
 * OUTPUT:
 *  count1: The amount of packages in the first weight category
 *  count2: The amount of packages in the second weight category
 *  count3: The amount of packages in the third weight category
 *  count4: The amount of packages in the fourth weight category
 * 	totalPrice: The total shipping price
 *
 *******************************************************************/

int main()
{
	//Declare constants for header output
	const char PROGRAMMER[] = "Omid Mogasemi";
	const char CLASS[]      = "CS1A";
	const char SECTION[]    = "MTWTh: 10:00a - 1:35p";
	const char LAB_NUM[]    = "4b";
	const char LAB_NAME[]   = "IF ONLY package";

	//OUTPUT - class heading
	cout << left;
	cout << "***************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* LAB #" << setw(9) << LAB_NUM << ": " << LAB_NAME;
	cout << "\n***************************************\n\n";
	cout << right;

	//Declare variables
	double weight1;        //INPUT - Weight of the first package
	double weight2;        //INPUT - Weight of the second package
	double weight3;        //INPUT - Weight of the third package
	double weight4;        //INPUT - Weight of the fourth package
	double weight5;        //INPUT - Weight of the fifth package
	double weight6;        //INPUT - Weight of the sixth package
	int count1 = 0;        //CALC & OUT - Find totalPrice & packages
	                       //             in weight category 1
	int count2 = 0;        //CALC & OUT - Find totalPrice & packages
                           //             in weight category 2
	int count3 = 0;        //CALC & OUT - Find totalPrice & packages
                           //             in weight category 3
	int count4 = 0;        //CALC & OUT - Find totalPrice & packages
                           //             in weight category 4
	double totalPrice;     //CALC & OUT - Total shipping price
	string packageOutput1; //OUTPUT - If the 1st package category
	                       //         should be plural or not
	string packageOutput2; //OUTPUT - If the 2nd package category
                           //         should be plural or not
	string packageOutput3; //OUTPUT - If the 3rd package category
                           //         should be plural or not
	string packageOutput4; //OUTPUT - If the 4th package category
                           //         should be plural or not

	//OUTPUT - Prompt the user for the six package weights
	cout << "Please input six package weights on separate lines: "
		 << endl;

	//INPUT - All six package weights
	cin >> weight1;
	cin >> weight2;
	cin >> weight3;
	cin >> weight4;
	cin >> weight5;
	cin >> weight6;

	//Check to see which weight category the first package falls into
	if (weight1 <= 2)
		count1++;
	if ((weight1 >= 3) && (weight1 <= 12))
		count2++;
	if ((weight1 >= 13) && (weight1 <= 20))
		count3++;
	if ((weight1 >= 21) && (weight1 <=40))
		count4++;

	//Check to see which weight category the second package falls into
	if (weight2 <= 2)
		count1++;
	if ((weight2 >= 3) && (weight2 <= 12))
		count2++;
	if ((weight2 >= 13) && (weight2 <= 20))
		count3++;
	if ((weight2 >= 21) && (weight2 <=40))
		count4++;

	//Check to see which weight category the third package falls into
	if (weight3 <= 2)
		count1++;
	if ((weight3 >= 3) && (weight3 <= 12))
		count2++;
	if ((weight3 >= 13) && (weight3 <= 20))
		count3++;
	if ((weight3 >= 21) && (weight3 <=40))
		count4++;

	//Check to see which weight category the fourth package falls into
	if (weight4 <= 2)
		count1++;
	if ((weight4 >= 3) && (weight4 <= 12))
		count2++;
	if ((weight4 >= 13) && (weight4 <= 20))
		count3++;
	if ((weight4 >= 21) && (weight4 <=40))
		count4++;

	//Check to see which weight category the fifth package falls into
	if (weight5 <= 2)
		count1++;
	if ((weight5 >= 3) && (weight5 <= 12))
		count2++;
	if ((weight5 >= 13) && (weight5 <= 20))
		count3++;
	if ((weight5 >= 21) && (weight5 <=40))
		count4++;

	//Check to see which weight category the sixth package falls into
	if (weight6 <= 2)
		count1++;
	if ((weight6 >= 3) && (weight6 <= 12))
		count2++;
	if ((weight6 >= 13) && (weight6 <= 20))
		count3++;
	if ((weight6 >= 21) && (weight6 <=40))
		count4++;

	//Check to see if package is singular or plural for category 1
	if ((count1 == 0) || (count1 >= 2))
		packageOutput1 = "packages";
	else
		packageOutput1 = "package";

	//Check to see if package is singular or plural for category 2
	if ((count2 == 0) || (count2 >= 2))
		packageOutput2 = "packages";
	else
		packageOutput2 = "package";

	//Check to see if package is singular or plural for category 3
	if ((count3 == 0) || (count3 >= 2))
		packageOutput3 = "packages";
	else
		packageOutput3 = "package";

	//Check to see if package is singular or plural for category 4
	if ((count4 == 0) || (count4 >= 2))
		packageOutput4 = "packages";
	else
		packageOutput4 = "package";

	//PROCESSING - Assign totalPrice to a value
	totalPrice = (count1 * 5.00) + (count2 * 8.50) + (count3 * 12.50) +
				 (count4 * 18.00);

	//OUTPUT - All 4 package categories and the total shipping price
	cout << "\n" << count1 << " " << packageOutput1
		 <<	" 2 lbs. or less" << endl;
	cout << count2 << " " << packageOutput2 << " between 3 - 12 lbs."
		 << endl;
	cout << count3 << " " << packageOutput3 << " between 13 - 20 lbs."
		 << endl;
	cout << count4 << " " << packageOutput4 << " between 21 - 40 lbs."
		 << endl;
	cout << fixed << setprecision(2);
	cout << "The total shipping price is $" << totalPrice
		 << endl;

	return 0;

}
