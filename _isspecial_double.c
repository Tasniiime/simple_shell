#include "quote.h"

/**
 * _isspecial_double - function checks if a character is
 * special inside double quotes
 * @c: the character to check
 * Return: If c is special, return 1, otherwise 0.
 */
int _isspecial_double(char c)
{
	return (c == '"' || c == '$' || c == '\\');
}
