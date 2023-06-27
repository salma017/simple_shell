#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void prompt() {
    printf("$ ");
}

void execute_command(char *command) {
    if (strlen(command) == 0) {
        return;
    }

    int pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        char *args[] = {command, NULL};
        execvp(command, args);

        // If execvp returns, an error occurred
        perror("execvp");
        exit(1);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

int main() {
    char command[BUFFER_SIZE];

    while (1) {
        prompt();

        if (fgets(command, BUFFER_SIZE, stdin) == NULL) {
            // Handle end of file (Ctrl+D)
            break;
        }

        command[strcspn(command, "\n")] = '\0';  // Remove trailing newline

        execute_command(command);
    }

    return 0;
}
