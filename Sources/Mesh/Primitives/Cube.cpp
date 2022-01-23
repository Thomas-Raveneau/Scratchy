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

Cube::Cube(Position3 position, float size, const Color &color): Mesh(CUBE, VERTEX_COLOR_SHADER, FRAGMENT_COLOR_SHADER) {
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

Cube::Cube(Position3 position, float size, const Texture &texture): Mesh() {
	vertexShaderPath = VERTEX_TEXTURE_SHADER;
	fragmentShaderPath = FRAGMENT_TEXTURE_SHADER;
	setIsTextured(true);
	faces.insert(faces.end(),
				 std::make_unique<Rect>(position + Position3(size / 2, size / 2, -size / 2),    // BACK FACE
										position + Position3(-size / 2, size / 2, -size / 2),
										position + Position3(-size / 2, -size / 2, -size / 2),
										position + Position3(size / 2, -size / 2, -size / 2),
										texture));
	faces.insert(faces.end(),
				 std::make_unique<Rect>(position + Position3(-size / 2, size / 2, size / 2),    // FRONT FACE
										position + Position3(size / 2, size / 2, size / 2),
										position + Position3(size / 2, -size / 2, size / 2),
										position + Position3(-size / 2, -size / 2, size / 2),
										texture));
	faces.insert(faces.end(),
				 std::make_unique<Rect>(position + Position3(size / 2, size / 2, size / 2),    // RIGHT FACE
										position + Position3(size / 2, size / 2, -size / 2),
										position + Position3(size / 2, -size / 2, -size / 2),
										position + Position3(size / 2, -size / 2, size / 2),
										texture));
	faces.insert(faces.end(),
				 std::make_unique<Rect>(position + Position3(-size / 2, size / 2, -size / 2),    // LEFT FACE
										position + Position3(-size / 2, size / 2, size / 2),
										position + Position3(-size / 2, -size / 2, size / 2),
										position + Position3(-size / 2, -size / 2, -size / 2),
										texture));
	faces.insert(faces.end(),
				 std::make_unique<Rect>(position + Position3(-size / 2, size / 2, -size / 2),    // TOP FACE
										position + Position3(size / 2, size / 2, -size / 2),
										position + Position3(size / 2, size / 2, size / 2),
										position + Position3(-size / 2, size / 2, size / 2),
										texture));
	faces.insert(faces.end(),
				 std::make_unique<Rect>(position + Position3(-size / 2, -size / 2, size / 2),    // BOT FACE
										position + Position3(size / 2, -size / 2, size / 2),
										position + Position3(size / 2, -size / 2, -size / 2),
										position + Position3(-size / 2, -size / 2, -size / 2),
										texture));
}

Cube::Cube(Position3 position, float size, const Texture &sideTexture, const Texture &topTexture, const Texture &bottomTexture) {
	vertexShaderPath = VERTEX_TEXTURE_SHADER;
	fragmentShaderPath = FRAGMENT_TEXTURE_SHADER;
	setIsTextured(true);
	faces.insert(faces.end(),
				 std::make_unique<Rect>(position + Position3(size / 2, size / 2, -size / 2),    // BACK FACE
				 position + Position3(-size / 2, size / 2, -size / 2),
				 position + Position3(-size / 2, -size / 2, -size / 2),
				 position + Position3(size / 2, -size / 2, -size / 2),
					sideTexture));
	faces.insert(faces.end(),
				 std::make_unique<Rect>(position + Position3(-size / 2, size / 2, size / 2),    // FRONT FACE
					 position + Position3(size / 2, size / 2, size / 2),
					 position + Position3(size / 2, -size / 2, size / 2),
					 position + Position3(-size / 2, -size / 2, size / 2),
					 sideTexture));
	faces.insert(faces.end(),
				 std::make_unique<Rect>(position + Position3(size / 2, size / 2, size / 2),    // RIGHT FACE
					 position + Position3(size / 2, size / 2, -size / 2),
					 position + Position3(size / 2, -size / 2, -size / 2),
					 position + Position3(size / 2, -size / 2, size / 2),
					 sideTexture));
	faces.insert(faces.end(),
				 std::make_unique<Rect>(position + Position3(-size / 2, size / 2, -size / 2),    // LEFT FACE
					 position + Position3(-size / 2, size / 2, size / 2),
					 position + Position3(-size / 2, -size / 2, size / 2),
					 position + Position3(-size / 2, -size / 2, -size / 2),
					 sideTexture));
	faces.insert(faces.end(),
				 std::make_unique<Rect>(position + Position3(-size / 2, size / 2, -size / 2),    // TOP FACE
					 position + Position3(size / 2, size / 2, -size / 2),
					 position + Position3(size / 2, size / 2, size / 2),
					 position + Position3(-size / 2, size / 2, size / 2),
					 topTexture));
	faces.insert(faces.end(),
				 std::make_unique<Rect>(position + Position3(-size / 2, -size / 2, size / 2),    // BOT FACE
					 position + Position3(size / 2, -size / 2, size / 2),
					 position + Position3(size / 2, -size / 2, -size / 2),
					 position + Position3(-size / 2, -size / 2, -size / 2),
					 bottomTexture));
}

Cube::~Cube() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Cube::draw(int windowWith, int windowHeight, glm::mat4 view) const {
	if (getIsTextured()) {
		for (auto const &rect: faces) {
			rect->draw(windowWith, windowHeight, view);
		}
	} else {
		shader.use();

		glm::mat4 projection    = glm::mat4(1.0f);

		projection = glm::perspective(glm::radians(45.0f), (float)windowWith / (float)windowHeight, 0.1f, 100.0f);

		shader.setMat4("projection", projection);
		shader.setMat4("view", view);
		shader.setMat4("model", getTransform());

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
	}
}

void Cube::setShader(Shader shader) {
	for (auto const &rect: faces) {
		rect->setShader(shader);
	}
}
