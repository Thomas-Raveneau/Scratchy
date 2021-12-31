//
// Project: Scratchy
// File: Cube.h
//

#ifndef SCRATCHY_CUBE_H
#define SCRATCHY_CUBE_H

#include <Mesh/Mesh.h>
#include <Mesh/Primitives/Rect.h>

namespace Scratchy {

	class Cube: public Mesh {

		public:
			Cube(Position3 position, float size, Color color);
			Cube(Position3 position, float size, std::string texturePath);
			~Cube();

		public:
			void draw(int windowWith, int windowHeight) const final;
	};
}

#endif //SCRATCHY_CUBE_H
