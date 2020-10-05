#include "HeateronEngineDLL.h"
#include <cstdlib>

void fatal_error(const char* msg)
{
	MessageBoxA(NULL, msg, "Error", MB_OK | MB_ICONEXCLAMATION);
	exit(EXIT_FAILURE);
}