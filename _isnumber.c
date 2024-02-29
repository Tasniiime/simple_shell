#include "ctype.h"

/**
  * _isnumber - func checks if a string consists of only of digits
  * @s: pointer to string
  * Return: returns true or false
  */
bool _isnumber(const char *s)
{
	if (s)
	{
		while (*s)
		{
			if (!_isdigit(*s++))
				return (false);
		}
		return (true);
	}
	return (false);
}
