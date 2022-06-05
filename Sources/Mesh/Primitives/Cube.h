//
// Project: Scratchy
// File: Cube.h
//

#ifndef SCRATCHY_CUBE_H
#define SCRATCHY_CUBE_H

#include <Mesh/Mesh.h>
#include <Mesh/Primitives/Rect.h>

#include <vector>

namespace Scratchy {

	class Cube: public Mesh {

		private:
			std::vector<Rect *> faces;

		public:
			Cube(Position3 position, float size, const Color &color);
			Cube(Position3 position, float size, const Texture &texture);
			Cube(Position3 position, float size, const Texture &sideTexture, const Texture &topTexture, const Texture &bottomTexture);
			~Cube();

		public:
			void draw(int windowWith, int windowHeight, glm::mat4 view) const final;

		public:
			void setShader(Shader shader) final;
	};
}

#endif //SCRATCHY_CUBE_H
