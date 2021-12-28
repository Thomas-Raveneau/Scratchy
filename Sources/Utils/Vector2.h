//
// Project: Scratch
// File: Vector2.h
//

#ifndef SCRATCH_VECTOR2_H
#define SCRATCH_VECTOR2_H

#pragma once

#include <utility>
#include <iostream>
#include <memory>

#include "Angle.h"

namespace Scratchy {

    class Vector2 {

		private:
			std::pair<double, double> vector;

		public:
			Angle angle;

		public :
            Vector2(int x, int y);
			Vector2(int x, double y);
			Vector2(double x, int y);
			Vector2(double x, double y);

			~Vector2();

		public:
			void set(int x, int y);
			void set(int x, double y);
			void set(double x, int y);
			void set(double x, double y);

			void setX(int x);
			void setX(double x);
			double getX() const;

			void setY(int y);
			void setY(double y);
			double getY() const;

			void operator=(const Vector2 &);

			Vector2 operator+(int n);
			Vector2 operator+(double n);
			Vector2 operator+(const Vector2 &v);

			Vector2 operator-(int n);
			Vector2 operator-(double n);
			Vector2 operator-(const Vector2 &v);

			Vector2 operator*(int n);
			Vector2 operator*(double n);
			Vector2 operator*(const Vector2 &v);

			Vector2 operator/(const Vector2 &v);

			bool operator==(const Vector2 &v);

			friend std::ostream &operator<<(std::ostream &os, const Vector2 v);
			friend std::ostream &operator<<(std::ostream &os, const Vector2 *v);
	};
}


#endif //SCRATCH_VECTOR2_H
