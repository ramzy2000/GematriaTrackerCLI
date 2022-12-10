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
	file.open(filePath);

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

// append a word to the file
void WordReader::appendWord(std::string_view word)
{
	std::fstream file;
	file.open(filePath, std::ios::app); // open the file
	if (file.fail()) {
		file.close();
		throw "Error WordReader::appendWord() failed to open file";
	}

	file << word << '\n';
	file.close();
}