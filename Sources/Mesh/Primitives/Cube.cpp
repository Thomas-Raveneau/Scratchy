//
// Project: Scratchy
// File: Cube.cpp
//

#include "Cube.h"

using namespace Scratchy;

const std::string VERTEX_COLOR_SHADER = std::string("../Shaders/Vertex/color.vs");
const std::string FRAGMENT_COLOR_SHADER = std::string("../Shaders/Fragment/color.fs");

const std::string VERTEX_TEXTURE_SHADER = std::string("../Shaders/Vertex/texture.vs");
const std::string FRAGMENT_TEXTURE_SHADER = std::string("../Shaders/Fragment/texture.fs");

Cube::Cube(Position3 position, float size, Color color): Mesh(VERTEX_COLOR_SHADER, FRAGMENT_COLOR_SHADER) {
	Mesh::setIsTextured(false);
	setColor(color);
	Mesh::setVertices({
		// Back face
		position + Position3(-size / 2, size / 2, -size / 2),		// 0 - Top right
		position + Position3(size / 2, size / 2, -size / 2),		// 1 - Top left
		position + Position3(size/ 2, -size / 2, -size / 2),		// 2 - Bottom left
		position + Position3(-size / 2, -size / 2, -size / 2),		// 3 - Bottom right

		// Front face
		position + Position3(-size / 2, size / 2, size / 2),		// 4 - Top left
		position + Position3(size / 2, size / 2, size / 2),			// 5 - Top right
		position + Position3(size/ 2, -size / 2, size / 2),			// 6 - Bottom right
		position + Position3(-size / 2, -size / 2, size / 2),		// 7 - Bottom left
	});

	unsigned int indices[] = {
		1, 0, 2, // Back face
		0, 3, 2,

		4, 5, 7, // Front face
		5, 6, 7,

		5, 1, 6, // Right face
		1, 2, 6,

		0, 4, 3, // Left face
		4, 7, 3,

		0, 1, 4, // Top Face
		1, 5, 4,

		7, 6, 3, // Bottom face
		6, 2, 3
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

Cube::Cube(Position3 position, float size, std::string texturePath): Mesh() {
	setIsTextured(true);
	faces.insert(faces.end(), {
		new Rect(position + Position3( size / 2 ,size / 2, -size / 2), 	// BACK FACE
				 position + Position3( -size / 2 ,size / 2, -size / 2),
				 position + Position3( -size / 2 ,-size / 2, -size / 2),
				 position + Position3( size / 2 ,-size / 2, -size / 2),
				 texturePath),

		new Rect(position + Position3( -size / 2 ,size / 2, size / 2), 	// FRONT FACE
				 position + Position3( size / 2 ,size / 2, size / 2),
				 position + Position3( size / 2 ,-size / 2, size / 2),
				 position + Position3( -size / 2 ,-size / 2, size / 2),
				 texturePath),

		new Rect(position + Position3( size / 2 ,size / 2, size / 2), 	// RIGHT FACE
				 position + Position3( size / 2 ,size / 2, -size / 2),
				 position + Position3( size / 2 ,-size / 2, -size / 2),
				 position + Position3( size / 2 ,-size / 2, size / 2),
				 texturePath),

		new Rect(position + Position3( -size / 2 ,size / 2, -size / 2), 	// LEFT FACE
				 position + Position3( -size / 2 ,size / 2, size / 2),
				 position + Position3( -size / 2 ,-size / 2, size / 2),
				 position + Position3( -size / 2 ,-size / 2, -size / 2),
				 texturePath),

		new Rect(position + Position3( -size / 2 ,size / 2, -size / 2), 	// TOP FACE
				 position + Position3( size / 2 ,size / 2, -size / 2),
				 position + Position3( size / 2 ,size / 2, size / 2),
				 position + Position3( -size / 2 ,size / 2, size / 2),
				 texturePath),

		new Rect(position + Position3( -size / 2 ,-size / 2, -size / 2), 	// BACK FACE
				 position + Position3( size / 2 ,-size / 2, -size / 2),
				 position + Position3( size / 2 ,-size / 2, size / 2),
				 position + Position3( -size / 2 ,-size / 2, size / 2),
				 texturePath),
	});
}

Cube::~Cube() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	for (Rect *rect: faces) {
		delete rect;
	}
}

void Cube::draw(int windowWith, int windowHeight) const {
	if (getIsTextured()) {
		for (Rect *rect: faces) {
			rect->rotate();
			rect->draw(windowWith, windowHeight);
		}
	} else {
		shader->use();

		glm::mat4 view          = glm::mat4(1.0f);
		glm::mat4 projection    = glm::mat4(1.0f);

		view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		projection = glm::perspective(glm::radians(45.0f), (float)windowWith / (float)windowHeight, 0.1f, 100.0f);

		unsigned int modelLoc = glGetUniformLocation(shader->ID, "model");
		unsigned int viewLoc  = glGetUniformLocation(shader->ID, "view");

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(transform));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);

		shader->setMat4("projection", projection);

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	}
}
