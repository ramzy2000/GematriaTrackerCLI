#include "GematriaFileScanner.h"

GematriaFileScanner::GematriaFileScanner()
{
	ClearScreen();
	printCommands();

	std::string command = "";

	while (isConsoleLoop)
	{
		command = ""; // clear the command buffer
		// promt the user for a command
		std::cout << "scanner>";
		std::getline(std::cin, command);

		this->processCommand(command);
	}
}

void GematriaFileScanner::printCommands()
{
	std::cout << "Welcome to Gematria File Scanner" << '\n';
	std::cout << "create - create a new folder for generateing reports and scanning text files." << '\n';
	std::cout << "generate - scan a text file from folder name" << '\n';
	std::cout << '\n';
}

void GematriaFileScanner::processCommand(const std::string command)
{
	// convert string into caps
	std::string input = toUppercase(command);
	if (input == "EXIT")
	{
		isConsoleLoop = false;
	}
	else if (input == "CREATE") // create a new word report
	{
		std::string input = "";
		ClearScreen();

		auto PrintCommands = [] (void)
		{
			std::cout << "Create a new folder to scan a text file." << '\n';
			std::cout << "Commands:" << '\n';
			std::cout << "!exit - exit scanner creator" << '\n';
			std::cout << "!clear - clear the screen" << '\n';
			std::cout << '\n';
		};

		PrintCommands();
		while (true)
		{
			input = ""; // clear the command buffer
		    // promt the user for a command
			std::cout << "Enter Folder Name: ";
			std::getline(std::cin, input);

			bool isCommand = true;

			if (input == "!exit")
			{
				break;
			}
			else if (input == "!help")
			{
				PrintCommands();
			}
			else if (input == "!clear")
			{
				ClearScreen();
			}
			else
			{
				isCommand = false;
			}

			if (!isCommand)
			{
				// process the command
				std::string dir = "scanner_data/";
				dir += input;

				// check if scanner_data/folderName folder path exists or not
				if (!std::filesystem::exists(dir))
				{
					std::cout << "Createing folder named " << input << '\n';
					std::filesystem::create_directories(dir);
				}
				else
				{
					std::cout << "Folder named " << input << " already exists" << '\n';
				}
			}
		}
	}
	else if (input == "GENERATE")
	{
		std::string input = "";
		while (true)
		{
			input = ""; // clear the command buffer
			// promt the user for a command
			std::cout << "Enter Folder Name: ";
			std::getline(std::cin, input);

			bool isCommand = true;

			if (input == "!exit")
			{
				break;
			}
			else
			{
				isCommand = false;
			}

			if (!isCommand)
			{
				// process the command
				std::string root = "scanner_data";
				std::string mainFolder = root + '/' + input; // holds scanner_data/folderName
				std::string dataFolder = mainFolder + '/' + "data"; // data folder
				std::string fileBeingScanned = mainFolder + '/' + input + ".txt"; // file being scanned

				// check if the root folder exits
				if (std::filesystem::exists(mainFolder))
				{
					// make sure the data folder is not already created
					if (!std::filesystem::exists(dataFolder))
					{
						// create the data folder

						std::filesystem::create_directories(dataFolder);

						// read the file and process each
						// word into a number and then create a file in the data
						// folder named after 
						std::fstream file;
						file.open(fileBeingScanned, std::ios::in);

						while (!file.eof())
						{
							std::string line;
							std::getline(file, line);
							if (line == "")
							{
								break;
							}

							std::string& word = line;

							// get the line form the number
							int number = getNumberFromString(line);

							// check if a file with the number name exits
							std::string fileWithNumberName = std::to_string(number) + ".txt";
							std::string path = dataFolder + "/" + fileWithNumberName;
							if (std::filesystem::exists(path))
							{
								// check if the file contains the word
								WordReader wordReader(path);
								if (!wordReader.wordExists(word))
								{
									// append the word to the file
									std::fstream file;
									file.open(path, std::ios::app);
									file << word << '\n';
									file.close();
								}
								else
								{
									std::cout << "Word Already Exists" << '\n';
								}
							}
							else
							{
								// create a new file
								std::fstream file;
								file.open(path, std::ios::out);
								file.close();

								// append the word to the file.
								file.open(path, std::ios::app);
								file << word << '\n';
								file.close();
							}
						}
					}
					else
					{
						std::cout << "data folder already generated" << '\n';
					}
				}
			}
		}
	}
	else
	{
		std::cout << "'" << command << "'" << " not found" << '\n';
		std::cout << "type 'help' to get help with commands" << '\n';
	}
}