//
// Project: Scratchy
// File: Viewport.cpp
//

#include "Viewport.h"

using namespace Scratchy;

Viewport::Viewport(int width, int height) {
	setSize(width, height);
}

Viewport::~Viewport() {

}

int Viewport::getWidth() const {
	return size.first;
}

void Viewport::setWidth(int width) {
	size.first = width;
}

int Viewport::getHeight() const {
	return size.second;
}

void Viewport::setHeight(int height) {
	size.second = height;
}

void Viewport::setSize(int width, int height) {
	setWidth(width);
	setHeight(height);
}

Viewport::MODE Viewport::getMode() const {
	return Viewport::mode;
}

void Viewport::setMode(Viewport::MODE mode) {
	Viewport::mode = mode;

	switch (mode) {
		case Viewport::MODE::FULLSCREEN:

			break;
		case Viewport::MODE::WINDOWED:

			break;
	}
}
