#include "core/Windows.h"
#include "core/Game.h"

Window window;
Game game;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

int main()
{
	window.init();

	while (!glfwWindowShouldClose(window)) 
	{
		glfwSwapBuffers(window);
		game.Input(deltaTime, window);

		//Time Processing
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		//Render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		game.update(deltaTime);

		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}