#pragma once

#include <utility>
#include <iostream>

class IntArray
{
	int* m_array = nullptr;
	const int size;
	int end_pos;

public:
	explicit IntArray(int size) : size(size), end_pos(0)
	{
		m_array = new int[size] {};
	}

	~IntArray() { delete []m_array; }

	void Insert(int &&value)
	{
		if (end_pos < size)
		{
			m_array[end_pos] = std::move(value);
			end_pos++;
		}
	}

	int GetSize() const noexcept { return size; }

	bool IsEmpty() const noexcept { return end_pos == 0; }

	void PrintArray()
	{
		std::cout << "{ ";
		for (int i = 0; i < end_pos; i++)
		{
			std::cout << m_array[i] << " ";
		}
		std::cout << "}" << std::endl;
	}

	int &operator[](int pos) const
	{
		if (pos < size && pos >= 0)
		{
			return m_array[pos];
		}

		throw std::exception("Try to access a slot of memory out of the array.");
	}
};

