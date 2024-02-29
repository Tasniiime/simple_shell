#include "hsh.h"

/**
  * _sigint - function re-prompts the user
  * @signal: signal passed
  */
void _sigint(int signal __attribute__((unused)))
{
	fflush(STDIN_FILENO);
	write(STDERR_FILENO, "\n$ ", 3);
}
