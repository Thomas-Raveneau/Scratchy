//
// Project: Scratchy
// File: Mesh.cpp
//

#include "Mesh.h"

using namespace Scratchy;
using namespace std;

Mesh::Mesh(TYPE type, const std::string &vertexShaderPath, const std::string &fragmentShaderPath) {
	Mesh::vertexShaderPath = vertexShaderPath;
	Mesh::fragmentShaderPath = fragmentShaderPath;
	Mesh::shader = new Shader(vertexShaderPath, fragmentShaderPath);
	Mesh::type = type;

	setIsTextured(false);
	setTransform(glm::mat4(1.0f));
}

Mesh::Mesh(TYPE type, const std::string &vertexShaderPath, const std::string &fragmentShaderPath, const std::string &texturePath) {
	Mesh::vertexShaderPath = vertexShaderPath;
	Mesh::fragmentShaderPath = fragmentShaderPath;
	Mesh::shader = new Shader(vertexShaderPath, fragmentShaderPath);
	Mesh::type = type;

	setTexture(texturePath);
	setIsTextured(true);
	setTransform(glm::mat4(1.0f));
}

Mesh::Mesh(TYPE type, const std::string &vertexShaderPath, const std::string &fragmentShaderPath, const Texture &texture) {
	Mesh::vertexShaderPath = vertexShaderPath;
	Mesh::fragmentShaderPath = fragmentShaderPath;
	Mesh::shader = new Shader(vertexShaderPath, fragmentShaderPath);
	Mesh::type = type;

	setTexture(texture);
	setIsTextured(true);
	setTransform(glm::mat4(1.0f));
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

void Mesh::rotate() {
	transform = glm::rotate(transform, glm::radians(0.05f), glm::vec3(0.0f, 0.5f, 0.0f));
}

const vector<Position3> &Mesh::getVertices() const {
	return vertices;
}

void Mesh::setVertices(const vector<Position3> &vertices) {
	Mesh::vertices = vertices;
}

void Mesh::setColor(const Color &color) {
	Mesh::color = color;
}

void Mesh::setTexture(const std::string &filepath) {
	Mesh::texture = Texture(filepath);
}

void Mesh::setTexture(const Texture &texture) {
	Mesh::texture = texture;
}

void Mesh::setTextureCoords(const std::vector<Position2> &textureCoords) {
	Mesh::textureCoords = textureCoords;
}

std::vector<float> Mesh::getColoredVertices() const {
	if (isTextured) {
		return {};
	}

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

bool Mesh::getIsTextured() const {
	return Mesh::isTextured;
}

void Mesh::setIsTextured(bool isTextured) {
	Mesh::isTextured = isTextured;
}

const glm::mat4 &Mesh::getTransform() const {
	return transform;
}

void Mesh::setTransform(const glm::mat4 &transform) {
	Mesh::transform = transform;
}

void Mesh::setShader(Shader shader) {
	//Mesh::shader = new Shader(shader);
}
