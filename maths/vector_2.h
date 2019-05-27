#pragma once


#ifndef _VECTOR_2_
#define _VECTOR_2_
class vector_2
{
public:
	union
	{
		struct
		{
			float x;
			float y;
		};
		float data[2];
	};

	vector_2(const float a_x = 0.0f, const float a_y = 0.0f);

	float& operator[] (const int a_index);

	operator float*();

	operator const float* () const;

	vector_2 operator+(const vector_2& a_rhs);
	vector_2 operator-(const vector_2& a_rhs);
	vector_2 operator/(const float a_rhs) const;
	vector_2 operator*(const float a_rhs) const;


	vector_2 operator+=(const vector_2& a_rhs);
	vector_2 operator-=(const vector_2& a_rhs);
	vector_2 operator/=(const float a_rhs);
	vector_2 operator*=(const float a_rhs);
	
	float square_magnitude() const;
	float magnitude() const;
		
	void normalise();
	vector_2 normalised() const;




	float dot(const vector_2& a_vector_2) const;
	static float dot(const vector_2& a_vec2_1, const vector_2& a_vec2_2);

	vector_2 cross(const vector_2& a_vector_2) const;
	static vector_2 cross(const vector_2& a_vec2_1, const vector_2& a_vec2_2);

	bool operator==(const vector_2& a_rhs) const;
	
	// utilities
	float min(float a, float b) { return a < b ? a : b; }
	float max(float a, float b) { return a > b ? a : b; }

	// t = clamp(t, minimumValue, maximumValue)
	float clamp(float t, float a, float b) { return max(a, min(b, t)); }

	vector_2 min(const vector_2& a, const vector_2& b) {
		return { min(a.x,b.x), min(a.x,b.y) };
	}

	vector_2 max(const vector_2& a, const vector_2& b) {
		return { max(a.x,b.x), max(a.y,b.y) };
	}

	vector_2 clamp(const vector_2& t, const vector_2& a, const vector_2& b) {
		return max(a, min(b, t));
	}
};

vector_2 operator*(const float a_lhs, const vector_2& a_rhs);

#endif 