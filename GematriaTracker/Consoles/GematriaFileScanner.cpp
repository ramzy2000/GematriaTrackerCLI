#include "GematriaFileScanner.h"

GematriaFileScanner::GematriaFileScanner()
{
	ClearScreen();
	printCommands();

	std::string command = "";

	while (isConsoleLoop)
	{
		command = ""; // clear the command buffer
		// promt the user for a command
		std::cout << "scanner>";
		std::getline(std::cin, command);

		this->processCommand(command);
	}
}

void GematriaFileScanner::printCommands()
{
	std::cout << "Welcome to Gematria File Scanner" << '\n';
	std::cout << '\n';
}

void GematriaFileScanner::processCommand(const std::string command)
{
	// convert string into caps
	std::string input = toUppercase(command);
	if (input == "EXIT")
	{
		isConsoleLoop = false;
	}
	else
	{
		std::cout << "'" << command << "'" << " not found" << '\n';
		std::cout << "type 'help' to get help with commands" << '\n';
	}
}