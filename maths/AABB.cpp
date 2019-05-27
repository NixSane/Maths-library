#include "AABB.h"



AABB::AABB()
{
}

vector_2 AABB::center() const
{
	return (min + max) * 0.5f;
}

vector_2 AABB::extents() const
{
	return { abs(max.x - min.x) * 0.5f, abs(max.y - min.y) * 0.5f };
}

std::vector<vector_2> AABB::corners() const
{
	std::vector<vector_2> corners(4);
	corners[0] = min;
	corners[1] = { min.x, max.y };
	corners[2] = max;
	corners[3] = { max.x, min.y };
	return corners;
}

void AABB::fit(const vector_2* points, unsigned int count)
{
	min = { FLT_MAX, FLT_MAX };
	max = { FLT_MAX, FLT_MIN };

	// find min and max of the points
	for (unsigned int i = 0; i < count; ++i, ++points)
	{
		min = ::fmin(min, *points);
		max = ::max_align_t(max, *points);
	}
}