//
// Project: Scratchy
// File: Window.cpp
//

#include "Window.h"

using namespace Scratchy;
using namespace std;

void errorCallback(int error_code, const char* description);

Window::Window(int width, int height, const std::string &title) : Viewport(width, height) {
	setTitle(title);
	camera = unique_ptr<Camera>(new Camera(glm::vec3(0.0f, 2.0f, 5.0f)));
	mousePos = std::unique_ptr<Position2>(new Position2(400, 300));

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

	setCallbacks();

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);

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

void Window::addMesh(Mesh &mesh) {
	bool shaderFound = false;

	for (Shader *shader: shaders) {
		if (shader->vertexShaderPath == mesh.vertexShaderPath
			&& shader->fragmentShaderPath == mesh.fragmentShaderPath) {
			shaderFound = true;
			mesh.setShader(*shader);
			break;
		}
	}
	if (!shaderFound) {
		Shader *shader = new Shader(mesh.vertexShaderPath, mesh.fragmentShaderPath);
		mesh.setShader(*shader);

		shaders.insert(shaders.end(), shader);
	}
//	&mesh.shader->ID;
	std::cout << "C: " << &mesh.shader->ID << std::endl;
	meshes.push_back(&mesh);
	std::cout << "D: " << &meshes[0]->shader->ID << std::endl;

}

void Window::drawMeshes() {
	if (getWidth() > 0) {
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
			camera->processKeyboard(Camera::FORWARD, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
			camera->processKeyboard(Camera::BACKWARD, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
			camera->processKeyboard(Camera::LEFT, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
			camera->processKeyboard(Camera::RIGHT, deltaTime);

		for (auto mesh: meshes) {
			mesh->draw(getWidth(), getHeight(), camera->getViewMatrix());
			mesh->rotate();
		}
	}
}

bool Window::isKeyPressed(int key) {
	return glfwGetKey(Window::window, key) == GLFW_PRESS ? true : false;
}

void Window::setCallbacks() {
	glfwSetWindowUserPointer(window, reinterpret_cast<void*>(this));

//	glDebugMessageCallback(messageCallback, 0 );
	glfwSetErrorCallback(errorCallback);
	glfwSetCursorPosCallback(window, processMouse);
	glfwSetFramebufferSizeCallback(Window::window, processResize);
}

void Window::processMouse(GLFWwindow *window, double x, double y) {
	Window *handler = reinterpret_cast<Window *>(glfwGetWindowUserPointer(window));
	if (!handler->mouseAlreadyUsed) {
		handler->mousePos->setPosition(x, y);
		handler->mouseAlreadyUsed = true;
	}

	float xOffset = x - handler->mousePos->getX();
	float yOffset = handler->mousePos->getY() - y;
	handler->mousePos->setPosition(x, y);

	handler->camera->processMouseMovement(xOffset, yOffset);
}

void Window::processResize(GLFWwindow *window, int width, int height) {
	Window *handler = reinterpret_cast<Window *>(glfwGetWindowUserPointer(window));

	glViewport(0, 0, width, height);
	handler->setSize(width, height);
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

void errorCallback(int error_code, const char* description)
{
	std::cout << "GLFW::ERROR: " << description << std::endl;
}
