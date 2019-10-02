#pragma once

#include <utility>
#include <iostream>

template<typename T>
class Item
{
	Item* m_next;
	T m_value;

public:
	explicit Item(T value) : m_value(value), m_next(nullptr) {}

	Item(const Item<T>& source) : m_value(source.m_value), m_next(source.m_next) {}

	Item(Item<T>& source) : m_value(source.m_value), m_next(source.m_next) 
	{
		m_value = 0;
		m_next = nullptr;
	}

	~Item() noexcept { delete m_next; }

	void AddNext(Item& nextNode) { m_next = nextNode; }
};

template<typename T>
class LinkedList
{
	int m_size;
	Item<T>* m_item;

public:
	explicit LinkedList() : m_size(0), m_item(nullptr) {}

	~LinkedList() { delete m_item; }

	T& operator [] (int index)
	{
		if (index >= m_size)
		{
			throw std::range_error("Index out of range.");
		}

		if (index == 0)
		{
			return m_item->m_value;
		}
		else
		{
			auto& temp = m_item;
			for (int i = 1; i < index; ++i)
			{
				temp = temp.m_next;
			}

			return temp.m_value;
		}
	}

	void PushBack(T item)
	{
		if (m_size == 0)
		{
			m_item = new Item<T>(item);
		}
		else
		{
			Item<T>& temp = m_item;

			while (temp.m_next)
			{
				temp = temp.m_next;
			}

			temp.AddNext(new Item<T>(item));
		}

		++m_size;
	}

	void InsertAfter(int index, T item)
	{
		if (index >= m_size)
		{
			throw std::range_error("Index out of range.");
		}

		Item<T>& temp = m_item;

		for (int i = 1; i < index; ++i)
		{
			temp = temp.m_next;
		}

		auto stored = temp.m_next;

		delete temp.m_next;

		temp.AddNext(new Item<T>(item));

		temp = temp.m_next;

		temp.AddNext(stored);
	}
};

