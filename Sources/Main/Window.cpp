//
// Project: Scratchy
// File: Window.cpp
//

#include "Window.h"

using namespace Scratchy;
using namespace std;

Window::Window(int width, int height, const std::string &title) : Viewport(width, height) {
	setTitle(title);

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

Window::~Window() {
	glfwTerminate();
}

int Window::init(Color clearColor) {
	setClearColor(clearColor);
	Window::window = glfwCreateWindow(getWidth(), getHeight(), getTitle().c_str(), NULL, NULL);

	if (Window::window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(Window::window);

	glfwSetWindowUserPointer(window, reinterpret_cast<void*>(this));
	glfwSetFramebufferSizeCallback(Window::window, resize);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glEnable(GL_DEPTH_TEST);

	state = OPEN;

	return 0;
}

void Window::close() {
	glfwSetWindowShouldClose(window, true);
}

bool Window::isOpen() const {
	 if (glfwWindowShouldClose(window))
		 return false;

	return state == OPEN ? true : false;
}

void Window::clear() {
	glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::swapBuffer() {
	glfwSwapBuffers(window);
}

void Window::pollEvents() {
	glfwPollEvents();
}

void Window::resize(GLFWwindow *window, int width, int height) {
	Window *handler = reinterpret_cast<Window *>(glfwGetWindowUserPointer(window));

	glViewport(0, 0, width, height);
	handler->setSize(width, height);

	std::cout << "DEBUG: Window->resize(" << width << ", " << height << ")" << std::endl;
}

const std::string &Window::getTitle() const {
	return Window::title;
}

void Window::setTitle(const std::string &title) {
	Window::title = title;
}

const Color &Window::getClearColor() const {
	return clearColor;
}

void Window::setClearColor(Color clearColor) {
	Window::clearColor = clearColor;
}

void Window::addMesh(Mesh &mesh) {
	meshes.push_back(&mesh);
}

void Window::drawMeshes() {
	if (getWidth() > 0) {
		for (Mesh *mesh: meshes) {
			mesh->draw(getWidth(), getHeight());
		}
	}
}
