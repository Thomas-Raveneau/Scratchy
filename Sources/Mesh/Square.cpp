//
// Project: Scratchy
// File: Square.cpp
//

#include "Square.h"

using namespace Scratchy;

Square::Square(Position3 a1, Position3 a2, Position3 a3, Position3 a4, Color color): Mesh() {
	vertices.insert(vertices.end(), { a1, a2, a3, a4 });
	Square::color = color;
	isTextured = false;
}

Square::~Square() {

}

void Square::draw() {

}
