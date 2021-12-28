//
// Project: Scratch
// File: Angle.h
//

#ifndef SCRATCH_ANGLE_H
#define SCRATCH_ANGLE_H

#define _USE_MATH_DEFINES

#pragma once

#include <cmath>

namespace Scratchy {

	class Angle {

		private:
			double angleInRadians;
			double angleInDegrees;

		public:
			Angle(double x = 0, double y = 0);
			~Angle();

		public:
			double toRadians() const;
			double toDegrees() const;

		private:
			void compute(double x, double y);
	};
}



#endif //SCRATCH_ANGLE_H
