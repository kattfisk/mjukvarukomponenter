#include "Vector.h"

#include <cassert>
#include <ostream>

namespace
{
	// Helper function to copy all values of one Vector to another
	void copyValues(const Vector & source, Vector & target)
	{
		assert(source.length() == target.length());
		for (int i = 0; i < source.length(); ++i)
		{
			target[i] = source[i];
		}

#ifndef NDEBUG
		int length = source.length();
		for (int i = 0; i < length; ++i)
		{
			assert(source[i] == target[i]);
		}
#endif // NDEBUG
	}
}

Vector::Vector(const int length, const double values[])
: mLength(length), mValues(new double[length])
{
	assert(length > 0);

	for (int i = 0; i < mLength; ++i)
	{
		mValues[i] = values[i];
	}

	assert(mLength == length);
#ifndef NDEBUG
	for (int i = 0; i < mLength; ++i)
	{
		assert(mValues[i] == values[i]);
	}
#endif // NDEBUG
	assert(invariant());
}

Vector::Vector(const Vector& vector)
: mLength(vector.mLength), mValues(new double[vector.mLength])
{
	assert(vector.mLength > 0);
	assert(vector.mValues != 0);

	copyValues(vector, *this);

	assert(mLength == vector.mLength);
#ifndef NDEBUG
	for (int i = 0; i < mLength; ++i)
	{
		assert(mValues[i] == vector.mValues[i]);
	}
#endif // NDEBUG
	assert(invariant());
}

Vector::~Vector()
{
	assert(invariant());
	delete mValues;
	mValues = 0;
	assert(mValues == 0);
}

Vector& Vector::operator=(const Vector &rhs)
{
	assert(invariant());
	assert(rhs.length() == mLength);

	copyValues(rhs, *this);

	assert(rhs.length() == mLength);
#ifndef NDEBUG
	for (int i = 0; i < mLength; ++i)
	{
		assert(mValues[i] == rhs.mValues[i]);
	}
#endif // NDEBUG
	assert(invariant());
	return *this;
}

Vector& Vector::operator+=(const Vector &rhs)
{
	assert(invariant());
	assert(rhs.length() == mLength);
#ifndef NDEBUG
	double *oldMValues = new double[mLength];
	for (int i = 0; i < mLength; ++i)
	{
		oldMValues[i] = mValues[i];
	}
#endif

	for (int i = 0; i < mLength; ++i)
	{
		mValues[i] += rhs.mValues[i];
	}

#ifndef NDEBUG
	for (int i = 0; i < mLength; ++i)
	{
		assert(mValues[i] == oldMValues[i] + rhs.mValues[i]);
	}
#endif // NDEBUG
	assert(invariant());
	return *this;
}

Vector& Vector::operator-=(const Vector &rhs)
{
	assert(invariant());
	assert(rhs.length() == mLength);
#ifndef NDEBUG
	double *oldMValues = new double[mLength];
	for (int i = 0; i < mLength; ++i)
	{
		oldMValues[i] = mValues[i];
	}
#endif

	for (int i = 0; i < mLength; ++i)
	{
		mValues[i] -= rhs.mValues[i];
	}

#ifndef NDEBUG
	for (int i = 0; i < mLength; ++i)
	{
		assert(mValues[i] == oldMValues[i] - rhs.mValues[i]);
	}
#endif // NDEBUG
	assert(invariant());
	return *this;
}

Vector& Vector::operator*=(const double &scalar)
{
	assert(invariant());
#ifndef NDEBUG
	double *oldMValues = new double[mLength];
	for (int i = 0; i < mLength; ++i)
	{
		oldMValues[i] = mValues[i];
	}
#endif

	for (int i = 0; i < mLength; ++i)
	{
		mValues[i] *= scalar;
	}

#ifndef NDEBUG
	for (int i = 0; i < mLength; ++i)
	{
		assert(mValues[i] == oldMValues[i] * scalar);
	}
#endif // NDEBUG
	assert(invariant());
	return *this;
}

// For getting value
const double & Vector::operator[](int index) const
{
	assert(invariant());
	assert(index < mLength);
	assert(index >= 0);
	return mValues[index];
}

// For setting value
double & Vector::operator[](int index)
{
	assert(invariant());
	assert(index < mLength);
	assert(index >= 0);
	return mValues[index];
}

int Vector::length() const
{
	assert(invariant());
	return mLength;
}

Vector& Vector::addVectorBroken(const Vector &rhs)
{
	assert(invariant());
	assert(rhs.length() == mLength);
#ifndef NDEBUG
	double *oldMValues = new double[mLength];
	for (int i = 0; i < mLength; ++i)
	{
		oldMValues[i] = mValues[i];
	}
#endif

	for (int i = 0; i < mLength; ++i)
	{
		// This should be mValues[i] += rhs.mValues[i];
		mValues[i] += mValues[i];
	}

#ifndef NDEBUG
	for (int i = 0; i < mLength; ++i)
	{
		assert(mValues[i] == oldMValues[i] + rhs.mValues[i]);
	}
#endif // NDEBUG
	assert(invariant());
	return *this;
}

bool Vector::invariant() const
{
	return mLength > 0 && mValues != 0;
}

const Vector operator+(const Vector &lhs, const Vector &rhs)
{
	assert(lhs.length() > 0);
	assert(lhs.length() == rhs.length());

	Vector result(lhs);
	result += rhs;

#ifndef NDEBUG
	for (int i = 0; i < lhs.length(); ++i)
	{
		assert(result[i] == lhs[i] + rhs[i]);
	}
#endif // NDEBUG
	return result;
}

const Vector operator-(const Vector &lhs, const Vector &rhs)
{
	assert(lhs.length() > 0);
	assert(lhs.length() == rhs.length());

	Vector result(lhs);
	result -= rhs;

#ifndef NDEBUG
	for (int i = 0; i < lhs.length(); ++i)
	{
		assert(result[i] == lhs[i] - rhs[i]);
	}
#endif // NDEBUG
	return result;
}

const double operator*(const Vector &lhs, const Vector &rhs)
{
	assert(lhs.length() > 0);
	assert(lhs.length() == rhs.length());

	double result = 0;
	for (int i = 0; i < lhs.length(); ++i)
	{
		result += lhs[i] * rhs[i];
	}

#ifndef NDEBUG
	double expectedResult = 0.0;
	for (int i = 0; i < lhs.length(); ++i)
	{
		expectedResult += lhs[i] * rhs[i];
	}
	assert(result == expectedResult);
#endif // NDEBUG
	return result;
}

const Vector operator*(const Vector &vector, const double scalar)
{
	assert(vector.length() > 0);

	Vector result(vector);
	result *= scalar;

#ifndef NDEBUG
	for (int i = 0; i < vector.length(); ++i)
	{
		assert(result[i] == vector[i] * scalar);
	}
#endif // NDEBUG
	return result;
}

const Vector operator*(const double scalar, const Vector &vector)
{
	return vector*scalar;
}

bool operator==(const Vector &lhs, const Vector &rhs)
{
	assert(lhs.length() > 0);
	assert(lhs.length() == rhs.length());

	bool result = true;
	for (int i = 0; i < lhs.length(); ++i)
	{
		if (lhs[i] != rhs[i])
		{
			result = false;
			break;
		}
	}

#ifndef NDEBUG
	int diffs = 0;
	for (int i = 0; i < lhs.length(); ++i)
	{
		diffs += (lhs[i] != rhs[i]);
	}
	assert(result == (diffs == 0));
#endif // NDEBUG
	return result;
}

bool operator!=(const Vector &lhs, const Vector &rhs)
{
	return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream &stream, const Vector &vector)
{
	assert(vector.length() > 0);

	stream << vector[0];
	for (int i = 1; i < vector.length(); ++i)
	{
		stream << ", " << vector[i];
	}
	return stream;
}