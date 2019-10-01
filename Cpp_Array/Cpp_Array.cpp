// Cpp_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>

template <typename T, int m_size>
class Array
{
	T* m_array = new T[m_size]{T()};
public:
	Array()
	{
		static_assert(m_size > 0, "O array deve ser maior que 0");
	}

	Array(Array&& other) = delete;
	Array(const Array& other) = delete;
	Array& operator=(Array&& other) = delete;
	Array& operator=(const Array& other) = delete;

	~Array()
	{
		if (m_array)
			delete[]m_array;
	}
	T& operator[](int index) const noexcept(false)
	{
		if(index >= m_size || index < 0)
			throw std::range_error("Index invalido");
		return m_array[index];
	}

	int size() const
	{
		return m_size;
	}
};

int main()
{
	Array<int, 1> a;
    std::cout << a[0] << '\n';
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
