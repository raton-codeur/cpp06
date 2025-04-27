
#include <iostream>

#include "ScalarConverter.class.hpp"

void	test_converter(std::string str) {
	std::cout << "--- Input: " << str << " ---" << std::endl;
	ScalarConverter::convert(str);
	std::cout << std::endl;
}

int main(int argc, char **argv) {

//	if (argc != 2) {
//		std::cout << "Usage: " << argv[0] << " <string>" << std::endl;
//		return 1;
//	}
//	ScalarConverter::convert(argv[1]);

	(void)argc;
	(void)argv;
	test_converter("0");
	test_converter("42");
	test_converter("42.0");
	test_converter("42.0f");
	test_converter("42.2");
	test_converter("-42.2");
	test_converter("42.2f");
	test_converter("-inff");
	test_converter("+inf");
	test_converter("nan");
	test_converter("invalid");
	test_converter("42.2ff");
	test_converter("4.2.2f");
	test_converter("--42");
	test_converter("2147483647");
	test_converter("2147483648");
	test_converter("");
	test_converter("999999999999999999f");
	test_converter("999999999999999999999999999999999999999999.9");
	test_converter("-1");

	return 0;
}
