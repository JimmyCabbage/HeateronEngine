#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader
{
public:
	//program ID
	unsigned int ID;

	//constructor reads and builds the shader
	Shader(const char* vertexPath, const char* fragmentPath);

	//use or activates program
	void use();
};

#endif