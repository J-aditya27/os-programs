#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pipe_fd[2];
    pid_t pid;

    if (pipe(pipe_fd) == -1) {
        perror("pipe creation failed");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        close(pipe_fd[1]);

        int number;
        printf("Child process (printing odd number) : \n");
        while (read(pipe_fd[0], &number, sizeof(number)) > 0) {
            if (number % 2 != 0) {
                printf("%d\n", number);
            }
        }
        close(pipe_fd[0]);
        exit(EXIT_SUCCESS);
    } else {
        close(pipe_fd[0]);

        printf("Parent process & sending numbers to child\n");
        for (int i = 1; i <= 10; i++) {
            printf("sending: %d\n", i);
            write(pipe_fd[1], &i, sizeof(i));
        }

        close(pipe_fd[1]);
        wait(NULL); // Add this line to ensure the child process finishes before the parent exits
        return 0;
    }
}


