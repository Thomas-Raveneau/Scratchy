//
// Project: Scratch
// File: Angle.cpp
//

#include "Angle.h"

using namespace Scratchy;

Angle::Angle(double x, double y) {
	compute(x , y);
}

Angle::~Angle() noexcept = default;

double Angle::toRadians() const {
	return angleInRadians;
}

double Angle::toDegrees() const {
	return angleInDegrees;
}

void Angle::compute(double x, double y) {
	angleInRadians = atan2(y, x);
	angleInDegrees = angleInRadians * M_PI / 180;
}
