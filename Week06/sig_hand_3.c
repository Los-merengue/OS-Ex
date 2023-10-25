#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int child_pid;

void sigalrm_handler(int signum) {
    printf("Child process (PID %d) received a SIGALRM signal.\n", child_pid);
    exit(0);
}

int main() {
    signal(SIGALRM, sigalrm_handler);

    int pid = fork();

    if (pid == 0) {
        // Child process
        child_pid = getpid();
        alarm(3); // Set an alarm for 3 seconds
        while (1) {
            printf("Child process (PID %d) is running...\n", child_pid);
            sleep(1); // Simulate some work
        }
    } else if (pid > 0) {
        // Parent process
        int status;
        wait(&status);
    } else {
        perror("fork");
        exit(1);
    }

    return 0;
}
