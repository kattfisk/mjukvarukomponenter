#ifndef STANDARDVECTOR2D_H
#define STANDARDVECTOR2D_H

#include "Vector2D.h"

class StandardVector2D : public Vector2D
{
public:
	StandardVector2D();
	StandardVector2D(float x, float y);
	explicit StandardVector2D(const Vector2D &vector);
	virtual float getX() const override;
	virtual float getY() const override;
	virtual void set(float x, float y) override;
	virtual void setX(float x) override;
	virtual void setY(float y) override;
	virtual void add(const Vector2D &vector) override;
	virtual void subtract(const Vector2D &vector) override;
	virtual void multiply(const float scalar) override;
	virtual void normalize() override;

private:
	float x, y;
};

#endif // STANDARDVECTOR2D_H