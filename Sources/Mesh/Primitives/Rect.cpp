//
// Project: Scratchy
// File: Rect.cpp
//

#include "Rect.h"

using namespace Scratchy;

const std::string VERTEX_COLOR_SHADER = std::string("../Shaders/Vertex/color.vs");
const std::string FRAGMENT_COLOR_SHADER = std::string("../Shaders/Fragment/color.fs");

const std::string VERTEX_TEXTURE_SHADER = std::string("../Shaders/Vertex/texture.vs");
const std::string FRAGMENT_TEXTURE_SHADER = std::string("../Shaders/Fragment/texture.fs");

Rect::Rect(Position3 a1, Position3 a2, Position3 a3, Position3 a4, Color color):
Mesh(VERTEX_COLOR_SHADER, FRAGMENT_COLOR_SHADER) {
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

Rect::Rect(Position3 a1, Position3 a2, Position3 a3, Position3 a4, std::string texturePath):
Mesh(VERTEX_TEXTURE_SHADER, FRAGMENT_TEXTURE_SHADER) {
	setIsTextured(true);
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

	setTexture(texturePath);
}

Rect::~Rect() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Rect::draw(int windowWith, int windowHeight) const {
	if (getIsTextured()) {
		texture.render();
	}

	shader->use();

	glm::mat4 view          = glm::mat4(1.0f);
	glm::mat4 projection    = glm::mat4(1.0f);

//	transform = glm::rotate(transform, glm::radians(-2.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	projection = glm::perspective(glm::radians(45.0f), (float)windowWith / (float)windowHeight, 0.1f, 100.0f);

	unsigned int modelLoc = glGetUniformLocation(shader->ID, "model");
	unsigned int viewLoc  = glGetUniformLocation(shader->ID, "view");

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(transform));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);

	shader->setMat4("projection", projection);

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
