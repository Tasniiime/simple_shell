#include "ctype.h"

/**
  * _isalpha - func checks if the character is alphabetic
  * @c: character to check
 * Return: returns 1 if c is alphanumeric, otherwise 0

  */
bool _isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
