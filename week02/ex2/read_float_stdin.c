#include <stdio.h>

int main() {
    float number;

    // Prompt the user to enter a float number
    printf("Enter a float number: ");
    
    // Read the float number from stdin
    if (scanf("%f", &number) == 1) {
        // Input was successfully read
        printf("You entered: %f\n", number);
    } else {
        // Input was not a valid float
        printf("Invalid input. Please enter a float number.\n");
    }

    return 0;
}
