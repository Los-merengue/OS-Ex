#include <stdio.h>
#include <stdlib.h>

int main() {
    int integerVal = 2022; // Input integer
    char str[10]; // Assuming a reasonable buffer size

    // Use sprintf to convert the integer to a string
    sprintf(str, "%d", integerVal);

    printf("Integer: %d\n", integerVal);
    printf("String: %s\n", str);

    return 0;
}
