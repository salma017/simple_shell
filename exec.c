#include "shell.h"

/**
 * cmd_error - handles execution errors
 *
 * @full: full path that specifies the location of the exucutable file
 * @arg: command and its arguments
 * @line: user command
*/

void cmd_error(char *full, char **arg, char *line)
{
	if (execve(full, arg, environ) == -1)
	{
		free(full);
		free(line);
		perror("./shell");
		exit(EXIT_FAILURE);
	}
}


/**
 * exec_cmd - executes a command by forking a new process
 *@arg: command and its arguments
 *@full:full path that specifies the location of the exucutable file
 *@line: user command
 * Return: depends
 */
int exec_cmd(char **arg, char *full, char *line)
{
	pid_t child_pid;

	if (strcmp(arg[0], "exit") == 0)
	{
		exit_func(arg, line, 0);
		return (-1);
	}
	child_pid = fork();
	if (child_pid == 0)
	{
		if (strcmp(arg[0], "./hbtn_ls") == 0)
		{
			char *new_env[] = {NULL};

			execve("./hbtn_ls", arg, new_env);
		}
		else
		{
			cmd_error(full, arg, line);
		}
		fprintf(stderr, "./shell: %s: command not found\n", line);
		exit(EXIT_FAILURE);
	}
	else if (child_pid > 0)
	{
		int status;

		waitpid(child_pid, &status, 0);
		free(full);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
		fprintf(stderr, "./shell: %s: terminated abnormally\n", line);
		return (-1);
	}
	else
	{
		perror("Failed to fork a new process");
		return (-1);
	}
}
