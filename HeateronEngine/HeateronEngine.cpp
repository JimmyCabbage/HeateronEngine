// Sample code showing how to create a modern OpenGL window and rendering context on Win32.

#include "HeateronEngineDLL.h"

#include <windows.h>
#include <exception>

int WINAPI WinMain(_In_ HINSTANCE inst, _In_opt_ HINSTANCE prev, _In_ LPSTR cmd_line, _In_ int show)
{
	auto window = CreateMainWindow();

	try
	{
		window->Create();

		ShowWindow(window->Window(), show);
		UpdateWindow(window->Window());

		bool running = true;
		MSG msg;
		while (running)
		{
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				if (msg.message == WM_QUIT)
				{
					running = false;
				}
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			window->Render();
		}

		DestroyMainWindow(window);
	}
	catch (const std::exception& exp)
	{
		MessageBoxA(nullptr, exp.what(), "Error!", MB_OK | MB_ICONEXCLAMATION);
	}

	return 0;
}