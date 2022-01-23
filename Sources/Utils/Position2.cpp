//
// Project: Scratchy
// File: Position2.cpp
//

#include "Position2.h"
#include <iostream>

using namespace Scratchy;


Position2::Position2(float x, float y) {
	coords = std::make_tuple(x, y);
}

void Position2::setPosition(float x, float y) {
	std::get<0>(coords) = x;
	std::get<1>(coords) = y;
}

void Position2::setX(const float x) {
	std::get<0>(coords) = x;
}

float Position2::getX() const {
	return std::get<0>(coords);
}

void Position2::setY(const float y) {
	std::get<1>(coords) = y;
}

float Position2::getY() const {
	return std::get<1>(coords);
}

float *Position2::getArray() const {
	float *result = std::vector<float>({getX(), getY()}).data();

	return result;
}

void Position2::operator=(const Position2 &p) {
	Position2::coords = p.coords;
}
