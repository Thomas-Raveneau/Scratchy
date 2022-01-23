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
			Mesh() = default;
			Mesh(TYPE type, const std::string &vertexShaderPath, const std::string &fragmentShaderPath);
			Mesh(TYPE type, const std::string &vertexShaderPath, const std::string &fragmentShaderPath, const Texture &texture);
			Mesh(TYPE type, const std::string &vertexShaderPath, const std::string &fragmentShaderPath, const std::string &texturePath);
			~Mesh() = default;

		public :
			void drawWireframe(bool active) final;

			void rotate() final;

		public:
			const std::vector<Position3> &getVertices() const final;
			void setVertices(const std::vector<Position3> &vertices) final;

			std::vector<float> getColoredVertices() const final;
			void setColor(const Color &color) final;

			std::vector<float> getTexturedVertices() const final;
			void setTexture(const std::string &filepath) final;
			void setTexture(const Texture &texture) final;
			void setTextureCoords(const std::vector<Position2> &textureCoords) final;

			bool getIsTextured() const final;
			void setIsTextured(bool isTextured) final;

			const glm::mat4 &getTransform() const final;
			void setTransform(const glm::mat4 &transform) final;

			void setShader(Shader shader) override;
	};
}

#endif //SCRATCHY_MESH_H
