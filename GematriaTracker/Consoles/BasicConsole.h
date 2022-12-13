#ifndef BASIC_CONSOLE
#define BASIC_CONSOLE

#include "../Utilities/ClearScreen.h"

class BasicConsole
{
private:
	BasicConsole(BasicConsole&) {}
	void operator=(BasicConsole&) {}
protected:
	/// <summary>
	/// Determines if the app loop is to terminate
	/// </summary>
	bool isConsoleLoop = true;
public:
	BasicConsole() {}
	virtual void printCommands() = 0;
	virtual void processCommand(const std::string command) = 0;
};

#endif //BASIC_CONSOLE