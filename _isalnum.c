#include "ctype.h"

/**
  * _isalnum - function checks if the character is alphanumeric
  * @c: character to check
 * Return: Returns 1 if c is alphanumeric, otherwise 0
  */
bool _isalnum(int c)
{
	return (_isalpha(c) || _isdigit(c));
}
