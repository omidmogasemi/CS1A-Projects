/*************************************************************************
 * AUTHOR	  : Omid Mogasemi
 * STUDENT ID : 1093893
 * LAB #4c	  : IF ONLY park
 * CLASS      : CS1A
 * SECTION	  : MTWTh: 10:00a - 1:35p";
 * DUE DATE   : 7/11/2018
 *************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/********************************************************************
 *
 * IF ONLY park
 * __________________________________________________________________
 * This program is designed to help aid in deciding which kids will
 * be taken to which activities and what to buy them for lunch for an
 * amusement park trip. It will prompt the user for information about
 * each of the 10 kids, including their name, age, and whether or not
 * they are vegetarian and if they like cheese. Based on this user
 * input the program will output two statements for each kid, telling
 * the user what rides that kid will be going on and what should be
 * bought for their lunch. After all 10 kids, the program will then
 * output the total cost for the food and park admission as well as
 * the average cost per kid to the user.
 *
 * __________________________________________________________________
 * INPUT:
 * 	name: The name of each kid -> input from user
 *  age: Age of each kid -> input from user
 *  vegetarian: If each kid is vegetarian or not -> input from user
 *  cheese: If each kid likes cheese or not -> input from user
 *
 * OUTPUT:
 *  attractions: What attraction each kid will be going on
 *  foodItem: What food item to buy for each kid
 *  totalCost: The total cost for all 10 kids
 *  averageCost: The average cost per kid
 *
 *******************************************************************/

int main()
{
	//Declare constants for header output
	const char PROGRAMMER[] = "Omid Mogasemi";
	const char CLASS[]       = "CS1A";
	const char SECTION[]    = "MTWTh: 10:00a - 1:35p";
	const char LAB_NUM[]         = "4c";
	const char LAB_NAME[]   = "IF ONLY park";

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
	string name;            //INPUT - Name of each kid
	int age;                //INPUT - Age of each kid
	char vegetarian;        //INPUT - IF each kid is vegetarian
	char cheese;            //INPUT - If each kid wants cheese
	string attractions;     //OUTPUT - What attraction each kid will go on
	string foodItem;        //OUTPUT - What food item to buy for each kid
	double totalCost = 0;   //CALC & OUT - Total cost for all 10 kids
	double averageCost = 0; //CALC & OUT - Average cost per kid

	//OUTPUT - Welcome statement
	cout << "Welcome to the Theme Park Planner! Please input each kid's "
			"information.\n" << endl;

	//OUTPUT & INPUT - Ask for information and take in user responses
	cout << "Kid #1:" << endl;

	cout << left << setw(32) << "What is your kid's name?";
	cin >> name;
	cin.ignore(1000, '\n');

	cout << left << setw(32) << "How old is the kid?";
	cin >> age;

	cout << left << setw(32) << "Vegetarian (Y/N)?";
	cin >> vegetarian;

	cout << left << setw(32) << "Does he/she like cheese (Y/N)?";
	cin >> cheese;

	//Determine what attractions the first kid will be going on
	if (age < 5)
	{
		attractions = "Ferris Wheel and will be visiting the Sheep "
				      "Petting Zoo.";
	}
	else if ((age >= 5) && (age <= 12))
	{
		attractions = "Tea Cups and will be playing Laser Tag.";
		totalCost += 15;
	}
	else if (age > 12)
	{
		attractions = "Roller Coaster and the Zip Line.";
		totalCost += 20;
	}

	//Determine what food items to pack for the first kid
	if (vegetarian == 'N')
	{
		if (cheese == 'Y')
		{
			foodItem = "Cheeseburger";
			totalCost += 3.50;
		}
		if (cheese == 'N')
		{
			foodItem = "Hamburger";
			totalCost += 3.25;
		}
	}
	else
	{
		if (cheese == 'Y')
		{
			foodItem = "Cheese Pizza";
			totalCost += 2.50;
		}
		else
		{
			foodItem = "Happy Garden meal";
			totalCost += 1.75;
		}
	}

	//OUTPUT - What attractions and food the second kid will be having
	cout << "\n" << name << " will be going on the " << attractions << endl;
	cout << "Pack a " << foodItem << " for " << name << "!" << endl;


	//OUTPUT & INPUT - Ask for information and take in user responses
	cout << "\n\n\nKid #2:" << endl;

	cout << left << setw(32) << "What is your kid's name?";
	cin >> name;
	cin.ignore(1000, '\n');

	cout << left << setw(32) << "How old is the kid?";
	cin >> age;

	cout << left << setw(32) << "Vegetarian (Y/N)?";
	cin >> vegetarian;

	cout << left << setw(32) << "Does he/she like cheese (Y/N)?";
	cin >> cheese;

	//Determine what attractions the second kid will be going on
	if (age < 5)
	{
		attractions = "Ferris Wheel and will be visiting the Sheep "
				       "Petting Zoo.";
	}
	else if ((age >= 5) && (age <= 12))
	{
		attractions = "Tea Cups and will be playing Laser Tag.";
		totalCost += 15;
	}
	else if (age > 12)
	{
		attractions = "Roller Coaster and the Zip Line.";
		totalCost += 20;
	}

	//Determine what food items to pack for the second kid
	if (vegetarian == 'N')
	{
		if (cheese == 'Y')
		{
			foodItem = "Cheeseburger";
			totalCost += 3.50;
		}
		if (cheese == 'N')
		{
			foodItem = "Hamburger";
			totalCost += 3.25;
		}
	}
	else
	{
		if (cheese == 'Y')
		{
			foodItem = "Cheese Pizza";
			totalCost += 2.50;
		}
		else
		{
			foodItem = "Happy Garden meal";
			totalCost += 1.75;
		}
	}

	//OUTPUT - What attractions and food the second kid will be having
	cout << "\n" << name << " will be going on the " << attractions << endl;
	cout << "Pack a " << foodItem << " for " << name << "!" << endl;


	//OUTPUT & INPUT - Ask for information and take in user responses
	cout << "\n\n\nKid #3:" << endl;

	cout << left << setw(32) << "What is your kid's name?";
	cin >> name;
	cin.ignore(1000, '\n');

	cout << left << setw(32) << "How old is the kid?";
	cin >> age;

	cout << left << setw(32) << "Vegetarian (Y/N)?";
	cin >> vegetarian;

	cout << left << setw(32) << "Does he/she like cheese (Y/N)?";
	cin >> cheese;

	//Determine what attractions the third kid will be going on
	if (age < 5)
	{
		attractions = "Ferris Wheel and will be visiting the Sheep "
				      "Petting Zoo.";
	}
	else if ((age >= 5) && (age <= 12))
	{
		attractions = "Tea Cups and will be playing Laser Tag.";
		totalCost += 15;
	}
	else if (age > 12)
	{
		attractions = "Roller Coaster and the Zip Line.";
		totalCost += 20;
	}

	//Determine what food items to pack for the third kid
	if (vegetarian == 'N')
	{
		if (cheese == 'Y')
		{
			foodItem = "Cheeseburger";
			totalCost += 3.50;
		}
		if (cheese == 'N')
		{
			foodItem = "Hamburger";
			totalCost += 3.25;
		}
	}
	else
	{
		if (cheese == 'Y')
		{
			foodItem = "Cheese Pizza";
			totalCost += 2.50;
		}
		else
		{
			foodItem = "Happy Garden meal";
			totalCost += 1.75;
		}
	}

	//OUTPUT - What attractions and food the third kid will be having
	cout << "\n" << name << " will be going on the " << attractions << endl;
	cout << "Pack a " << foodItem << " for " << name << "!" << endl;


	//OUTPUT & INPUT - Ask for information and take in user responses
	cout << "\n\n\nKid #4:" << endl;

	cout << left << setw(32) << "What is your kid's name?";
	cin >> name;
	cin.ignore(1000, '\n');

	cout << left << setw(32) << "How old is the kid?";
	cin >> age;

	cout << left << setw(32) << "Vegetarian (Y/N)?";
	cin >> vegetarian;

	cout << left << setw(32) << "Does he/she like cheese (Y/N)?";
	cin >> cheese;

	//Determine what attractions the fourth kid will be going on
	if (age < 5)
	{
		attractions = "Ferris Wheel and will be visiting the Sheep "
				      "Petting Zoo.";
	}
	else if ((age >= 5) && (age <= 12))
	{
		attractions = "Tea Cups and will be playing Laser Tag.";
		totalCost += 15;
	}
	else if (age > 12)
	{
		attractions = "Roller Coaster and the Zip Line.";
		totalCost += 20;
	}

	//Determine what food items to pack for the fourth kid
	if (vegetarian == 'N')
	{
		if (cheese == 'Y')
		{
			foodItem = "Cheeseburger";
			totalCost += 3.50;
		}
		else
		{
			foodItem = "Hamburger";
			totalCost += 3.25;
		}
	}
	else
	{
		if (cheese == 'Y')
		{
			foodItem = "Cheese Pizza";
			totalCost += 2.50;
		}
		else
		{
			foodItem = "Happy Garden meal";
			totalCost += 1.75;
		}
	}

	//OUTPUT - What attractions and food the fourth kid will be having
	cout << "\n" << name << " will be going on the " << attractions << endl;
	cout << "Pack a " << foodItem << " for " << name << "!" << endl;


	//OUTPUT & INPUT - Ask for information and take in user responses
	cout << "\n\n\nKid #5:" << endl;

	cout << left << setw(32) << "What is your kid's name?";
	cin >> name;
	cin.ignore(1000, '\n');

	cout << left << setw(32) << "How old is the kid?";
	cin >> age;

	cout << left << setw(32) << "Vegetarian (Y/N)?";
	cin >> vegetarian;

	cout << left << setw(32) << "Does he/she like cheese (Y/N)?";
	cin >> cheese;

	//Determine what attractions the fifth kid will be going on
	if (age < 5)
	{
		attractions = "Ferris Wheel and will be visiting the Sheep "
				      "Petting Zoo.";
	}
	else if ((age >= 5) && (age <= 12))
	{
		attractions = "Tea Cups and will be playing Laser Tag.";
		totalCost += 15;
	}
	else if (age > 12)
	{
		attractions = "Roller Coaster and the Zip Line.";
		totalCost += 20;
	}

	//Determine what food items to pack for the fifth kid
	if (vegetarian == 'N')
	{
		if (cheese == 'Y')
		{
			foodItem = "Cheeseburger";
			totalCost += 3.50;
		}
		if (cheese == 'N')
		{
			foodItem = "Hamburger";
			totalCost += 3.25;
		}
	}
	else
	{
		if (cheese == 'Y')
		{
			foodItem = "Cheese Pizza";
			totalCost += 2.50;
		}
		else
		{
			foodItem = "Happy Garden meal";
			totalCost += 1.75;
		}
	}

	//OUTPUT - What attractions and food the fifth kid will be having
	cout << "\n" << name << " will be going on the " << attractions << endl;
	cout << "Pack a " << foodItem << " for " << name << "!" << endl;


	//OUTPUT & INPUT - Ask for information and take in user responses
	cout << "\n\n\nKid #6:" << endl;

	cout << left << setw(32) << "What is your kid's name?";
	cin >> name;
	cin.ignore(1000, '\n');

	cout << left << setw(32) << "How old is the kid?";
	cin >> age;

	cout << left << setw(32) << "Vegetarian (Y/N)?";
	cin >> vegetarian;

	cout << left << setw(32) << "Does he/she like cheese (Y/N)?";
	cin >> cheese;

	//Determine what attractions the sixth kid will be going on
	if (age < 5)
	{
		attractions = "Ferris Wheel and will be visiting the Sheep "
				      "Petting Zoo.";
	}
	else if ((age >= 5) && (age <= 12))
	{
		attractions = "Tea Cups and will be playing Laser Tag.";
		totalCost += 15;
	}
	else if (age > 12)
	{
		attractions = "Roller Coaster and the Zip Line.";
		totalCost += 20;
	}

	//Determine what food items to pack for the sixth kid
	if (vegetarian == 'N')
	{
		if (cheese == 'Y')
		{
			foodItem = "Cheeseburger";
			totalCost += 3.50;
		}
		if (cheese == 'N')
		{
			foodItem = "Hamburger";
			totalCost += 3.25;
		}
	}
	else
	{
		if (cheese == 'Y')
		{
			foodItem = "Cheese Pizza";
			totalCost += 2.50;
		}
		else
		{
			foodItem = "Happy Garden meal";
			totalCost += 1.75;
		}
	}

	//OUTPUT - What attractions and food the sixth kid will be having
	cout << "\n" << name << " will be going on the " << attractions << endl;
	cout << "Pack a " << foodItem << " for " << name << "!" << endl;


	//OUTPUT & INPUT - Ask for information and take in user responses
	cout << "\n\n\nKid #7:" << endl;

	cout << left << setw(32) << "What is your kid's name?";
	cin >> name;
	cin.ignore(1000, '\n');

	cout << left << setw(32) << "How old is the kid?";
	cin >> age;

	cout << left << setw(32) << "Vegetarian (Y/N)?";
	cin >> vegetarian;

	cout << left << setw(32) << "Does he/she like cheese (Y/N)?";
	cin >> cheese;

	//Determine what attractions the seventh kid will be going on
	if (age < 5)
	{
		attractions = "Ferris Wheel and will be visiting the Sheep "
				      "Petting Zoo.";
	}
	else if ((age >= 5) && (age <= 12))
	{
		attractions = "Tea Cups and will be playing Laser Tag.";
		totalCost += 15;
	}
	else if (age > 12)
	{
		attractions = "Roller Coaster and the Zip Line.";
		totalCost += 20;
	}

	//Determine what food items to pack for the seventh kid
	if (vegetarian == 'N')
	{
		if (cheese == 'Y')
		{
			foodItem = "Cheeseburger";
			totalCost += 3.50;
		}
		if (cheese == 'N')
		{
			foodItem = "Hamburger";
			totalCost += 3.25;
		}
	}
	else
	{
		if (cheese == 'Y')
		{
			foodItem = "Cheese Pizza";
			totalCost += 2.50;
		}
		else
		{
			foodItem = "Happy Garden meal";
			totalCost += 1.75;
		}
	}

	//OUTPUT - What attractions and food the seventh kid will be having
	cout << "\n" << name << " will be going on the " << attractions << endl;
	cout << "Pack a " << foodItem << " for " << name << "!" << endl;


	//OUTPUT & INPUT - Ask for information and take in user responses
	cout << "\n\n\nKid #8:" << endl;

	cout << left << setw(32) << "What is your kid's name?";
	cin >> name;
	cin.ignore(1000, '\n');

	cout << left << setw(32) << "How old is the kid?";
	cin >> age;

	cout << left << setw(32) << "Vegetarian (Y/N)?";
	cin >> vegetarian;

	cout << left << setw(32) << "Does he/she like cheese (Y/N)?";
	cin >> cheese;

	//Determine what attractions the eighth kid will be going on
	if (age < 5)
	{
		attractions = "Ferris Wheel and will be visiting the Sheep "
				      "Petting Zoo.";
	}
	else if ((age >= 5) && (age <= 12))
	{
		attractions = "Tea Cups and will be playing Laser Tag.";
		totalCost += 15;
	}
	else if (age > 12)
	{
		attractions = "Roller Coaster and the Zip Line.";
		totalCost += 20;
	}

	//Determine what food items to pack for the eighth kid
	if (vegetarian == 'N')
	{
		if (cheese == 'Y')
		{
			foodItem = "Cheeseburger";
			totalCost += 3.50;
		}
		if (cheese == 'N')
		{
			foodItem = "Hamburger";
			totalCost += 3.25;
		}
	}
	else
	{
		if (cheese == 'Y')
		{
			foodItem = "Cheese Pizza";
			totalCost += 2.50;
		}
		else
		{
			foodItem = "Happy Garden meal";
			totalCost += 1.75;
		}
	}

	//OUTPUT - What attractions and food the eighth kid will be having
	cout << "\n" << name << " will be going on the " << attractions << endl;
	cout << "Pack a " << foodItem << " for " << name << "!" << endl;


	//OUTPUT & INPUT - Ask for information and take in user responses
	cout << "\n\n\nKid #9:" << endl;

	cout << left << setw(32) << "What is your kid's name?";
	cin >> name;
	cin.ignore(1000, '\n');

	cout << left << setw(32) << "How old is the kid?";
	cin >> age;

	cout << left << setw(32) << "Vegetarian (Y/N)?";
	cin >> vegetarian;

	cout << left << setw(32) << "Does he/she like cheese (Y/N)?";
	cin >> cheese;

	//Determine what attractions the ninth kid will be going on
	if (age < 5)
	{
		attractions = "Ferris Wheel and will be visiting the Sheep "
				      "Petting Zoo.";
	}
	else if ((age >= 5) && (age <= 12))
	{
		attractions = "Tea Cups and will be playing Laser Tag.";
		totalCost += 15;
	}
	else if (age > 12)
	{
		attractions = "Roller Coaster and the Zip Line.";
		totalCost += 20;
	}

	//Determine what food items to pack for the ninth kid
	if (vegetarian == 'N')
	{
		if (cheese == 'Y')
		{
			foodItem = "Cheeseburger";
			totalCost += 3.50;
		}
		if (cheese == 'N')
		{
			foodItem = "Hamburger";
			totalCost += 3.25;
		}
	}
	else
	{
		if (cheese == 'Y')
		{
			foodItem = "Cheese Pizza";
			totalCost += 2.50;
		}
		else
		{
			foodItem = "Happy Garden meal";
			totalCost += 1.75;
		}
	}

	//OUTPUT - What attractions and food the ninth kid will be having
	cout << "\n" << name << " will be going on the " << attractions << endl;
	cout << "Pack a " << foodItem << " for " << name << "!" << endl;


	//OUTPUT & INPUT - Ask for information and take in user responses
	cout << "\n\n\nKid #10:" << endl;

	cout << left << setw(32) << "What is your kid's name?";
	cin >> name;
	cin.ignore(1000, '\n');

	cout << left << setw(32) << "How old is the kid?";
	cin >> age;

	cout << left << setw(32) << "Vegetarian (Y/N)?";
	cin >> vegetarian;

	cout << left << setw(32) << "Does he/she like cheese (Y/N)?";
	cin >> cheese;

	//Determine what attractions the tenth kid will be going on
	if (age < 5)
	{
		attractions = "Ferris Wheel and will be visiting the Sheep "
				      "Petting Zoo.";
	}
	else if ((age >= 5) && (age <= 12))
	{
		attractions = "Tea Cups and will be playing Laser Tag.";
		totalCost += 15;
	}
	else if (age > 12)
	{
		attractions = "Roller Coaster and the Zip Line.";
		totalCost += 20;
	}

	//Determine what food items to pack for the tenth kid
	if (vegetarian == 'N')
	{
		if (cheese == 'Y')
		{
			foodItem = "Cheeseburger";
			totalCost += 3.50;
		}
		if (cheese == 'N')
		{
			foodItem = "Hamburger";
			totalCost += 3.25;
		}
	}
	else
	{
		if (cheese == 'Y')
		{
			foodItem = "Cheese Pizza";
			totalCost += 2.50;
		}
		else
		{
			foodItem = "Happy Garden meal";
			totalCost += 1.75;
		}
	}

	//OUTPUT - What attractions and food the tenth kid will be having
	cout << "\n" << name << " will be going on the " << attractions << endl;
	cout << "Pack a " << foodItem << " for " << name << "!" << "\n\n\n\n"
		 << endl;

	//PROCESSING - Initialize the average cost per kid
	averageCost = totalCost / 10;

	//OUTPUT - The total and average costs
	cout << fixed << setprecision(2);
	cout << left << setw(35) << "\nThe total cost for the day is:" << "$" <<
		right << setw(6) << totalCost;
	cout << left << setw(35) << "\nThe average cost per kid is:" << "$" <<
		right << setw(6) << averageCost;

	return 0;

}
