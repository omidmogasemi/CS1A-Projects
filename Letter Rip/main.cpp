#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	string inString;
	string trimString = "";
	string resultString = "";
	bool flag = false;

	cout << "Please enter the word(s) you'd like to convert: ";
	getline(cin, inString);

	for (unsigned int i = 0; i < inString.length(); i++)
	{
		if (inString[i] != ' ')
		{
			trimString += toupper(inString[i]);
		}
	}

	while (trimString[0] != '#')
	{
		if (trimString.length() < 7)
		{
			inString = "";
			trimString = "";
			resultString = "";
			flag = false;

			cout << "String length too short. Please try again.";
			getline(cin, inString);

			for (unsigned int i = 0; i < inString.length(); i++)
			{
			if (inString[i] != ' ')
			{
				trimString += toupper(inString[i]);
			}
			}
			continue;
		}
		if (trimString.length() > 8)
		{
			cout << "Warning, this word exceeds 8 characters. Proceeding...\n";
		}
		for (int i = 0; i < 7; i++)
		{
			if (i == 3)
			{
				resultString += "-";
			}

			switch (trimString[i])
			{
			case 'A':
			case 'B':
			case 'C':
				resultString += "2";
				break;
			case 'D':
			case 'E':
			case 'F':
				resultString += "3";
				break;
			case 'G':
			case 'H':
			case 'I':
				resultString += "4";
				break;
			case 'J':
			case 'K':
			case 'L':
				resultString += "5";
				break;
			case 'M':
			case 'N':
			case 'O':
				resultString += "6";
				break;
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
				resultString += "7";
				break;
			case 'T':
			case 'U':
			case 'V':
				resultString += "8";
				break;
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
				resultString += "9";
				break;
			case '0':
				resultString += "0";
				break;
			case '1':
				resultString += "1";
				break;
			case '2':
				resultString += "2";
				break;
			case '3':
				resultString += "3";
				break;
			case '4':
				resultString += "4";
				break;
			case '5':
				resultString += "5";
				break;
			case '6':
				resultString += "6";
				break;
			case '7':
				resultString += "7";
				break;
			case '8':
				resultString += "8";
				break;
			case '9':
				resultString += "9";
				break;
			default:
				flag = true;
			}
		}

		if (flag)
		{
			cout << "Error, invalid input. Please try again" << endl;
		}
		else
		{
			cout << "Your number is: " << resultString << endl;
		}

		inString = "";
		trimString = "";
		resultString = "";
		flag = false;

		cout << "Please enter the word(s) you'd like to convert: ";
		getline(cin, inString);

		for (unsigned int i = 0; i < inString.length(); i++)
		{
			if (inString[i] != ' ')
			{
				trimString += toupper(inString[i]);
			}
		}

	}

	return 0;
}
