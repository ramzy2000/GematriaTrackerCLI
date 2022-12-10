#include "ClearScreen.h"

void ClearScreen()
{
#ifdef WINDOWS
	system("cls");
#endif
#ifdef LINUX
	system("clear");
#endif
}