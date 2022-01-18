#include "Point4.h"
#include "MathUtilities.h"


// Default constructor, sets x,y,z to zero and w to the defined value
Point4::Point4(void)
{
	for (int i = 0; i < 3; i++)
		v[i] = 0.f;
	w = 1.f;
}

// Copy constructor, copies every component from the other Point4
Point4::Point4(const Point4& rhs)
{
	for (int i = 0; i < 4; i++)
		v[i] = rhs.v[i];
}

// Non-Default constructor, self-explanatory
Point4::Point4(float xx, float yy, float zz, float ww)
{
	x = xx;
	y = yy;
	z = zz;
	w = ww;
}


// Assignment operator, copies every component from the other Point4
Point4& Point4::operator=(const Point4& rhs)
{
	for (int i = 0; i < 4; i++)
		v[i] = rhs.v[i];
	return *this;
}


// Unary negation operator, negates every component and returns a copy
Point4 Point4::operator-(void) const
{
	Point4 vec;
	for (int i = 0; i < 4; i++)
		vec.v[i] = -v[i];

	return vec;
}


// Binary subtraction operator, Subtract two Point4s and you get a Vector4
Vector4 Point4::operator-(const Point4& rhs) const
{
	Vector4 vec;
	for (int i = 0; i < 4; i++)
		vec.v[i] = v[i] - rhs.v[i];

	return vec;
}

// Basic vector math operations with points, you can add a Vector4 to a Point4, or
// subtract a Vector4 from a Point4
Point4 Point4::operator+ (const Vector4& rhs) const
{
	Point4 point;
	for (int i = 0; i < 4; i++)
		point.v[i] = v[i] + rhs.v[i];

	return point;
}

Point4 Point4::operator- (const Vector4& rhs) const
{
	Point4 point;
	for (int i = 0; i < 4; i++)
		point.v[i] = v[i] - rhs.v[i];

	return point;
}


// Same as previous two operators, just modifies the original instead of returning a
// copy
Point4& Point4::operator+=(const Vector4& rhs)
{
	*this = *this + rhs;
	return *this;
}

Point4& Point4::operator-=(const Vector4& rhs)
{
	*this = *this - rhs;
	return *this;
}


// Comparison operators which should use an epsilon defined in
// MathUtilities.h to see if the value is within a certain range
// in which case we say they are equivalent.
bool Point4::operator==(const Point4& rhs) const
{
	for (int i = 0; i < 4; i++)
		if (!isEqual(v[i], rhs.v[i]))
			return false;

	return true;
}

bool Point4::operator!=(const Point4& rhs) const
{
	return !(*this == rhs);
}


// Sets x,y,z to zeroes, w to defined value
void Point4::Zero(void)
{
	*this = Point4(0.0f, 0.0f, 0.0f);
}

