#include "Common.h"
#include "Shader.h"
#include "Texture.h"
#include "../core/Windows.h"

Shader shader;
Texture texture;
Window win;

void Common::initialize()
{
	shader.load("res/shader/VertexShader.vert", "res/shader/FragmentShader.frag");
	texture.loadtexture("res/texture/ConceptArt.jpg");

	//position
	positions.push_back(glm::vec2(-0.5f, -0.5f));
	positions.push_back(glm::vec2(0.5f, -0.5f));
	positions.push_back(glm::vec2(0.5f,  0.5f));
	positions.push_back(glm::vec2(-0.5f, 0.5f));

	//Texture
	texturecoords.push_back(glm::vec2(1.0f, 1.0f));
	texturecoords.push_back(glm::vec2(1.0f, 0.0f));
	texturecoords.push_back(glm::vec2(0.0f, 0.0f));
	texturecoords.push_back(glm::vec2(0.0f, 1.0f));

	indices = {
		0,1,3,
		1,2,3
	};

	//VertexArray
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	//Buffer
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(glm::vec2), positions.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

	//Position
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//Texture
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);;
	glEnableVertexAttribArray(1);

	//Memory address
	std::cout << &VBO << "\n";
	std::cout << &VAO << "\n";
	std::cout << &EBO << "\n";

	//Output
	std::cout << positions.size() << "\n";
	std::cout << indices.size() << "\n";
	std::cout << texturecoords.size() << "\n";

}

void Common::render()
{
	shader.use();

	float nearPlane = 0.0f;
	float farPlane = 100.0f;
	glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(win.screenWidth), 0.0f, static_cast<float>(win.screenHeight), nearPlane, farPlane);

	glm::mat4 view = glm::lookAt(
		glm::vec3(0.0f, 0.0f, 0.0f), // Camera position in world space
		glm::vec3(0.0f, 0.0f, -1.0f), // Point the camera towards the origin
		glm::vec3(0.0f, 1.0f, 0.0f)  // Up vector
	);

	glm::mat4 model(1.0f);
	model = glm::translate(model, glm::vec3(0.5f * win.screenWidth, 0.5f * win.screenHeight, 0.0f));
	model = glm::scale(model, glm::vec3(500.0f, 500.0f, 0));

	int ProjectionLocation = glGetUniformLocation(shader.shaderID, "projection");
	glUniformMatrix4fv(ProjectionLocation, 1, GL_FALSE, &projection[0][0]);

	int ModelLocation = glGetUniformLocation(shader.shaderID, "model");
	glUniformMatrix4fv(ModelLocation, 1, GL_FALSE, &model[0][0]);

	int ViewLocation = glGetUniformLocation(shader.shaderID, "view");
	glUniformMatrix4fv(ViewLocation, 1, GL_FALSE, &view[0][0]);

	texture.bind(0);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}

Common::~Common()
{
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteVertexArrays(1, &VAO);
	glDeleteProgram(shader.shaderID);
	texture.cleanUp();
}
