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

		if (!isCommand && argument != "")
		{
			int aggString = getNumberFromString(argument);

			// convert the number into string and append
			// .txt to it.
			std::string fileName = "data/";
			fileName += std::to_string(aggString);
			fileName += ".txt";

			// check if the file exists
			if (std::filesystem::exists(fileName))
			{
				// check if the string is already in the file
				// if its not then append it to the file

				WordReader wordReader(fileName);
				if (!wordReader.wordExists(argument))
				{
					wordReader.appendWord(argument);
					std::cout << "Word Added" << '\n';
				}
			}
			else
			{
				// generate the file and append the string to it.
				std::fstream file;
				file.open(fileName, std::ios::out);
				file.close();

				WordReader wordReader(fileName);
				wordReader.appendWord(argument);
				std::cout << "Word Added" << '\n';
				std::cout << "Generated New File" << '\n';
			}

			std::cout << "Result: " << aggString << '\n';
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