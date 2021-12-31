//
// Project: Scratchy
// File: Rect.h
//

#ifndef SCRATCHY_RECT_H
#define SCRATCHY_RECT_H

#include <Mesh/Mesh.h>

namespace Scratchy {

	class Rect: public Mesh {

		public:
			Rect(Position3 a1, Position3 a2, Position3 a3, Position3 a4, Color color);
			Rect(Position3 a1, Position3 a2, Position3 a3, Position3 a4, std::string texturePath);
			~Rect();
		public:
			void draw(int windowWith, int windowHeight) const final;
	};
}

#endif //SCRATCHY_RECT_H
