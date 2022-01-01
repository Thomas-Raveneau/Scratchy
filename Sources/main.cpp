//
// Project: Scratchy
// File: main.cpp
//

#include <iostream>

#include "Mesh/Primitives/Triangle.h"
#include "Mesh/Primitives/Rect.h"
#include "Mesh/Primitives/Cube.h"
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

//	Scratchy::Position3 a1(-0.5, 0.5, 0);
//	Scratchy::Position3 a2(0.5, 0.5, 0);
//	Scratchy::Position3 a3(0.5, -0.5, 0);
//	Scratchy::Position3 a4(-0.5, -0.5, 0);
	std::string texturePath = "../Ressources/Textures/mc_texture.jpg";
	Scratchy::Color color(64, 100, 90);
//
//	Scratchy::Rect rect = Scratchy::Rect(a1, a2, a3, a4, texturePath);
	Scratchy::Cube cube = Scratchy::Cube(Position3(0, 0, 0), 0.5, color);

//	cube.drawWireframe(true);

	window->addMesh(cube);

	while (window->isOpen()) {
		window->clear();

		cube.rotate();
		window->drawMeshes();

		window->swapBuffer();
		window->pollEvents();
	}

	return EXIT_SUCCESS;
}