//
// Project: Scratchy
// File: Mesh.h
//

#ifndef SCRATCHY_MESH_H
#define SCRATCHY_MESH_H

#include <Mesh/IMesh.h>

namespace Scratchy {

	class Mesh: virtual public IMesh {

		public:
			Mesh(std::string vertexShaderPath, std::string fragmentShaderPath);
			Mesh(std::string vertexShaderPath, std::string fragmentShaderPath, std::string texturePath);
			~Mesh() = default;

		public :
			void drawWireframe(bool active) final;

		public:
			const std::vector<Position3> &getVertices() const final;
			void setVertices(const std::vector<Position3> &vertices) final;

			std::vector<float> getColoredVertices() const final;
			void setColor(Color &color) final;

			std::vector<float> getTexturedVertices() const final;
			void setTexture(std::string &filepath) final;
			void setTextureCoords(std::vector<Position2> &textureCoords) final;

			bool getIsTextured() const final;
			void setIsTextured(bool isTextured) final;

			const glm::mat4 &getTransform() const final;
			void setTransform(const glm::mat4 &transform) final;
	};
}


#endif //SCRATCHY_MESH_H
