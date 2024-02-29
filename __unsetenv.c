#include "builtins.h"

/**
* __unsetenv - function unsets the environment variables
* @info: arguments given
* Return: returns status
*/
int __unsetenv(info_t *info)
{
	char **args = info->tokens + 1;

	if (!args[0])
	{
		perror("unsetenv: Missing name argument.\n");
		info->status = EXIT_FAILURE;
		return (info->status);
	}

	while (*args)
	{
		if (unsetenv(*args) != 0)
		{
			perror("unsetenv");
			info->status = EXIT_FAILURE;
			return (info->status);
		}
		args++;
	}

	info->status = EXIT_SUCCESS;
	return (info->status);
}
