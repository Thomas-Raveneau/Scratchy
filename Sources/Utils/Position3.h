//
// Project: Scratchy
// File: Position3.h
//

#ifndef SCRATCHY_POSITION3_H
#define SCRATCHY_POSITION3_H

#include <tuple>

namespace Scratchy {

	class Position3 {

		private:
			std::tuple<float, float, float> coords;

		public:
			Position3();
			Position3(float x, float y, float z);
			~Position3();

		public:
			float getX() const;
			float getY() const;
			float getZ() const;
			float *getArray() const;

		public:
			void operator=(const Position3 &p);
	};
}

#endif //SCRATCHY_POSITION3_H
