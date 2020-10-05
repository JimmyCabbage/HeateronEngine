#include "HeateronEngineDLL.h"
#include "framework.h"

#include <glad/glad.h>
#include <glad/glad_wgl.h>

class MainWindow : public IMainWindow
{
	HWND m_hwnd;
	HDC m_gldc;
	HGLRC m_glrc;

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		MainWindow* pThis = nullptr;

		if (uMsg == WM_NCCREATE)
		{
			CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
			pThis = (MainWindow*)pCreate->lpCreateParams;
			SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pThis);

			pThis->m_hwnd = hwnd;
		}
		else
		{
			pThis = (MainWindow*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
		}
		if (pThis)
		{
			return pThis->HandleMessage(uMsg, wParam, lParam);
		}
		else
		{
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
	}

public:
	BOOL Create()
	{
		WNDCLASS window_class = {};
		window_class.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		window_class.lpfnWndProc = WindowProc;
		window_class.hInstance = GetModuleHandle(nullptr);
		window_class.hCursor = LoadCursor(0, IDC_ARROW);
		window_class.lpszClassName = L"WGL_fdjhsklf";

		if (!RegisterClass(&window_class))
		{
			fatal_error("Failed to register window.");
		}

		// Specify a desired width and height, then adjust the rect so the window's client area will be
		// that size.
		RECT rect =
		{
			0,
			0,
			1280,
			720,
		};
		DWORD window_style = WS_OVERLAPPEDWINDOW;
		AdjustWindowRect(&rect, window_style, false);

		m_hwnd = CreateWindowEx(
			0,
			window_class.lpszClassName,
			L"HeateronEngine",
			window_style,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			rect.right - rect.left,
			rect.bottom - rect.top,
			0,
			0,
			GetModuleHandle(nullptr),
			this);

		if (!m_hwnd)
		{
			fatal_error("Failed to create window.");
		}

		m_gldc = GetDC(m_hwnd);
		m_glrc = init_opengl(m_gldc);

		return true;
	}

	//gets the window handle
	HWND Window() const
	{
		return m_hwnd;
	}

	void Render()
	{
		glClearColor(1.0f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Do OpenGL rendering here

		SwapBuffers(m_gldc);
	}

	//constructor, initialize window handle to nullptr
	MainWindow()
		: m_hwnd(nullptr), m_gldc(nullptr), m_glrc(nullptr)
	{
	}

	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_CLOSE:
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
		} //switch (uMsg)
		return TRUE;
	}
};

IMainWindow* CreateMainWindow()
{
	return new MainWindow();
}
void DestroyMainWindow(IMainWindow* window)
{
	delete window;
}