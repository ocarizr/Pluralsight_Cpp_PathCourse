#include <iostream>

class test
{
	uint8_t value;

public:
	test() = default;
	test(uint8_t v) noexcept : value(v) {}
	test(test& t) noexcept : value(t.value) {}
	
	uint8_t& get_value() const noexcept { return value; }

	test& operator++()
	{
		++value;
		return *this;
	}

	test operator++(int)
	{
		test t(*this);
		operator++();
		return t;
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