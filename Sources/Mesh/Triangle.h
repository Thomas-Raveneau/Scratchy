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
			Triangle(Position3 a1, Position3 a2, Position3 a3, Color color);
			Triangle(Position3 a1, Position3 a2, Position3 a3, std::string texturePath);
			~Triangle();

		public:
			void draw() const override;
	};
}

#endif //SCRATCHY_TRIANGLE_H
