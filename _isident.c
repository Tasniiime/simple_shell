#include "ctype.h"

/**
  * _isident - function checks if the character is a valid identifier character
  * @c: character to check
  * Return: Returns 1 if c is alphanumeric, or 0
  */
bool _isident(int c)
{
	return (c == '_' || _isalnum(c));
}
