//
// Project: Scratchy
// File: Position2.h
//

#ifndef SCRATCHY_POSITION2_H
#define SCRATCHY_POSITION2_H

#include <tuple>

namespace Scratchy {

	class Position2 {

		private:
			std::tuple<float, float> coords;

		public:
			Position2();
			Position2(float x, float y);
			~Position2();

		public:
			float getX() const;
			float getY() const;
			float *getArray() const;

		public:
			void operator=(const Position2 &p);
	};
}


#endif //SCRATCHY_POSITION2_H
