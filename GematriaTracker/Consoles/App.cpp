#include "App.h"

App::App()
{
	if (!isFirstRun())
	{
		std::cout << "First time running ..." << '\n';
		// generate the data folder
		std::filesystem::create_directories("data");
		std::filesystem::create_directories("scanner_data");
	}

	App::printCommands();
	std::string command = "";
	while (isConsoleLoop)
	{
		command = ""; // clear the command buffer
		// promt the user for a command
		std::cout << "home>";
		std::getline(std::cin, command);

		this->processCommand(command);
	}
}

App::~App()
{

}

bool App::isFirstRun()
{
	if (std::filesystem::exists("scanner_data") 
		&& std::filesystem::exists("data"))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void App::printCommands()
{
	std::cout << "Welcome to Gematria Calculator" << '\n';
	std::cout << "help - print all commands" << '\n';
	std::cout << "calc - calculate new words" << '\n';
	std::cout << "scanner - scan text files to generate numbers" << '\n';
	std::cout << "clear - clear the screen" << '\n';
	std::cout << "exit - close the program" << '\n';
	std::cout << '\n';
}

void App::processCommand(const std::string command)
{
	// convert string into caps
	std::string input = toUppercase(command);
	if (input == "EXIT")
	{
		isConsoleLoop = false;
	}
	else if (input == "CLEAR")
	{
		ClearScreen();
	}
	else if (input == "CALC")
	{
		GematriaTracker gematriaTracker;
	}
	else if (input == "SCANNER")
	{
		GematriaFileScanner gematriaScanner;
	}
	else if (input == "HELP")
	{
		App::printCommands();
	}
	else
	{
		std::cout << "'" << command << "'" << " not found" << '\n';
		std::cout << "type 'help' to get help with commands" << '\n';
	}
}