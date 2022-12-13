#include "WordReverseSearch.h"

WordReverseSearch::WordReverseSearch()
{
	ClearScreen();
	printCommands();
	while (isConsoleLoop)
	{
		std::string input = "";
		std::cout << "Enter a word to search backwards: ";
		std::getline(std::cin, input);
		processCommand(input);
	}
}

void WordReverseSearch::printCommands()
{
	std::cout << "Type in a word and google search the word backwards" << '\n';
	std::cout << "!exit - exit this part of the application" << '\n';
	std::cout << '\n';
}
void WordReverseSearch::processCommand(const std::string command)
{
	bool isCommand = true;
	if (command == "!exit")
	{
		isConsoleLoop = false;
	}
	else if (command == "!help")
	{
		printCommands();
	}
	else
	{
		isCommand = false;
	}

	if (!isCommand)
	{
		reverseSearchWord(command);
	}
}

void WordReverseSearch::reverseSearchWord(std::string word)
{
	if (!(word == ""))
	{
		std::string res = reverseString(word);
		std::string url = "start msedge.exe https://www.google.com/search?q=";
		url += res;
		system(url.c_str());
		std::cout << "Searched " << word << " backwards" << '\n';
	}
	else
	{
		std::cout << "Enter a word please" << '\n';
	}
}