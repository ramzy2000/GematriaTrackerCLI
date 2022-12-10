#ifndef GEMATRIA_FILE_SCANNER
#define GEMATRIA_FILE_SCANNER

#include <iostream>
#include <string>
#include "ClearScreen.h"
#include "Utils.h"
#include "BasicConsole.h"

class GematriaFileScanner : public BasicConsole
{
public:
	GematriaFileScanner();

	void printCommands() override;

	void processCommand(const std::string command) override;
};

#endif GEMATRIA_FILE_SCANNER