#ifndef APP_H
#define APP_H

#include <iostream>
#include <string>
#include <string_view>
#include "Utils.h"
#include "GematriaTracker.h"

class App
{
public:
	bool isConsoleLoop = true;

	void printAppCommands();

	void processCommand(const std::string_view command);

	App();

	void test01();
};

#endif // APP_H