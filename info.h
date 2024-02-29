#ifndef _INFO_H_
#define _INFO_H_

#include <stdlib.h>
#include <unistd.h>
#include "alias.h"
#include "tokens.h"
#include "command.h"
#include "env.h"
#include "history.h"
#include "error.h"
#include "getline.h"
#include "list.h"
#include "string.h"
#include "types.h"
#include <fcntl.h>

extern char **environ;

/**
  * struct info - This is the shell state
  * @interactive: the functions argument(s)
  * @argc: the functions argument(s)
  * @argv: the functions argument(s)
  * @file: the functions argument(s)
  * @fileno: the functions argument(s)
  * @status: the functions argument(s)
  * @line: the functions argument(s)
  * @lineno: the functions argument(s)
  * @tokens: the functions argument(s)
  * @pid: the functions argument(s)
  * @cwd: the functions argument(s)
  * @exe: the functions argument(s)
  * @env: the functions argument(s)
  * @path: the functions argument(s)
  * @aliases: the functions argument(s)
  * @history: the functions argument(s)
  * @commands: the functions argument(s)
  */
struct info
{
	int interactive;
	int argc;
	char **argv;
	char *file;
	int fileno;
	int status;
	char *line;
	size_t lineno;
	char **tokens;
	pid_t pid;
	char *cwd;
	char *exe;
	env_t *env;
	list_t *path;
	alias_t *aliases;
	history_t *history;
	cmdlist_t *commands;
};

info_t *init_info(int argc, char **argv);
int free_info(info_t *info);

#endif /* _INFO_H_ */
