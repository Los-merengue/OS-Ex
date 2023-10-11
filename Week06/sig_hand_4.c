#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <ctype.h>

void sigusr1_handler(int signum) {
    printf("Received SIGUSR1: Input may be a negative number.\n");
}

void sigusr2_handler(int signum) {
    printf("Received SIGUSR2: Input is not a valid number.\n");
}

int main() {
    signal(SIGUSR1, sigusr1_handler);
    signal(SIGUSR2, sigusr2_handler);

    printf("Enter a positive integer: ");

    char input[256];
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove the newline character from input
        input[strcspn(input, "\n")] = '\0';

        if (isdigit(input[0])) {
            printf("Valid input: %s\n", input);
        } else if (input[0] == '-') {
            raise(SIGUSR1); // Raise SIGUSR1 for potential negative number
        } else {
            raise(SIGUSR2); // Raise SIGUSR2 for non-numeric input
        }
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}
