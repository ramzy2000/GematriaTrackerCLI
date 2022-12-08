#ifndef APP_H
#define APP_H

#include <iostream>
#include <string>
#include <string_view>
#include <filesystem>
#include <fstream>
#include "Utils.h"
#include "GematriaTracker.h"

/// <summary>
/// Add a first time run feature that will create the files when 
/// first time run
/// </summary>

class App
{
public:
	/// <summary>
	/// Determines if the app loop is to terminate
	/// </summary>
	bool isConsoleLoop = true;

	/// <summary>
	/// Print out the commands that are used
	/// in the application layer.
	/// </summary>
	void printAppCommands();

	/// <summary>
	/// Process the application layer commands
	/// </summary>
	/// <param name="command"></param>
	void processCommand(const std::string_view command);

	bool isFirstRun();

	App();

	~App();
};

#endif // APP_H