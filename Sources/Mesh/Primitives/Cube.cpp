//
// Project: Scratchy
// File: Cube.cpp
//

#include "Cube.h"

using namespace Scratchy;

const std::string VERTEX_COLOR_SHADER = std::string("../Shaders/Vertex/color.vs");
const std::string FRAGMENT_COLOR_SHADER = std::string("../Shaders/Fragment/color.fs");

const std::string VERTEX_TEXTURE_SHADER = std::string("../Shaders/Vertex/texture.vs");
const std::string FRAGMENT_TEXTURE_SHADER = std::string("../Shaders/Fragment/texture.fs");

Cube::Cube(Position3 position, float size, Color color): Mesh() {

}

Cube::Cube(Position3 position, float size, std::string texturePath): Mesh() {
	setIsTextured(true);
	faces.insert(faces.end(), {
		new Rect(Position3( size / 2 ,size / 2, -size / 2), 	// BACK FACE
				 Position3( -size / 2 ,size / 2, -size / 2),
				 Position3( -size / 2 ,-size / 2, -size / 2),
				 Position3( size / 2 ,-size / 2, -size / 2),
				 texturePath),

		new Rect(Position3( -size / 2 ,size / 2, size / 2), 	// FRONT FACE
				 Position3( size / 2 ,size / 2, size / 2),
				 Position3( size / 2 ,-size / 2, size / 2),
				 Position3( -size / 2 ,-size / 2, size / 2),
				 texturePath),

		new Rect(Position3( size / 2 ,size / 2, size / 2), 	// RIGHT FACE
				 Position3( size / 2 ,size / 2, -size / 2),
				 Position3( size / 2 ,-size / 2, -size / 2),
				 Position3( size / 2 ,-size / 2, size / 2),
				 texturePath),

		new Rect(Position3( -size / 2 ,size / 2, -size / 2), 	// LEFT FACE
				 Position3( -size / 2 ,size / 2, size / 2),
				 Position3( -size / 2 ,-size / 2, size / 2),
				 Position3( -size / 2 ,-size / 2, -size / 2),
				 texturePath),

		new Rect(Position3( -size / 2 ,size / 2, -size / 2), 	// TOP FACE
				 Position3( size / 2 ,size / 2, -size / 2),
				 Position3( size / 2 ,size / 2, size / 2),
				 Position3( -size / 2 ,size / 2, size / 2),
				 texturePath),

		new Rect(Position3( -size / 2 ,-size / 2, -size / 2), 	// BACK FACE
				 Position3( size / 2 ,-size / 2, -size / 2),
				 Position3( size / 2 ,-size / 2, size / 2),
				 Position3( -size / 2 ,-size / 2, size / 2),
				 texturePath),
	});
}

Cube::~Cube() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	for (Rect *rect: faces) {
		delete rect;
	}
}

void Cube::draw(int windowWith, int windowHeight) const {
	for (Rect *rect: faces) {
		rect->rotate();
		rect->draw(windowWith, windowHeight);
	}
}
