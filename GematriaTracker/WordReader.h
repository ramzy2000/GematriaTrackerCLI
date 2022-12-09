#ifndef WORD_READER
#define WORD_READER

#include <string>
#include <fstream>
#include "Utils.h"

class WordReader
{
protected:
	std::string filePath;
	WordReader();
public:
	WordReader(std::string filePath);

	bool wordExists(std::string word);
};

#endif //WORD_READER