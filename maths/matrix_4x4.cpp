#include "matrix_4x4.h"
#include <cstdlib>



matrix_4x4::matrix_4x4(const float a_m00, const float a_m01, const float a_m02, const float a_m03,
					   const float a_m10, const float a_m11, const float a_m12, const float a_m13,
					   const float a_m20, const float a_m21, const float a_m22, const float a_m23,
					   const float a_m30, const float a_m31, const float a_m32 , const float a_m33) :
	one_d{ a_m00, a_m01, a_m02, a_m03, a_m10, a_m11, a_m12, a_m13, a_m20, a_m21, a_m22, a_m23, a_m30, a_m31, a_m32, a_m33} {}


matrix_4x4::matrix_4x4(const vector_4& a_right, const vector_4& a_up, const vector_4& a_forward, const vector_4& a_position) :
	axes{ a_right, a_up, a_forward, a_position } {}

matrix_4x4::operator float*()
{
	return one_d;
}

matrix_4x4::operator const float* () const
{
	return one_d;
}

vector_4& matrix_4x4::operator[](const int a_index)
{
	return axes[a_index];
}

const vector_4& matrix_4x4::operator[] (int a_index) const
{
	return axes[a_index];
}

matrix_4x4 matrix_4x4::operator*(const matrix_4x4& a_rhs) const
{
	return {multi_d[0][0] * a_rhs.multi_d[0][0] + multi_d[1][0] * a_rhs.multi_d[0][1] + multi_d[2][0] * a_rhs.multi_d[0][2] + multi_d[3][0] *  a_rhs.multi_d[0][3],
			multi_d[0][1] * a_rhs.multi_d[0][0] + multi_d[1][1] * a_rhs.multi_d[0][1] + multi_d[2][1] *  a_rhs.multi_d [0][2] + multi_d[3][1] * a_rhs.multi_d[0][3],
			multi_d[0][2] * a_rhs.multi_d[0][0] + multi_d[1][2] * a_rhs.multi_d[0][1] + multi_d[2][2] *  a_rhs.multi_d [0][2] + multi_d[3][2] * a_rhs.multi_d[0][3],
			multi_d[0][3] * a_rhs.multi_d[0][0] + multi_d[1][3] * a_rhs.multi_d[0][1] + multi_d[2][3] *  a_rhs.multi_d [0][2] + multi_d[3][3] * a_rhs.multi_d[0][3],
																											  										 
			multi_d[0][0] * a_rhs.multi_d[1][0] + multi_d[1][0] * a_rhs.multi_d[1][1] + multi_d[2][0] *  a_rhs.multi_d [1][2] + multi_d[3][0] * a_rhs.multi_d[1][3],
			multi_d[0][1] * a_rhs.multi_d[1][0] + multi_d[1][1] * a_rhs.multi_d[1][1] + multi_d[2][1] *  a_rhs.multi_d [1][2] + multi_d[3][1] * a_rhs.multi_d[1][3],
			multi_d[0][2] * a_rhs.multi_d[1][0] + multi_d[1][2] * a_rhs.multi_d[1][1] + multi_d[2][2] *  a_rhs.multi_d [1][2] + multi_d[3][2] * a_rhs.multi_d[1][3],
			multi_d[0][3] * a_rhs.multi_d[1][0] + multi_d[1][3] * a_rhs.multi_d[1][1] + multi_d[2][3] *  a_rhs.multi_d [1][2] + multi_d[3][3] * a_rhs.multi_d[1][3],
																										 	  										 
			multi_d[0][0] * a_rhs.multi_d[2][0] + multi_d[1][0] * a_rhs.multi_d[2][1] + multi_d[2][0] *  a_rhs.multi_d [2][2] + multi_d[3][0] * a_rhs.multi_d[2][3],
			multi_d[0][1] * a_rhs.multi_d[2][0] + multi_d[1][1] * a_rhs.multi_d[2][1] + multi_d[2][1] *  a_rhs.multi_d [2][2] + multi_d[3][1] * a_rhs.multi_d[2][3],
			multi_d[0][2] * a_rhs.multi_d[2][0] + multi_d[1][2] * a_rhs.multi_d[2][1] + multi_d[2][2] *  a_rhs.multi_d [2][2] + multi_d[3][2] * a_rhs.multi_d[2][3],
			multi_d[0][3] * a_rhs.multi_d[2][0] + multi_d[1][3] * a_rhs.multi_d[2][1] + multi_d[2][3] *  a_rhs.multi_d [2][2] + multi_d[3][3] * a_rhs.multi_d[2][3],
																										 	  										 
			multi_d[0][0] * a_rhs.multi_d[3][0] + multi_d[1][0] * a_rhs.multi_d[3][1] + multi_d[3][0] *  a_rhs.multi_d [3][2] + multi_d[3][0] * a_rhs.multi_d[3][3],
			multi_d[0][1] * a_rhs.multi_d[3][0] + multi_d[1][1] * a_rhs.multi_d[3][1] + multi_d[3][1] *  a_rhs.multi_d [3][2] + multi_d[3][1] * a_rhs.multi_d[3][3],
			multi_d[0][2] * a_rhs.multi_d[3][0] + multi_d[1][2] * a_rhs.multi_d[3][1] + multi_d[3][2] *  a_rhs.multi_d [3][2] + multi_d[3][2] * a_rhs.multi_d[3][3],
			multi_d[0][3] * a_rhs.multi_d[3][0] + multi_d[1][3] * a_rhs.multi_d[3][1] + multi_d[3][3] *  a_rhs.multi_d [3][2] + multi_d[3][3] * a_rhs.multi_d[3][3]
	};
}

vector_4 matrix_4x4::operator* (const vector_4& vector) const
{
	return { multi_d[0][0] * vector[0] + multi_d[1][0] * vector[1] + multi_d[2][0] * vector[2] + multi_d[3][0] * vector[3],
			 multi_d[0][1] * vector[0] + multi_d[1][1] * vector[1] + multi_d[2][1] * vector[2] + multi_d[3][1] * vector[3],
			 multi_d[0][2] * vector[0] + multi_d[1][2] * vector[1] + multi_d[2][2] * vector[2] + multi_d[3][2] * vector[3],
			 multi_d[0][3] * vector[0] + multi_d[1][3] * vector[1] + multi_d[2][3] * vector[2] + multi_d[3][3] * vector[3]
	};
}

void matrix_4x4::setRotateX(float x_rotation)
{
	one_d[5] = cos(x_rotation);
	one_d[6] = sin(x_rotation);
	one_d[9] = -sin(x_rotation);
	one_d[10] = cos(x_rotation);

}

void matrix_4x4::setRotateY(float y_rotation)
{
	one_d[0] = cos(y_rotation);
	one_d[2] = -sin(y_rotation);
	one_d[8] = sin(y_rotation);
	one_d[10] = cos(y_rotation);
}

void matrix_4x4::setRotateZ(float z_rotation)
{
	one_d[0] = cos(z_rotation);
	one_d[1] = sin(z_rotation);
	one_d[4] = -sin(z_rotation);
	one_d[5] = cos(z_rotation);
}