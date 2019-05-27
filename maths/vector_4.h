#pragma once


#ifndef _VECTOR_4_
#define _VECTOR_4_

class vector_4
{
public:
	union {
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
		float data[4];
	};
	vector_4(const float a_x = 0.0f, const float a_y = 0.0f, const float a_z = 0.0f, const float a_w = 0.0f);

	float& operator[] (const int a_index);

	operator float*();

	operator const float* () const;



	// ** CONSTRUCTOR ZONE **//
	// Vector + Vector(i, e, a, Point + an offset Vector)
	vector_4 operator+(const vector_4& a_rhs) const;
	vector_4 operator-(const vector_4& a_rhs) const;
	vector_4 operator*(const float a_rhs) const;
	vector_4 operator/(const float a_rhs) const;

	// And the corresponding
	vector_4 operator+=(const vector_4& a_rhs);
	vector_4 operator-=(const vector_4& a_rhs);
	vector_4 operator*=(const float a_rhs);
	vector_4 operator/=(const float a_rhs);

	float square_magnitude() const;
	float magnitude() const;

	void normalise();
	vector_4 normalised() const;

	float dot(const vector_4& a_vector_3) const;
	static float dot(const vector_4& a_vec3_1, const vector_4& a_vec3_2);

	vector_4 cross(const vector_4& a_vector_3) const;
	static vector_4 cross(const vector_4& a_vec3_1, const vector_4& a_vec3_2);

	bool operator==(const vector_4& a_rhs) const;

};

vector_4 operator*(const float a_lhs, const vector_4& a_rhs);

#endif