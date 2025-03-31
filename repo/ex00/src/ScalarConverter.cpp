#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{}

std::string trim(const std::string& s)
{
	int i, start, end;

	i = 0;
	while (i < s.length() && std::isspace(s[i]))
		i++;
	start = i;
	i = s.length() - 1;
	while (i > start && std::isspace(s[i]))
		i--;
	end = i + 1;
	return s.substr(start, end);
}

void ScalarConverter::convert(const std::string& literal)
{
	(void)literal;
	std::cout << "test" << std::endl;
}
