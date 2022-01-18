#include "Vector4.h"
#include "MathUtilities.h"

// Default constructor, initializes x,y,z to zeroes, w to defined value
Vector4::Vector4(void)
{
	for (int i = 0; i < 4; i++)
		v[i] = 0.0f;
}

// Copy constructor, copies every component from the other Vector4
Vector4::Vector4(const Vector4& rhs)
{
	for (int i = 0; i < 4; i++)
		v[i] = rhs.v[i];
}

// Non-Default constructor, self explanatory
Vector4::Vector4(float xx, float yy, float zz, float ww)
{
	x = xx;
	y = yy;
	z = zz;
	w = ww;
}

// Assignment operator, does not need to handle self assignment
Vector4& Vector4::operator=(const Vector4& rhs)
{
	if (*this != rhs)
	{
		for (int i = 0; i < 4; i++)
			v[i] = rhs.v[i];
	}

	return *this;
}

// Unary negation operator, negates all components and returns a copy
Vector4 Vector4::operator-(void) const
{
	Vector4 vec;
	for (int i = 0; i < 4; i++)
		vec.v[i] = -v[i];

	return vec;
}


// Basic Vector math operations. Add Vector to Vector B, or Subtract Vector A from
// Vector B, or multiply a vector with a scalar, or divide a vector by that scalar
Vector4 Vector4::operator+(const Vector4& rhs) const
{
	Vector4 vec;
	for (int i = 0; i < 4; i++)
		vec.v[i] = v[i] + rhs.v[i];

	return vec;
}

Vector4 Vector4::operator-(const Vector4& rhs) const
{
	Vector4 vec;
	for (int i = 0; i < 4; i++)
		vec.v[i] = v[i] - rhs.v[i];

	return vec;
}

Vector4 Vector4::operator*(const float rhs) const
{
	Vector4 vec;
	for (int i = 0; i < 4; i++)
		vec.v[i] = v[i] * rhs;

	return vec;
}

Vector4 Vector4::operator/(const float rhs) const
{
	Vector4 vec;
	for (int i = 0; i < 4; i++)
		vec.v[i] = v[i] / rhs;

	return vec;
}

// Same as above, just stores the result in the original vector
Vector4& Vector4::operator+=(const Vector4& rhs)
{
	*this = *this + rhs;
	return *this;
}

Vector4& Vector4::operator-=(const Vector4& rhs)
{
	*this = *this - rhs;
	return *this;
}

Vector4& Vector4::operator*=(const float rhs)
{
	*this = *this * rhs;
	return *this;
}

Vector4& Vector4::operator/=(const float rhs)
{
	*this = *this / rhs;
	return *this;
}

// Comparison operators which should use an epsilon defined in
// MathUtilities.h to see if the value is within a certain range
// in which case we say they are equivalent.
bool Vector4::operator==(const Vector4& rhs) const
{
	for (int i = 0; i < 4; i++)
		if (!isEqual(v[i], rhs.v[i]))
			return false;

	return true;
}

bool Vector4::operator!=(const Vector4& rhs) const
{
	return !(*this == rhs);
}


// Computes the dot product with the other vector. Treat it as 3D vector.
float Vector4::Dot(const Vector4& rhs) const
{
	float dot = 0.f;
	for (int i = 0; i < 4; i++)
		dot += v[i] * rhs.v[i];

	return dot;
}

// Computes the cross product with the other vector. Treat it as a 3D vector.
Vector4 Vector4::Cross(const Vector4& rhs) const
{
	Vector4 vec;
	vec.v[0] = v[1] * rhs.v[2] - v[2] * rhs.v[1];
	vec.v[1] = v[2] * rhs.v[0] - v[0] * rhs.v[2];
	vec.v[2] = v[0] * rhs.v[1] - v[1] * rhs.v[0];

	return vec;
}

// Computes the true length of the vector
float Vector4::Length(void) const
{
	return sqrt(LengthSq());
}

// Computes the squared length of the vector
float Vector4::LengthSq(void) const
{
	//Sanity check: value of w

	float lengthSq = 0.0f;
	for (int i = 0; i < 4; i++)
		lengthSq += v[i] * v[i];

	return lengthSq;
}

// Normalizes the vector to make the final vector be of length 1. If the length is zero
// then this function should not modify anything.
void Vector4::Normalize(void)
{
	float length = Length();

	if (length == 0.f)
		return;

	for (int i = 0; i < 4; i++)
		v[i] = v[i] / length;
}

// Sets x,y,z to zeroes, w to defined value
void Vector4::Zero(void)
{
	*this = Vector4(0.0f, 0.0f, 0.0f);
}

