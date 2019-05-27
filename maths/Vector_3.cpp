#include "Vector_3.h"
#include <cassert>
#include <cmath>


Vector_3::Vector_3(const float a_x, const float a_y, const float a_z) 
	: data{ a_x, a_y, a_z }
{
}

float& Vector_3::operator[] (const int a_index)
{
	assert((a_index >= 0) && (a_index < 3)
		&& "Vector 3 index out of range");
	return data[a_index];
}

Vector_3::operator float*()
{
	return data;
}

Vector_3::operator const float* () const
{
	return data;
}

Vector_3 Vector_3::operator+(const Vector_3& a_rhs) const
{
	return Vector_3(x + a_rhs.x, y + a_rhs.y, z + a_rhs.z);
}

Vector_3 Vector_3::operator-(const Vector_3& a_rhs) const
{
	return Vector_3(x - a_rhs.x, y - a_rhs.y, z - a_rhs.z);
}			

Vector_3 Vector_3::operator*(const float a_rhs) const
{
	return Vector_3(x * a_rhs, y * a_rhs, z * a_rhs);
}			

Vector_3 Vector_3::operator/(const float a_rhs) const
{
	return Vector_3(x / a_rhs, y / a_rhs, z / a_rhs);
}

Vector_3 operator*(const float a_lhs, const Vector_3& a_rhs)
{
	return a_rhs * a_lhs;
}

Vector_3 Vector_3::operator+=(const Vector_3& a_rhs)
{
	*this = *this + a_rhs;
	return *this;
}

Vector_3 Vector_3::operator-=(const Vector_3& a_rhs)
{
	*this = *this - a_rhs;
	return *this;
}

Vector_3 Vector_3::operator*=(const float a_rhs)
{
	*this = *this * a_rhs;
	return *this;
}

Vector_3 Vector_3::operator/=(const float a_rhs)
{
	*this = *this / a_rhs;
	return *this;
}

float Vector_3::square_magnitude() const
{
	return (x * x) + (y * y) + (z * z);
}

float Vector_3::magnitude() const
{
	return sqrt(square_magnitude());
}

void Vector_3::normalise()
{
	*this /= magnitude();
}

Vector_3 Vector_3::normalised() const
{
	return *this / magnitude();
}

float Vector_3::dot(const Vector_3& a_vector_3) const
{
	return (x * a_vector_3.x) +
		   (y * a_vector_3.y) +
		   (z * a_vector_3.z);
}

float Vector_3::dot(const Vector_3& a_vec3_1, const Vector_3& a_vec3_2)
{
	return a_vec3_1.dot(a_vec3_2);
}

Vector_3 Vector_3::cross(const Vector_3& a_vector_3) const
{
	return { y * a_vector_3.z - z * a_vector_3.y,
			 z * a_vector_3.x - x * a_vector_3.z,
			 x * a_vector_3.y - y * a_vector_3.x };
}

Vector_3 Vector_3::cross(const Vector_3& a_vec3_1, const Vector_3& a_vec3_2)
{
	return a_vec3_1.cross(a_vec3_2);
}

bool Vector_3::operator==(const Vector_3& a_rhs) const
{
	return((x == a_rhs.x) && (y == a_rhs.y) && (z == a_rhs.z));
}