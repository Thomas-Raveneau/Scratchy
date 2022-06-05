//
// Project: Scratchy
// File: IMesh.h
//

#ifndef SCRATCHY_IMESH_H
#define SCRATCHY_IMESH_H

#include <Mesh/Shader.h>
#include <Mesh/Texture.h>

#include <Utils/Position2.h>
#include <Utils/Position3.h>
#include <Utils/Color.h>

#include <vector>
#include <memory>

namespace Scratchy {

	class IMesh {
		protected:
			enum DRAW_MODE {
				FILL,
				WIREFRAME
			};

			enum TYPE {
				TRIANGLE,
				RECTANGLE,
				CUBE
			};

		public:
			unsigned int VBO;
			unsigned int VAO;
			unsigned int EBO;

			Color color;
			std::unique_ptr<Shader> shader;
			Texture texture;

			TYPE type;
			DRAW_MODE drawMode = FILL;

			std::vector<Position3> vertices;
			std::vector<Position2> textureCoords;

			glm::mat4 transform;

			bool isTextured;

		public:
			std::string vertexShaderPath;
			std::string fragmentShaderPath;

		public:
			virtual ~IMesh() = default;

		public:
			virtual void draw(int windowWith, int windowHeight, glm::mat4 view) const = 0;
			virtual void drawWireframe(bool active) = 0;

			virtual void rotate() = 0;

		public:
			virtual const std::vector<Position3> &getVertices() const = 0;
			virtual void setVertices(const std::vector<Position3> &vertices) = 0;

			virtual std::vector<float> getColoredVertices() const = 0;
			virtual void setColor(const Color &color) = 0;

			virtual std::vector<float> getTexturedVertices() const = 0;
			virtual void setTexture(const std::string &filepath) = 0;
			virtual void setTexture(const Texture &texture) = 0;
			virtual void setTextureCoords(const std::vector<Position2> &textureCoords) = 0;

			virtual bool getIsTextured() const = 0;
			virtual void setIsTextured(bool isTextured) = 0;

			virtual const glm::mat4 &getTransform() const = 0;
			virtual void setTransform(const glm::mat4 &transform) = 0;

			virtual void setShader(Shader shader) = 0;
	};
}

#endif //SCRATCHY_IMESH_H

