// Sample code showing how to create a modern OpenGL window and rendering context on Win32.
#include <windows.h>
#include "HeateronEngineDLL.h"
#include <gl/gl.h>
#include <stdbool.h>

#pragma comment(lib, "opengl32.lib")

int WINAPI WinMain(_In_ HINSTANCE inst, _In_opt_ HINSTANCE prev, _In_ LPSTR cmd_line, _In_ int show)
{
	auto window = CreateMainWindow();

	window->Create();

	ShowWindow(window->Window(), show);
	UpdateWindow(window->Window());

	bool running = true;
	while (running)
	{
		MSG msg;
		while (PeekMessageA(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				running = false;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		window->Render();
	}

	DestroyMainWindow(window);

	return 0;
}