#include "StandardVector2D.h"

#include <math.h>

StandardVector2D::StandardVector2D(float x, float y)
	: x(x), y(y)
{
}

StandardVector2D::StandardVector2D()
	: x(0), y(0)
{
}

StandardVector2D::StandardVector2D(const Vector2D &vector)
	: x(vector.getX()), y(vector.getY())
{
}

float StandardVector2D::getX() const
{
	return x;
}

float StandardVector2D::getY() const
{
	return y;
}

void StandardVector2D::set(float x, float y)
{
	this->x = x;
	this->y = y;
}

void StandardVector2D::setX(float x)
{
	this->x = x;
}

void StandardVector2D::setY(float y)
{
	this->y = y;
}

void StandardVector2D::add(const Vector2D &vector)
{
	x+=vector.getX();
	y+=vector.getY();
}

void StandardVector2D::subtract(const Vector2D &vector)
{
	x-=vector.getX();
	y-=vector.getY();
}

void StandardVector2D::multiply(float scalar)
{
	x*=scalar;
	y*=scalar;
}

void StandardVector2D::normalize()
{
	if(!(x == 0 && y == 0))
	{ // We can't normalise the zero vector
		float length = sqrt((x * x) + (y * y));
		x/=length;
		y/=length;
	}
}