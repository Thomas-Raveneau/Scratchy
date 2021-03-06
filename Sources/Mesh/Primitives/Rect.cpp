//
// Project: Scratchy
// File: Rect.cpp
//

#include "Rect.h"

using namespace Scratchy;

const std::string VERTEX_COLOR_SHADER = std::string("./Shaders/Vertex/color.vs");
const std::string FRAGMENT_COLOR_SHADER = std::string("./Shaders/Fragment/color.fs");

const std::string VERTEX_TEXTURE_SHADER = std::string("./Shaders/Vertex/texture.vs");
const std::string FRAGMENT_TEXTURE_SHADER = std::string("./Shaders/Fragment/texture.fs");

Rect::Rect(Position3 a1, Position3 a2, Position3 a3, Position3 a4, Color color):
Mesh(RECTANGLE, VERTEX_COLOR_SHADER, FRAGMENT_COLOR_SHADER) {
	setVertices(std::vector<Position3>({a1, a2, a3, a4}));
	setColor(color);

	unsigned int indices[] = {
			0, 1, 3, // first triangle
			1, 2, 3  // second triangle
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	std::vector<float> coloredVertices = getColoredVertices();

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * coloredVertices.size(), coloredVertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

Rect::Rect(Position3 a1, Position3 a2, Position3 a3, Position3 a4, const Texture &texture):
Mesh(RECTANGLE, VERTEX_TEXTURE_SHADER, FRAGMENT_TEXTURE_SHADER) {
	setIsTextured(true);
	Mesh::setTexture(texture);
	setVertices(std::vector<Position3>({a1, a2, a3, a4}));
	Position2 textureCoord1(0.0f, 0.0f);
	Position2 textureCoord2(1.0f, 0.0f);
	Position2 textureCoord3(1.0f, 1.0f);
	Position2 textureCoord4(0.0f, 1.0f);
	std::vector<Position2> textureCoords({textureCoord1, textureCoord2, textureCoord3, textureCoord4});
	setTextureCoords(textureCoords);

	unsigned int indices[] = {
			0, 1, 3, // first triangle
			1, 2, 3  // second triangle
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	std::vector<float> texturedVertices = getTexturedVertices();

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * texturedVertices.size(), texturedVertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

Rect::~Rect() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Rect::draw(int windowWith, int windowHeight, glm::mat4 view) const {
	if (getIsTextured()) {
		texture.render();
	}

	//std::cout << "E: " << &shader->ID << std::endl;
	shader->use();

	glm::mat4 projection    = glm::mat4(1.0f);

	projection = glm::perspective(glm::radians(45.0f), (float)windowWith / (float)windowHeight, 0.1f, 100.0f);

	shader->setMat4("projection", projection);
	shader->setMat4("view", view);
	shader->setMat4("model", getTransform());

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
