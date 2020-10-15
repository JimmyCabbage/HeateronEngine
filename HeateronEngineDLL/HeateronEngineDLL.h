#ifndef HEATERONENGINEDLL_H
#define HEATERONENGINEDLL_H

#ifndef UNICODE
#define UNICODE
#endif

#ifdef HEATERONENGINEDLL_EXPORTS
#define HEATERONENGINE_API __declspec(dllexport)
#define GLAD_GLAPI_EXPORT_BUILD
#else
#define HEATERONENGINE_API __declspec(dllimport)
#endif

#include <Windows.h>

class IMainWindow
{
public:
	virtual BOOL Create() = 0;

	//gets the window handle
	virtual HWND Window() const = 0;

	virtual void Render() = 0;

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
};

extern "C" HEATERONENGINE_API IMainWindow* CreateMainWindow();
extern "C" HEATERONENGINE_API void DestroyMainWindow(IMainWindow* window);

#endif