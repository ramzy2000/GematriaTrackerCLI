#include "GematriaTracker.h"

GematriaTracker::GematriaTracker()
{
	ClearScreen();
	GematriaTracker::printCommands();

	std::string command = "";
	while (isConsoleLoop)
	{
		command = ""; // clear the command buffer
		// promt the user for a command
		std::cout << "Enter string: ";
		std::getline(std::cin, command);

		this->processCommand(command);
	}
}

void GematriaTracker::printCommands()
{
	std::cout << "Type in the words you want to register" << '\n';
	std::cout << "!clear - clear the screen" << '\n';
	std::cout << "!help - print out commands" << '\n';
	std::cout << "!exit - return back to main menu" << '\n';
	std::cout << '\n';
}

void GematriaTracker::processCommand(const std::string command)
{
	bool isCommand = true;
	if (command == "!exit") // check if exit command
	{
		isConsoleLoop = false;
	}
	else if (command == "!clear")
	{
		ClearScreen();
	}
	else if (command == "!help")
	{
		GematriaTracker::printCommands();
	}
	else
	{
		isCommand = false;
	}

	if (!isCommand && command != "")
	{
		int aggStringNum = getNumberFromString(command);

		// Set up file path based off resulting number
		std::string fileName = "data/";
		fileName += std::to_string(aggStringNum);
		fileName += ".txt";

		// check if the file exists
		if (std::filesystem::exists(fileName))
		{
			WordReader wordReader(fileName); // read file
			if (!wordReader.wordExists(command))
			{
				wordReader.appendWord(command);
				std::cout << "Word Added" << '\n';
			}
		}
		else
		{
			// generate the file and append the string to it.
			std::fstream file;
			file.open(fileName, std::ios::out);
			file.close();

			// append the word
			WordReader wordReader(fileName);
			wordReader.appendWord(command);
			std::cout << "Word Added" << '\n';
			std::cout << "Generated New File" << '\n';
		}

		std::cout << "Result: " << aggStringNum << '\n'; 
	}
}