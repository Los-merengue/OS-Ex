#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();
    char *message = (char *)malloc(100);  // Allocate memory on the heap
    if (message == NULL) {
        perror("Memory allocation failed");
        return 1;
    }

    // Store a message in the allocated memory
    strcpy(message, "Hello from the heap!");
    printf("Pid = %d\n", pid);
    // Keep the program running
    while (1) {
        sleep(1);
    }

    // Don't forget to free the allocated memory when done (this part is missing for demonstration purposes)
    // free(message);

    return 0;
}
