//
// Project: Scratchy
// File: Mesh.h
//

#ifndef SCRATCHY_MESH_H
#define SCRATCHY_MESH_H

#include <Mesh/Shader.h>
#include <Mesh/Texture.h>

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

		protected:
			unsigned int VBO;
			unsigned int VAO;
			unsigned int EBO;

			Color color;
			Shader shader;
			Texture texture;

			DRAW_MODE drawMode = FILL;
			std::vector<Position3> vertices;

			bool isTextured;

		public:
			Mesh(std::string vertexShaderPath, std::string fragmentShaderPath);
			Mesh(std::string vertexShaderPath, std::string fragmentShaderPath, std::string texturePath);
			~Mesh();

		public:
			void drawWireframe(bool active);

		public:
			virtual void draw() const;
			virtual void setTexture(std::string filepath);

		public:
			std::vector<float> getVertices();
			std::vector<float> getColoredVertices();
			std::vector<float> getTexturedVertices();
	};
}


#endif //SCRATCHY_MESH_H
