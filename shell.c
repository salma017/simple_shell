#include "shell.h"
/**
 * shell - function representing the main shell loop it takes
 * user input processes and executes based on the command type
 */
void shell_(void)
{
	char *line = NULL, *arg[10], *path = "/bin/", *full;
	/* line : store user input command*/
	/*arg : store tokenized command arguments path : default path*/
	/*full: store the full path*/
	size_t len = 0;
	ssize_t read;
	/* stores the number of characters read by the read_cmd function */
	int exitstatus = -1;

	while ((read = read_command(&line, &len)) != -1)
	{
		line[read - 1] = (line[read - 1] == '\n') ? '\0' : line[read - 1];

		if (line[0] == '\0')
			continue;
		if (remove_whitespace(line))
			break;
		switch (get_command_type(line))
		{
			case COMMAND_ENV:
				print_env();
				free(line);
				exit(EXIT_SUCCESS);
				break;
			case COMMAND_EXIT:
				tokenize_string(line, arg);
				handle_exit(arg, line, exitstatus);
				break;
			default:
				tokenize_string(line, arg);
				_path_(arg[0], path, &full);
				exitstatus = execute_command(arg, full, line);
				break;
		}
	}

	free(line);
}
/**
 * main - Entry main
 * Return: 0
 */
int main(void)
{
	shell_();
	return (0);
}
