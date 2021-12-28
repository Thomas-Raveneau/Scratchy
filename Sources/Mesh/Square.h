//
// Project: Scratchy
// File: Square.h
//

#ifndef SCRATCHY_SQUARE_H
#define SCRATCHY_SQUARE_H

#include <Mesh/Mesh.h>

namespace Scratchy {

	class Square: public Mesh {

		public:
			Square(Position3 a1, Position3 a2, Position3 a3, Position3 a4, Color color);
			~Square();
		public:
			void draw();
	};
}


#endif //SCRATCHY_SQUARE_H
