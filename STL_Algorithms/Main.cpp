#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>
#include "vector_preparation.h"

void unexpected_error()
{
	std::cout << "An Unexpected error happened, contact SAC team." << std::endl;
}

void do_try_catch(std::function<void()> func)
{
	try
	{
		func();
	}
	catch (std::exception& ex)
	{
		std::cout << "ERROR: " << ex.what() << std::endl;
	}
	catch (...)
	{
		unexpected_error();
	}
}

int main()
{
	std::set_terminate(unexpected_error);

	do_try_catch([]() 
		{
		std::vector<int> vector_of_int;
		vector_preparation::fill_vector(vector_of_int);
		const int target = 1;
		
		auto count = std::count(vector_of_int.begin(), vector_of_int.end(), target);
		auto find = std::find(vector_of_int.begin(), vector_of_int.end(), target);

		auto count_if = std::count_if(std::begin(vector_of_int), std::end(vector_of_int), 
			[](auto& number) 
			{
				return number % 2 == 0;
			});

		std::cout << "The vector has " << count << " number " << target << std::endl;
		std::cout << "The vector has " << count_if << " even numbers." << std::endl;
		std::cout << "The number " << target << (find != vector_of_int.end() ? " exists in the vector." : " doesn't exists in the vector.") << std::endl;
		});

	do_try_catch([]()
		{
			std::vector<int> vector_of_int;
			vector_preparation::fill_vector(vector_of_int);

			bool all_of, any_of, none_of;

			all_of = std::all_of(std::begin(vector_of_int), std::end(vector_of_int), [](auto& element) { return element % 2 != 0; });
			none_of = std::none_of(std::begin(vector_of_int), std::end(vector_of_int), [](auto& element) { return element % 2 != 0; });
			any_of = std::any_of(std::begin(vector_of_int), std::end(vector_of_int), [](auto& element) { return element % 2 != 0; });

			std::cout << all_of << ' ' << none_of << ' ' << any_of << std::endl;
		});

	return 0;
}