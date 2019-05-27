#pragma once
#include "vector_2.h"
#include <vector>

class AABB
{
public:
	AABB() {}
	AABB(const vector_2& min, const vector_2& max) :
		min(min), max(max) {}
	
	vector_2 min, max;

	vector_2 center() const;

	vector_2 extents() const;

	std::vector<vector_2> corners() const;

	void fit(const vector_2* points, unsigned int count);

};

