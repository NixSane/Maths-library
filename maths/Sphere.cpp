#include "Sphere.h"




Sphere::Sphere()
{
}


Sphere::~Sphere()
{
}

void Sphere::fit(const vector_2* points, unsigned int count)
{
	// invalidate extents (so... only the length it should be?)
	vector_2 min = { FLT_MAX , FLT_MAX };
	vector_2 max = { FLT_MIN , FLT_MIN };

	// find min and max of the points
	for (unsigned int i = 0; i < count; ++i, ++points)
	{
		min = ::min(min, *points);
		max = ::max(max, *points);
	}

	// put a circle around the min/max box
	center = (min + max) * 0.5f;
	radius = center.distanceTo(max);
}

void Sphere::fit(const std::vector<vector_2>& points)
{

}