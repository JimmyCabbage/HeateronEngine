#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "HeateronEngineDLL.h"

constexpr float vertices[] =
{
	// positions         // colors
	 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
	 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
};

class MainWindow : public IMainWindow
{
	unsigned int VBO, VAO;
	int shaderProgram;

	HWND m_hwnd;
	HDC m_gldc;
	HGLRC m_glrc;

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void init_opengl_extensions(void);

	HGLRC init_opengl(HDC& real_dc);

public:
	BOOL Create();

	//gets the window handle
	HWND Window() const;

	void Render();

	//constructor, initialize window handle to nullptr
	MainWindow();

	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

	void fatal_error(const wchar_t* msg);
	void fatal_error(const char* msg);
};

#endif