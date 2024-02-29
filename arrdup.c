#include "tokens.h"

/**
 * arrdup - function duplicates a (NULL-terminated) array
 * @arr: the array to be duplicate
 *
 * Return: returns a duplicate of the arr
 */
char **arrdup(char **arr)
{
	char **dup = NULL;
	size_t len = 0;

	if (!arr)
		return (NULL);
	while (arr[len++])
		;
	dup = malloc(sizeof(*dup) * len);
	if (!dup)
		return (NULL);
	while (len--)
		dup[len] = _strdup(arr[len]);
	return (dup);
}
