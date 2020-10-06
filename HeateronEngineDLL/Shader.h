#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glm/mat4x4.hpp>

class Shader
{
public:
	//program ID
	unsigned int ID;

	//constructor reads and builds the shader, or optionally, data
	Shader(const char* vertexPath, const char* fragmentPath, const bool data = false);
	//default constructor
	Shader();

	//use or activates program
	void use();

	// utility uniform functions
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setMat4(const std::string& name, const glm::mat4& mat) const;
};

#endif