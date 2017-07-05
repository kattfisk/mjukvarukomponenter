#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
public:
	virtual ~Vector2D() {};
	virtual float getX() const = 0;
	virtual float getY() const = 0;
	virtual void set(float x, float y) = 0;
	virtual void setX(float x) = 0;
	virtual void setY(float y) = 0;
	virtual void add(const Vector2D &vector) = 0;
	virtual void subtract(const Vector2D &vector) = 0;
	virtual void multiply(const float scalar) = 0;
	virtual void normalize() = 0;

};

#endif // VECTOR2D_H