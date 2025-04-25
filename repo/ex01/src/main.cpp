#include "Serializer.hpp"

int main()
{
	std::cout << "--- 1 ---" << std::endl;
	Data data;
	data.a = 21;
	data.b = 42;
	std::cout << "data content : " << data.a << ", " << data.b << std::endl;
	std::cout << "data address : " << &data << std::endl;

	std::cout << "--- 2 ---" << std::endl;
	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "serialized value (uintptr_t) (in hex) : " << std::hex << serialized << std::dec << std::endl;

	std::cout << "--- 3 ---" << std::endl;
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "deserialized value (Data*) : " << deserialized << std::endl;

	std::cout << "--- 4 ---" << std::endl;
	std::cout << "data content using the deserialized value : " << deserialized->a << ", " << deserialized->b << std::endl;
}
