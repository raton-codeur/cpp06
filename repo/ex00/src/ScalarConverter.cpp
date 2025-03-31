#include "ScalarConverter.hpp"

char	ScalarConverter::_char = 0;
long	ScalarConverter::_int = 0;
float	ScalarConverter::_float = 0;
double	ScalarConverter::_double = 0;
int		ScalarConverter::_char_state = S_DEFAULT;
int		ScalarConverter::_int_state = S_DEFAULT;
int		ScalarConverter::_float_state = S_DEFAULT;
int		ScalarConverter::_double_state = S_DEFAULT;

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

	// char
	if (trimmed.length() == 1 && std::isprint(trimmed[0]) && !std::isdigit(trimmed[0]))
	{
		_char = trimmed[0];
		std::cout << "char : " << _char << std::endl;
	}

	// special
	else if (trimmed == "+inf" || trimmed == "-inf" || trimmed == "nan" ||
		trimmed == "+inff" || trimmed == "-inff" || trimmed == "nanf")
	{
		std::cout << "special" << std::endl;

	}

	// float
	else if (is_float_string(to_check))
	{
		errno = 0;
		_float = std::strtof(to_check, NULL);
		check_erange(_float);
		if (_float_state == S_OK)
			std::cout << "float : " << _float << std::endl;
		else
			std::cout << "float error : " << _float_state << std::endl;
	}

	// double
	else if (is_double_string(to_check))
	{
		errno = 0;
		_double = std::strtod(to_check, NULL);
		check_erange(_double);
		if (_double_state == S_OK)
			std::cout << "double : " << _double << std::endl;
		else
			std::cout << "double error : " << _double_state << std::endl;
	}

	// int
	else if (is_int_string(to_check))
	{
		errno = 0;
		_int = std::strtol(to_check, NULL, 10);
		check_erange(_int);
		if (_int_state == S_OK)
			std::cout << "int : " << _int << std::endl;
		else
			std::cout << "int error : " << _int_state << std::endl;
	}

	else
		std::cout << "other" << std::endl;
}
