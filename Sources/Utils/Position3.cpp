//
// Project: Scratchy
// File: Position3.cpp
//

#include "Position3.h"

using namespace Scratchy;


Position3::Position3(float x, float y, float z) {
	coords = std::make_tuple(x, y, z);
}

void Position3::setX(const float x) {
	std::get<0>(coords) = x;
}

float Position3::getX() const {
	return std::get<0>(coords);
}

void Position3::setY(const float y) {
	std::get<1>(coords) = y;
}

float Position3::getY() const {
	return std::get<1>(coords);
}

void Position3::setZ(const float z) {
	std::get<2>(coords) = z;
}

float Position3::getZ() const {
	return std::get<2>(coords);
}

float *Position3::getArray() const {
	float *result = std::vector<float>({getX(), getY(), getZ()}).data();

	return result;
}

void Position3::operator=(const Position3 &p) {
	Position3::coords = p.coords;
}

Position3 Position3::operator+(const Position3 &position) {
	float x = this->getX() + position.getX();
	float y = this->getY() + position.getY();
	float z = this->getZ() + position.getZ();

	Position3 result = Position3(x, y, z);

	return result;
}
