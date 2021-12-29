//
// Project: Scratchy
// File: Position2.cpp
//

#include "Position2.h"

Scratchy::Position2::Position2() {
	coords = std::make_tuple(0, 0);
}

Scratchy::Position2::Position2(float x, float y) {
	coords = std::make_tuple(x, y);
}

Scratchy::Position2::~Position2() {

}

float Scratchy::Position2::getX() const {
	return std::get<0>(coords);
}

float Scratchy::Position2::getY() const {
	return std::get<1>(coords);
}

float *Scratchy::Position2::getArray() const {
	float result[] = {getX(), getY()};

	return result;
}

void Scratchy::Position2::operator=(const Scratchy::Position2 &p) {
	Position2::coords = p.coords;
}
