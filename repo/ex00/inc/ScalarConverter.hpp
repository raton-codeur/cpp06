#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP
#include <iostream>
#include <string>
#include <cctype>
#include <cerrno>
#include <climits>
#include <cstdlib>

class ScalarConverter
{
	private :
		static char		_char;
		static long		_int;
		static float	_float;
		static double	_double;

							ScalarConverter();
							ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConverter& other);
							~ScalarConverter();

	public :
		static void convert(const std::string& literal);
};

/* utils.cpp */
std::string	trim(const std::string& s);
bool		is_int(const char* s);
bool		is_double(const char* s);
bool		is_float(const char* s);

#endif