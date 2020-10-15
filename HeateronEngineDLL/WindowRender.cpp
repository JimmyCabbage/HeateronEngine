#include "MainWindow.h"

#include <glad/glad.h>
#include <glad/glad_wgl.h>

#include <glm/gtc/matrix_transform.hpp>

#include <chrono>

void MainWindow::Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Do OpenGL rendering here
	shaderProgram.use();
	shaderProgram.setMat4("projection", glm::perspective(glm::radians(25.0), (double)cwidth / cheight, 0.1, 100.0));
	shaderProgram.setMat4("view", glm::translate(glm::mat4(1.0), glm::vec3(0.0, 0.0, -3.0)));
	auto timeValue = std::chrono::duration_cast<std::chrono::milliseconds>(Clock::now() - start_time).count();
	auto model = glm::rotate(glm::mat4(1.0), (timeValue * glm::radians(75.0f)) / 200, glm::vec3(0.0f, 2.0f, 0.0f));
	shaderProgram.setMat4("model", model);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	SwapBuffers(m_gldc);
}