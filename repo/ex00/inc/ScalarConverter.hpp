#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP
#include <iostream>
#include <string>
#include <cctype>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <cfloat>
#include <iomanip>

enum
{
	_OK,
	_ERROR,
	_NON_DISPLAYABLE,
	_INF,
	_M_INF,
	_NAN,
};

class ScalarConverter
{
	private :
		static char		_char;
		static long		_int;
		static float	_float;
		static double	_double;
		static int		_state_char;
		static int		_state_int;
		static int		_state_float;
		static int		_state_double;

		static void	convert_from_char(char c);
		static void	convert_from_int(const char* literal);
		static void	convert_from_float(const char* literal);
		static void	convert_from_double(const char* literal);
		static void	convert_from_string(const std::string& literal_trim);

		static void	print_char();
		static void	print_int();
		static void	print_float();
		static void	print_double();
		static void	print();

							ScalarConverter();
							ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConverter& other);
							~ScalarConverter();

	public :
		static void convert(const std::string& literal);
};

/* utils.cpp */
std::string	trim(const std::string& s);
bool		is_int_string(const char* s);
bool		is_double_string(const char* s);
bool		is_float_string(const char* s);

#endif