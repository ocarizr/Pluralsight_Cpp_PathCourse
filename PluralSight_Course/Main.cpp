#include <functional>
#include <chrono>
#include "Array.h"
#include "SortedArray.h"

void DoTryCatch(std::function<void()> func)
{
	try
	{
		func();
	}
	catch (std::exception &ex)
	{
		std::cout << "ERROR: " << ex.what() << std::endl;
	}
}

int main()
{
	int size = 10000000;
	Array<int> lista(size);

	std::cout << lista.IsEmpty() << std::endl;

	DoTryCatch([&]()
	{
		auto beginTime = std::chrono::time_point< std::chrono::system_clock>();
		for (int i = 0; i < size; i++)
		{
			lista.Insert(i);
		}
		/*lista.Insert(10);
		lista.Insert(5);
		lista.Insert(9);
		lista.Insert(11);
		lista.Insert(1);*/
		auto endTime = std::chrono::time_point< std::chrono::system_clock>();

		std::cout << "Insert unordered Array: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - beginTime).count() << " nanoseconds" << std::endl;
	});

	DoTryCatch([&]()
	{
		// std::cout << lista << std::endl;
		std::cout << lista[1] << std::endl;
	});

	DoTryCatch([&]()
	{
		Array<int> listaCopy = lista;
		// std::cout << listaCopy << std::endl;
		auto beginTime = std::chrono::time_point< std::chrono::system_clock>();
		std::cout << listaCopy.Find(4590) << std::endl;
		auto endTime = std::chrono::time_point< std::chrono::system_clock>();

		std::cout << "Find unordered Array: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - beginTime).count() << " nanoseconds" << std::endl;
	});

	//DoTryCatch([&]()
	//{
	//	Array<int> listaCopy(std::move(lista));
	//	// std::cout << listaCopy << std::endl;
	//});

	DoTryCatch([&]()
	{
		LazySortedArray<int> sLista(size);

		auto beginTime = std::chrono::time_point<std::chrono::system_clock>();
		for (int i = size - 1; i > 0; i--)
		{
			sLista.Insert(i);
		}
		/*sLista.Insert(5);
		sLista.Insert(6);
		sLista.Insert(1);
		sLista.Insert(7);
		sLista.Insert(10);*/
		auto endTime = std::chrono::time_point< std::chrono::system_clock>();
		/*sLista.Insert(3);
		sLista.Insert(2);
		sLista.Insert(4);
		sLista.Insert(8);
		sLista.Insert(9);*/

		std::cout << "Insert ordered Array: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - beginTime).count() << " nanoseconds" << std::endl;

		// std::cout << sLista << std::endl;
		std::cout << sLista[5] << std::endl;
		beginTime = std::chrono::time_point< std::chrono::system_clock>();
		std::cout << sLista.Find(4590) << std::endl;
		endTime = std::chrono::time_point< std::chrono::system_clock>();

		std::cout << "Find ordered Array: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - beginTime).count() << " nanoseconds" << std::endl;
	});

	return 0;
}