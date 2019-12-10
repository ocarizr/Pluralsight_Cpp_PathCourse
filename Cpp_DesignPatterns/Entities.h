#pragma once
enum class Color { Red, Green, Blue };
enum class Size { Small, Medium, Large };

struct Product {
	std::string name;
	Color color;
	Size size;
};
