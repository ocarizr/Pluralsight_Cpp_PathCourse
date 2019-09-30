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

	std::cout << lista[0] << std::endl;

	return 0;
}