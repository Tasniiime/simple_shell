#include "ctype.h"

/**
 * _isquote - func checks if a character is a quote
 * @c: the character to check
 * Return: If c is a quote, returns 1, or 0.
 */
bool _isquote(int c)
{
	return (c == '"' || c == '\'' || c == '\\');
}
