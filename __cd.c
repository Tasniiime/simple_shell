#include "builtins.h"


/**
* __cd_error - Function prints an error
* if there is failure to change directory
* @info: shell informations
* @dir: a directory
*/
void __cd_error(info_t *info, char *dir)
{
	fprintf(stderr, "%s: %d: can't cd to %s\n", info->argv[0], info->lineno, dir);
	info->status = 2;
}


/**
* __cd_success - function updates the environment on success
* @info: shell info
*/
void __cd_success(info_t *info)
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		_setenv("OLDPWD", info->cwd);
		free(info->cwd);
		info->cwd = strdup(cwd);
		_setenv("PWD", info->cwd);
	}
	else
	{
		fprintf(stderr, "Error updating current working directory.\n");
	}

	info->status = EXIT_SUCCESS;
}

/**
* __cd - changing the directory
* @info: arguments passed in
*
* Return: int
*/
int __cd(info_t *info)
{
	char *dir = NULL, **args = info->tokens + 1;

	if (*args)
	{
		if (!_strcmp(*args, "-"))
		{
			dir = get_dict_val(info->env, "OLDPWD");
			dir = (dir) ? dir : info->cwd;
		}
		else
		{
			dir = *args;
		}
	}
	else
	{
		dir = get_dict_val(info->env, "HOME");
	}

	if (dir && chdir(dir) == 0)
	{
		_cd_success(info);
	}
	else
	{
		_cd_error(info, dir ? dir : "HOME");
	}

	return (info->status);
}
