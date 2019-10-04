#pragma once

#include <cassert>
#include <iostream>

template<typename T>
class LifoArray
{
	int m_size;
	int m_top;
	T* m_array = nullptr;

public:
	explicit LifoArray(int size) : m_size(size), m_top(-1)
	{
		assert(m_size > 0, "ERROR: Array size must be greater than 0.");
		m_array = new T[m_size];
	}

	LifoArray(const LifoArray<T>& source) noexcept : m_size(source.m_size), m_top(source.m_top)
	{
		m_array = new T[m_size];

		for (int i = 0; i <= m_top; i++)
		{
			m_array[i] = source.m_array[i];
		}
	}

	LifoArray(LifoArray<T>&& source) noexcept : m_size(source.m_size), m_top(source.m_top), m_array(source.m_array)
	{
		source.m_array = nullptr;
		source.m_size = 0;
		source.m_top = -1;
	}

	LifoArray<T>& operator = (const LifoArray<T>& source)
	{
		m_size = source.m_size;
		m_top = source.m_top;

		if (m_array) delete[]m_array;
		m_array = new T[m_size];

		for (int i = 0; i <= m_top; i++)
		{
			m_array[i] = source.m_array[i];
		}
		return *this;
	}

	LifoArray<T>& operator = (LifoArray<T>&& source)
	{
		m_size = source.m_size;
		m_top = source.m_top;

		if (m_array) delete[]m_array;

		if (!source.m_array) m_array = new T[m_size];
		else m_array = source.m_array;

		source.m_size = 0;
		source.m_top = -1;
		source.m_array = nullptr;
		return *this;
	}

	~LifoArray()
	{
		if (m_array)
			delete []m_array;
	}

	void Push(const T& item) noexcept
	{
		if (m_top == (m_size - 1))
			throw std::range_error("Stack is already Full.");

		++m_top;
		m_array[m_top] = item;
	}

	T Pop() noexcept
	{
		auto &ret = Top();

		m_array[m_top] = 0;
		--m_top;

		return ret;
	}

	const T& Top() const noexcept
	{
		if (m_top == -1)
			throw std::exception("Stack is Empty.");

		return m_array[m_top];
	}

	int Size() const noexcept { return m_size; }

	int CurrentStackSize() const noexcept { return (m_top + 1); }

	bool IsEmpty() { return m_top == -1; }

	void Clear() noexcept
	{ 
		m_top = -1;
		if (m_array) delete[]m_array;
		m_array = new T[m_size];
	}

	friend std::ostream& operator << (std::ostream& out, const LifoArray<T>& source)
	{
		int top = source.m_top;

		out << "[Top] " << source.m_array[top];
		--top;
		while (top >= 0)
		{
			out << " -> " << source.m_array[top];
			--top;
		}

		out << " [Bottom]";

		return out;
	}
};

