#include <iostream>
#include "IntArray.h"

int main()
{
	IntArray lista(5);

	std::cout << lista.IsEmpty() << std::endl;

	lista.Insert(10);
	lista.Insert(5);

	lista.PrintArray();

	std::cout << lista.IsEmpty() << std::endl;

	try
	{
		std::cout << lista[5] << std::endl;
	}
	catch (std::exception ex)
	{
		std::cout << "ERROR: " << ex.what() << std::endl;
	}
	return 0;
}