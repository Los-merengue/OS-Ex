#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>


int main(void){
    pid_t root_pid = getpid();
    printf("Root Pid: %d\n", root_pid);
    int status;
    clock_t t;
    t = clock();
    pid_t child_pid = fork();
    if(child_pid == 0){
        // it is child
        pid_t child = getpid();
        printf("First child pid %d, parents pid: %d\n", child, root_pid);
    }
    else{
        pid_t root_pid1 = getpid();
        pid_t child_pid2 = fork();
        pid_t child = getpid();
        if(child_pid2 == 0){
            // it is child
            printf("Second child pid %d, parents pid: %d\n", child, root_pid1);
        }
        else{
            clock_t init_t = clock();
            waitpid(child_pid, &status, 0);
            double delta = (double)(clock() - t);
            if(WIFEXITED(status)){
                printf("Execution time of first child is: %lf milliseconds\n", delta / CLOCKS_PER_SEC * 1000.0);
            }
            
            clock_t wasted_time = clock() - init_t;
            waitpid(child_pid2, &status, 0);
            double delta2 = (double)(clock() - wasted_time - t);
            if(WIFEXITED(status)){
                printf("Execution time of second child is: %lf milliseconds\n", delta2 / CLOCKS_PER_SEC * 1000.0);
            }
        }
    }

	return 0;
}
