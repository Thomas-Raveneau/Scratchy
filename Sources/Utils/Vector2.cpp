//
// Project: Scratch
// File: Vector2.cpp
//

#include "Vector2.h"

using namespace Scratchy;

Vector2::Vector2(int x, int y) {
	set(x, y);
	angle = Angle(x, y);
}

Vector2::Vector2(int x, double y) {
	set(x, y);
	angle = Angle(x, y);
}

Vector2::Vector2(double x, int y) {
	set(x, y);
	angle = Angle(x, y);
}

Vector2::Vector2(double x, double y) {
	set(x, y);
	angle = Angle(x, y);
}

Vector2::~Vector2() noexcept = default;

void Vector2::set(int x, int y) {
	vector = std::make_pair(x, y);
}

void Vector2::set(int x, double y) {
	vector = std::make_pair(x, y);
}

void Vector2::set(double x, int y) {
	vector = std::make_pair(x, y);
}

void Vector2::set(double x, double y) {
	vector = std::make_pair(x, y);
}

void Vector2::setX(int x) {
	vector.first = x;
}

void Vector2::setX(double x) {
	vector.first = x;
}

double Vector2::getX() const {
	return vector.first;
}

void Vector2::setY(int y) {
	vector.second = y;
}

void Vector2::setY(double y) {
	vector.second = y;
}

double Vector2::getY() const {
	return vector.second;
}

void Vector2::operator=(const Vector2 &v) {
	vector = v.vector;
}

Vector2 Vector2::operator+(int n) {
	return Vector2(getX() + n, getY() + n);
}

Vector2 Vector2::operator+(double n) {
	return Vector2(getX() + n, getY() + n);
}

Vector2 Vector2::operator+(const Vector2 &v) {
	return Vector2(getX() + v.getX(), getY() + v.getY());
}

Vector2 Vector2::operator-(int n) {
	return Vector2(getX() - n, getY() - n);
}

Vector2 Vector2::operator-(double n) {
	return Vector2(getX() - n, getY() - n);
}

Vector2 Vector2::operator-(const Vector2 &v) {
	return Vector2(getX() - v.getX(), getY() - v.getY());
}

Vector2 Vector2::operator*(int n) {
	return Vector2(getX() * n, getY() * n);
}

Vector2 Vector2::operator*(double n) {
	return Vector2(getX() * n, getY() * n);
}

Vector2 Vector2::operator*(const Vector2 &v) {
	return Vector2(getX() * v.getX(), getY() * v.getY());
}

Vector2 Vector2::operator/(const Vector2 &v) {
	return Vector2(getX() / v.getX(), getY() / v.getY());
}

bool Vector2::operator==(const Vector2 &v) {
	return (getX() == v.getX() && getY() == v.getY());
}

std::ostream &operator<<(std::ostream &os, const Vector2 v) {
	os << "Vector2(" << v.getX() << ", " << v.getY() << ")";
	return os;
}

std::ostream &operator<<(std::ostream &os, const Vector2 *v) {
	os << "Vector2(" << v->getX() << ", " << v->getY() << ")";
	return os;
}
