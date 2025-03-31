#include "ScalarConverter.hpp"

void ScalarConverter::check_erange(long n)
{
	if (errno == ERANGE || n < INT_MIN || n > INT_MAX)
	{
		if (n == LONG_MIN || n < INT_MIN)
			_state = S_UNDERFLOW;
		else
			_state = S_OVERFLOW;
	}
	else
	{
		_state = S_OK;
		// _float_state = S_OK;
		// _float = static_cast<float>(n);
		// _double_state = S_OK;
		// _double = static_cast<double>(n);
		// // peut etre que char marche pas
	}
}

void ScalarConverter::check_erange(double d)
{
	if (errno == ERANGE)
	{
		if (d == 0.0)
			_state = S_UNDERFLOW;
		else if (d == HUGE_VAL || d == -HUGE_VAL)
			_state = S_OVERFLOW;
		else
			_state = S_ERANGE;
	}
	else
	{
		_state = S_OK;
		// peut etre que float, int, char marchent pas
	}
}

void ScalarConverter::check_erange(float f)
{
	if (errno == ERANGE)
	{
		if (f == 0.0f)
			_state = S_UNDERFLOW;
		else if (f == HUGE_VALF || f == -HUGE_VALF)
			_state = S_OVERFLOW;
		else
			_state = S_ERANGE;
	}
	else
	{
		_state = S_OK;
		// _double_state = S_OK;
		// _double = static_cast<double>(f);
		// _int_state = S_OK;
		// _int = static_cast<long>(f);
		// // peut etre que char marche pas
	}
}
