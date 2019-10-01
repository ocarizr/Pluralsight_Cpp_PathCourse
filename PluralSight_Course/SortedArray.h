#pragma once

#include <algorithm>
#include "Array.h"

template<typename T>
class SortedArray : public Array<T>
{
public:
	explicit SortedArray(int size) : Array<T>(size) {};

	virtual void Insert(T&& value) override
	{
		if (Array<T>::end_pos < Array<T>::size)
		{
			for (int i = 0; i < Array<T>::end_pos; ++i)
			{
				if (value < Array<T>::m_array[i])
				{
					for (int j = Array<T>::end_pos - 1; j >= i; j--)
					{
						Array<T>::m_array[j + 1] = Array<T>::m_array[j];
					}

					Array<T>::m_array[i] = value;
					Array<T>::end_pos++;

					return;
				}
			}

			Array<T>::m_array[Array<T>::end_pos] = value;
			Array<T>::end_pos++;
		}
		else
		{
			throw std::exception("Try to add more data than the array size.");
		}
	}

	virtual int Find(const T& element) const noexcept override
	{
		int left = 0;
		int right = Array<T>::size - 1;

		while (left <= right)
		{
			int middle = (left + right) / 2;

			if (Array<T>::m_array[middle] == element)
			{
				return middle;
			}
			else if (Array<T>::m_array[middle] > element)
			{
				right = middle - 1;
			}
			else if (Array<T>::m_array[middle] < element)
			{
				left = middle + 1;
			}
		}

		return Array<T>::k_not_found;
	}

	int& operator [] (int pos) const
	{
		if (pos < Array<T>::size && pos >= 0)
		{
			return Array<T>::m_array[pos];
		}

		throw std::range_error("Try to access a slot of memory out of the array.");
	}

	friend std::ostream& operator << (std::ostream& stream, const SortedArray<T>& item)
	{
		stream << "[ ";
		for (int i = 0; i < item.GetSize(); i++)
		{
			stream << item[i] << ' ';
		}
		stream << ']';

		return stream;
	}
};

