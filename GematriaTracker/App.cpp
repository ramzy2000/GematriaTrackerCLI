#include "App.h"

App::App()
{
	App::printAppCommands();
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

App::~App()
{

}

void App::printAppCommands()
{
	std::cout << "Welcome to Gematria Calculator" << '\n';
	std::cout << "help - print all commands" << '\n';
	std::cout << "calc - calculate new words" << '\n';
	std::cout << "clear - clear the screen" << '\n';
	std::cout << "exit - close the program" << '\n';
	std::cout << '\n';
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
	else if (input == "HELP")
	{
		App::printAppCommands();
	}
	else
	{
		std::cout << "'" << command << "'" << " not found" << '\n';
	}
}