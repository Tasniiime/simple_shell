#include "builtins.h"
/**
* _cd - Function implementation changes current working directory.
* @path: Directory to change to, or NULL to change to HOME.
* Return: Returns 0 on success, or -1 on error
* we have an error message printed to stderr.
*/
int _cd(const char *path)
{
	const char *dir;
	char cwd[1024];
	static char prev_dir[1024] = "";

	if (path == NULL || strcmp(path, "~") == 0)
	{
		dir = getenv("HOME");
		if (!dir)
		{
			fprintf(stderr, "HOME not set\n");
			return (-1);
		}
	}
	else if (strcmp(path, "-") == 0)
	{
		if (strlen(prev_dir) == 0)
		{
			fprintf(stderr, "Previous directory is not available\n");
			return (-1);
		}
		dir = prev_dir;
		printf("%s\n", dir);
	}
	else
	{
		dir = path;
	}
	if (getcwd(prev_dir, sizeof(prev_dir)) == NULL)
	{
		fprintf(stderr, "Error in getting the current directory\n");
		return (-1);
	}
	if (chdir(dir) != 0)
	{
		perror("cd");
		return (-1);
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		fprintf(stderr, "Error in updating PWD\n");
		return (-1);
	}
	_setenv("PWD", cwd);
	return (0);
}
