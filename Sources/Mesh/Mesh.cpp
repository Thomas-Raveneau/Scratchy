//
// Project: Scratchy
// File: Mesh.cpp
//

#include "Mesh.h"

using namespace Scratchy;
using namespace std;

Mesh::Mesh(std::string vertexShaderPath, std::string fragmentShaderPath):
shader(vertexShaderPath, fragmentShaderPath) {

}

Mesh::Mesh(std::string vertexShaderPath, std::string fragmentShaderPath, std::string texturePath):
		shader(vertexShaderPath, fragmentShaderPath),
		texture(texturePath) {
}

Mesh::~Mesh() {

}

void Mesh::draw() const {

}

void Mesh::drawWireframe(bool active) {
	if (active) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	} else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
}

void Mesh::setTexture(std::string filepath) {

}

std::vector<float> Mesh::getVertices() {
	std::vector<float> result;

	for (auto & element : vertices) {
		result.insert(result.end(), {element.getX(), element.getY(), element.getZ()});
	}

	return result;
}

std::vector<float> Mesh::getColoredVertices() {
	std::vector<float> result;

	for (auto & element : vertices) {
		result.insert(result.end(), {element.getX(), element.getY(), element.getZ(), color.r, color.g, color.b});
	}

	return result;
}

std::vector<float> Mesh::getTexturedVertices() {
	std::vector<float> result;

	for (auto & element : vertices) {
		result.insert(result.end(), {element.getX(), element.getY(), element.getZ(), element.getX(), element.getY()});
	}

	return result;
}
