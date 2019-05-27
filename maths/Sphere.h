#pragma once
#include "vector_2.h"
#include <vector>

// simple sphere
class Sphere
{
public:
	Sphere();
	Sphere(const vector_2& middle, float a_radius) :
		center(middle), radius(a_radius) {}
	~Sphere();

	vector_2 center;
	float radius;

	void fit(const vector_2* points, unsigned int count);
	void fit(const std::vector<vector_2>& points);
};

