#pragma once
#include "FilterSpecifications.h"

template <typename T> struct IFilter
{
	virtual std::vector<T*> Filter(std::vector<T*> items, ISpecification<T>& spec) = 0;

	virtual ~IFilter() = default;
};

struct TheFilter : IFilter<Product>
{
	using Items = std::vector<Product*>;

	std::vector<Product*> Filter(std::vector<Product*> items, ISpecification<Product>& spec) override
	{
		Items result;
		for (auto& p : items)
			if (spec.is_satisfied(p))
				result.push_back(p);

		return result;
	}

	~TheFilter() = default;
};

