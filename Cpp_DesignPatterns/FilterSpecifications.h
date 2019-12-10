#pragma once
#include "Entities.h"

template <typename T> struct ISpecification
{
	virtual bool is_satisfied(T* item) = 0;

	virtual ~ISpecification() = default;
};

struct ColorSpecification : ISpecification<Product>
{
	Color color;

	ColorSpecification(Color c) : color{ c } {}

	bool is_satisfied(Product* item) override
	{
		return color == item->color;
	}

	~ColorSpecification() = default;
};

struct SizeSpecification : ISpecification<Product>
{
	Size size;

	SizeSpecification(Size s) : size{ s } {}

	bool is_satisfied(Product* item) override
	{
		return size == item->size;
	}

	~SizeSpecification() = default;
};

struct ColorAndSizeSpecification : ISpecification<Product>
{
	Color color;
	Size size;

	ColorAndSizeSpecification(Color c, Size s) : color{ c }, size{ s } {}

	bool is_satisfied(Product* item) override
	{
		return color == item->color && size == item->size;
	}

	~ColorAndSizeSpecification() = default;
};

