#pragma once

#include <utility>
#include <iostream>

template<typename T>
class Array
{
	T* m_array = nullptr;
	const int size;
	int end_pos;

public:
	explicit Array(int size) : size(size), end_pos(0)
	{
		m_array = new T[size] {};
	}

	Array(const Array &source) : size(source.size), end_pos(source.end_pos)
	{
		if (!source.IsEmpty())
		{
			m_array = new T[size] {};

			for (int i = 0; i < size; ++i)
			{
				m_array[i] = source[i];
			}
		}
	}

	~Array() { delete []m_array; }

	void Insert(T &&value)
	{
		if (end_pos < size)
		{
			m_array[end_pos] = std::move(value);
			end_pos++;
		}
		else
		{
			throw std::exception("Try to add more data than the array size.");
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

	int &operator [] (int pos) const
	{
		if (pos < size && pos >= 0)
		{
			return m_array[pos];
		}

		throw std::exception("Try to access a slot of memory out of the array.");
	}
};

