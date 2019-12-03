#include <list>
#include <array>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	{
		std::vector<int> vector(10);
		int start = 1;
		std::generate_n(std::begin(vector), 10,
			[&start]()
			{
				return start++;
			});

		try
		{
			auto data = vector[9];
			auto data2 = vector.at(11);
		}
		catch (std::out_of_range & e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (std::range_error & e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "Error on anything." << std::endl;
		}

		vector.push_back(11);

		try
		{
			if (std::binary_search(vector.begin(), vector.end(), 12))
			{
				std::cout << "The value exists" << std::endl;
			}
			else
			{
				throw "";
			}
		}
		catch (...)
		{
			std::cout << "Data doens't exist." << std::endl;
		}

		std::sort(std::rbegin(vector), std::rend(vector));

		vector.insert(std::begin(vector) + 5, 15);

		{
			std::vector<int> another{ 20,21,22,23,24,25 };

			vector.insert(std::end(vector) - 2, another.begin(), another.end());
		}

		std::sort(vector.begin(), vector.end());

		auto it = std::remove_if(vector.begin(), vector.end(), [](int& number) {return number % 2 == 1; });
		auto it2 = vector.erase(it, vector.end());

		std::cout << *std::find(vector.begin(), vector.end(), 20) << std::endl;
	}

	// Arrays are faster than vectors but have fixed size
	// They are allocated on the stack
	// Can use with big collections due to stack limitations
	// No heap overhead
	{ 
		std::array<int, 10> a{ 1,2,3,4,5,6,7,8,9,0 };

		auto i = a.at(9);

		auto size = a.size();

		auto result = std::find(a.begin(), a.end(), 10);

		auto number = result == a.end() ? -1 : *result;

		std::sort(a.rbegin(), a.rend());
		std::sort(a.begin(), a.end());

		auto it = std::lower_bound(a.begin(), a.end(), 7);

		std::cout << "std::array tests" << std::endl;
	}

	// It has a O(1) complexity to add or remove elements anywhere in the collection
	// it's a doubled linked-list
	// can't grab an element in the middle of the collection without iterate through the collection
	// It has iterator stability
	// It can't use sdt::sort function
	// most of the stl algorithm compatible with std::lists are overwriten inside sts::list
	{ 
		std::list<int> list;

		for (int i = 50; i >0; --i)
		{
			list.push_back(i);
		}

		list.remove_if([](int& element) {return element % 2 == 1; });

		list.sort();

		std::cout << "std::list lessons" << std::endl;
	}
	return 0;
}