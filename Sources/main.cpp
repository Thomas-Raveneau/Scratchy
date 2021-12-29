//
// Project: Scratchy
// File: main.cpp
//

//#include <stb_image.h>
//
#include <iostream>

#include "Mesh/Triangle.h"
#include "Mesh/Rect.h"
#include "Main/Window.h"

using namespace std;
using namespace Scratchy;

// settings
const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

int main() {
	Scratchy::Window *window = new Scratchy::Window(WIDTH, HEIGHT, "Scratchy");
	Scratchy::Color clearColor(64, 64, 64);

	window->init(clearColor);

	Scratchy::Position3 a1(-0.5, 0.5, 0);
	Scratchy::Position3 a2(0.5, 0.5, 0);
	Scratchy::Position3 a3(0.5, -0.5, 0);
	Scratchy::Position3 a4(-0.5, -0.5, 0);
	std::string texturePath = "../Ressources/Textures/mc_texture.jpg";
	Scratchy::Color rectColor(64, 0, 0);

	Scratchy::Rect rect(a1, a2, a3, a4, texturePath);

	while (window->isOpen()) {
		window->clear();

		rect.draw();

		window->swapBuffer();
		window->pollEvents();
	}

	return EXIT_SUCCESS;
}