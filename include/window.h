#include "glad/glad.h"
#include <GLFW/glfw3.h>

class Window {
protected:
	GLFWwindow* window;
public:
	Window(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	~Window() {
		glfwTerminate();
	}

	bool Update();
	void LateUpdate();

	bool init = false;
};
