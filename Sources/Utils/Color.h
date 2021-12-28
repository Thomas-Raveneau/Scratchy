//
// Project: Scratchy
// File: Color.h
//

#ifndef SCRATCHY_COLOR_H
#define SCRATCHY_COLOR_H

#include <iostream>

namespace Scratchy {

	class Color {
		public:
			float r;
			float g;
			float b;
			float a;

		public:
			Color();
			Color(float r, float g, float b);
			Color(float r, float g, float b, float a);
			~Color();

		public:
			friend std::ostream &operator<<(std::ostream &os, const Color c);
	};
}

#endif //SCRATCHY_COLOR_H
