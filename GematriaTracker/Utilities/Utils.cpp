#include "Utils.h"

/// <summary>
/// Convert a string to a upper case string
/// </summary>
/// <param name="str"></param>
/// <returns></returns>
std::string toUppercase(std::string_view str)
{
	std::string res = "";
	for (int i = 0; i < str.length(); i++)
	{
		char c = std::toupper(str[i]);
		res += c;
	}

	return res;
}

/// <summary>
/// function that takes in a string and returns the
/// get the numbers from the string and add them together.
/// </summary>
/// <returns>Total added numbers</returns>
int getNumberFromString(std::string str)
{
	int totalCount = 0;
	for (int i = 0; i < str.length(); i++)
	{
		char character = str[i];
		// convert string to uppercase
		character = char(std::toupper(character));
		switch (character)
		{
		case 'A':
			totalCount = totalCount + 1;
			break;
		case 'B':
			totalCount = totalCount + 2;
			break;
		case 'C':
			totalCount = totalCount + 3;
			break;
		case 'D':
			totalCount = totalCount + 4;
			break;
		case 'E':
			totalCount = totalCount + 5;
			break;
		case 'F':
			totalCount = totalCount + 6;
			break;
		case 'G':
			totalCount = totalCount + 7;
			break;
		case 'H':
			totalCount = totalCount + 8;
			break;
		case 'I':
			totalCount = totalCount + 9;
			break;
		case 'J':
			totalCount = totalCount + 10;
			break;
		case 'K':
			totalCount = totalCount + 11;
			break;
		case 'L':
			totalCount = totalCount + 12;
			break;
		case 'M':
			totalCount = totalCount + 13;
			break;
		case 'N':
			totalCount = totalCount + 14;
			break;
		case 'O':
			totalCount = totalCount + 15;
			break;
		case 'P':
			totalCount = totalCount + 16;
			break;
		case 'Q':
			totalCount = totalCount + 17;
			break;
		case 'R':
			totalCount = totalCount + 18;
			break;
		case 'S':
			totalCount = totalCount + 19;
			break;
		case 'T':
			totalCount = totalCount + 20;
			break;
		case 'U':
			totalCount = totalCount + 21;
			break;
		case 'V':
			totalCount = totalCount + 22;
			break;
		case 'W':
			totalCount = totalCount + 23;
			break;
		case 'X':
			totalCount = totalCount + 24;
			break;
		case 'Y':
			totalCount = totalCount + 25;
			break;
		case 'Z':
			totalCount = totalCount + 26;
			break;
		default:
			break;
		}
	}

	return totalCount;
}

std::string reverseString(const std::string str)
{
	std::string res = "";
	for (int i = str.length() - 1; i >= 0; i--)
	{
		res += str[i];
	}
	return res;
}