#include "UnitVector2D.h"

#include <math.h>

UnitVector2D::UnitVector2D(float x, float y)
	: vector(StandardVector2D(x, y))
{
	vector.normalize();
}

UnitVector2D::UnitVector2D()
	: vector(StandardVector2D())
{
	// We allow 0,0 unit vectors even though they're not really unit vectors
	// as they are useful to signify "no direction"
}

UnitVector2D::UnitVector2D(const Vector2D &vector)
	: vector(vector.getX(), vector.getY())
{
	this->vector.normalize();
}

float UnitVector2D::getX() const
{
	return vector.getX();
}

float UnitVector2D::getY() const
{
	return vector.getY();
}

void UnitVector2D::set(float x, float y)
{
	vector.set(x,y);
	vector.normalize();
}

void UnitVector2D::setX(float x)
{
	vector.setX(x);
	vector.normalize();
}

void UnitVector2D::setY(float y)
{
	vector.setY(y);
	vector.normalize();
}

void UnitVector2D::add(const Vector2D &vector)
{
	StandardVector2D v(vector.getX(), vector.getY());
	v.normalize();
	v.add(this->vector);
	v.normalize();
	this->vector = v;
}

void UnitVector2D::subtract(const Vector2D &vector)
{
	StandardVector2D v(vector.getX(), vector.getY());
	v.normalize();
	this->vector.subtract(v);
	this->vector.normalize();
}

void UnitVector2D::multiply(const float scalar)
{ 
// There are only two cases in which scalar multiplication of a unit vector
// changes it and they are covered below.
	if(scalar < 0)
	{
		vector.multiply(-1);
	}
	else if(scalar == 0)
	{
		vector.set(0, 0);
	}
}

void UnitVector2D::normalize()
{
	// Do nothing
}