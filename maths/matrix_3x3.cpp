#include "matrix_3x3.h"
#include <cstdlib>



matrix_3x3::matrix_3x3(const float a_m00, const float a_m01, const float a_m02,
					   const float a_m10, const float a_m11, const float a_m12,
					   const float a_m20, const float a_m21, const float a_m22) :
	one_d{ a_m00, a_m01, a_m02, a_m10, a_m11, a_m12, a_m20, a_m21, a_m22 } {}


matrix_3x3::matrix_3x3(const Vector_3& a_right, const Vector_3& a_up, const Vector_3& a_forward) :
	axes{ a_right, a_up, a_forward } {}

Vector_3& matrix_3x3::operator[](const int a_index)
{
	return axes[a_index];
}

matrix_3x3::operator float*()
{
	return one_d;
}

matrix_3x3::operator const float* () const
{
	return one_d;
}

const Vector_3& matrix_3x3::operator[] (int index) const
{
	return axes[index];
}

matrix_3x3 matrix_3x3::operator*(const matrix_3x3& a_rhs) const
{
	return { multi_d[0][0] * a_rhs.multi_d[0][0] + multi_d[1][0] * a_rhs.multi_d[0][1] + multi_d[2][0] * a_rhs.multi_d[0][2],
		     multi_d[0][1] * a_rhs.multi_d[0][0] + multi_d[1][1] * a_rhs.multi_d[0][1] + multi_d[2][1] * a_rhs.multi_d[0][2],
		     multi_d[0][2] * a_rhs.multi_d[0][0] + multi_d[1][2] * a_rhs.multi_d[0][1] + multi_d[2][2] * a_rhs.multi_d[0][2],
		     																								  
		     multi_d[0][0] * a_rhs.multi_d[1][0] + multi_d[1][0] * a_rhs.multi_d[1][1] + multi_d[2][0] * a_rhs.multi_d[1][2],
		     multi_d[0][1] * a_rhs.multi_d[1][0] + multi_d[1][1] * a_rhs.multi_d[1][1] + multi_d[2][1] * a_rhs.multi_d[1][2],
		     multi_d[0][2] * a_rhs.multi_d[1][0] + multi_d[1][2] * a_rhs.multi_d[1][1] + multi_d[2][2] * a_rhs.multi_d[1][2],
		     																								 
		     multi_d[0][0] * a_rhs.multi_d[2][0] + multi_d[1][0] * a_rhs.multi_d[2][1] + multi_d[2][0] * a_rhs.multi_d[2][2],
		     multi_d[0][1] * a_rhs.multi_d[2][0] + multi_d[1][1] * a_rhs.multi_d[2][1] + multi_d[2][1] * a_rhs.multi_d[2][2],
		     multi_d[0][2] * a_rhs.multi_d[2][0] + multi_d[1][2] * a_rhs.multi_d[2][1] + multi_d[2][2] * a_rhs.multi_d[2][2]
		};
}

Vector_3 matrix_3x3::operator* (const Vector_3& vector) const
{
	return { multi_d[0][0] * vector[0] + multi_d[1][0] * vector[1] + multi_d[2][0] * vector[2],
			 multi_d[0][1] * vector[0] + multi_d[1][1] * vector[1] + multi_d[2][1] * vector[2],
			 multi_d[0][2] * vector[0] + multi_d[1][2] * vector[1] + multi_d[2][2] * vector[2]
			};
}


void matrix_3x3::setRotateX(float x_rotation)
{
	one_d[4] = cos(x_rotation);
	one_d[5] = sin(x_rotation);
	one_d[7] = -sin(x_rotation);
	one_d[8] = cos(x_rotation);

}

void matrix_3x3::setRotateY(float y_rotation)
{
	one_d[0] = cos(y_rotation);
	one_d[2] = -sin(y_rotation);
	one_d[6] = sin(y_rotation);
	one_d[8] = cos(y_rotation);
}

void matrix_3x3::setRotateZ(float z_rotation)
{
	one_d[0] = cos(z_rotation);
	one_d[1] = sin(z_rotation);
	one_d[3] = -sin(z_rotation);
	one_d[4] = cos(z_rotation);
}