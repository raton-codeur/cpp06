#include "ScalarConverter.hpp"

int main()
{
	std::string s;
	while (s != "q")
	{
		std::cout << "literal : ";
		std::getline(std::cin, s);
		ScalarConverter::convert(s);
	}
	return 0;
}
