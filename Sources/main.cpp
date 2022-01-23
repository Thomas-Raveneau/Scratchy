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
	Scratchy::Window *window = new Scratchy::Window(WIDTH, HEIGHT, "Scratchy");
	Scratchy::Color clearColor(64, 64, 64);

	window->init(clearColor);

	Texture textureSide("../Ressources/Textures/Grass/side.jpg");
	Texture textureTop("../Ressources/Textures/Grass/top.jpg");
	Texture textureBottom("../Ressources/Textures/Grass/bottom.jpg");

	Scratchy::Color color(64, 100, 90);

	auto start = std::chrono::steady_clock::now();

	Scratchy::Rect *rect = new Scratchy::Rect(Position3(-0.5, 0.5, 0),
											  Position3(0.5, 0.5, 0),
											  Position3(0.5, -0.5, 0),
											  Position3(-0.5, -0.5, 0),
											  textureSide);
//	Scratchy::Cube *cube = new Scratchy::Cube(Position3(0, 0, 0), 1, color);
//	window->addMesh(*cube);
	window->addMesh(*rect);

//	int size = 0;
//
//	for (int x = size; x != -size; x++) {
//		for (int z = size; z != -size; z++) {
////			Scratchy::Cube *cube = new Scratchy::Cube(Position3(x, 0, z), 1, color);
////			cube->drawWireframe(true);
//
//			window->addMesh(*cube);
//		}
//	}

//	auto end = std::chrono::steady_clock::now();
//	std::chrono::duration<double> elapsed_seconds = end-start;
//	std::cout << elapsed_seconds.count() << "s\n";


	while (window->isOpen()) {
		auto lastFrame = std::chrono::steady_clock::now();

		window->clear();


		window->drawMeshes();

		break;
		window->swapBuffer();
		window->pollEvents();
		auto end = std::chrono::steady_clock::now();
		double elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end-lastFrame).count();

//		std::cout << round(1000 / elapsedTime) << "FPS\n";
	}

	return EXIT_SUCCESS;
}