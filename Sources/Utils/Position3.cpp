//
// Project: Scratchy
// File: Position3.cpp
//

#include "Position3.h"

using namespace Scratchy;

Position3::Position3() {
	coords = std::make_tuple(0, 0, 0);
}

Position3::Position3(float x, float y, float z) {
	coords = std::make_tuple(x, y, z);
}

Position3::~Position3() {

}

float Position3::getX() const {
	return std::get<0>(coords);
}

float Position3::getY() const {
	return std::get<1>(coords);
}

float Position3::getZ() const {
	return std::get<2>(coords);
}

float *Position3::getArray() const {
	float array[] = {getX(), getY(), getZ()};

	return array;
}

void Position3::operator=(const Position3 &p) {
	Position3::coords = p.coords;
}
