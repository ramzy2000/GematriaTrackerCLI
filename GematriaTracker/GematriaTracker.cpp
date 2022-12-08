#include "GematriaTracker.h"

GematriaTracker::GematriaTracker()
{
	system("cls");
	GematriaTracker::printCommands();
	while (true)
	{
		std::string argument = ""; // clear the buffer
		std::cout << "Enter string: ";
		std::getline(std::cin, argument); // fill the buffer
		bool isCommand = true;
		if (argument == "!exit") // check if exit command
		{
			break;
		}
		else if (argument == "!clear")
		{
			system("cls");
		}
		else if (argument == "!help")
		{
			GematriaTracker::printCommands();
		}
		else
		{
			isCommand = false;
		}

		if (!isCommand)
		{
			std::cout << "Result: " << getNumberFromString(argument) << '\n';
		}
	}
}

void GematriaTracker::printCommands() const
{
	std::cout << "Type in the words you want to register" << '\n';
	std::cout << "!clear - clear the screen" << '\n';
	std::cout << "!help - print out commands" << '\n';
	std::cout << "!exit - return back to main menu" << '\n';
	std::cout << '\n';
}