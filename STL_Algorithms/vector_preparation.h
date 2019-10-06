#pragma once
#include <vector>

class vector_preparation
{
public:
	static void fill_vector(std::vector<int>& v)
	{
		for (int i = 100; i > 0; --i)
		{
			v.push_back(i);
		}
	}
};

