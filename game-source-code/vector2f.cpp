#include "vector2f.h"

Vector2f::Vector2f()
{}

Vector2f::Vector2f(float x, float y):
	_x{x},
	_y{y}
{}

Vector2f Vector2f::unitVector()
{
	auto magnitude = sqrtf(_x*_x+ _y*_y);
	return Vector2f(this->_x/magnitude, this->_y/magnitude);
}

float Vector2f::vectorDistance(Vector2f vector1, Vector2f vector2)
{
	auto x_resultant = vector1._x - vector2._x;
	auto y_resultant = vector1._y - vector2._y;
	return sqrtf(x_resultant*x_resultant + y_resultant*y_resultant);
}