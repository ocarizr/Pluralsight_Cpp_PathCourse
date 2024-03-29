#include <functional>
#include <atomic>
#include <chrono>
#include "Array.h"
#include "SortedArray.h"
#include "LifoArray.h"

void UnexpectedError()
{
	std::cout << "An Unexpected error happened, contact SAC team." << std::endl;
}

void DoTryCatch(std::function<void()> func)
{
	try
	{
		func();
	}
	catch (std::range_error & ex)
	{
		std::cout << "RANGE_ERROR: " << ex.what() << std::endl;
	}
	catch (std::exception & ex)
	{
		std::cout << "ERROR: " << ex.what() << std::endl;
	}
	catch (...)
	{
		UnexpectedError();
	}
}

int main()
{
	std::set_terminate(UnexpectedError);

	//int size = 100;
	//Array<int> lista(size);

	//std::cout << lista.IsEmpty() << std::endl;

	//DoTryCatch([&]()
	//{
	//	for (int i = 0; i < size; i++)
	//	{
	//		lista.Insert(i);
	//	}
	//	lista.Insert(10);
	//	lista.Insert(5);
	//	lista.Insert(9);
	//	lista.Insert(11);
	//	lista.Insert(1);
	//});

	//DoTryCatch([&]()
	//{
	//	// std::cout << lista << std::endl;
	//	std::cout << lista[1] << std::endl;
	//});

	//DoTryCatch([&]()
	//{
	//	Array<int> listaCopy = lista;
	//	std::cout << listaCopy << std::endl;
	//	std::cout << listaCopy.Find(4590) << std::endl;
	//});

	//DoTryCatch([&]()
	//{
	//	Array<int> listaCopy(std::move(lista));
	//	std::cout << listaCopy << std::endl;
	//});

	//DoTryCatch([&]()
	//{
	//	LazySortedArray<int> sLista(size);

	//	for (int i = size - 1; i > 0; i--)
	//	{
	//		sLista.Insert(i);
	//	}
	//	sLista.Insert(5);
	//	sLista.Insert(6);
	//	sLista.Insert(1);
	//	sLista.Insert(7);
	//	sLista.Insert(10);
	//	sLista.Insert(3);
	//	sLista.Insert(2);
	//	sLista.Insert(4);
	//	sLista.Insert(8);
	//	sLista.Insert(9);

	//	std::cout << sLista << std::endl;
	//	std::cout << sLista[5] << std::endl;
	//	std::cout << sLista.Find(4590) << std::endl;
	//});

	//DoTryCatch([]()
	//{
	//	LifoArray<int> lifo_first(10);

	//	std::cout << "Total size of the Stack = " << lifo_first.Size() << std::endl;
	//	std::cout << "Current size of the Stack = " << lifo_first.CurrentStackSize() << std::endl;

	//	lifo_first.Push(10);
	//	lifo_first.Push(8);
	//	lifo_first.Push(9);
	//	lifo_first.Push(5);
	//	lifo_first.Push(6);
	//	lifo_first.Push(4);
	//	lifo_first.Push(7);
	//	lifo_first.Push(3);
	//	lifo_first.Push(1);
	//	lifo_first.Push(2);

	//	std::cout << "First stack: " << lifo_first << std::endl;

	//	auto lifo_second = lifo_first;

	//	std::cout << "Second stack: " << lifo_second << std::endl;

	//	auto lifo_copy = std::move(lifo_first);

	//	std::cout << "Moved stack: " << lifo_copy << std::endl;

	//	// It needs to be done in two lines
	//	// For some kind of reason it's executing in an unordered way on vs2019
	//	std::cout << lifo_copy.Top() << " | ";
	//	std::cout << lifo_copy.CurrentStackSize() << " | " << lifo_copy << std::endl;
	//	std::cout << lifo_copy.Pop() << " | ";
	//	std::cout << lifo_copy.CurrentStackSize() << " | " << lifo_copy << std::endl;
	//});

	DoTryCatch([]()
			   {
				   bool expected = false;
				   std::atomic<bool> test = false;
				   if (!test.compare_exchange_strong(expected, true))
				   {
					   return false;
				   }

				   if (!test.compare_exchange_strong(expected, true))
				   {
					   return false;
				   }

				   std::cout << test << ' ';
				   std::cout << expected << std::endl;
			   });

	return 0;
}