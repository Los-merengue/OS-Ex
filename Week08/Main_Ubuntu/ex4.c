#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = getpid(); // Get the current process ID

    printf("My PID is: %d\n", pid);
    
    // Exit the program with a success status code (0)
    exit(0);
}
