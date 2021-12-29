//
// Project: Scratchy
// File: Mesh.h
//

#ifndef SCRATCHY_MESH_H
#define SCRATCHY_MESH_H

#include <Mesh/Shader.h>
#include <Mesh/Texture.h>

#include <Utils/Position2.h>
#include <Utils/Position3.h>
#include <Utils/Color.h>

#include <vector>

namespace Scratchy {

	class Mesh {
		private:
			enum DRAW_MODE {
				FILL,
				WIREFRAME
			};

			enum TYPE {
				TRIANGLE,
				RECTANGLE
			};

		protected:
			unsigned int VBO;
			unsigned int VAO;
			unsigned int EBO;

			Color color;
			Shader shader;
			Texture texture;

			TYPE type;
			DRAW_MODE drawMode = FILL;
			std::vector<Position3> vertices;
			std::vector<Position2> textureCoords;

			bool isTextured;

		public:
			Mesh(std::string vertexShaderPath, std::string fragmentShaderPath);
			Mesh(std::string vertexShaderPath, std::string fragmentShaderPath, std::string texturePath);
			~Mesh();

		public:
			void drawWireframe(bool active);

		public:
			virtual void draw() const {};

		public:
			std::vector<float> getVertices() const;
			void setVertices(std::vector<Position3> vertices);

			std::vector<float> getColoredVertices() const;
			void setColor(Color color);

			std::vector<float> getTexturedVertices() const;
			void setTexture(std::string filepath);
			void setTextureCoords(std::vector<Position2> textureCoords);

			bool getIsTextured() const;
			void setIsTextured(bool isTextured);
	};
}


#endif //SCRATCHY_MESH_H
