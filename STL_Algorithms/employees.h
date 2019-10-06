#pragma once

class employees
{
	std::string m_name;
	int m_age;
	std::string m_department;
	float m_salary;

public:
	employees(std::string name, int age, std::string department, float salary) :
		m_name(name),
		m_age(age),
		m_department(department),
		m_salary(salary) {}

	employees(const employees& source) = default;
	employees(employees&& source) = default;
	employees& operator = (const employees& source) = default;
	employees& operator = (employees&& source) = default;

	void set_name(std::string name) { m_name = name; }
	void set_age(int age) { m_age = age; }
	void set_department(std::string department) { m_department = department; }
	void set_salary(float salary) { m_salary = salary; }

	std::string get_name() const noexcept { return m_name; }
	int get_age() const noexcept { return m_age; }
	std::string get_deparment() const noexcept { return m_department; }
	float get_salary() const noexcept { return m_salary; }

	friend std::ostream& operator << (std::ostream& out, const employees& source)
	{
		out << source.m_name << "\t|\t" << source.m_age << "\t|\t" << source.m_department << "\t|\t$" << source.m_salary << ".\n";
		return out;
	}
};

