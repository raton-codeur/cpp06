#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP
#include <iostream>
#include <string>
#include <cctype>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <cmath>

typedef enum
{
	S_DEFAULT,
	S_OK,
	S_OVERFLOW,
	S_UNDERFLOW,
	S_ERANGE,
	S_INF,
	S_M_INF,
	S_NAN
}	state;

class ScalarConverter
{
	private :
		static char		_char;
		static long		_int;
		static float	_float;
		static double	_double;
		static int		_char_state;
		static int		_int_state;
		static int		_float_state;
		static int		_double_state;

		/* check_erange.cpp */
		static void check_erange(long n);
		static void	check_erange(double d);
		static void	check_erange(float f);

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