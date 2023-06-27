#include "shell.h"
/**
 * exit_func - function that handle the termination of a shell program
 * @arg: array of string represent command line with arguments
 *@line: the user input command
 *@exitsts: exit status of the shell program
 *Return: -
 */
void exit_func(char *arg[], char *line, int exitsts)
{
	if (arg[1])
	{
		if (is_valid_exit_num(arg[1]))
		{
			exitsts = atoi(arg[1]);
		}
		else
		{
			fprintf(stderr, "./shell: exit: you can't exit with number: %s\n", arg[1]);
			exitsts = 2;
		}
	}
	else if (exitsts == -1)
	{
		exitsts = EXIT_SUCCESS;
	}

	free(line);
	exit(exitsts);
}
/**
 * is_valid_exit_num - checks if the argument is a valid exit number or not
 *@arg: argument
 *Return: 1 or 0
 */
int is_valid_exit_num(char *arg)
{
	if (arg[0] != '-' && check_if_numeric(arg))
		return (1);
	else
		return (0);
}
