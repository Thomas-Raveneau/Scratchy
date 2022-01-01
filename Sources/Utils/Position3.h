//
// Project: Scratchy
// File: Position3.h
//

#ifndef SCRATCHY_POSITION3_H
#define SCRATCHY_POSITION3_H

#include <tuple>
#include <vector>

namespace Scratchy {

	class Position3 {

		private:
			std::tuple<float, float, float> coords;

		public:
			Position3() = default;
			Position3(float x, float y, float z);
			~Position3() = default;

		public:
			void setX(const float x);
			float getX() const;
			void setY(const float y);
			float getY() const;
			void setZ(const float z);
			float getZ() const;

			float *getArray() const;

		public:
			void operator=(const Position3 &p);

			Position3 operator+(const Position3 &position);
	};
}

#endif //SCRATCHY_POSITION3_H
