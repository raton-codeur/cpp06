
#include "Serializer.class.hpp"

Serializer::Serializer(void) {
	std::cout << "Default serializer constructor called" << std::endl;
}

Serializer::Serializer(Serializer const &src) {
	std::cout << "Copy serializer constructor called" << std::endl;
	*this = src;
}

Serializer::~Serializer(void) {
	std::cout << "Destructor serializer called" << std::endl;
}

Serializer	&Serializer::operator=(Serializer const &src) {
	(void)src;
	std::cout << "Copy serializer assignment operator called" << std::endl;
	return *this;
}

/*
 * The reinterpret_cast operator allows you to convert any pointer into any other pointer type.
 */
uintptr_t	Serializer::serialize(Data *ptr) {
	std::cout << "Serialize called" << std::endl;
	return reinterpret_cast<uintptr_t>(ptr);
}

/*
 * The reinterpret_cast operator allows you to convert any pointer into any other pointer type.
 */
Data		*Serializer::deserialize(uintptr_t raw) {
	std::cout << "Deserialize called" << std::endl;
	return reinterpret_cast<Data *>(raw);
}