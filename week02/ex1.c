#include <stdio.h>

int main() {
    char username[100]; // Define a buffer to hold the user input

    printf("Enter your username: ");
    if (fgets(username, sizeof(username), stdin) != NULL) {
        // fgets succeeded, so the input is stored in 'username'
        printf("Hello, %s", username);
    } else {
        // An error occurred while reading input
        printf("Error reading input.\n");
    }

    return 0;
}
