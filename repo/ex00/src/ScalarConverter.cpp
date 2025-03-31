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
	std::string::size_type i, start, end;

	i = 0;
	while (i < s.length() && std::isspace(s[i]))
		i++;
	start = i;
	i = s.length() - 1;
	while (i > start && std::isspace(s[i]))
		i--;
	end = i + 1;
	return s.substr(start, end - start);
}

bool is_int(const char* s)
{
	int i;

	if (s[0] == '\0')
		return false;
	if (s[0] == '-' || s[0] == '+')
		i = 1;
	else
		i = 0;
	if (std::isdigit(s[i]) == false)
		return false;
	i++;
	while (s[i])
	{
		if (std::isdigit(s[i]) == false)
			return false;
		i++;
	}
	return true;
}

bool is_double(const char* s)
{
	int i;

	if (s[0] == '\0')
		return false;
	if (s[0] == '-' || s[0] == '+')
		i = 1;
	else
		i = 0;
	if (std::isdigit(s[i]) == false)
		return false;
	i++;
	while (s[i] && s[i] != '.')
	{
		if (std::isdigit(s[i]) == false)
			return false;
		i++;
	}
	if (s[i] != '.')
		return false;
	i++;
	if (std::isdigit(s[i]) == false)
		return false;
	i++;
	while (s[i])
	{
		if (std::isdigit(s[i]) == false)
			return false;
		i++;
	}
	return true;
}

bool is_float(const char* s)
{
	int i;

	if (s[0] == '\0')
		return false;
	if (s[0] == '-' || s[0] == '+')
		i = 1;
	else
		i = 0;
	if (std::isdigit(s[i]) == false)
		return false;
	i++;
	while (s[i] && s[i] != '.')
	{
		if (std::isdigit(s[i]) == false)
			return false;
		i++;
	}
	if (s[i] != '.')
		return false;
	i++;
	if (std::isdigit(s[i]) == false)
		return false;
	i++;
	while (s[i] && s[i] != 'f')
	{
		if (std::isdigit(s[i]) == false)
			return false;
		i++;
	}
	if (s[i] != 'f')
		return false;
	i++;
	return s[i] == '\0';
}

void ScalarConverter::convert(const std::string& literal)
{
	std::string trimmed_literal = trim(literal);
	const char* literal_to_check = trimmed_literal.c_str();
	

	std::cout << is_float(s2) << std::endl;
}
