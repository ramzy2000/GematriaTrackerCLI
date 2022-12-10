#ifndef APP_H
#define APP_H

#include <iostream>
#include <string>
#include <string_view>
#include <filesystem>
#include <fstream>
#include "ClearScreen.h"
#include "BasicConsole.h"
#include "Utils.h"
#include "GematriaTracker.h"
#include "GematriaFileScanner.h"

/// <summary>
/// Add a first time run feature that will create the files when 
/// first time run
/// </summary>

class App : BasicConsole
{
public:
	/// <summary>
	/// Print out the commands that are used
	/// in the application layer.
	/// </summary>
	void printCommands() override;

	/// <summary>
	/// Process the application layer commands
	/// </summary>
	/// <param name="command"></param>
	void processCommand(const std::string command) override;

	bool isFirstRun();

	App();

	~App();
};

#endif // APP_H