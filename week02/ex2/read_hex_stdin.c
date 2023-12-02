#include <stdio.h>

int main() {
    int hexNumber;

    // Prompt the user to enter a hexadecimal number
    printf("Enter a hexadecimal number: ");
    
    // Read the hexadecimal number from stdin
    if (scanf("%x", &hexNumber) == 1) {
        // Input was successfully read
        printf("You entered: 0x%x\n", hexNumber);
    } else {
        // Input was not a valid hexadecimal number
        printf("Invalid input. Please enter a hexadecimal number.\n");
    }

    return 0;
}
