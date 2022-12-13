#ifndef WORD_REVERSE_SEARCH
#define WORD_REVERSE_SEARCH

#include "../Utilities/Utils.h"
#include "BasicConsole.h"

class WordReverseSearch : public BasicConsole
{
public:
	WordReverseSearch();
	void printCommands();
	void processCommand(const std::string command);
	void reverseSearchWord(std::string word);
};

#endif WORD_REVERSE_SEARCH