#include "MainWindow.h"

#include <glad/glad.h>
#include <glad/glad_wgl.h>

void MainWindow::Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Do OpenGL rendering here
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	SwapBuffers(m_gldc);
}