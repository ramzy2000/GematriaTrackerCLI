/// <summary>
/// Change Log
/// 
/// Programmer: Casey Duffy
/// Date: 12/6/2022
/// Des:Adding a process that will take the resulting number
/// and check IF (file named after the number exists 
/// in the folder called data in the root folder of the project)
/// {
///     IF (string is not alredy in the file)
///     {
///         Take string that was typed in and append it to this file.   
///     }
/// }
/// ELSE
/// {
///     Create a file with the number and 
/// }
/// </summary>

#ifndef GEMATRIA_TRACKER_H
#define GEMATRIA_TRACKER_H

#include <iostream>
#include <string>
#include <filesystem>
#include "ClearScreen.h"
#include "BasicConsole.h"
#include "Utils.h"
#include "WordReader.h"

class GematriaTracker : public BasicConsole
{
public:
	GematriaTracker();

	void printCommands() override;

	void processCommand(const std::string command) override;
};

#endif // GEMATRIA_TRACKER_H