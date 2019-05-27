#pragma once
#include "vector_4.h"

class matrix_4x4
{
public:
	union
	{
		struct
		{
			float x_axis[4];
			float y_axis[4];
			float z_axis[4];
			float w_axis[4];
		};

		float one_d[16];
		float multi_d[4][4];

		struct
		{
			vector_4 right;
			vector_4 up;
			vector_4 forward;
			vector_4 position;
			
		};

		vector_4 axes[4];
	};

	operator float*();

	operator const float* () const;

	// Constructor
	matrix_4x4(const float a_m00 = 1.0f, const float a_m01 = 0.0f, const float a_m02 = 0.0f, const float a_m03 = 0.0f,
			   const float a_m10 = 0.0f, const float a_m11 = 1.0f, const float a_m12 = 0.0f, const float a_m13 = 0.0f,
			   const float a_m20 = 0.0f, const float a_m21 = 0.0f, const float a_m22 = 1.0f, const float a_m23 = 0.0f,
			   const float a_m30 = 0.0f, const float a_m31 = 0.0f, const float a_m32 = 0.0f, const float a_m33 = 1.0f);

	// Constructor
	matrix_4x4(const vector_4& a_right, const vector_4& a_up, const vector_4& a_forward, const vector_4& a_position);

	// Reference access so it can be edited
	vector_4& operator[] (int index);

	// const access for read only
	const vector_4& operator[] (int a_index) const;

	//binary * operator (multiplication)
	matrix_4x4 operator* (const matrix_4x4& other) const;

	//binary * operator (multiplication matrix and vector)
	vector_4 operator* (const vector_4& vector) const;

	// Rotation axes
	void setRotateX(float x_rotation);

	void setRotateY(float y_rotation);

	void setRotateZ(float z_rotation);
};

