
#ifndef SERIALIZER_CLASS_HPP
# define SERIALIZER_CLASS_HPP

# include <iostream>

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

class Serializer
{
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);

	private:
		Serializer(); // Default constructor
		~Serializer(); // Destructor
		Serializer(Serializer const &src); // Copy constructor
		Serializer	&operator=(Serializer const &src); // Copy assignment operator
};

#endif