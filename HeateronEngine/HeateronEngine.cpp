#include "HeateronEngineDLL.h"

#include <windows.h>
#include <exception>

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ LPWSTR cmd_line, _In_ int nCmdShow)
{
	auto window = CreateMainWindow();

	try
	{
		window->Create();

		ShowWindow(window->Window(), nCmdShow);
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