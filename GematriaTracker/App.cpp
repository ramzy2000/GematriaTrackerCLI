#include "App.h"

App::App()
{
	std::string command = "";
	while (isConsoleLoop)
	{
		command = ""; // clear the command buffer
		// promt the user for a command
		std::cout << "prompt>";
		std::getline(std::cin, command);

		this->processCommand(command);
	}
}

void printAppCommands()
{
	std::cout << "Welcome to Gematria Calculator" << '\n';
}

void App::test01()
{
	while (true)
	{
		std::string argument = "";
		std::cout << "Enter string: ";
		std::getline(std::cin, argument);
		if (argument == "!exit")
		{
			break;
		}
		std::cout << "Result: " << getNumberFromString(argument) << '\n';
	}
}

void App::processCommand(const std::string_view command)
{
	// convert string into caps
	std::string input = toUppercase(command);
	if (input == "EXIT")
	{
		isConsoleLoop = false;
	}
	else if (input == "CLEAR")
	{
		system("cls");
	}
	else if (input == "CALC")
	{
		GematriaTracker gematriaTracker;
	}
	else
	{
		std::cout << "'" << command << "'" << " not found" << '\n';
	}
}