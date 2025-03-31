#include "ScalarConverter.hpp"

char	ScalarConverter::_char = 0;
long	ScalarConverter::_int = 0;
float	ScalarConverter::_float = 0;
double	ScalarConverter::_double = 0;
int		ScalarConverter::_state_char = _OK;
int		ScalarConverter::_state_int = _OK;
int		ScalarConverter::_state_float = _OK;
int		ScalarConverter::_state_double = _OK;

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
	const std::string&	literal_trim = trim(literal);
	const char*			literal_c_str = literal_trim.c_str();

	errno = 0;

	// char
	if (literal_trim.length() == 1
		&& std::isprint(literal_trim[0])
		&& !std::isdigit(literal_trim[0]))
			convert_from_char(literal_trim[0]);

	// int
	else if (is_int_string(literal_c_str))
		convert_from_int(literal_c_str);

	// float
	else if (is_float_string(literal_c_str))
		convert_from_float(literal_c_str);

	// double
	else if (is_double_string(literal_c_str))
		convert_from_double(literal_c_str);

	else
		convert_from_string(literal_trim);

	print();
}

void ScalarConverter::convert_from_char(char c)
{
	_char = c;
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
}

void ScalarConverter::convert_from_int(const char* literal)
{
	_int = std::strtol(literal, NULL, 10);
	if (errno == ERANGE || _int < INT_MIN || _int > INT_MAX)
	{
		_state_char = _ERROR;
		_state_int = _ERROR;
		_state_float = _ERROR;
		_state_double = _ERROR;
		return ;
	}

	//char
	if (_int < CHAR_MIN || _int > CHAR_MAX)
		_state_char = _ERROR;
	else if (std::isprint(_int) == false)
		_state_char = _NON_DISPLAYABLE;
	else
		_char = static_cast<char>(_int);

	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
}

void ScalarConverter::convert_from_float(const char* literal)
{
	_float = std::strtof(literal, NULL);
	if (errno == ERANGE)
	{
		_state_char = _ERROR;
		_state_int = _ERROR;
		_state_float = _ERROR;
		_state_double = _ERROR;
		return ;
	}

	// char
	if (_float < CHAR_MIN || _float > CHAR_MAX)
		_state_char = _ERROR;
	else if (std::isprint(_float) == false)
		_state_char = _NON_DISPLAYABLE;
	else
		_char = static_cast<char>(_float);

	// int
	if (_float < INT_MIN || _float > INT_MAX)
		_state_int = _ERROR;
	else
		_int = static_cast<int>(_float);

	_double = static_cast<double>(_float);
}

void ScalarConverter::convert_from_double(const char* literal)
{
	_double = std::strtod(literal, NULL);
	if (errno == ERANGE)
	{
		_state_char = _ERROR;
		_state_int = _ERROR;
		_state_float = _ERROR;
		_state_double = _ERROR;
		return ;
	}

	// char
	if (_double < CHAR_MIN || _double > CHAR_MAX)
		_state_char = _ERROR;
	else if (std::isprint(_double) == false)
		_state_char = _NON_DISPLAYABLE;
	else
		_char = static_cast<char>(_double);

	// int
	if (_double < INT_MIN || _double > INT_MAX)
		_state_int = _ERROR;
	else
		_int = static_cast<int>(_double);

	// float
	if (_double < -FLT_MAX || _double > FLT_MAX)
		_state_float = _ERROR;
	else
	{
		_float = static_cast<float>(_double);
		if (_double != 0.0 && _float == 0.0f)
			_state_float = _ERROR;
	}
}

void ScalarConverter::convert_from_string(const std::string& literal)
{
	if (literal == "+inf" || literal == "+inff")
	{
		_state_char = _ERROR;
		_state_int = _ERROR;
		_state_float = _INF;
		_state_double = _INF;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		_state_char = _ERROR;
		_state_int = _ERROR;
		_state_float = _M_INF;
		_state_double = _M_INF;
	}
	else if (literal == "nan" || literal == "nanf")
	{
		_state_char = _ERROR;
		_state_int = _ERROR;
		_state_float = _NAN;
		_state_double = _NAN;
	}
	else
	{
		_state_char = _ERROR;
		_state_int = _ERROR;
		_state_float = _ERROR;
		_state_double = _ERROR;
	}
}

void ScalarConverter::print_char()
{
	std::cout << "char : ";
	if (_state_char == _ERROR)
		std::cout << "impossible";
	else if (_state_char == _NON_DISPLAYABLE)
		std::cout << "non displayable";
	else
		std::cout << _char;
	std::cout << std::endl;
}

void ScalarConverter::print_int()
{
	std::cout << "int : ";
	if (_state_int == _ERROR)
		std::cout << "impossible";
	else
		std::cout << _int;
	std::cout << std::endl;
}

void ScalarConverter::print_float()
{
	std::cout << "float : ";
	if (_state_float == _ERROR)
		std::cout << "impossible";
	else if (_state_float == _INF)
		std::cout << "+inff";
	else if (_state_float == _M_INF)
		std::cout << "-inff";
	else if (_state_float == _NAN)
		std::cout << "nanf";
	else
		std::cout << std::fixed << std::setprecision(1) << _float << "f";
	std::cout << std::endl;
}

void ScalarConverter::print_double()
{
	std::cout << "double : ";
	if (_state_double == _ERROR)
		std::cout << "impossible";
	else if (_state_double == _INF)
		std::cout << "+inf";
	else if (_state_double == _M_INF)
		std::cout << "-inf";
	else if (_state_double == _NAN)
		std::cout << "nan";
	else
		std::cout << std::fixed << std::setprecision(1) << _double;
	std::cout << std::endl;
}

void ScalarConverter::print()
{
	print_char();
	print_int();
	print_float();
	print_double();
}
