#include "MainWindow.h"

#include <glad/glad.h>

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_SIZE:
	{
		//resize the OpenGL viewport depending on the window size
		cwidth = LOWORD(lParam);
		cheight = HIWORD(lParam);
		//since lParam is the client size, and glViewport needs the window size
		int width, height;
		GetSize(width, height);
		wwidth = width;
		wheight = height;
		glViewport(0, 0, (GLsizei)cwidth, (GLsizei)cheight);
	}
	break;
	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		//default protocal
		return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
	} //switch (uMsg)
	return TRUE;
}