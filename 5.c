//5.c create process in LINUX


#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child_pid;
    child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (child_pid == 0) {
        printf("This is the child process (pid %d)\n", getpid());
    } else {
        printf("This is the parent process (pid %d)\n", getpid());
        printf("Child process created with (pid %d)\n", child_pid);
    }

    return 0;
}
