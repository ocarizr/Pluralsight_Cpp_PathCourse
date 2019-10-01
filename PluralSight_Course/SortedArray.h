#pragma once

#include <algorithm>
#include "Array.h"

template<typename T>
class SortedArray : public Array
{
public:
	explicit SortedArray(int size) : Array(size) {};

	void Insert(T&& value)
	{
		if (end_pos < size)
		{
			T temp;
			for (int i = 0; i < end_pos ++i)
			{
				if (value < m_array[i])
				{
					temp = m_array[i];
					m_array[i] = std::move(value);
					value = temp;
					end_pos++;
				}
			}
		}
		else
		{
			throw std::exception("Try to add more data than the array size.");
		}
	}

	int Find(const T& element)
	{
		std::binary_search(m_array.begin(), m_array.end(), element);

		return k_not_found;
	}
};

