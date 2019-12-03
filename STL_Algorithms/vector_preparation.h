#pragma once
#include <vector>
#include "employees.h"

class vector_preparation
{
public:
	static void fill_vector(std::vector<int>& v, const int size)
	{
		v.resize(size);
		int vector_values = size;
		std::generate_n(std::begin(v), size,
			[&vector_values]()
			{
				return (vector_values -= 1);
			});
	}

	static void fill_vector_with_duplicates(std::vector<int>& v, const int size)
	{
		v.resize(size);
		float values = size;
		std::generate_n(std::begin(v), size,
			[&values]()
			{
				return (int)(values -= 0.5);
			});
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
		std::cout << std::endl;
		std::for_each(std::begin(v), std::end(v),
			[](int value)
			{
				std::cout << value << ' ';
			});
		std::cout << std::endl;
	}

	static void print_vector_backwards(const std::vector<int>& v)
	{
		std::cout << std::endl;
		std::for_each(std::rbegin(v), std::rend(v),
			[](int value)
			{
				std::cout << value << ' ';
			});
		std::cout << std::endl;
	}

	static void print_employees_vector(const std::vector<employees>& e)
	{
		std::cout << std::endl;
		std::for_each(std::begin(e), std::end(e),
			[](const auto& value)
			{
				std::cout << value;
			});
		std::cout << std::endl;
	}
};

