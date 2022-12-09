#include "WordReader.h"

WordReader::WordReader() {}

WordReader::WordReader(std::string filePath)
{
	this->filePath = filePath;
}

bool WordReader::wordExists(std::string word)
{
	word = toUppercase(word);
	std::ifstream file;
	file.open("englishdictionary.txt");

	std::string line = "";
	while (!file.eof())
	{
		std::getline(file, line);
		// uppercase the line
		line = toUppercase(line);
		if (line == word)
		{
			file.close();
			return true;
		}
	}

	file.close();
	return false;
}