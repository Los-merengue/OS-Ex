#include <stdio.h>
#include <stdlib.h>

int main() {
    char *message = (char *)malloc(50 * sizeof(char));
    if (message == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    snprintf(message, 50, "Hello, this is a message in the heap.");

    printf("Message: %s\n", message);

    free(message);

    return 0;
}
