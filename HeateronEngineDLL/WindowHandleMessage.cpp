#include "MainWindow.h"

#include <glad/glad.h>
#include <glad/glad_wgl.h>

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_SIZE:
	{
		//resize the OpenGL viewport depending on the window size
		width = LOWORD(lParam);
		height = HIWORD(lParam);
		glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	}
	break;
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