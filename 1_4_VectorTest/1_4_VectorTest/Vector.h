#ifndef VECTOR_H
#define VECTOR_H

#include <iosfwd>

class Vector
{
public:
	Vector(int length, const double values[]);
	Vector(const Vector&);
	~Vector();
	Vector& operator=(const Vector &rhs);
	Vector& operator+=(const Vector &rhs);
	Vector& operator-=(const Vector &rhs);
	Vector& operator*=(const double &scalar);
	const double & operator[](int index) const; // For getting value
	double & operator[](int index); // For setting value
	int length() const;
	// Purposely broken function to demonstrate contracts
	Vector& addVectorBroken(const Vector &rhs);

private:
	bool invariant() const;
	double *mValues; // Points to first element in array of mLength
	const int mLength;
};

const Vector operator+(const Vector &lhs, const Vector &rhs);
const Vector operator-(const Vector &lhs, const Vector &rhs);
const double operator*(const Vector &lhs, const Vector &rhs); // Dot product
const Vector operator*(const Vector &vector, double scalar);
const Vector operator*(double scalar, const Vector &vector);
bool operator==(const Vector &lhs, const Vector &rhs);
bool operator!=(const Vector &lhs, const Vector &rhs);
std::ostream& operator<<(std::ostream &stream, const Vector &vector); // Prints values to stream

#endif VECTOR_H