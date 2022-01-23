//
// Project: Scratchy
// File: Triangle.h
//

#ifndef SCRATCHY_TRIANGLE_H
#define SCRATCHY_TRIANGLE_H

#include <Mesh/Mesh.h>

namespace Scratchy {

	class Triangle: public Mesh {

		public:
			Triangle(Position3 a1, Position3 a2, Position3 a3, const Color &color);
			Triangle(Position3 a1, Position3 a2, Position3 a3, const Texture &texture);
			~Triangle();

		public:
			void draw(int windowWith, int windowHeight, glm::mat4 view) const final;
	};
}

#endif //SCRATCHY_TRIANGLE_H
