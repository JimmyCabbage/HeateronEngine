#include "HeateronEngineDLL.h"
#include "framework.h"

#include "MainWindow.h"

IMainWindow* CreateMainWindow()
{
	return new MainWindow();
}
void DestroyMainWindow(IMainWindow* window)
{
	delete window;
}