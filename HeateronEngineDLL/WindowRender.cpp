#include "MainWindow.h"

#include <glad/glad.h>
#include <glad/glad_wgl.h>

#include <glm/gtc/matrix_transform.hpp>

void MainWindow::Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Do OpenGL rendering here
	shaderProgram.use();
	shaderProgram.setMat4("projection", glm::perspective(glm::radians(24.0), (double)width / height, 0.1, 100.0));
	shaderProgram.setMat4("view", glm::translate(glm::mat4(1.0), glm::vec3(0.0, 0.0, -3.0)));
	shaderProgram.setMat4("model", glm::mat4(1.0));

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	SwapBuffers(m_gldc);
}