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

Cube::Cube(Position3 position, float size, Color color):
Mesh(VERTEX_COLOR_SHADER, FRAGMENT_COLOR_SHADER) {

}

Cube::Cube(Position3 position, float size, std::string texturePath):
Mesh(VERTEX_TEXTURE_SHADER, FRAGMENT_TEXTURE_SHADER){

}

Cube::~Cube() {

}

void Cube::draw(int windowWith, int windowHeight) const {

}
