#include <functional>
#include "Array.h"

std::ostream& operator << (std::ostream& stream, Array<int> &item)
{
	stream << "[ ";
	for (int i = 0; i < item.GetSize(); i++)
	{
		stream << item[i] << ' ';
	}
	stream << ']';

	return stream;
}

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
		std::cout << listaCopy.Find(11) << std::endl;
	});

	return 0;
}