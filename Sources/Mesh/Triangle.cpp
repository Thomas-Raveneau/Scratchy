//
// Project: Scratchy
// File: Triangle.cpp
//

#include "Triangle.h"

using namespace Scratchy;

const std::string VERTEX_COLOR_SHADER = std::string("../Shaders/Vertex/triangle_colored.vs");
const std::string FRAGMENT_COLOR_SHADER = std::string("../Shaders/Fragment/color.fs");

const std::string VERTEX_TEXTURE_SHADER = std::string("../Shaders/Vertex/triangle_textured.vs");
const std::string FRAGMENT_TEXTURE_SHADER = std::string("../Shaders/Fragment/texture.fs");

Triangle::Triangle(Position3 a1, Position3 a2, Position3 a3, Color color) :
Mesh(VERTEX_COLOR_SHADER, FRAGMENT_COLOR_SHADER) {
	vertices.insert(vertices.end(), { a1, a2, a3 });
	Triangle::color = color;
	isTextured = false;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	std::vector<float> coloredVertices = getColoredVertices();

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * coloredVertices.size(), coloredVertices.data(), GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

Triangle::Triangle(Position3 a1, Position3 a2, Position3 a3, std::string texturePath) :
Mesh(VERTEX_TEXTURE_SHADER, FRAGMENT_TEXTURE_SHADER) {
	vertices.insert(vertices.end(), { a1, a2, a3 });
	isTextured = true;
	float verticess[] = {
		-0.5f, -0.5f, 0.0f,    0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f,    1.0f, 0.0f,
		 0.0f,  0.5f, 0.0f,    0.5f, 1.0f
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	std::vector<float> texturedVertices = getTexturedVertices();

//	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * texturedVertices.size(), texturedVertices.data(), GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticess), verticess, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	texture = Texture(texturePath);
}

Triangle::~Triangle() {

}

void Triangle::draw() {
	shader.use();
//	texture.render();

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
