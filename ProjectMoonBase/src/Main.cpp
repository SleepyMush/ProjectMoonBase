#include "core/Windows.h"
#include "render/Common.h"

Window window;
Common common;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

int main()
{
	window.init();
	common.initialize();

	while (!glfwWindowShouldClose(window)) 
	{
		glfwSwapBuffers(window);

		//Time Processing
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		//Render
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		common.render();

		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}