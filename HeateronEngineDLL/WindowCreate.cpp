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
	//shader code
	const char* vertexShaderSource =
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec3 aColor;\n"
		"out vec3 ourColor;\n"
		"uniform mat4 model, view, projection;"
		"void main()\n"
		"{\n"
		"   gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
		"   ourColor = aColor;\n"
		"}\0";

	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"in vec3 ourColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(ourColor, 1.0f);\n"
		"}\n\0";

	shaderProgram = Shader(vertexShaderSource, fragmentShaderSource, true);

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