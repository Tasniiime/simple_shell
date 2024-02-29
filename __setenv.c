#include "builtins.h"

/**
* __setenv - function sets the environment variables
* @info: arguments passed
*
* Return: returns the status
*/
int __setenv(info_t *info)
{
	char **args = info->tokens + 1;

	if (!args[0])
	{
		perror("setenv: Missing name argument.\n");
		info->status = EXIT_FAILURE;
		return (info->status);
	}
	if (!args[1])
	{
		perror("setenv: Missing value argument.\n");
		info->status = EXIT_FAILURE;
		return (info->status);
	}
	if (args[2])
	{
		perror("setenv: Too many arguments.\n");
		info->status = EXIT_FAILURE;
		return (info->status);
	}

	if (setenv(args[0], args[1], 1) != 0)
	{
		perror("setenv");
		info->status = EXIT_FAILURE;
	}
	else
	{
		info->status = EXIT_SUCCESS;
	}

	return (info->status);
}
