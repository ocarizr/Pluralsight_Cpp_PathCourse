#pragma once
#include <iostream>
#include <vector>
#include "Filter.h"

class Preliminar
{
public:
	static void filter_function()
	{
		Product house{ "house", Color::Blue, Size::Large };
		Product apple{ "apple", Color::Red, Size::Small };
		Product car{ "car", Color::Blue, Size::Medium };
		Product tree{ "tree", Color::Green, Size::Large };
		Product ball{ "ball", Color::Red, Size::Small };

		std::vector<Product*> products{ &house, &apple, &car, &tree, &ball };

		TheFilter filter;
		ColorSpecification cs(Color::Blue);
		SizeSpecification ss(Size::Medium);
		ColorAndSizeSpecification css(Color::Blue, Size::Large);

		auto result = filter.Filter(products, cs);
		auto result2 = filter.Filter(products, ss);
		auto result3 = filter.Filter(products, css);

		for (auto& item : result)
			std::cout << item->name << std::endl;
		std::cout << std::endl;
		for (auto& item : result2)
			std::cout << item->name << std::endl;
		std::cout << std::endl;
		for (auto& item : result3)
			std::cout << item->name << std::endl;
		std::cout << std::endl;
	}
};

