#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window {
private:
	GLFWwindow* window;
public:
	int screenWidth = 1920;
	int screenHeight = 1080;

	Window() : window(nullptr) {};
	operator GLFWwindow* () const {
		return window;
	}

	void init();
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};
