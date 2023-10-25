#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void sigint_handler(int signum) {
    printf("Interrupted!\n");
}

int main() {
    signal(SIGINT, sigint_handler);
    
    while (1) {
        // Run "Hello World" program
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
