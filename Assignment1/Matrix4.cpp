#include "Matrix4.h"
#include "MathUtilities.h"

// Default constructor should initialize to zeroes
Matrix4::Matrix4(void)
{
	for (int i = 0; i < 16; i++)
		v[i] = 0.0f;
}

// Copy constructor, copies every entry from the other matrix.
Matrix4::Matrix4(const Matrix4& rhs)
{
	for (int i = 0; i < 16; i++)
		v[i] = rhs.v[i];
}

// Non-default constructor, self-explanatory
Matrix4::Matrix4(float mm00, float mm01, float mm02, float mm03,
float mm10, float mm11, float mm12, float mm13,
float mm20, float mm21, float mm22, float mm23,
float mm30, float mm31, float mm32, float mm33)
{
	m[0][0] = mm00;	m[0][1] = mm01;	m[0][2] = mm02; m[0][3] = mm03;
	m[1][0] = mm10;	m[1][1] = mm11;	m[1][2] = mm12; m[1][3] = mm13;
	m[2][0] = mm20;	m[2][1] = mm21;	m[2][2] = mm22; m[2][3] = mm23;
	m[3][0] = mm30;	m[3][1] = mm31;	m[3][2] = mm32; m[3][3] = mm33;
}

// Assignment operator, does not need to handle self-assignment
Matrix4& Matrix4::operator=(const Matrix4& rhs)
{
	for (int i = 0; i < 16; i++)
		v[i] = rhs.v[i];
	return *this;
}

// Multiplying a Matrix4 with a Vector4 or a Point4
Vector4 Matrix4::operator*(const Vector4& rhs) const
{
	Vector4 vec;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			vec.v[i] += m[i][j] * rhs.v[j];
		}
	}

	return vec;
}

Point4 Matrix4::operator*(const Point4& rhs) const
{
	Point4 point;
	point.w = 0.f;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			point.v[i] += m[i][j] * rhs.v[j];
		}
	}

	return point;
}


// Basic Matrix arithmetic operations
Matrix4 Matrix4::operator+(const Matrix4& rhs) const
{
	Matrix4 mtx;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mtx.m[i][j] += m[i][j] + rhs.m[i][j];
		}
	}

	return mtx;
}

Matrix4 Matrix4::operator-(const Matrix4& rhs) const
{
	Matrix4 mtx;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mtx.m[i][j] += m[i][j] - rhs.m[i][j];
		}
	}

	return mtx;
}

Matrix4 Matrix4::operator*(const Matrix4& rhs) const
{
	Matrix4 mtx;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				mtx.m[i][j] += m[i][k] * rhs.m[k][j];
			}
		}
	}

	return mtx;
}


// Similar to the three above except they modify the original
Matrix4& Matrix4::operator+=(const Matrix4& rhs)
{
	*this = *this + rhs;
	return *this;
}

Matrix4& Matrix4::operator-=(const Matrix4& rhs)
{
	*this = *this - rhs;
	return *this;
}
Matrix4& Matrix4::operator*=(const Matrix4& rhs)
{
	*this = *this * rhs;
	return *this;
}


// Scale/Divide the entire matrix by a float
Matrix4 Matrix4::operator*(const float rhs) const
{
	Matrix4 mtx;
	for (int i = 0; i < 16; i++)
		mtx.v[i] = rhs * v[i];

	return mtx;
}

Matrix4 Matrix4::operator/(const float rhs) const
{
	Matrix4 mtx;
	for (int i = 0; i < 16; i++)
		mtx.v[i] = v[i] / rhs;

	return mtx;
}


// Same as previous
Matrix4& Matrix4::operator*=(const float rhs)
{
	*this = *this * rhs;
	return *this;
}

Matrix4& Matrix4::operator/=(const float rhs)
{
	*this = *this / rhs;
	return *this;
}


// Comparison operators which should use an epsilon defined in
// MathUtilities.h to see if the value is within a certain range
// in which case we say they are equivalent.
bool Matrix4::operator==(const Matrix4& rhs) const
{
	for (int i = 0; i < 16; i++)
	{
		if (!isEqual(v[i], rhs.v[i]))
			return false;
	}

	return true;
}

bool Matrix4::operator!=(const Matrix4& rhs) const
{
	return !(*this == rhs);
}


// Zeroes out the entire matrix
void Matrix4::Zero(void)
{
	for (int i = 0; i < 16; i++)
		v[i] = 0.0f;
}

// Builds the identity matrix
void Matrix4::Identity(void)
{
	Zero();
	for (int i = 0; i < 4; i++)
		m[i][i] = 1.0f;
}