//
// Project: Scratchy
// File: Color.cpp
//

#include "Color.h"

using namespace Scratchy;

Color::Color() {
	Color::r = 1.0f;
	Color::g = 1.0f;
	Color::b = 1.0f;
	Color::a = 1.0f;
}

Color::Color(float r, float g, float b) {
	Color::r = r / 255.0f;
	Color::g = g / 255.0f;
	Color::b = b / 255.0f;
	Color::a = 1.0f;
}

Color::Color(float r, float g, float b, float a) {
	Color::r = r / 255.0f;
	Color::g = g / 255.0f;
	Color::b = b / 255.0f;
	Color::a = a / 255.0f;
}

Color::~Color() {

}

std::ostream &Scratchy::operator<<(std::ostream &os, const Color c) {
	os << "Color("
	<< c.r * 255 << ", "
	<< c.g * 255 << ", "
	<< c.b * 255 << ", "
	<< c.a * 255 << ")";

	return os;
}
