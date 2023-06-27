#ifndef SHELL_H
#define SHELL_H

#define COMMAND_ENV 1
#define COMMAND_EXIT 2
#define COMMAND_CUSTOM 3

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void shell(void);
int exec_cmd(char **arg, char *full, char *line);
void _path(char *bin, char *path, char **full);
int tokenize_string(char *line, char **arg);
ssize_t read_command(char **line, size_t *len);
void shell(void);
int get_command_type(const char *line);
int is_valid_exit_num(char *arg);
void exit_func(char *arg[], char *line, int exitstatus);
int check_if_numeric(const char *str);
int remove_whitespace(char *str);
void print_env(void);

#endif
