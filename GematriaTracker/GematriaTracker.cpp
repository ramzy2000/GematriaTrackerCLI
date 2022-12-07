#include "GematriaTracker.h"

GematriaTracker::GematriaTracker()
{
	while (true)
	{
		std::string argument = ""; // clear the buffer
		std::cout << "Enter string: ";
		std::getline(std::cin, argument); // fill the buffer
		if (argument == "!exit") // check if exit command
		{
			break;
		}
		std::cout << "Result: " << getNumberFromString(argument) << '\n';
	}
}