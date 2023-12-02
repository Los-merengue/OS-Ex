#include <stdio.h>

int main() {
    char str[100]; // Declare a character array to store the string

    // Prompt the user to enter a string
    printf("Enter a string: ");

    // Use scanf to read a string from stdin
    if (scanf("%s", str) == 1) {
        // Input was successfully read
        printf("You entered: %s\n", str);
    } else {
        // Input was not successfully read
        printf("Invalid input. Please enter a string.\n");
    }

    return 0;
}
