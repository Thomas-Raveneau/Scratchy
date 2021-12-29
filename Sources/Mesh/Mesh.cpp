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

void Mesh::drawWireframe(bool active) {
	if (active && drawMode != WIREFRAME) { 				// Set draw mode to wireframed polygon
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		drawMode = WIREFRAME;
	} else if (!active && drawMode != FILL) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);		// Set draw mode to filled polygon
		drawMode = FILL;
	}
}

void Mesh::setTexture(std::string filepath) {
	texture = Texture("filepath");
}

void Mesh::setVertices(std::vector<Position3> vertices) {
	Mesh::vertices = vertices;
	int verticesCount = Mesh::vertices.size();

	if (verticesCount == 3) {
		type = TRIANGLE;
	} else if (verticesCount == 4) {
		type = RECTANGLE;
	}
}

void Mesh::setTextureCoords(std::vector<Position2> textureCoords) {
	Mesh::textureCoords = textureCoords;
}

std::vector<float> Mesh::getVertices() const {
	std::vector<float> result;

	for (auto & element : vertices) {
		result.insert(result.end(), {element.getX(), element.getY(), element.getZ()});
	}

	return result;
}

std::vector<float> Mesh::getColoredVertices() const {
	std::vector<float> result;

	for (auto & element : vertices) {
		result.insert(result.end(), {element.getX(), element.getY(), element.getZ(), color.r, color.g, color.b});
	}

	return result;
}

std::vector<float> Mesh::getTexturedVertices() const {
	if (!isTextured) {
		return {};
	}

	std::vector<float> result;
	int i = 0;

	for (auto & element : vertices) {
		result.insert(result.end(), {element.getX(), element.getY(), element.getZ(),
									 textureCoords[i].getX(), textureCoords[i].getY()});
		i++;
	}

	return result;
}
