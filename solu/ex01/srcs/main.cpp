
#include <iostream>
#include "Serializer.class.hpp"

void	print_data_structure(Data *data) {
	std::cout << std::endl << "Data structure:" << std::endl;
	std::cout << "s1: " << data->s1 << std::endl;
	std::cout << "n: " << data->n << std::endl;
	std::cout << "s2: " << data->s2 << std::endl << std::endl;
}

int main() {

	// Create data structure
	Data data;
	data.s1 = "Hello";
	data.n = 42;
	data.s2 = "World";
	print_data_structure(&data);

	// Serialize data structure
	uintptr_t raw = Serializer::serialize(&data);

	// Deserialize data structure
	Data *data2 = Serializer::deserialize(raw);
	print_data_structure(data2);

	return 0;
}
