#ifndef SCALARCONVERTER_CLASS_HPP
# define SCALARCONVERTER_CLASS_HPP

# include <iostream>
# include <sstream>
# include <iomanip>

class ScalarConverter
{
	public:
		static void convert(const std::string& str);

	private:
		ScalarConverter(); // Default constructor
		ScalarConverter(ScalarConverter const &src); // Copy constructor
		~ScalarConverter(); // Destructor
		ScalarConverter	&operator=(ScalarConverter const &rhs); // Copy assignment operator
};

#endif