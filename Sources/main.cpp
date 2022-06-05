//
// Project: Scratchy
// File: main.cpp
//


#include "Mesh/Primitives/Triangle.h"
#include "Mesh/Primitives/Rect.h"
#include "Mesh/Primitives/Cube.h"
#include "Main/Window.h"
#include "Mesh/Texture.h"

#include <iostream>
#include <chrono>

using namespace std;
using namespace Scratchy;

// settings
const unsigned int WIDTH = 1200;
const unsigned int HEIGHT = 600;

int main() {
	Scratchy::Window* window = new Scratchy::Window(WIDTH, HEIGHT, "Scratchy");
	Scratchy::Color clearColor(64, 64, 64);

	window->init(clearColor);

	Texture textureSide("./Ressources/Textures/Grass/side.jpg");
	Texture textureTop("./Ressources/Textures/Grass/top.jpg");
	Texture textureBottom("./Ressources/Textures/Grass/bottom.jpg");

	Scratchy::Color color(64, 100, 90);

	Scratchy::Cube* cube = new Scratchy::Cube(Position3(2, 0, 0), 1, textureSide, textureTop, textureBottom);
	window->addMesh(*cube);

	Scratchy::Rect* rect = new Scratchy::Rect(Position3(-2.5, 0.5, 0),
		Position3(-1.5, 0.5, 0),
		Position3(-1.5, -0.5, 0),
		Position3(-2.5, -0.5, 0),
		textureSide);

	window->addMesh(*rect);

	/*Scratchy::Triangle* triangle = new Scratchy::Triangle(Position3(-0.5, 0.5, 0), Position3(0.5, 0.5, 0), Position3(0.5, -0.5, 0), textureSide);
	window->addMesh(*triangle);*/

	int size = -1;

	/*for (int x = size; x != -size; x++) {
		for (int z = size; z != -size; z++) {

			Scratchy::Cube* cube = new Scratchy::Cube(Position3(x, 0, z), 1, textureSide, textureTop, textureBottom);
			cube->drawWireframe(true);

			window->addMesh(*cube);
		}
	}*/

	while (window->isOpen()) {
		window->clear();

		window->drawMeshes();
		//break;

		window->swapBuffer();
		window->pollEvents();

	}

	return EXIT_SUCCESS;
}