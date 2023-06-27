#include "shell.h"
/**
 * remove_whitespace -> function that remove whitespace
 * and trailing whitespace characters from a given string
 * @str: string
 * Return: 1 or 0
 */
int remove_whitespace(char *str)
{
	int len = strlen(str); /* length of the input string */
	int start = 0; /* index of the first non-whitespace chara in input string */
	int end = len - 1; /* index of the last non-whitespace char in input string */
	int i;

	/* Trim leading whitespace */
	while (str[start] == ' ' || str[start] == '\t')
	{
		start++;
	}
	/* Trim trailing whitespace */
	while (end > start && (str[end] == ' ' || str[end] == '\t'))
	{
		end--;
	}

	/* Move the trimmed string to the beginning of the original string */
	for (i = 0; i <= end - start; i++)
	{
		str[i] = str[start + i];
	}
	str[i] = '\0';

	/* Return 1 if the string is empty after trimming, 0 otherwise */
	return (i == 0);
}
/**
 * get_command_type - determines the type of command line based on input
 * @line: user input command
 * Return: depend
 */
int get_command_type(const char *line)
{
	if (strcmp(line, "env") == 0)
	{
		return (COMMAND_ENV); /* exit with a status */
	}
	else if (strcmp(line, "exit") == 0)
	{
		return (COMMAND_EXIT); /* exit with a status */
	}
	else
	{
		if (strcmp(line, "custom") == 0)
		{
			return (COMMAND_CUSTOM); /* exit with a status */
		}
		return (0);
	}
}
/**
 * read_command - eads a line of input from the user
 * @line: input command
 * @len: length
 * Return: input
 */
ssize_t read_command(char **line, size_t *len)
{
	ssize_t read = 0;

	if (isatty(STDIN_FILENO))
	{
		write(1, "$ ", 2);
	}
	read = getline(line, len, stdin);
	if (read == -1)
	{
		if (!isatty(STDIN_FILENO))
		{
			return (-1);
		}
		free(line);
		exit(EXIT_FAILURE);
	}
	return (read);
}
