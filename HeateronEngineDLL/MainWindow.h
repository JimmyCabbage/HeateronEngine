#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "HeateronEngineDLL.h"
#include "Shader.h"

#include <chrono>

typedef std::chrono::high_resolution_clock Clock;

constexpr float vertices[] =
{
	// positions         // colors
	 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
	 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
};

class MainWindow : public IMainWindow
{
	//start of program
	std::chrono::high_resolution_clock::time_point start_time;

	WORD cwidth, cheight, wwidth, wheight;
	unsigned int VBO, VAO;
	Shader shaderProgram;

	HWND m_hwnd;
	HDC m_gldc;
	HGLRC m_glrc;

	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void init_opengl_extensions(void);

	HGLRC init_opengl(HDC& real_dc);

	void GetSize(int& width, int& height);

public:
	BOOL Create();

	//gets the window handle
	HWND Window() const;

	void Render();

	//constructor, initialize window handle to nullptr
	MainWindow();

	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

	static void fatal_error(const wchar_t* msg);
	static void fatal_error(const char* msg);
};

#endif