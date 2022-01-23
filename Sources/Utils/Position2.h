//
// Project: Scratchy
// File: Position2.h
//

#ifndef SCRATCHY_POSITION2_H
#define SCRATCHY_POSITION2_H

#include <tuple>
#include <vector>

namespace Scratchy {

	class Position2 {

		private:
			std::tuple<float, float> coords;

		public:
			Position2() = default;
			Position2(float x, float y);
			~Position2() = default;

		public:
			void setPosition(float x, float y);

			void setX(const float x);
			float getX() const;

			void setY(const float y);
			float getY() const;

			float *getArray() const;

		public:
			void operator=(const Position2 &p);
	};
}


#endif //SCRATCHY_POSITION2_H
