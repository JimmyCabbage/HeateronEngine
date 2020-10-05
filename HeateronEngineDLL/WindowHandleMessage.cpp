#include "MainWindow.h"

#include <glad/glad.h>
#include <glad/glad_wgl.h>

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_SIZE:
	{
		WORD width = LOWORD(lParam);
		WORD height = HIWORD(lParam);
		glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	}
	break;
	break;
	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
	} //switch (uMsg)
	return TRUE;
}