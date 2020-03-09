#include "window.h"

Window::Window(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) {
	if (!glfwInit()) {
		return;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);
	gladLoadGL();

	init = true;
}

bool Window::Update() {
	int width, height;

	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);

	return glfwWindowShouldClose(window);
}

void Window::LateUpdate() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}

bool Window::GetKeyPressed(int key) {
	int state = glfwGetKey(window, key);
	
	return state == GLFW_PRESS;
}

const char* Window::GetKeyName(int key, int scancode) {
	return glfwGetKeyName(key, scancode);
}
