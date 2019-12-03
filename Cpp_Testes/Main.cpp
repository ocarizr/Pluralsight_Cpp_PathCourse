#include <iostream>

class test
{
	uint8_t value;

public:
	test() = default;
	test(uint8_t v) noexcept : value(v) {}

	uint8_t& get_value() noexcept { return value; }

	test& operator++()
	{
		++value;
		return *this;
	}

	test operator++(int)
	{
		return operator++();
	}
};

int main()
{
	test t(5);
	++t;
	t++;
	auto& value = t.get_value();
	std::cout << value << "\n";
	return 0;
}