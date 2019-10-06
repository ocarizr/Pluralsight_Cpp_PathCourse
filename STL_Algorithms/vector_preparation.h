#pragma once
#include <vector>
#include "employees.h"

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

	static void fill_employees_vector(std::vector<employees>& e)
	{
		e.push_back(std::move(employees("John", 20, "management", 8000.00)));
		e.push_back(std::move(employees("Anna", 18, "intern team", 1500.00)));
		e.push_back(std::move(employees("Josh", 35, "human-resources", 7500.00)));
		e.push_back(std::move(employees("Rafael", 29, "engineering", 9000.00)));
		e.push_back(std::move(employees("Giovana", 21, "mentoring", 4000.00)));
		e.push_back(std::move(employees("Monica", 26, "front-end", 3500.00)));
	}

	static void print_vector(const std::vector<int>& v)
	{
		for (auto i = std::begin(v); i != std::end(v); ++i)
		{
			std::cout << *i << ' ';
		}
		std::cout << std::endl;
	}

	static void print_employees_vector(const std::vector<employees>& e)
	{
		std::cout << std::endl;
		for (auto i = std::begin(e); i != std::end(e); ++i)
		{
			std::cout << *i;
		}
		std::cout << std::endl;
	}
};

