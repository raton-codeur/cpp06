#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP
#include <iostream>

class ScalarConverter
{
	private :
							ScalarConverter();
							ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConverter& other);
							~ScalarConverter();

	public :
		static void convert(const std::string& literal);
};

#endif