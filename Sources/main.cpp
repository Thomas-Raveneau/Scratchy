//
// Project: Scratchy
// File: main.cpp
//

//#include <stb_image.h>
//
#include <iostream>

#include "Mesh/Triangle.h"
#include "Main/Window.h"

using namespace std;
using namespace Scratchy;

// settings
const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

int main() {
	Scratchy::Window *window = new Scratchy::Window(WIDTH, HEIGHT, "Scratchy");
	Scratchy::Color clearColor = Scratchy::Color(64, 64, 64);

	window->init(clearColor);
//
	Scratchy::Position3 a1 = Scratchy::Position3(0.5, -0.5, 0);
	Scratchy::Position3 a2 = Scratchy::Position3(-0.5, -0.5, 0);
	Scratchy::Position3 a3 = Scratchy::Position3(0, 0.5, 0);
	std::string texturePath = "../Ressources/Textures/mc_texture.jpg";

	Scratchy::Triangle triangle = Scratchy::Triangle(a1, a2, a3, texturePath);

	while (window->isOpen()) {
		window->clear();

		triangle.draw();

		window->swapBuffer();
		window->pollEvents();
	}

	return EXIT_SUCCESS;
}