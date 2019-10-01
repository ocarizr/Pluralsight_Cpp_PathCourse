#pragma once

#include <utility>
#include <iostream>

template<typename T>
class Array
{
	int size;
	int end_pos;
	T* m_array = nullptr;

	const int k_not_found = -1;

public:
	explicit Array(int size) : size(size), end_pos(0)
	{
		static_assert(size > 0, "ERROR: Array size must be greater than 0.");

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

	Array(Array&& source) : size(source.size), end_pos(source.end_pos), m_array(source.m_array)
	{		
		source.m_array = nullptr;
		source.size = 0;
		source.end_pos = 0;
	}

	~Array() { delete []m_array; }

	Array& operator=(Array&& source)
	{
		size = source.size;
		end_pos = source.end_pos;

		if (!source.m_array) m_array = new T[size];
		else m_array = source.m_array;

		source.size = 0;
		source.end_pos = 0;
		source.m_array = nullptr;

		return *this;
	}

	Array& operator=(const Array& source)
	{
		size = source.size;
		end_pos = source.end_pos;

		if (m_array) delete[]m_array;

		m_array = new T[size];

		if (end_pos > 0)
		{
			for (int i = 0; i < size; ++i)
			{
				m_array[i] = source[i];
			}
		}

		return *this;
	}

	virtual void Insert(T &&value)
	{
		if (end_pos < size)
		{
			m_array[end_pos] = std::move(value);
			end_pos++;
		}
		else
		{
			throw std::range_error("Try to add more data than the array size.");
		}
	}

	int GetSize() const noexcept { return size; }

	bool IsEmpty() const noexcept { return end_pos == 0; }

	virtual int Find(const T &element) const noexcept
	{
		for (int i = 0; i < size; ++i)
		{
			if (m_array[i] == element)
			{
				return i;
			}
		}

		return k_not_found;
	}

	int &operator [] (int pos) const
	{
		if (pos < size && pos >= 0)
		{
			return m_array[pos];
		}

		throw std::range_error("Try to access a slot of memory out of the array.");
	}

	friend std::ostream& operator << (std::ostream& stream, const Array<int>& item)
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

