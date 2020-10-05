#ifndef HEATERONENGINEDLL_H
#define HEATERONENGINEDLL_H

#ifdef HEATERONENGINEDLL_EXPORTS
#define HEATERONENGINE_API __declspec(dllexport)
#define GLAD_GLAPI_EXPORT_BUILD
#else
#define HEATERONENGINE_API __declspec(dllimport)
#endif

#include <Windows.h>

extern "C" HEATERONENGINE_API void fatal_error(const char* msg);
extern "C" HEATERONENGINE_API void init_opengl_extensions(void);
extern "C" HEATERONENGINE_API HGLRC init_opengl(HDC& real_dc);

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