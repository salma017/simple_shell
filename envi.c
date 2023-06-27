#include "main.h"
/**
 * print_env - this function is used to print all environment in the program
 *
 */
void print_env(void)
{
	int i;
	char **env = environ;

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}
/**
 * tokenize_string - tokenizes a string into
 * separate arguments by splitting the whitespace characters
 *@line: store the user input command
 *@arg: store the tokenized command arg
 *Return: i
 */
int tokenize_string(char *line, char **arg)
{
	int i = 0;
	char *token = strtok(line, " \n");

	while (token != NULL && i < 10)
	{
		arg[i] = token;
		i++;
		token = strtok(NULL, " \n");
	}

	arg[i] = NULL;

	return (i);
}
