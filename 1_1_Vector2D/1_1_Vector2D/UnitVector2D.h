#ifndef UNITVECTOR2D_H
#define UNITVECTOR2D_H

#include "Vector2D.h"
#include "StandardVector2D.h"

class UnitVector2D : public Vector2D
{
public:
	UnitVector2D();
	UnitVector2D(float x, float y);
	explicit UnitVector2D(const Vector2D &vector);
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
	StandardVector2D vector;
};

#endif // UNITVECTOR2D_H