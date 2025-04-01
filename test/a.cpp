#include <iostream>

int main()
{
	float f = 2147483647;
	std::cout << std::fixed << f << std::endl;
	int i;
	if (f > static_cast<double>(INT_MAX) || f < static_cast<double>(INT_MIN))
		i = 0;
	else
		i = static_cast<int>(f);
	std::cout << i << std::endl;
}
