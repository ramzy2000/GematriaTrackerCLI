#include "fileTools.h"

// sort a file alphabetically
void sortTextFileAphabetically(const std::string filePath)
{
	// load files lines into a vector
	std::vector<std::string> vector;
	std::fstream file;
	file.open(filePath, std::ios::in);
	std::string line = "";
	if (!file.fail())
	{
		while (!file.eof())
		{
			line = "";
			std::getline(file, line);
			vector.push_back(line);
		}
		file.close();

		// sort the vector alphabetically
		alphabeticallySort(vector);

		// override the data in the text file with the new vector data
		file.open(filePath, std::ios::out);
		for (int i = 0; i < vector.size(); i++)
		{
			line = "";
			line = vector.at(i);

			file << line << '\n';
		}
		file.close();
	}
	else
	{
		file.close();
		throw "Excetion thrown fileTools.h sortTextFileAphabetically::file_not_found.";
	}
}