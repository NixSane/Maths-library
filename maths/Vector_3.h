#pragma once

#ifndef _VECTOR_3_
#define _VECTOR_3_

class Vector_3
{
public:
	union {
		struct
		{
			float x;
			float y;
			float z;
		};
		float data[3];
	};
	Vector_3(const float a_x = 0.0f, const float a_y = 0.0f, const float a_z = 0.0f);

	float& operator[] (const int a_index);

	operator float*();

	operator const float* () const;



	// ** CONSTRUCTOR ZONE **//
	// Vector + Vector(i, e, a, Point + an offset Vector)
	Vector_3 operator+(const Vector_3& a_rhs) const;
	Vector_3 operator-(const Vector_3& a_rhs) const;
	Vector_3 operator*(const float a_rhs) const;
	Vector_3 operator/(const float a_rhs) const;

	// And the corresponding
	Vector_3 operator+=(const Vector_3& a_rhs);
	Vector_3 operator-=(const Vector_3& a_rhs);
	Vector_3 operator*=(const float a_rhs);
	Vector_3 operator/=(const float a_rhs);

	float square_magnitude() const;
	float magnitude() const;

	void normalise();
	Vector_3 normalised() const;

	float dot(const Vector_3& a_vector_3) const;
	static float dot(const Vector_3& a_vec3_1, const Vector_3& a_vec3_2);

	Vector_3 cross(const Vector_3& a_vector_3) const;
	static Vector_3 cross(const Vector_3& a_vec3_1, const Vector_3& a_vec3_2);

	bool operator==(const Vector_3& a_rhs) const;

};

Vector_3 operator*(const float a_lhs, const Vector_3& a_rhs);

#endif