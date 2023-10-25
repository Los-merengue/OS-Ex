#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int sigint_count = 0;

void sigint_handler(int signum) {
    if (sigint_count == 0) {
        printf("Ignoring the first SIGINT\n");
        sigint_count++;
    } else {
        printf("Received SIGINT, terminating.\n");
        exit(1);
    }
}

int main() {
    signal(SIGINT, sigint_handler);

    while (1) {
        int pid = fork();
        if (pid == 0) {
            execlp("echo", "echo", "Hello World", NULL);
            perror("execlp");
            exit(1);
        } else if (pid > 0) {
            int status;
            wait(&status);
        } else {
            perror("fork");
            exit(1);
        }
    }

    return 0;
}
