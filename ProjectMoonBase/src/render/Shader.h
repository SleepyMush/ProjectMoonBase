#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
private:
	void checkCompileErrors(unsigned int shader, std::string type);
public:
	unsigned int shaderID;

	void load(const char* vertexPath, const char* fragmentPath);
	void use() const;

	Shader() = default;
};
