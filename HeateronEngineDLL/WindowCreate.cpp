#include "MainWindow.h"

#include <glad/glad.h>

BOOL MainWindow::Create()
{
	start_time = Clock::now();

	//create the window
	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	window_class.lpfnWndProc = WindowProc;
	window_class.hInstance = GetModuleHandle(nullptr);
	window_class.hCursor = LoadCursor(0, IDC_ARROW);
	window_class.lpszClassName = L"WGL_fdjhsklf";

	if (!RegisterClass(&window_class))
	{
		fatal_error(L"Failed to register window.");
	}


	m_hwnd = CreateWindowEx(
		0,
		window_class.lpszClassName,
		L"HeateronEngine",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		1024, 768,
		0,
		0,
		GetModuleHandle(nullptr),
		this);

	if (!m_hwnd)
	{
		fatal_error(L"Failed to create window.");
	}

	m_gldc = GetDC(m_hwnd);
	m_glrc = init_opengl(m_gldc);

	//create shader program for OpenGL

	shaderProgram = Shader("shader.vert", "shader.frag");

	//create the Vertex Attribute Object, and the Vertex Buffer Object to prepare for drawing
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	shaderProgram.use();

	glEnable(GL_DEPTH_TEST);

	return true;
}