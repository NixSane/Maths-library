#include "vector_2.h"
#include <cassert>
#include <cmath>


vector_2::vector_2(const float a_x, const float a_y) : 
	data{ a_x, a_y }
{
}


float& vector_2::operator[] (const int a_index)
{
	_STL_ASSERT((a_index >= 0) && (a_index < 2) ,
		"Vector 2 index is out of range");
	return data[a_index];
}

vector_2::operator float* ()
{
	return data;
}

vector_2::operator const float* () const
{
	return data;
}

vector_2 vector_2::operator+(const vector_2& a_rhs)
{
	return vector_2(x + a_rhs.x, y + a_rhs.y);
}

vector_2 vector_2::operator-(const vector_2& a_rhs)
{
	return vector_2(x - a_rhs.x, y - a_rhs.y);
}

vector_2 vector_2::operator/(const float a_rhs) const
{
	return vector_2(x / a_rhs, y / a_rhs);
}

vector_2 vector_2::operator*(const float a_rhs) const
{
	return vector_2(x * a_rhs, y * a_rhs);
}

vector_2 operator*(const float a_lhs, const vector_2& a_rhs)
{
	return a_rhs * a_lhs;
}

vector_2 vector_2::operator+=(const vector_2& a_rhs)
{		 
	*this = *this + a_rhs;
	return *this;
}		 
		 
vector_2 vector_2::operator-=(const vector_2& a_rhs)
{
	*this = *this - a_rhs;
	return *this;
}
vector_2 vector_2::operator/=(const float a_rhs)
{
	x /= a_rhs;
	y /= a_rhs;
	return *this;
}

vector_2 vector_2::operator*=(const float a_rhs) 
{
	*this = *this * a_rhs;
	return *this;
}

float vector_2::square_magnitude() const
{
	return (x * x) + (y * y);
}

float vector_2::magnitude() const
{
	return sqrt(square_magnitude());
}

void vector_2::normalise()
{
	*this /= magnitude();
}

vector_2 vector_2::normalised() const
{
	return *this / magnitude();
}

float vector_2::dot(const vector_2& a_vector_2) const
{
	return (x * a_vector_2.x) +
		   (y * a_vector_2.y);
}

float vector_2::dot(const vector_2& a_vec2_1, const vector_2& a_vec2_2)
{
	return a_vec2_1.dot(a_vec2_2);
}

vector_2 vector_2::cross(const vector_2& a_vector_2) const
{
	return { y * a_vector_2.x - x * a_vector_2.y };
}

vector_2 vector_2::cross(const vector_2& a_vec2_1, const vector_2& a_vec2_2)
{
	return a_vec2_1.cross(a_vec2_2);
}


bool vector_2::operator==(const vector_2& a_rhs) const
{
	return((x == a_rhs.x) && (y == a_rhs.y));
}
