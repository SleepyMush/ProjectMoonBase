#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>

class Common {
private:
	//Box property
	std::vector<glm::vec2> positions;
	std::vector<glm::vec2> texturecoords;
	std::vector<unsigned int> indices;
public:
	unsigned int VBO;
	unsigned int VAO;
	unsigned int EBO;
	void initialize();
	void render();
	~Common();

};
