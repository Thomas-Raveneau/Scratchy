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

	Scratchy::Color color(64, 190, 90);
	Scratchy::Color color1(190, 190, 90);
	Scratchy::Color color2(64, 190, 190);

	Scratchy::Cube* cube = new Scratchy::Cube(Position3(0, 0, 0), 1, textureSide, textureTop, textureBottom);
	//cube->drawWireframe(true);
	window->addMesh(*cube);

	Scratchy::Cube* cube2 = new Scratchy::Cube(Position3(-2, 0, 0), 1, color1);
	window->addMesh(*cube2);

	Scratchy::Cube* cube3 = new Scratchy::Cube(Position3(2, 0, 0), 1, color2);
	window->addMesh(*cube3);

	/*Scratchy::Rect* rect = new Scratchy::Rect(Position3(-0.5, 0.5, 0),
		Position3(0.5, 0.5, 0),
		Position3(0.5, -0.5, 0),
		Position3(-0.5, -0.5, 0),
		textureSide);

	window->addMesh(*rect);


	Scratchy::Rect* rect5 = new Scratchy::Rect(Position3(-0.5, 2.5, 0),
		Position3(0.5, 2.5, 0),
		Position3(0.5, 1.5, 0),
		Position3(-0.5, 1.5, 0),
		textureTop);

	window->addMesh(*rect5);

	Scratchy::Rect* rect6 = new Scratchy::Rect(Position3(-0.5, -1.5, 0),
		Position3(0.5, -1.5, 0),
		Position3(0.5, -2.5, 0),
		Position3(-0.5, -2.5, 0),
		textureBottom);

	window->addMesh(*rect6);*/


	/// 

	/*Scratchy::Rect* rect1 = new Scratchy::Rect(Position3(1.5, 0.5, 0),
		Position3(2.5, 0.5, 0),
		Position3(2.5, -0.5, 0),
		Position3(1.5, -0.5, 0),
		color);
	window->addMesh(*rect1);

	Scratchy::Rect* rect3 = new Scratchy::Rect(Position3(1.5, 2.5, 0),
		Position3(2.5, 2.5, 0),
		Position3(2.5, 1.5, 0),
		Position3(1.5, 1.5, 0),
		color1);
	window->addMesh(*rect3);

	Scratchy::Rect* rect4 = new Scratchy::Rect(Position3(1.5, -1.5, 0),
		Position3(2.5, -1.5, 0),
		Position3(2.5, -2.5, 0),
		Position3(1.5, -2.5, 0),
		color2);
	window->addMesh(*rect4);*/


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

		//rect->rotate();

		window->swapBuffer();
		window->pollEvents();

	}

	return EXIT_SUCCESS;
}