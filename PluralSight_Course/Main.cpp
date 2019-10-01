#include <functional>
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
	Array<int> lista(5);

	std::cout << lista.IsEmpty() << std::endl;

	DoTryCatch([&]()
	{
		lista.Insert(10);
		lista.Insert(5);
		lista.Insert(9);
		lista.Insert(11);
		lista.Insert(1);
		lista.Insert(0);
	});

	DoTryCatch([&]()
	{
		std::cout << lista << std::endl;
		std::cout << lista[1] << std::endl;
		std::cout << lista[5] << std::endl;
	});

	DoTryCatch([&]()
	{
		Array<int> listaCopy = lista;
		std::cout << listaCopy << std::endl;
		std::cout << listaCopy.Find(20) << std::endl;
	});

	DoTryCatch([&]()
	{
		Array<int> listaCopy(std::move(lista));
		std::cout << listaCopy << std::endl;
	});

	DoTryCatch([&]()
	{
		SortedArray<int> sLista(10);

		sLista.Insert(5);
		sLista.Insert(6);
		sLista.Insert(1);
		sLista.Insert(7);
		sLista.Insert(10);
		sLista.Insert(3);
		sLista.Insert(2);
		sLista.Insert(4);
		sLista.Insert(8);
		sLista.Insert(9);

		std::cout << sLista << std::endl;
		std::cout << sLista[5] << std::endl;
		std::cout << sLista.Find(7) << std::endl;
		std::cout << sLista.Find(11) << std::endl;
	});

	return 0;
}