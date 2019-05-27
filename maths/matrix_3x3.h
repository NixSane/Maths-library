#pragma once
#include "Vector_3.h"

class matrix_3x3
{
public:
	union
	{
		struct
		{
			float x_axis[3];
			float y_axis[3];
			float z_axis[3];
		};

		float one_d[9];
		float multi_d[3][3];

		struct
		{
			/*Vector_3 right;
			Vector_3 up;
			Vector_3 forward;*/

			Vector_3 right;
			Vector_3 forward;
			Vector_3 left;
		};

		Vector_3 axes[3];
	};

	operator float*();

	operator const float* () const;

	// Constructor
	matrix_3x3(const float a_m00 = 1.0f, const float a_m01 = 0.0f, const float a_m02 = 0.0f,
			   const float a_m10 = 0.0f, const float a_m11 = 1.0f, const float a_m12 = 0.0f, 
			   const float a_m20 = 0.0f, const float a_m21 = 0.0f, const float a_m22 = 1.0f);

	// Constructor
	matrix_3x3(const Vector_3& a_right, const Vector_3& a_up, const Vector_3& a_forward);

	// Reference access so it can be edited
	Vector_3& operator[] (int index);

	// const access for read only
	const Vector_3& operator[] (int index) const;

	//binary * operator (multiplication matrix and vector)
	Vector_3 operator* (const Vector_3& vector) const;

	void setRotateX(float x_rotation);

	void setRotateY(float y_rotation);

	void setRotateZ(float z_rotation);

	//binary * operator (multiplication)
	matrix_3x3 operator* (const matrix_3x3& a_rhs) const;
};

