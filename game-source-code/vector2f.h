#ifndef VECTOR2F_H
#define VECTOR2F_H

#include <cmath>

class Vector2f
{
public:
	Vector2f();
	Vector2f(float x, float y);
	Vector2f unitVector();
	float vectorDistance(Vector2f vector1, Vector2f vector2);
	float _x = 0;
	float _y = 0;
	
private:

};

inline bool operator==(const Vector2f& lhs, const Vector2f& rhs)
{
	return (lhs._x == rhs._x && lhs._y == rhs._y);
}

inline bool operator!=(const Vector2f& lhs, const Vector2f& rhs)
{
	return !(lhs==rhs);
}

// PLUS operators

inline Vector2f operator+( const Vector2f& lhs, const Vector2f& rhs)
{
	return Vector2f(lhs._x + rhs._x, lhs._y + rhs._y);
}

inline Vector2f operator+( const Vector2f& lhs, float scalar)
{
	return Vector2f(lhs._x + scalar, lhs._y + scalar);
}

inline Vector2f& operator+= ( Vector2f& lhs, const Vector2f& rhs)
{
	lhs = Vector2f(lhs._x + rhs._x, lhs._y + rhs._y);
	return lhs;
}

inline Vector2f& operator+= ( Vector2f& lhs, float scalar)
{
	lhs = Vector2f(lhs._x + scalar, lhs._y + scalar);
	return lhs;
}

// MINUS operators

inline Vector2f operator-( const Vector2f& lhs, const Vector2f& rhs)
{
	return Vector2f(lhs._x - rhs._x, lhs._y - rhs._y);
}

inline Vector2f operator-( const Vector2f& lhs, float scalar)
{
	return Vector2f(lhs._x - scalar, lhs._y - scalar);
}

inline Vector2f& operator-= ( Vector2f& lhs, Vector2f rhs)
{
	lhs = Vector2f(lhs._x - rhs._x, lhs._y - rhs._y);
	return lhs;
}

inline Vector2f& operator-= ( Vector2f& lhs, float scalar)
{
	lhs = Vector2f(lhs._x - scalar, lhs._y - scalar);
	return lhs;
}

// MULTIPL_y operators (dot product)

inline float operator*( Vector2f lhs, Vector2f rhs)
{
	return lhs._x * rhs._x + lhs._y * rhs._y;
}

inline Vector2f operator* ( Vector2f lhs, float scalar)
{
	return Vector2f(lhs._x * scalar , lhs._y * scalar);
}

inline Vector2f operator* ( float scalar, Vector2f lhs)
{
	return Vector2f(lhs._x * scalar , lhs._y * scalar);
}

inline Vector2f& operator*= ( Vector2f& lhs, Vector2f rhs)
{
	lhs = Vector2f(lhs._x * rhs._x, lhs._y * rhs._y);
	return lhs;
}

inline Vector2f& operator*= ( Vector2f& lhs, float scalar)
{
	lhs = Vector2f(lhs._x * scalar, lhs._y * scalar);
	return lhs;
}

// DIVISION operators

inline Vector2f operator/ ( Vector2f lhs, float scalar)
{
	return Vector2f( lhs._x / scalar , lhs._y / scalar);
}

inline Vector2f& operator/= ( Vector2f& lhs, float scalar)
{
	lhs = Vector2f( lhs._x / scalar , lhs._y / scalar);
	return lhs;
}

#endif