#include "ScalarConverter.hpp"

char ScalarConverter::_char = 0;
int ScalarConverter::_int = 0;
float ScalarConverter::_float = 0;
double ScalarConverter::_double = 0;

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

void ScalarConverter::convert(const std::string& literal)
{
	std::string trimmed = trim(literal);
	const char* to_check = trimmed.c_str();

	if (trimmed.length() == 1 && std::isprint(trimmed[0]) && !std::isdigit(trimmed[0]))
	{
		_char = trimmed[0];
		std::cout << "char : " << _char << std::endl;
	}
	else if (trimmed == "+inf" || trimmed == "-inf" || trimmed == "nan" ||
		trimmed == "+inff" || trimmed == "-inff" || trimmed == "nanf")
	{
		std::cout << "special" << std::endl;

	}
	else if (is_float(to_check))
	{
		errno = 0;
		_float = std::strtof(to_check, NULL);
		if (errno == ERANGE)
			std::cout << "float : overflow ou underflow : " << _float << std::endl;
		else
			std::cout << "float : " << _float << std::endl;
	}
	else if (is_double(to_check))
	{
		errno = 0;
		_double = std::strtod(to_check, NULL);
		if (errno == ERANGE)
			std::cout << "double : overflow ou underflow : " << _double << std::endl;
		else
			std::cout << "double : " << _double << std::endl;
	}
	else if (is_int(to_check))
	{
		errno = 0;
		_int = std::strtol(to_check, NULL, 10);
		if (errno == ERANGE || _int > INT_MAX || _int < INT_MIN)
			std::cout << "int : overflow ou underflow : " << _int << std::endl;
		else
			std::cout << "int : " << _int << std::endl;
	}
	else
		std::cout << "other" << std::endl;
}
