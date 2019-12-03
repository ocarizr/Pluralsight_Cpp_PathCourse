#include <chrono>
#include <time.h>
#include <vector>
#include <iomanip>
#include <numeric>
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
	catch (std::exception & ex)
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
<<<<<<< HEAD
				 {
					 std::vector<int> vector_of_int;
					 vector_preparation::fill_vector(vector_of_int);
					 const int target = 1;
=======
		{
			std::vector<int> vector_of_int;
			vector_preparation::fill_vector(vector_of_int, 75);
			const int target = 1;
>>>>>>> 3420c4313218d173dab9abf9a8bc967d8b5ebe04

					 auto count = std::count(vector_of_int.begin(), vector_of_int.end(), target);
					 auto find = std::find(vector_of_int.begin(), vector_of_int.end(), target);

<<<<<<< HEAD
					 auto count_if = std::count_if(std::begin(vector_of_int), std::end(vector_of_int),
												   [](auto& number)
												   {
													   return number % 2 == 0;
												   });
=======
			auto count_if = std::count_if(std::begin(vector_of_int), std::end(vector_of_int),
				[](const auto& number)
				{
					return number % 2 == 0;
				});
>>>>>>> 3420c4313218d173dab9abf9a8bc967d8b5ebe04

					 std::cout << "The vector has " << count << " number " << target << std::endl;
					 std::cout << "The vector has " << count_if << " even numbers." << std::endl;
					 std::cout << "The number " << target << (find != vector_of_int.end() ? " exists in the vector." : " doesn't exists in the vector.") << std::endl;
				 });

	do_try_catch([]()
<<<<<<< HEAD
				 {
					 std::vector<int> vector_of_int;
					 vector_preparation::fill_vector(vector_of_int);
=======
		{
			std::vector<int> vector_of_int;
			vector_preparation::fill_vector(vector_of_int, 10);
>>>>>>> 3420c4313218d173dab9abf9a8bc967d8b5ebe04

					 bool all_of, any_of, none_of;

					 all_of = std::all_of(std::begin(vector_of_int), std::end(vector_of_int), [](auto& element) { return element % 2 != 0; });
					 none_of = std::none_of(std::begin(vector_of_int), std::end(vector_of_int), [](auto& element) { return element % 2 != 0; });
					 any_of = std::any_of(std::begin(vector_of_int), std::end(vector_of_int), [](auto& element) { return element % 2 != 0; });

					 std::cout << all_of << ' ' << none_of << ' ' << any_of << std::endl;
				 });

	do_try_catch([]()
<<<<<<< HEAD
				 {
					 std::vector<int> vector_of_int;
					 vector_preparation::fill_vector(vector_of_int);
=======
		{
			std::vector<int> vector_of_int;
			vector_preparation::fill_vector(vector_of_int, 100);
>>>>>>> 3420c4313218d173dab9abf9a8bc967d8b5ebe04

					 vector_preparation::print_vector(vector_of_int);

					 std::sort(std::begin(vector_of_int), std::end(vector_of_int));

					 vector_preparation::print_vector(vector_of_int);
				 });

	do_try_catch([]()
<<<<<<< HEAD
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

					 if (!equal)
					 {
						 auto firstDiff = std::mismatch(std::begin(vector_of_employees), std::end(vector_of_employees), std::begin(list_of_employees),
														[](auto& employee_vector, auto& employee_list)
														{
															return employee_vector.get_age() == employee_list.get_age() &&
																employee_vector.get_name() == employee_list.get_name() &&
																employee_vector.get_salary() == employee_list.get_salary() &&
																employee_vector.get_department() == employee_list.get_department();
														});

						 std::cout << "First Diff is on slot: " << firstDiff.first - std::begin(vector_of_employees) << std::endl;
					 }

					 vector_preparation::print_employees_vector(vector_of_employees);
					 vector_preparation::print_employees_vector(list_of_employees);

					 std::cout << "The collections " << (equal ? "are " : "aren't ") << "equal." << std::endl;
				 });
=======
		{
			std::vector<employees> employees;
			vector_preparation::fill_employees_vector(employees);

			vector_preparation::print_employees_vector(employees);

			std::sort(std::begin(employees), std::end(employees),
				[](const auto& employee_one, const auto& employee_two)
				{
					return employee_one.get_salary() < employee_two.get_salary();
				});

			vector_preparation::print_employees_vector(employees);

			std::sort(std::begin(employees), std::end(employees),
				[](const auto& employee_one, const auto& employee_two)
				{
					return employee_one.get_name() < employee_two.get_name();
				});

			vector_preparation::print_employees_vector(employees);

			std::cout << "The vector " <<
				(std::is_sorted(std::begin(employees), std::end(employees),
					[](const auto& employee_one, const auto& employee_two)
					{
						return employee_one.get_age() < employee_two.get_age();
					})
					? "is " : "isn't ")
				<< "sorted by age." << std::endl;

					std::stable_sort(std::begin(employees), std::end(employees),
						[](const auto& employee_one, const auto& employee_two)
						{
							return employee_one.get_age() < employee_two.get_age();
						});

					vector_preparation::print_employees_vector(employees);

					std::cout << "The vector " <<
						(std::is_sorted(std::begin(employees), std::end(employees),
							[](const auto& employee_one, const auto& employee_two)
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
				[](const auto& employee_vector, const auto& employee_list)
				{
					return employee_vector.get_age() == employee_list.get_age() &&
						employee_vector.get_name() == employee_list.get_name() &&
						employee_vector.get_salary() == employee_list.get_salary() &&
						employee_vector.get_department() == employee_list.get_department();
				});

			if (!equal)
			{
				auto firstDiff = std::mismatch(std::begin(vector_of_employees), std::end(vector_of_employees), std::begin(list_of_employees),
					[](const auto& employee_vector, const auto& employee_list)
					{
						return employee_vector.get_age() == employee_list.get_age() &&
							employee_vector.get_name() == employee_list.get_name() &&
							employee_vector.get_salary() == employee_list.get_salary() &&
							employee_vector.get_department() == employee_list.get_department();
					});

				std::cout << "First Diff is on slot: " << firstDiff.first - std::begin(vector_of_employees) << std::endl;
			}

			vector_preparation::print_employees_vector(vector_of_employees);
			vector_preparation::print_employees_vector(list_of_employees);

			std::cout << "The collections " << (equal ? "are " : "aren't ") << "equal." << std::endl;
		});
>>>>>>> 3420c4313218d173dab9abf9a8bc967d8b5ebe04

	// Comparing performance to build a string
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

	do_try_catch([]()
		{
			std::vector<int> vector_of_int;
			vector_preparation::fill_vector(vector_of_int, 50);

			auto total = std::accumulate(std::begin(vector_of_int), std::end(vector_of_int), 0);

			std::vector<employees> vector_of_employees;
			vector_preparation::fill_employees_vector(vector_of_employees);

			auto total_salary = std::accumulate(std::begin(vector_of_employees), std::end(vector_of_employees), 0,
				[](float total, const auto& employee)
				{
					return total += employee.get_salary();
				});

			std::cout << "Accumulate of vector_of_int: " << total << std::endl;
			std::cout << "Accumulate of salaries: " << total_salary << std::endl;

			auto size_of_vector = std::size(vector_of_int);
			auto amount_of_employees = std::size(vector_of_employees);

			std::cout << "Size of the vector: " << size_of_vector << std::endl;
			std::cout << "Amout of employees: " << amount_of_employees << std::endl;

			vector_preparation::print_employees_vector(vector_of_employees);

			std::for_each(std::begin(vector_of_employees), std::end(vector_of_employees),
				[](auto& employee)
				{
					employee.set_salary(employee.get_salary() * 1.1);
				});

			vector_preparation::print_employees_vector(vector_of_employees);
		});

	do_try_catch([]()
		{
			std::vector<employees> vector_of_employees;

			vector_preparation::fill_employees_vector(vector_of_employees);

			auto second_collection = vector_of_employees;

			vector_preparation::print_employees_vector(vector_of_employees);
			vector_preparation::print_employees_vector(second_collection);

			auto it = std::remove_if(std::begin(second_collection), std::end(second_collection),
				[](const auto& employee)
				{
					return employee.get_salary() < 5000.00f;
				});
			second_collection.erase(it, std::end(second_collection));

			vector_preparation::print_employees_vector(second_collection);

			std::transform(std::begin(second_collection), std::end(second_collection), std::begin(second_collection),
				[](employees& employee)
				{
					employee.set_salary(employee.get_salary() * 1.5);
					return employee;
				});

			vector_preparation::print_employees_vector(second_collection);

			std::vector<int> vector_of_int;
			vector_preparation::fill_vector(vector_of_int, 120);
			std::vector<int> second_vector(std::size(vector_of_int));

			auto iterator = std::copy_if(std::begin(vector_of_int), std::end(vector_of_int), std::begin(second_vector),
				[](const int& value)
				{
					return value > 90;
				});
			second_vector.resize(std::distance(std::begin(second_vector), iterator));

			vector_preparation::print_vector(second_vector);
		});

	do_try_catch([]()
		{
			std::vector<int> vector;
			vector_preparation::fill_vector_with_duplicates(vector, 50);

			vector_preparation::print_vector(vector);

			std::sort(std::begin(vector), std::end(vector));

			vector.erase(std::unique(std::begin(vector), std::end(vector)), std::end(vector));
			vector_preparation::print_vector(vector);

			vector_preparation::print_vector_backwards(vector);

			std::vector<int> second_vector(10);

			std::copy_n(std::begin(vector), 10, std::begin(second_vector));

			vector_preparation::print_vector(second_vector);
		});

	do_try_catch([]()
		{
			std::vector<int> vector_of_int;
			vector_preparation::fill_vector(vector_of_int, 50);

			auto query_result = std::stable_partition(std::begin(vector_of_int), std::end(vector_of_int),
				[](const int& number)
				{
					return number % 2 != 0;
				});

			vector_preparation::print_vector(vector_of_int);

			std::rotate(std::begin(vector_of_int), query_result - 1, query_result);
			
			vector_preparation::print_vector(vector_of_int);
		});

	return 0;
}