#include <chrono>
#include <iomanip>
#include <time.h>
#include <vector>
#include <sstream>
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

	do_try_catch([]()
		{
			std::vector<int> vector_of_int;
			vector_preparation::fill_vector(vector_of_int);

			vector_preparation::print_vector(vector_of_int);

			std::sort(std::begin(vector_of_int), std::end(vector_of_int));

			vector_preparation::print_vector(vector_of_int);
		});

	do_try_catch([]()
		{
			std::vector<employees> employees;
			vector_preparation::fill_employees_vector(employees);

			vector_preparation::print_employees_vector(employees);

			std::sort(std::begin(employees), std::end(employees),
				[](auto& employee_one, auto& employee_two)
				{
					return employee_one.get_salary() < employee_two.get_salary();
				});

			vector_preparation::print_employees_vector(employees);

			std::sort(std::begin(employees), std::end(employees),
				[](auto& employee_one, auto& employee_two)
				{
					return employee_one.get_name() < employee_two.get_name();
				});

			vector_preparation::print_employees_vector(employees);

			std::cout << "The vector " <<
				(std::is_sorted(std::begin(employees), std::end(employees),
					[](auto& employee_one, auto& employee_two)
					{
						return employee_one.get_age() < employee_two.get_age();
					})
					? "is " : "isn't ")
				<< "sorted by age." << std::endl;

			std::stable_sort(std::begin(employees), std::end(employees),
				[](auto& employee_one, auto& employee_two)
				{
					return employee_one.get_age() < employee_two.get_age();
				});

			vector_preparation::print_employees_vector(employees);

			std::cout << "The vector " << 
				(std::is_sorted(std::begin(employees), std::end(employees),
				[](auto& employee_one, auto& employee_two)
					{
						return employee_one.get_age() < employee_two.get_age();
					}) 
					? "is " : "isn't ") 
				<< "sorted by age." << std::endl;
		});

	do_try_catch([]()
		{
			using pairTry = std::pair<std::string, int>;

			pairTry pair;
			pair = std::move(pairTry("Rafael", 29));

			std::cout << pair.first << ' ' << pair.second << std::endl;

			std::vector<employees> vector_of_employees;
			std::vector<employees> list_of_employees;

			vector_preparation::fill_employees_vector(vector_of_employees);
			vector_preparation::fill_employees_vector(list_of_employees);

			bool equal = std::equal(std::begin(vector_of_employees), std::end(vector_of_employees), std::begin(list_of_employees),
									[](auto& employee_vector, auto& employee_list)
									{
										return employee_vector.get_age() == employee_list.get_age() &&
											employee_vector.get_name() == employee_list.get_name() &&
											employee_vector.get_salary() == employee_list.get_salary() &&
											employee_vector.get_department() == employee_list.get_department();
									});

			vector_preparation::print_employees_vector(vector_of_employees);
			vector_preparation::print_employees_vector(list_of_employees);

			std::cout << "The collections " << (equal ? "are " : "aren't ") << "equal." << std::endl;
		});

	do_try_catch([]()
				 {
					 time_t rawtime;
					 time(&rawtime);
					 struct tm ptm;
					 gmtime_s(&ptm, &rawtime);

					 auto start = std::chrono::high_resolution_clock::now();
					 for (int i = 0; i < 100000; ++i)
					 {
						 std::stringstream fix_time;
						 std::stringstream fix_date;

						 fix_time << ptm.tm_hour << ':' << std::setfill('0') << std::setw(2) << ptm.tm_min << ':' << std::setfill('0') << std::setw(2) << ptm.tm_sec << ".000";
						 fix_date << (1900 + ptm.tm_year) << std::setfill('0') << std::setw(2) << (ptm.tm_mon + 1) << std::setfill('0') << std::setw(2) << ptm.tm_mday;
					 }
					 auto end = std::chrono::high_resolution_clock::now();

					 auto timestamp = end - start;

					 std::cout << "Stringstream performance = " << timestamp.count() << " nanoseconds" << std::endl;

					 start = std::chrono::high_resolution_clock::now();
					 for (int i = 0; i < 100000; ++i)
					 {
						 char fix_time[13] = {};
						 char fix_date[9] = {};

						 sprintf_s(fix_date, "%04d%02d%02d", ptm.tm_year + 1900, ptm.tm_mon + 1, ptm.tm_mday);
						 sprintf_s(fix_time, "%02d:%02d:%02d.%03d", ptm.tm_hour, ptm.tm_min, ptm.tm_sec, 0);
					 }
					 end = std::chrono::high_resolution_clock::now();

					 timestamp = end - start;

					 std::cout << "sprintf_s performance = " << timestamp.count() << " nanoseconds" << std::endl;
				 });

	return 0;
}