#ifndef VECTOR2F_H
#define VECTOR2F_H

#include <cmath>


/**
* Vector2f class - manages all vector related operations of game.
* Appropriate operators are overloaded for required functionality of standard vector operations.
*/
class Vector2f
{
public:
	/**
	* Constructor. Creates Vector2f object.
	*/
	Vector2f();
	/**
	* Constructor. Creates Vector2f object with specific coordinates.
	* @param x is a float containing horizontal coordinate.
	* @param y is a float conaining vertical coordinate.
	*/
	Vector2f(float x, float y);
	/** 
	* Calculates and returns the unit vector of a vector.
	* @return Vector2f containg unit vector of the vector.
	*/
	Vector2f unitVector();
	/**
	* Calculates and returns the distance between two selected vectors.
	* @param vector1 is a Vector2f containing the first vector.
	* @param vector2 is a Vector2f conaining the second vector.
	* @return float containing the distance between the two vectors.
	*/
	float vectorDistance(Vector2f vector1, Vector2f vector2);
	float _x = 0;
	float _y = 0;
};

inline bool operator==(const Vector2f& lhs, const Vector2f& rhs)
{
	return (lhs._x == rhs._x && lhs._y == rhs._y);
}

inline bool operator!=(const Vector2f& lhs, const Vector2f& rhs)
{
	return !(lhs==rhs);
}

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