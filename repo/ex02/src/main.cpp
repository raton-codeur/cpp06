#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

Base* generate(void)
{
	int i = std::rand() % 3;
	switch (i)
	{
		case 0 :
			std::cout << "generated type :\t\t\t" << RED << "A" << RESET << std::endl;
			return new A();
		case 1 :
			std::cout << "generated type :\t\t\t" << GREEN << "B" << RESET << std::endl;
			return new B();
		default :
			std::cout << "generated type :\t\t\t" << BLUE << "C" << RESET << std::endl;
			return new C();
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "identified type using a pointer :\t" << RED << "A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "identified type using a pointer :\t" << GREEN << "B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "identified type using a pointer :\t" << BLUE << "C" << RESET << std::endl;
	else
		std::cerr << "error : unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "identified type using a reference :\t" << RED << "A" << RESET << std::endl;
		return;
	}
	catch (std::exception &e) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "identified type using a reference :\t" << GREEN << "B" << RESET << std::endl;
		return;
	}
	catch (std::exception &e) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "identified type using a reference :\t" << BLUE << "C" << RESET << std::endl;
		return;
	}
	catch (std::exception &e) {}

	std::cerr << "error : unknown type" << std::endl;
}

int main()
{
	std::srand(std::time(NULL));
	for (int i = 0; i < 10; i++)
	{
		std::cout << "---" << std::endl;
		Base* ptr = generate();
		identify(ptr);
		identify(*ptr);
	}
}
